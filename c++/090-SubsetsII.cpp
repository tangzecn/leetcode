#include<iostream>
#include<vector>
using namespace std;

class compare {
public:
    bool operator() (const int i, const int j) {
        return i < j;
    }    
} compareObj;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ans;
        vector<int> nums(S), solution;
        sort(nums.begin(), nums.end(), compareObj);
        dfs(0, nums, solution, ans);
        return ans;
    }
    
    void dfs(
        const int index, 
        const vector<int> &nums, 
        vector<int> &solution, 
        vector<vector<int> > &ans) {
        if (index >= nums.size()) {
            ans.push_back(solution);
            return;
        }
        solution.push_back(nums[index]);
        dfs(index + 1, nums, solution, ans);
        solution.erase(solution.end() - 1);
            
        int nextIndex = index + 1;
        while (nextIndex < nums.size() && nums[nextIndex] == nums[index]) {
            nextIndex++;
        }
        dfs(nextIndex, nums, solution, ans);
            
    }
};

int main() {
    vector<int> nums;
    nums.push_back(0);
    Solution solution;
    vector<vector<int> > ans = solution.subsetsWithDup(nums);
    for (int i=0; i<ans.size(); i++) {
        for (int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}
