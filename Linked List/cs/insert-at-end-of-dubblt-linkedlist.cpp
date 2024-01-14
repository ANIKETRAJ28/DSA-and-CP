#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/insert-at-end-of-doubly-linked-list_8160464?leftPanelTabValue=PROBLEM

struct Node {
    int value;
    Node *prev;
    Node *next;
    Node() : value(0), prev(nullptr), next(nullptr) {}
    Node(int val) : value(val), prev(nullptr), next(nullptr) {}
    Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
};

Node * insertAtTail(Node *head, int k) {
    // Write your code here
    if(!head){
        Node* dummy = new Node(k);
        return dummy;
    }
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    Node* dummy = new Node(k);
    dummy->prev = temp;
    temp->next = dummy;
    return head;
}

int main(){
    
    return 0;
}