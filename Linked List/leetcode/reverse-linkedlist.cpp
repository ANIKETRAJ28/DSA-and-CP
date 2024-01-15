#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/reverse-linked-list/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode *prv = NULL, *cur = head,  *nxt = head->next;
        while(cur){
            cur->next = prv;
            prv = cur;
            cur = nxt;
            if(nxt == NULL) return prv;
            nxt = nxt->next;
        }
        return prv;
    }
};

int main(){
    
    return 0;
}