#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/delete-last-node-of-a-doubly-linked-list_8160469?leftPanelTabValue=PROBLEM

struct Node {
    int value;
    Node *prev;
    Node *next;
    Node() : value(0), prev(nullptr), next(nullptr) {}
    Node(int val) : value(val), prev(nullptr), next(nullptr) {}
    Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
};

Node * deleteLastNode(Node *head) {
    // Write your code here
    if(!head->next) return NULL;
    Node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}


int main(){
    
    return 0;
}