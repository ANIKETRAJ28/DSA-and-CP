#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *modifiedList(vector<int> &nums, ListNode *head)
  {
    int n = nums.size();
    unordered_set<int> st;
    for (int el : nums)
      st.insert(el);
    ListNode *dummyHead = new ListNode(-1);
    dummyHead->next = head;
    ListNode *temp1 = dummyHead;
    ListNode *temp2 = dummyHead->next;
    while (temp2)
    {
      if (st.find(temp2->val) == st.end())
      {
        temp1->next = temp2;
        temp1 = temp1->next;
      }
      temp2 = temp2->next;
    }
    temp1->next = temp2;
    return dummyHead->next;
  }
};

int main()
{

  return 0;
}