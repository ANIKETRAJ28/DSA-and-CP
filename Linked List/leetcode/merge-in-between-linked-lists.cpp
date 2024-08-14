#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/merge-in-between-linked-lists/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *x = NULL, *y = NULL;
        ListNode *temp = list1;
        int n = 1;
        while(temp) {
            if(n == a) {
                x = temp;
                temp = temp->next;
                x->next = NULL;
            }
            if(n == b) {
                y = temp->next;
                temp->next = NULL;
            }
            else temp = temp->next;
            n++;
        }
        x->next = list2;
        temp = list2;
        while(list2->next) list2 = list2->next;
        list2->next = y;
        return list1;
    }
};

int main() {
    
    return 0;
}