#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

// https://www.codingninjas.com/studio/problems/subset-sum_3843086?leftPanelTabValue=SUBMISSION

using namespace std;
template<typename T>
using vec = vector<T>;

vector<int> ans;
void f(vector<int> &nums, int i, int sum) {
	int n = nums.size();
	if(i == n) {
		ans.push_back(sum);
		return;
	}

	f(nums, i+1, sum+nums[i]);
	f(nums, i+1, sum);
}
vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	f(num, 0, 0);
	sort(ans.begin(), ans.end());	
	return ans;
}

int main(){
    
    return 0;
}