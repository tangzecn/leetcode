#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        if (k < 0 || n < 0) return res;
        vector<int> solution(k, 0);
        dfs(res, solution, 9, k, n);
        return res;
    }
    
    void dfs(vector<vector<int> > &res, vector<int> &solution, int currNum, int k, int n) {
        if (k == 0) {
            if (n == 0) {
                res.push_back(solution);
            }
            return;
        }
        if (currNum > 0) {
            dfs(res, solution, currNum - 1, k, n);
            if (n >= currNum) {
                solution[k - 1] = currNum;
                dfs(res, solution, currNum - 1, k - 1, n - currNum);
            }
        }
    }
};

int main() {
	return 0;
}