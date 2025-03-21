//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array
{
public:
  template <class T>
  static void input(vector<T> &A, int n)
  {
    for (int i = 0; i < n; i++)
    {
      cin >> A[i];
    }
  }

  template <class T>
  static void print(vector<T> &A)
  {
    for (int i = 0; i < A.size(); i++)
    {
      cout << A[i] << " ";
    }
    cout << endl;
  }
};

// } Driver Code Ends

class Gfg
{
public:
  int k;
  int maxSec = 24 * 60 * 60;
  unordered_map<string, int> mp;
  Gfg(int gap)
  {
    k = gap;
  }
  bool judgeOrNot(string &s)
  {
    int n = s.size();
    string s_time = s.substr(n - 8);
    string name = s.substr(0, n - 9);
    int hour = (s_time[0] - '0') * 10 + (s_time[1] - '0');
    int mins = (s_time[3] - '0') * 10 + (s_time[4] - '0');
    int secs = (s_time[6] - '0') * 10 + (s_time[7] - '0');
    int time = (hour * 60 * 60) + (mins * 60) + (secs);
    if (mp.find(name) == mp.end())
    {
      mp[name] = time;
      return true;
    }
    if (mp[name] > time)
    {
      // next day
      int remTime = maxSec - mp[name];
      remTime += time;
      if (remTime < k)
        return false;
      mp[name] = time;
      return true;
    }
    if (time - mp[name] < k)
      return false;
    mp[name] = time;
    return true;
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  scanf("%d ", &t);
  while (t--)
  {

    int n;
    scanf("%d", &n);

    int gap;
    scanf("%d", &gap);

    vector<string> s(n);
    Array::input(s, n);

    Gfg obj(gap);
    for (int i = 0; i < n; i++)
    {
      bool res = obj.judgeOrNot(s[i]);
      if (res)
      {
        cout << "true ";
      }
      else
      {
        cout << "false ";
      }
    }
    cout << endl;

    cout << "~" << "\n";
  }
}

// } Driver Code Ends