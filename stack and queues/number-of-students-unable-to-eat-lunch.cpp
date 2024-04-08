#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> student;
        stack<int> food;
        int n = students.size();
        for(int i = n-1 ; i >= 0 ; i--) {
            food.push(sandwiches[i]);
        }
        for(int i = 0 ; i < n ; i++) {
            student.push(students[i]);
        }
        while(!food.empty()) {
            if(student.front() == food.top()) {
                student.pop();
                food.pop();
                continue;
            }
            int k = student.size();
            while(k and student.front() != food.top()) {
                student.push(student.front());
                student.pop();
                k--;
            }
            if(!k) return student.size();
        }
        return 0;
    }
};

int main() {
    
    return 0;
}