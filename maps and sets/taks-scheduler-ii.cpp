#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/task-scheduler-ii/description/

/**
 * TC O(n)
 * SC = O(n)
*/

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long day = 0;
        unordered_map<long long, long long> mp;
        for(int i = 0 ; i < tasks.size() ; i++) {
            if(mp.find(tasks[i]) != mp.end()) {
                // encountered before
                day = max(space + mp[tasks[i]] + 1, day+1);
                mp[tasks[i]] = day;
            } else {
                // encountered first time
                day++;
                mp[tasks[i]] = day;
            }
        }
        return day;
    }
};

int main() {
    
    return 0;
}