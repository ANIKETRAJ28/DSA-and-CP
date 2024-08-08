#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode *l2) {
        ListNode *ans = NULL, *dummy = ans;
        while(l1 && l2) {
            if(l1->val > l2->val) {
                if(!ans) {
                    ans = l2;
                    dummy = ans;
                    l2 = l2->next;
                } else {
                    dummy->next = l2;
                    dummy = dummy->next;
                    l2 = l2->next;
                }
            } else {
                if(!ans) {
                    ans = l1;
                    dummy = ans;
                    l1 = l1->next;
                } else {
                    dummy->next = l1;
                    dummy = dummy->next;
                    l1 = l1->next;
                }
            }
        }
        if(l1) {
            if(!ans) {
                ans = l1;
            } else {
                dummy->next = l1;
            }
        }
        if(l2) {
            if(!ans) {
                ans = l2;
            } else {
                dummy->next = l2;
            }
        }
        return ans;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL; 
        while(lists.size() > 1) {
            ListNode *list1 = lists[lists.size()-1];
            lists.pop_back();
            ListNode *list2 = lists[lists.size()-1];
            lists.pop_back();
            ListNode *newList = merge(list1, list2);
            lists.push_back(newList);
        }
        return lists[0];
    }
};

int main() {
    
    return 0;
}