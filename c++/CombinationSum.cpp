#include<iostream>
#include<vector>
using namespace std;

int combinationSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> f(target + 1, 0);
    f[0] = 1;
    for (int i=0; i<nums.size(); i++) {
	int nexti = i + 1;
	while (nexti < nums.size() && nums[nexti] == nums[i]) {
	    nexti++;
	}
	int tot = nexti - i;
	for (int j=target; j>0; j--) {
	    for (int k=1; k<=tot; k++) {
		if (nums[i] * k > j) break;
		f[j] += f[j - nums[i] * k];
	    }
	}
	i = nexti;
    }
    return f[target];
}

int main() {
    return 0;
}
