#include <iostream>
using namespace std;

int binary_to_decimal(string &s)
{
  int n = s.size();
  int ans = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    ans += (s[i] - '0') << n - i - 1;
  }
  return ans;
}

string decimal_to_binary(int num)
{
  string ans = "";
  while (num > 0)
  {
    if (num % 2)
    {
      ans = '1' + ans;
    }
    else
    {
      ans = '0' + ans;
    }
    num /= 2;
  }
  return ans;
}

int main()
{
  string s;
  cin >> s;
  int num = binary_to_decimal(s);
  cout << num << "\t" << decimal_to_binary(num) << "\n";
  return 0;
}