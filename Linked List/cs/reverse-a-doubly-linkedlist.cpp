#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

class Node
{
    public:
    int data;
    Node *next, *prev;
    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
};

Node* reverseDLL(Node* head)
{   
    // Write your code here   
    Node *temp1 = head, *temp2 = head;
    int cnt = 1;
    while(temp2->next){
        cnt++;
        temp2 = temp2->next;
    }
    cnt /= 2;
    while(cnt--){
        swap(temp1->data, temp2->data);
        temp1 = temp1->next;
        temp2 = temp2->prev;
    }
    return head;
}

int main(){
    
    return 0;
}