#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/sort-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1), *headTravel = head;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                headTravel->next = l1;
                l1 = l1->next;
            } else {
                headTravel->next = l2;
                l2 = l2->next;
            }
            headTravel = headTravel->next;
        }
        if(l1) {
            headTravel->next = l1;
        }
        if(l2) {
            headTravel->next = l2;
        }
        return head->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *a = head, *b = slow->next;
        slow->next = NULL;
        a = sortList(a);
        b = sortList(b);
        return merge(a, b);
    }
};

int main() {
    
    return 0;
}