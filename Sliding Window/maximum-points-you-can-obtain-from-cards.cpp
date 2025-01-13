#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

class Solution
{
public:
  int maxScore(vector<int> &cardPoints, int k)
  {
    int n = cardPoints.size();
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
      sum += cardPoints[i];
    }
    int maxSum = sum;
    for (int i = k - 1; i >= 0; i--)
    {
      sum -= cardPoints[i];
      sum += cardPoints[n - k + i];
      maxSum = max(maxSum, sum);
    }
    return maxSum;
  }
};

int main()
{

  return 0;
}