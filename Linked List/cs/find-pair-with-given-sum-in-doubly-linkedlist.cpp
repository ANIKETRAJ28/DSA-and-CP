#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/find-pairs-with-given-sum-in-doubly-linked-list_1164172

class Node
{
    public:
    int data;
    Node *next, *prev;
    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
    Node(int x, Node *next, Node *prev) : data(x), next(next), prev(prev) {}
};

vector<pair<int, int>> findPairs(Node* head, int k)
{
    // Write your code here.
    unordered_set<int> st;
    vector<pair<int, int>> ans;
    Node* temp = head;
    while(temp){
        int val = k - temp->data;
        if(st.find(val) == st.end()){
            st.insert(temp->data);
        }
        else{
            ans.push_back({temp->data, val});
            st.erase(val);
        }
        temp = temp->next;
    }
    return ans;
}

int main(){
    
    return 0;
}