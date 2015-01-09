#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        vector<int> solution(k);
        getCombine(n, k, 1, 0, solution, ans);
        return ans;
    }
    
    void getCombine(
        const int &n, 
        const int &k,
        const int minNum,
        const int level,
        vector<int> &solution,
        vector<vector<int> > &ans
        ) {
        if (level >= k) {
            ans.push_back(solution);
            return;
        }        
        for (int num = minNum; num <= n; num++) {
            solution[level] = num;
            getCombine(n, k, num + 1, level + 1, solution, ans);
        }
    }
};

int main() {
	return 0;
}