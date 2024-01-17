#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/palindrome-linked-list/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *p = NULL, *c = slow, *n = slow->next;
        while(c){
            if(!n){
                c->next = p;
                break;
            }
            c->next = p;
            p = c;
            c = n;
            n = n->next;
        }
        while(head and c){
            if(head->val != c->val) return false;
            head = head->next;
            c = c->next;
        }
        return true;
    }
};

int main(){
    
    return 0;
}