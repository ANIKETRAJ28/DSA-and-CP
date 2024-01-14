#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/insert-node-at-the-beginning_8144739

class Node {
    public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

Node* insertAtFirst(Node* list, int newValue) {
    // Write your code here
    Node* temp = new Node(newValue);
    temp->next = list;
    list = temp;
    return list;
}

int main(){
    
    return 0;
}