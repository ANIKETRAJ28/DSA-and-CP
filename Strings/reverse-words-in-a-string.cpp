#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string> st;
        string words = "";
        for(int i = 0 ; i < n ; i++){
            if(s[i] == ' '){
                if(words != "") st.push(words);
                words = "";
                continue;
            }
            else words += s[i];
        }
        if(words != "") st.push(words);
        s = "";
        while(!st.empty()){
            s +=st.top();
            st.pop();
            if(!st.empty()) s += ' ';
        }
        return s;
    }
};

int main(){
    
    return 0;
}