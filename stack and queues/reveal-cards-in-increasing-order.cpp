#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/reveal-cards-in-increasing-order/description

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n, 0);
        int i = 0, j = 0;
        bool skip = false;
        sort(deck.begin(), deck.end());
        while(i < n) {
            if(!ans[j]) {
                if(!skip) {
                    ans[j] = deck[i];
                    i++;
                }
                skip = !skip;
            }
            j = (j+1)%n;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}