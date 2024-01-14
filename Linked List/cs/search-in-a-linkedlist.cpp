#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/search-in-a-linked-list_975381?leftPanelTabValue=PROBLEM

class Node{
    public:
    int data;
    Node *next;
    Node(){
        this->data = 0;
        next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next){
        this->data = data;
            this->next = next;
    }
};

int searchInLinkedList(Node<int> *head, int k) {
    // Write your code here.
    while(head){
        if(head->data == k) return true;
        head = head->next;
    }
    return false;
}

int main(){
    
    return 0;
}