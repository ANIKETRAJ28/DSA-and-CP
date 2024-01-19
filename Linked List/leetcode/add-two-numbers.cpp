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
        int rem = 0;
        bool flag = true;
        ListNode *head, *temp;
        while(l1 and l2){
            int sum = l1->val + l2->val+ rem;
            if(flag){
                ListNode* dummy = new ListNode(sum%10);
                rem = sum/10;
                head = dummy;
                temp = dummy;
                flag = false;
            }
            else{
                ListNode* dummy = new ListNode(sum%10);
                rem = sum/10;
                temp->next = dummy;
                temp = dummy;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if(!l1){
            while(l2){
                int sum = l2->val+ rem;
                ListNode* dummy = new ListNode(sum%10);
                rem = sum/10;
                temp->next = dummy;
                temp = dummy;
                l2 = l2->next;
            }
        }
        if(!l2){
            while(l1){
                int sum = l1->val+ rem;
                ListNode* dummy = new ListNode(sum%10);
                rem = sum/10;
                temp->next = dummy;
                temp = dummy;
                l1 = l1->next;
            }
        }
        if(rem){
            ListNode* dummy = new ListNode(rem);
            temp->next = dummy;
        }
        return head;
    }
};

int main(){
    
    return 0;
}