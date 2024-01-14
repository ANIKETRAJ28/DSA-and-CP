#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/introduction-to-linked-list_8144737

class Node {
    public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

Node* constructLL(vector<int>& arr) {
    // Write your code here
    Node* head = new Node(arr[0]);
    Node* temp = head; 
    int n = arr.size();
    for(int i = 1 ; i < n ; i++){
        Node* dummy = new Node(arr[i]);
        temp->next = dummy;
        temp = dummy;
    }
    return head;
}

int main(){
    
    return 0;
}