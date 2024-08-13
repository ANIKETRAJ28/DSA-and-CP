#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/linked-list-cycle-ii/description/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool flag = false;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                flag = true;
                break;
            }
        }
        if(!flag) return NULL;
        ListNode *temp = head;
        while(temp) {
            if(temp == slow) return slow;
            temp = temp->next;
            slow = slow->next;
        }
        return NULL;
    }
};

int main() {
    
    return 0;
}