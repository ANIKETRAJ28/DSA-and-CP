#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/introduction-to-doubly-linked-list_8160413?leftPanelTabValue=PROBLEM

class Node
{
    public:
    int data;
    Node *next, *prev;
    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
};

Node* constructDLL(vector<int>& arr) {
    // Write your code here
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1 ; i < n ; i++){
        Node* dummy = new Node(arr[i]);
        temp->next = dummy;
        dummy->prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    
    return 0;
}