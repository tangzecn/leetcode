#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        int n = num.size();
        vector<vector<int> > ans;
        vector<int> solution(n);
        vector<bool> mark(n);
        for (int i=0; i<n; i++) {
            solution[i] = 0;
            mark[i] = false;
        }
        permute(0, num, mark, solution, ans);
        return ans;
    }
    
    void permute(int level, const vector<int> &num, vector<bool> &mark, 
        vector<int> &solution, vector<vector<int> > &ans) {
        if (level >= num.size()) {
            ans.push_back(solution);
            return;
        }        
        for (int i=0; i<num.size(); i++) {
            if (!mark[i]) {
                mark[i] = true;
                solution[i] = num[level];
                permute(level + 1, num, mark, solution, ans);
                solution[i] = 0;
                mark[i] = false;
            }
        }
    }
};

int main() {
	return 0;
}