#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/rabbits-in-forest/description/

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i = 0 ; i < answers.size() ; i++) {
            if(mp.find(answers[i]) == mp.end()) {
                ans += answers[i]+1;
                if(answers[i] == 0) continue;
                mp[answers[i]] = 0;
            } else {
                mp[answers[i]]++;
                if(mp[answers[i]] == answers[i]) mp.erase(mp[answers[i]]);
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}