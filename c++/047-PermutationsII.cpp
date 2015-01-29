#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ans;
        if (num.size() > 0) {    
            std::sort(num.begin(), num.end());
            vector<int> solution(num.size());
            vector<bool> mark(num.size());
            for (int i=0; i<num.size(); i++) {
                solution[i] = 0;
                mark[i] = false;
            }
            permuteUnique(0, -1, num, mark, solution, ans);
        }
        return ans;
    }
    
    void permuteUnique(const int level, const int lastPos, const vector<int> &num, 
        vector<bool> &mark, vector<int> &solution, vector<vector<int> > &ans) {
        if (level >= num.size()) {
            ans.push_back(solution);
            return;
        }      
        int minPos = (level > 0 && num[level] == num[level - 1]) ? lastPos + 1 : 0;
        for (int i=minPos; i<num.size(); i++) {
            if (!mark[i]) {
                mark[i] = true;
                solution[i] = num[level];
                permuteUnique(level + 1, i, num, mark, solution, ans);
                solution[i] = 0;
                mark[i] = false;
            }
        }
    }
};

int main() {
	return 0;
}