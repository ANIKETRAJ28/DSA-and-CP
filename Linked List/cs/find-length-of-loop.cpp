#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/find-length-of-loop_8160455?leftPanelTabValue=PROBLEM

class Node {
    public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

int lengthOfLoop(Node *head) {
    // Write your code here
    Node *fast = head, *slow = head;
    bool flag = true;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            flag = false;
            break;
        }
    }
    slow = slow->next;
    if(flag) return 0;
    int cnt = 1;
    while(slow != fast){
        slow = slow->next;
        cnt++;
    }
    return cnt;
}

int main(){
    
    return 0;
}