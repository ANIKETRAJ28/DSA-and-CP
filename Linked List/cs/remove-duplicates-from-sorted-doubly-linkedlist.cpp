#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/remove-duplicates-from-a-sorted-doubly-linked-list_2420283?leftPanelTabValue=PROBLEM

class Node
{
    public:
    int data;
    Node *next, *prev;
    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
};

Node * removeDuplicates(Node *head)
{
    // Write your code here
    Node* temp = head;
    while(temp){
        Node* dummy = temp->next;
        while(dummy and dummy->data == temp->data){
            dummy = dummy->next;
        }
        temp->next = dummy;
        temp = dummy;
    }
    return head;
}

int main(){
    
    return 0;
}