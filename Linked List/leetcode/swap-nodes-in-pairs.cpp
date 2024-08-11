#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/swap-nodes-in-pairs/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *ans = NULL, *curr = head, *nxt = curr->next, *prv = NULL;
        while(curr) {
            curr->next = curr->next->next;
            nxt->next = curr;
            if(prv == NULL) ans = nxt;
            else prv->next = nxt;
            prv = curr;
            curr = curr->next;
            if(!curr || !curr->next) return ans;
            nxt = curr->next; 
        }
        return NULL;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *curr = head, *nxt = curr->next, *prv = new ListNode(-1), *ans = prv;
        while(curr) {
            curr->next = curr->next->next;
            nxt->next = curr;
            prv->next = nxt;
            prv = curr;
            curr = curr->next;
            if(!curr || !curr->next) return ans->next;
            nxt = curr->next; 
        }
        return NULL;
    }
};

int main() {
    
    return 0;
}