/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> copies;

    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;

        if (copies.count(node)) {
            return copies[node];
        }

        Node* copy = new Node(node->val);
        copies[node] = copy;

        for (Node* neighbor: node->neighbors) {
            Node* clonedNeighbor = cloneGraph(neighbor);
            copy->neighbors.push_back(clonedNeighbor);
        }

        return copy;
    }
};