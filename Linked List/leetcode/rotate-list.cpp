#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/rotate-list/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!k || !head) return head;
        int n = 0;
        ListNode *temp = head, *dummy = head;
        while(dummy){
            n++;
            dummy = dummy->next;
        }
        k%=n;
        n = n-k-1;
        dummy = head;
        while(dummy->next){
            dummy = dummy->next;
            n--;
            if(!n) temp = dummy;
        }
        dummy->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode * reverse(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode *newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || !k) return head;
        int n = 0;
        ListNode *dummy = head;
        while(dummy) {
            n++;
            dummy = dummy->next;
        }
        k %= n;
        k = n-k-1;
        ListNode *reverse1 = head, *reverse2 = head;
        while(k--) {
            reverse1 = reverse1->next;
            reverse2 = reverse2->next;
        }
        reverse2 = reverse2->next;
        reverse1->next = NULL;
        reverse1 = reverse(head);
        reverse2 = reverse(reverse2);
        dummy = reverse1;
        while(dummy->next) {
            dummy = dummy->next;
        }
        dummy->next = reverse2;
        return reverse(reverse1);
    }
};

int main(){
    
    return 0;
}