#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *prv = new ListNode(INT_MIN), *cur = prv, *nxt = head;
        prv->next = head;
        head = prv;
        while(nxt) {
            if(cur->val == nxt->val) {
                nxt = nxt->next;
                if(!nxt) prv->next = NULL;
            } else {
                prv->next = nxt;
                cur = nxt;
                nxt = nxt->next;
                if(!nxt) {
                    prv->next = cur;
                    break;
                }
                if(cur->val != nxt->val) {
                    prv = cur;
                }
            }
        }
        return head->next;
    }
};

int main() {
    
    return 0;
}