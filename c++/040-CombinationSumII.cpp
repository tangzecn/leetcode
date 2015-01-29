#include<iostream>
#include<vector>
using namespace std;

class Compare {
public:
    bool operator() (const int x, const int y) {
        return x < y;
    }
} compare;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<int> solution;
        vector<vector<int> > ans;
        if (candidates.size() > 0) {
            std::sort(candidates.begin(), candidates.end(), compare);
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
            solution.push_back(candidates[level]);
            combinationSum(candidates, target - candidates[level], level + 1, ans, solution);
            solution.erase(solution.end() - 1);
            
            int nextLevel = level;
            while (nextLevel < candidates.size() && candidates[nextLevel] == candidates[level]) {
                nextLevel++;
            }
            combinationSum(candidates, target, nextLevel, ans, solution);
        }
    }
};

int main() {
	return 0;
}