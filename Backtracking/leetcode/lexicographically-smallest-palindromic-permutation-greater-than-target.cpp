#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

// https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/

class Solution {
public:
  void find(string curr, string &m, multiset<char> &pool, string &target, string &best) {
    int n = target.size();
    int i = curr.size();
    string temp = curr;
    if(i >= n/2) {
      reverse(temp.begin(), temp.end());
      temp = curr + m + temp;
      if(temp > target) best = min(temp, best);
      return;
    }
    auto it = pool.upper_bound(target[i]);
    if(it != pool.end()) {
      char c = *it;
      temp += c;
      pool.erase(it);
      for(char c : pool) {
        temp += c;
      }
      string temp1 = temp;
      reverse(temp1.begin(), temp1.end());
      temp = temp + m + temp1;
      if(temp > target) best = min(temp, best);
      pool.insert(c);
    }
    if(pool.find(target[i]) == pool.end()) return;
    curr += target[i];
    pool.erase(pool.find(target[i]));
    find(curr, m, pool, target, best);
    pool.insert(target[i]);
  }
  string lexPalindromicPermutation(string s, string target) {
    int n = s.size();
    string m = "";
    map<char, int> mp;
    for(char el : s) mp[el]++;
    multiset<char> pool;
    string res(n, '{');
    for(auto el : mp) {
      if(el.second % 2 == 1 && n % 2 == 0) return "";
      if(el.second % 2 == 1) {
        if(!m.empty()) return "";
        m += el.first;
      }
      for(int i = 0 ; i < el.second/2 ; i++) pool.insert(el.first);
    }
    find("", m, pool, target, res);
    if(res == string(n, '{')) return "";
    return res;
  }
};

int main() {
  fast_io();
  
  return 0;
}