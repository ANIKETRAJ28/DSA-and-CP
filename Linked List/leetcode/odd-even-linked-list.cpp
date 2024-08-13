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
        ListNode *odd = new ListNode(-1), *even = new ListNode(-1), *oddTemp = odd, *evenTemp = even;
        int n = 1;
        while(head) {
            if(n%2) {
                oddTemp->next = head;
                head = head->next;
                oddTemp = oddTemp->next;
                oddTemp->next = NULL;
            } else {
                evenTemp->next = head;
                head = head->next;
                evenTemp = evenTemp->next;
                evenTemp->next = NULL;
            }
            n++;
        }
        oddTemp = odd;
        while(oddTemp->next) oddTemp = oddTemp->next;
        oddTemp->next = even->next;
        return odd->next;
    }
};

int main() {
    
    return 0;
}