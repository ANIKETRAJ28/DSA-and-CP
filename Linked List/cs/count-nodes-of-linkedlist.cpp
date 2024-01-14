#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/count-nodes-of-linked-list_5884?leftPanelTabValue=SUBMISSION

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

int length(Node *head)
{
	//Write your code here/
    int cnt = 0;
    while(head){
        cnt++;
        head = head->next;
    }
    return cnt;
}

int main(){
    
    return 0;
}