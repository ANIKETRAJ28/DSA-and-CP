#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/task-scheduler/description

/**
 * TC = O(n*k) -> n => cooldown time k -> size of array
 * SC = O(26) ~ O(1) => array size
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        int arr[26];
        memset(arr, 0, sizeof(arr));
        for(int i = 0 ; i < tasks.size() ; i++) arr[tasks[i] - 'A']++;
        for(int i = 0 ; i < 26 ; i++) {
            if(arr[i] != 0) pq.push(arr[i]);
        }
        int ans = 0;
        while(not pq.empty()) {
            vector<int> remaining;
            int cycle = n+1; // cooldown period
            int interval = 0; // for counting the interval

            while(!pq.empty() and cycle--) {
                int task = pq.top();
                pq.pop();
                task--;
                if(task != 0) remaining.push_back(task);
                interval++; // incrementing at each task
            }

            for(auto el : remaining) {
                pq.push(el);
            }

            ans += (pq.empty() ? interval : n+1);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}