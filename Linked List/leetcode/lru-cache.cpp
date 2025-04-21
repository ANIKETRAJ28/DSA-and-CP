#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/lru-cache/description/

class LRUCache
{
public:
  int n;
  list<int> dll;
  map<int, pair<list<int>::iterator, int>> mp;

  LRUCache(int capacity)
  {
    n = capacity;
  }

  void updateRecentlyUsed(int key)
  {
    dll.erase(mp[key].first);
    dll.push_front(key);
    mp[key].first = dll.begin();
  }

  int get(int key)
  {
    if (mp.find(key) == mp.end())
      return -1;
    updateRecentlyUsed(key);
    return mp[key].second;
  }

  void put(int key, int value)
  {
    if (mp.find(key) != mp.end())
    {
      mp[key].second = value;
      updateRecentlyUsed(key);
    }
    else
    {
      dll.push_front(key);
      mp[key] = {dll.begin(), value};
      n--;
    }
    if (n < 0)
    {
      int key = dll.back();
      mp.erase(key);
      dll.pop_back();
      n++;
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{

  return 0;
}