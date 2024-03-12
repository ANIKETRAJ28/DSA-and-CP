#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://youtu.be/wHXZ5_JmLa8?si=_g1BSmxMj4kI6ZjD
// https://leetcode.com/problems/shortest-uncommon-substring-in-an-array/

/**
 * Constraints:
 * n == arr.length
 * 2 <= n <= 100
 * 1 <= arr[i].length <= 20
 * arr[i] consists only of lowercase English letters.
*/

/**
1. for time complexity => It's simple, we will traverse the whole array i.e 20 iterations.
 And for each element of size n we will generate the substring which is 20^2 i.e 400.
 So, overall time complexity is O(n*400) ~ O(n).
2. for space complexity => the size of array -> n.
 And for each element of size n in the worst case we can get 20^2 unique substrings.
 So, we will get the sc as O(n*400) ~ O(n).
*/

/**
 * TC = O(n*400) ~ O(n)
 * SC = O(n*400) ~ O(n)
*/
class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        unordered_map<string, int> substrings;
        for(auto &str : arr) {
            unordered_set<string> unique;
            for(int i = 0 ;  i < str.size() ; i++) {
                for(int j = i ; j < str.size() ; j++) {
                    string s = str.substr(i, j-i+1);
                    if(unique.find(s) == unique.end()) {
                        unique.insert(s);
                        substrings[s]++;
                    }
                }
            }
        }
        vector<string> result;
        for(auto &str : arr) {
            string shortest = "";
            for(int i = 0 ;  i < str.size() ; i++) {
                for(int j = i ; j < str.size() ; j++) {
                    string s = str.substr(i, j-i+1);
                    if(substrings[s] == 1 && 
                        (shortest == "" || shortest.size() > s.size() || (shortest.size() == s.size() && shortest > s))
                    ) shortest = s;
                }
            }
            result.push_back(shortest);
        }
        return result;
    }
};

int main() {
    
    return 0;
}