#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
 
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;
        return dfsClone(node, nodeMap);
    }
    
    UndirectedGraphNode *dfsClone(UndirectedGraphNode *node, 
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &nodeMap) {
        if (node == NULL) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator it = nodeMap.find(node);
        if (it != nodeMap.end()) {
            return it->second;
        }
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        newNode->neighbors.resize(node->neighbors.size());
        nodeMap[node] = newNode;
        for (int i=0; i<node->neighbors.size(); i++) {
            newNode->neighbors[i] = dfsClone(node->neighbors[i], nodeMap);
        }
        return newNode;
    }
};

int main() {
	return 0;
}