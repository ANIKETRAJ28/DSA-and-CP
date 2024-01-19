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

int main(){
    
    return 0;
}