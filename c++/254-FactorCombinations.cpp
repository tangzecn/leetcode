#include<cmath>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > getFactors(int n) {
        vector<vector<int> > res;
        if (n <= 0) return res;
        
        vector<int> solution;
        dfs(2, n, solution, res);
        return res;
    }
    
private:
    void dfs(int low, int n, vector<int> &solution, vector<vector<int> > &res) {
        if (solution.size() > 0 && n > 1) {
            solution.push_back(n);
            res.push_back(solution);
            solution.pop_back();
        }
        int high = int(sqrt(n));
        for (int i=low; i<=high; i++) {
            if (n % i == 0) {
                solution.push_back(i);
                dfs(i, n / i, solution, res);
                solution.pop_back();
            }
        }
    }
};

int main() {
    return 0;
}
