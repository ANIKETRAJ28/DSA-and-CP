#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/reverse-nodes-in-k-group/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverse(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ans = new ListNode(-1), *prv = ans, *cur = prv;
        ans->next = head;
        while(cur) {
            int cnt = k;
            while(cur->next && cnt) {
                cur = cur->next;
                cnt--;
            }
            if(cnt) return ans->next;
            ListNode *nxt = cur->next;
            cur->next = NULL;
            ListNode *rev = reverse(prv->next);
            ListNode *dummy = rev;
            while(dummy) {
                dummy = dummy->next;
            }
            prv->next = rev;
            while(rev->next) rev = rev->next;
            rev->next = nxt;
            prv = rev;
            cur = rev;
        };
        return ans->next;
    }
};

class Solution {
public:
    ListNode *reverse(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ans = new ListNode(-1), *prv = ans, *cur = prv;
        ans->next = head;
        while(cur) {
            int cnt = k;
            while(cur->next && cnt) {
                cur = cur->next;
                cnt--;
            }
            if(cnt) return ans->next;
            ListNode *nxt = cur->next;
            cur->next = NULL;
            cur = reverse(prv->next);
            prv->next = cur;
            while(cur->next) {
                cur = cur->next;
            }
            cur->next = nxt;
            prv = cur;
            cur = prv;
        };
        return ans->next;
    }
};

int main() {
    
    return 0;
}