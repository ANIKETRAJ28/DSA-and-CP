#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://leetcode.com/problems/minimum-amount-of-damage-dealt-to-bob/

class Solution {
public:
    #define ll long long
    static bool cmp(pair<ll, ll> &p1, pair<ll, ll> &p2) {
        return p1.first*p2.second > p2.first*p1.second;
    }
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<pair<ll, ll>> enemy(n);
        for(int i = 0 ; i < n ; i++) {
            int time = ceil((double)health[i]/power);
            enemy[i] = {damage[i], time};
        }
        sort(enemy.begin(), enemy.end(), cmp);
        ll minDamage = 0;
        ll bufferTime = 0;
        for(int i = 0 ; i < n ; i++) {
            ll damage = enemy[i].first;
            ll time = enemy[i].second;
            minDamage += damage*(bufferTime+time);
            bufferTime += time;
        }
        return minDamage;
    }
};

int main()
{
  return 0;
}