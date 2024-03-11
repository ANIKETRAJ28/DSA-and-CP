#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/clone-graph/description/

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

class Solution {
public:
    vector<Node*> graph;
    void dfs(Node* real, Node* clone) {
        for(auto neig : real->neighbors) {
            if(graph[neig->val] == NULL) {
                Node* new_node = new Node(neig->val);
                clone->neighbors.push_back(new_node);
                graph[neig->val] = new_node;
                dfs(neig, new_node);
            } else {
                clone->neighbors.push_back(graph[neig->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        graph.resize(105, NULL);
        Node* clone = new Node(node->val);
        graph[node->val] = clone;
        dfs(node, clone);
        return clone;
    }
};

int main() {
    
    return 0;
}