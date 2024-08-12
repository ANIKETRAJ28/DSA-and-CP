#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode* head) {
        ListNode *temp = head;
        int n = 0;
        while(temp) {
            n++;
            temp = temp->next;
        }
        n/= 2;
        temp = head;
        while(n--) temp = temp->next;
        ListNode *tail = temp->next;
        temp->next = NULL;
        tail = reverse(tail);
        while(head && tail) {
            ListNode *headNxt = head->next, *tailNxt = tail->next;
            head->next = tail;
            tail->next = headNxt;
            head = headNxt;
            tail = tailNxt;
        }
        return;
    }
};

int main() {
    
    return 0;
}