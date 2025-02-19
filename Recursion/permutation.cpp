#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

void permutation(string s, int i)
{
  int n = s.size();
  if (i == n)
  {
    cout << s << "\n";
    return;
  }
  for (int j = i; j < s.size(); j++)
  {
    string temp = s;
    swap(temp[i], temp[j]);
    permutation(temp, i + 1);
  }
  return;
}

int main()
{
  string s;
  cin >> s;
  permutation(s, 0);
  return 0;
}