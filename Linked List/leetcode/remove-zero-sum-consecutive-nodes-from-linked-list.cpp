#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> arr;
        while(head) {
            arr.push_back(head->val);
            head = head->next;
        }
        ListNode* newHead = NULL;
        ListNode* dummy = newHead;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++) {
            int sum = 0;
            bool flag = true;
            for(int j = i ; j < n ; j++) {
                sum += arr[j];
                if(sum == 0) {
                    flag = false;
                    i = j;
                    break;
                }
            }
            if(flag) {
                ListNode* temp = new ListNode(arr[i]);
                if(!newHead) {
                    newHead = temp;
                    dummy = temp;
                } else {
                    dummy->next = temp;
                    dummy = temp;
                }
            }
        }
        return newHead;
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        unordered_map<int, ListNode*> mp;
        mp[0] = dummyNode;
        dummyNode->next = head;
        int prefix = 0;
        while(head) {
            prefix += head->val;
            if(mp.find(prefix) == mp.end()) {
                mp[prefix] = head;
            } else {
                ListNode* strt = mp[prefix];
                ListNode* temp = strt;
                int subPrefix = prefix;
                while(temp != head) {
                    temp = temp->next;
                    subPrefix += temp->val;
                    if(temp != head) mp.erase(subPrefix);
                }
                strt->next = head->next;
            }
            head = head->next;
        }
        return dummyNode->next;
    }
};

int main() {
    
    return 0;
}