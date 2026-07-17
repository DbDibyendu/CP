#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <string>
#include <shared_mutex>
#include <mutex>

using namespace std;

struct Node {
    set<string> val; // Set of unique conversational partners
    Node *next = nullptr;
    Node *prev = nullptr;
    bool isTopK = false;
    string id;

    Node() {}
};

class ChatApp {
private:
    Node *start, *end;
    int linked_list_size, K;

    // FIX: Map stores Node* to prevent object slicing and invalidation during rehashes
    unordered_map<string, Node*> user_to_node;
    shared_mutex mx;

    // Helper: Safely cuts a node out of its current linked list position
    void detachNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Helper: Places a node immediately before a target reference marker
    void insertBefore(Node* target, Node* newNode) {
        newNode->next = target;
        newNode->prev = target->prev;
        target->prev->next = newNode;
        target->prev = newNode;
    }

    void updateLinkedList(Node *user) { // O(K)
        if (user->isTopK) {
            // Bubble Up: Move left while previous node has fewer conversations
            Node* curr = user->prev;
            while (curr != start && curr->val.size() < user->val.size()) {
                curr = curr->prev;
            }
            // If its position actually changed, slice and re-insert
            if (curr->next != user) {
                detachNode(user);
                insertBefore(curr->next, user);
            }
        } else {
            // Case A: The Top-K list still has vacancies
            if (linked_list_size < K) {
                insertBefore(end, user);
                user->isTopK = true;
                linked_list_size++;
                
                // Bubble up to ensure correct sorted position among top entries
                Node* curr = user->prev;
                while (curr != start && curr->val.size() < user->val.size()) {
                    curr = curr->prev;
                }
                if (curr->next != user) {
                    detachNode(user);
                    insertBefore(curr->next, user);
                }
            } 
            // Case B: Top-K list is full. Check if it beats the lowest existing member
            else {
                Node *lowestTopK = end->prev;
                if (lowestTopK->val.size() < user->val.size()) {
                    // Evict the lowest node
                    lowestTopK->isTopK = false;
                    detachNode(lowestTopK);
                    linked_list_size--;

                    // Insert the new node and bubble it up to its correct spot
                    insertBefore(end, user);
                    user->isTopK = true;
                    linked_list_size++;

                    // bubble up
                    Node* curr = user->prev;
                    while (curr != start && curr->val.size() < user->val.size()) {
                        curr = curr->prev;
                    }
                    if (curr->next != user) {
                        detachNode(user);
                        insertBefore(curr->next, user);
                    }
                }
            }
        }
    }

public: // FIX: Exposed constructor and methods to public visibility scope
    ChatApp(int k) {
        K = k;
        start = new Node();
        end = new Node();
        start->next = end;
        end->prev = start;
        linked_list_size = 0;
    }

    void RegisterEvent(int ts, string sender_id, string reciever_id, string message) {
        unique_lock<shared_mutex> lock(mx);

        // Process Sender Node
        if (user_to_node.find(sender_id) == user_to_node.end()) {
            Node* new_node = new Node();
            new_node->id = sender_id;
            user_to_node[sender_id] = new_node;
        }
        Node *userA = user_to_node[sender_id];
        if (sender_id != reciever_id) { 
            userA->val.insert(reciever_id); 
        }

        // Process Receiver Node
        if (user_to_node.find(reciever_id) == user_to_node.end()) {
            Node* new_node = new Node();
            new_node->id = reciever_id;
            user_to_node[reciever_id] = new_node;
        }
        Node *userB = user_to_node[reciever_id];
        if (sender_id != reciever_id) { 
            userB->val.insert(sender_id); 
        }

        // Maintain top-k tracking list positions
        updateLinkedList(userA);
        updateLinkedList(userB);
    }

    string GetMostActiveUser() {
        shared_lock<shared_mutex> lock(mx);
        if (linked_list_size == 0) return "";
        return start->next->id; // The highest element always sits right after start sentinel
    }
};

// alternatively for thread safety, we can consider pub sub method, publish from writer 
// And a subscriber end where it can support concurrent reads, downside might be complex implementation
// Or maybe use distributed lock if there are multiple pods via redis. but there as well we need to lock only
//Asynchronous Event-Driven Pipeline:RegisterEvent instantly publishes event payloads straight to an Apache Kafka 
/// AWS Kinesis partition stream keyed by sender_id.A downstream streaming consumer cluster tracks conversations.
/// It updates a Redis Sorted Set (ZSET) using ZINCRBY.GetMostActiveUser performs an $O(1)$ read hitting the Redis master or a read-replica cluster using ZREVRANGEBYSCORE.
