#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/merge-two-sorted-lists/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans = new ListNode(-1);
        ListNode *dummy = ans;
        while(list1 && list2) {
            if(list1->val <= list2->val) {
                dummy->next = new ListNode(list1->val);
                dummy = dummy->next;
                list1 = list1->next;
            } else {
                dummy->next = new ListNode(list2->val);
                dummy = dummy->next;
                list2 = list2->next;
            }
        }
        if(!list1) {
            while(list2) {
                dummy->next = new ListNode(list2->val);
                dummy = dummy->next;
                list2 = list2->next;
            }   
        }
        if(!list2) {
            while(list1) {
                dummy->next = new ListNode(list1->val);
                dummy = dummy->next;
                list1 = list1->next;
            }   
        }
        return ans->next;
    }
};

int main() {
    
    return 0;
}