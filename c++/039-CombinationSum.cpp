#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> solution;
        vector<vector<int> > ans;
        if (candidates.size() > 0) {
            std::sort(candidates.begin(), candidates.end());
        }
        combinationSum(candidates, target, 0, ans, solution);
        return ans;
    }
    
    void combinationSum(const vector<int> &candidates, int target, int level, 
        vector<vector<int> > &ans, vector<int> &solution) {
        if (target == 0) {
            ans.push_back(solution);
            return;
        }
        if (level >= candidates.size()) {
            return;
        }        
        if (candidates[level] <= target) {
            if (level == 0 || candidates[level] != candidates[level - 1]) {
                solution.push_back(candidates[level]);
                combinationSum(candidates, target - candidates[level], level, ans, solution);
                solution.erase(solution.end() - 1);
            }
            combinationSum(candidates, target, level + 1, ans, solution);
        }
    }
};

int main() {
	return 0;
}