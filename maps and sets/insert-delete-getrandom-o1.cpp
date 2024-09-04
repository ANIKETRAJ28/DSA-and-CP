#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/insert-delete-getrandom-o1

class RandomizedSet {
public:
    unordered_set<int> st;
    RandomizedSet() {
        st.clear();
    }
    
    bool insert(int val) {
        if(st.find(val) != st.end()) return false;
        st.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(st.find(val) == st.end()) return false;
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % st.size();
        auto it = st.begin();
        advance(it, randomIndex);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    
    return 0;
}