#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Node {
public:
    int id;
    int data;
    vector<Node*> neighbors;

    Node(int _id = 0, int _data = 0) {
        id = _id;
        data = _data;
    }
};

class GraphCodec {
private:
    void encodeDFS(
        Node* node,
        vector<int>& serialized,
        unordered_set<int>& vis
    ) {
        if (!node || vis.count(node->id))
            return;

        vis.insert(node->id);

        // [id, data, degree]
        serialized.push_back(node->id);
        serialized.push_back(node->data);
        serialized.push_back((int)node->neighbors.size());

        // store neighbor ids
        for (auto nbr : node->neighbors) {
            serialized.push_back(nbr->id);
        }

        // DFS traversal
        for (auto nbr : node->neighbors) {
            encodeDFS(nbr, serialized, vis);
        }
    }

public:
    vector<int> encode(Node* root) {
        vector<int> serialized;

        if (!root)
            return serialized;

        unordered_set<int> vis;

        encodeDFS(root, serialized, vis);

        return serialized;
    }

    Node* decode(const vector<int>& graph) {
        if (graph.empty())
            return nullptr;

        unordered_map<int, Node*> nodes;

        // Pass 1:
        // Create all nodes
        int i = 0;

        while (i < (int)graph.size()) {
            int id = graph[i++];
            int data = graph[i++];
            int degree = graph[i++];

            nodes[id] = new Node(id, data);

            i += degree; // skip neighbor ids
        }

        // Pass 2:
        // Reconstruct edges
        i = 0;

        while (i < (int)graph.size()) {
            int id = graph[i++];
            int data = graph[i++];
            int degree = graph[i++];

            Node* curr = nodes[id];

            for (int j = 0; j < degree; j++) {
                int nbrId = graph[i++];
                curr->neighbors.push_back(nodes[nbrId]);
            }
        }

        // First node serialized is root
        return nodes[graph[0]];
    }
};

void printGraph(Node* root) {
    unordered_set<int> vis;

    function<void(Node*)> dfs = [&](Node* node) {
        if (!node || vis.count(node->id))
            return;

        vis.insert(node->id);

        cout << "Node " << node->id
             << " (data=" << node->data << ") -> ";

        for (auto nbr : node->neighbors) {
            cout << nbr->id << " ";
        }

        cout << "\n";

        for (auto nbr : node->neighbors) {
            dfs(nbr);
        }
    };

    dfs(root);
}

int main() {
    /*
            1
          /   \
         2     3
          \   /
            4

       cycle:
       4 -> 1
    */

    Node* n1 = new Node(1, 10);
    Node* n2 = new Node(2, 20);
    Node* n3 = new Node(3, 30);
    Node* n4 = new Node(4, 40);

    n1->neighbors = {n2, n3};
    n2->neighbors = {n4};
    n3->neighbors = {n4};
    n4->neighbors = {n1};

    GraphCodec codec;

    vector<int> encoded = codec.encode(n1);

    cout << "Encoded Graph:\n";
    for (int x : encoded) {
        cout << x << " ";
    }
    cout << "\n\n";

    Node* decodedRoot = codec.decode(encoded);

    cout << "Decoded Graph:\n";
    printGraph(decodedRoot);

    return 0;
}
