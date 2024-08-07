#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;
        while(n--){
            fast = fast->next;
        }
        if(!fast){
            return head->next;
        }
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode *newNode = new ListNode(INT_MAX);
        newNode->next = head;
        head = newNode;
        ListNode *dummy = head;
        while(dummy) {
            dummy = dummy->next;
            cnt++;
        }
        cnt = cnt-n-1;
        dummy = head;
        while(cnt--) {
            dummy = dummy->next;
        }
        dummy->next = dummy->next->next;
        return head->next;
    }
};

int main(){
    
    return 0;
}