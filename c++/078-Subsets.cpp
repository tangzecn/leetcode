#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        std::sort(S.begin(), S.end());
        vector<vector<int> > ans;
        vector<int> solution;
        
        getSubsets(S, ans, 0, solution);
        return ans;
    }
    
    void getSubsets(
        const vector<int> &S,
        vector<vector<int> > &ans, 
        int level,
        vector<int> &solution) {
        if (level >= S.size()) {
            ans.push_back(solution);
            return;
        }        
        getSubsets(S, ans, level + 1, solution);
        solution.push_back(S[level]);
        getSubsets(S, ans, level + 1, solution);
        solution.pop_back();
    }
};

int main() {
	return 0;
}