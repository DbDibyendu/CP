#include <iostream>
#include <unordered_map>
#ifndef _GLIBCXX_NO_ASSERT
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
#endif

using namespace std;

struct Entity{
  string type;
  string name;
  int size;
  vector<string> children;
};

struct Operation{
  string type; // "add", "remove"
  string fileId;
  string parId;
  Entity savedEntity; // FIX: Need to store the entity data to restore it during a remove-rewind
};

class FileSystem{
// FIX: Added public specifier so your constructor and methods can actually be called from outside
public: 

  unordered_map<string, Entity> fileSystem;

  FileSystem(unordered_map<string, Entity> fs){
    fileSystem = fs;
  };

  unordered_map<string, int> fileSize, fileValid, vis;
  unordered_map<string, string> pars;

  stack<Operation> ops; // FIX: Changed from queue to stack because undo/rewind must be LIFO (Last In, First Out)

  int getSize(string entityId){
    
    int totalSize = 0;
    // FIX: Use a reference (&) so you aren't making a heavy copy of the entity
    Entity &el = fileSystem[entityId]; 

    if(fileSize.find(entityId) != fileSize.end()){
      return fileSize[entityId];
    }

    if(el.type == "file"){
      totalSize += el.size;
    }else if(el.type == "directory"){
      for(auto a: el.children){
        totalSize += getSize(a);
      }
    }

    return fileSize[entityId] = totalSize;
  }

  void addEntity(Entity entity, string parentId){
    
    int totalSize = 0;
    if(fileSystem.find(parentId) == fileSystem.end()) return;

    // FIX: Changed to reference (&). Otherwise, you modify a temporary local copy 
    Entity &el = fileSystem[parentId]; 

    string randId = to_string(rand()); // FIX: changed random() to rand() for standard portability

    if(el.type == "file"){
      return;
    }else if(el.type == "directory"){
      el.children.push_back(randId);
      fileSystem[randId] = entity;
      pars[randId] = parentId; // FIX: Must map the child to its parent here so getFilePath() and removeEntity() work
      
      // FIX: Instead of fileSize[parentId]++, we clear the cached sizes up to the root 
      // because adding a file changes the byte size of all its ancestor directories
      string curr = parentId;
      while(!curr.empty()) {
        fileSize.erase(curr);
        curr = pars[curr];
      }

      Operation o;
      o.type = "add";
      o.fileId = randId;
      o.parId = parentId; // FIX: Storing parentId so rewind knows where it came from
      ops.push(o);
    }

  }


  void removeEntity(string entityId){
    
    int totalSize = 0;
    if(fileSystem.find(entityId) == fileSystem.end()) return; // FIX: Guard clause to prevent crashing if entity doesn't exist
    Entity el = fileSystem[entityId];

    // FIX: Removed the `if(fileSize.find(entityId) != ...)` return. 
    // It was causing the function to exit immediately without deleting anything if the size was cached!

    string parId = pars[entityId];
    // FIX: Changed to reference (&) so changes apply to the actual parent in the fileSystem
    Entity &parEntity = fileSystem[parId]; 

    // FIX: Vector erase requires an iterator. Also changed condition from (a == parId) to (a == entityId)
    for(auto it = parEntity.children.begin(); it != parEntity.children.end(); ++it){
      if(*it == entityId){
        parEntity.children.erase(it);
        
        Operation o;
        o.type = "remove";
        o.fileId = entityId;
        o.parId = parId;
        o.savedEntity = el; // FIX: Save the entity data before deleting it so rewind can restore it
        ops.push(o);
        break; // FIX: Break out of loop since iterator is now invalidated after erase
      }
    }

    // FIX: Clear the cached sizes up to the root because removing an entity changes total directory sizes
    string curr = parId;
    while(!curr.empty()) {
      fileSize.erase(curr);
      curr = pars[curr];
    }

    fileSystem.erase(entityId);
    pars.erase(entityId); // FIX: Clean up parent map tracking
  }

  void rewind(){
    if(ops.empty()) return; // FIX: Prevent top() crash on an empty stack

    Operation top = ops.top(); // FIX: Changed from front() to top() for stack
    ops.pop(); // FIX: Must pop the operation so you don't track it forever

    if(top.type == "add"){
      removeEntity(top.fileId);
    }else if(top.type == "remove"){
      // FIX: You can't fetch from fileSystem[top.fileId] here because it was already erased.
      // We use the savedEntity we attached to the operation structure.
      addEntity(top.savedEntity, top.parId);
    }

  }

  bool validateFile(string parId){
    
    int valid = 1;

    if(vis.find(parId) != vis.end()) valid = 0;

    vis[parId] = 1;

    Entity el = fileSystem[parId];

    if(fileValid.find(parId) != fileValid.end()){
      return fileValid[parId];
    }

    if(el.type == "file"){
      if(el.children.size() > 0){
        valid = 0;
      };

    }else if(el.type == "directory"){
      for(auto a: el.children){
        pars[a] = parId;
        valid &= validateFile(a);
      }
    }

    return fileValid[parId] = valid;
  }

  string getFilePath(string entityId){

    string path ="";
    vector<string> els;

    string curr = entityId;
    while(pars.find(curr) != pars.end()){
      els.push_back(curr);
      curr = pars[curr];
    }

    reverse(els.begin(), els.end());

    for(auto e: els){
      path += e + '/';
    }
    
    if(!path.empty()) path = path.substr(0, path.length()-1); // FIX: Added safety check to prevent out-of-bounds on empty path
    return path;
  }

};
