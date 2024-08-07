#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/add-two-numbers/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *ans = NULL;
        ListNode *dummy = ans;
        while(l1 && l2) {
            int sum = (l1->val + l2->val + carry)%10;
            carry = (l1->val + l2->val + carry)/10;
            ListNode *newNode = new ListNode(sum);
            if(!ans) {
                ans = newNode;
                dummy = ans;
            }
            else {
                dummy->next = newNode;
                dummy = dummy->next;
            }
            l1 = l1->next; 
            l2 = l2->next;
        }
        if(l1) {
            while(l1) {
                int sum = (l1->val + carry)%10;
                carry = (l1->val + carry)/10;
                ListNode *newNode = new ListNode(sum);
                dummy->next = newNode;
                dummy = dummy->next;
                l1 = l1->next; 
            }
        }
        if(l2) {
            while(l2) {
                int sum = (l2->val + carry)%10;
                carry = (l2->val + carry)/10;
                ListNode *newNode = new ListNode(sum);
                dummy->next = newNode;
                dummy = dummy->next;
                l2 = l2->next; 
            }
        }
        if(carry) {
            ListNode *newNode = new ListNode(carry);
            dummy->next = newNode;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}