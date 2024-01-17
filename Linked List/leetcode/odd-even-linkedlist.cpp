#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/odd-even-linked-list/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode *t1 = head, *t2 = head->next, *dumHead = head->next;
        while(t2 and t2->next){
            t1->next = t1->next->next;
            t2->next = t2->next->next;
            t1 = t1->next;
            t2 = t2->next;
        }
        t1->next = dumHead;
        return head;
    }
};

int main(){
    
    return 0;
}