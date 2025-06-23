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
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;

        std::unordered_map<int, Node*> idToNodeClone;
        std::set<int> fullyClonedIds;
        
        Node* originClone = new Node(node->val);
        idToNodeClone[1] = originClone;

        std::vector<Node*> copyQueue = {node};
        while (copyQueue.size() > 0) {
            std::vector<Node*> nextCopyQueue;
            for (std::vector<Node*>::iterator itor = copyQueue.begin(); itor != copyQueue.end(); ++itor) {
                Node* currNode = *itor;
                if (fullyClonedIds.contains(currNode->val)) continue;

                std::vector<Node*> neighbors = currNode->neighbors;
                std::vector<Node*> neighborClones;
                for (std::vector<Node*>::iterator nItor = neighbors.begin(); nItor != neighbors.end(); ++nItor) {
                    Node* neighbor = *nItor;
                    int neighborId = neighbor->val;

                    if (not idToNodeClone.contains(neighborId)) {
                        idToNodeClone[neighborId] = new Node(/* _val= */ neighborId);
                    }
                    neighborClones.push_back(idToNodeClone[neighborId]);
                    nextCopyQueue.push_back(neighbor);
                }
                Node* currClone = idToNodeClone[currNode->val];
                currClone->neighbors = neighborClones;
                fullyClonedIds.insert(currNode->val);
            }
            copyQueue = nextCopyQueue;
        }

        return originClone;
    }
};
