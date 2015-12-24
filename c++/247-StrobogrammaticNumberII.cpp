#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        if (n <= 0) return res;
        string solution(n, '0');
        dfs(0, n - 1, solution, res);
        return res;
    }

private:
    static const vector<pair<char, char> > PAIRS;
	
    void dfs(int left, int right, string &solution, vector<string> &res) {
        if (left > right) {
            res.push_back(solution);
        } else if (left == right) {
            for (int i=0; i<PAIRS.size(); i++) {
                if (PAIRS[i].first == PAIRS[i].second && 
                    (left > 0 || PAIRS[i].first != '0' || solution.size() == 1)) {
                    solution[left] = PAIRS[i].first;
                    dfs(left + 1, right - 1, solution, res);
                }
            }
        } else {
            for (int i=0; i<PAIRS.size(); i++) {
                if (left > 0 || PAIRS[i].first != '0') {
                    solution[left] = PAIRS[i].first;
                    solution[right] = PAIRS[i].second;
                    dfs(left + 1, right - 1, solution, res);
                }
            }
        }
    }
};

const vector<pair<char, char> > 
    Solution::PAIRS =  {{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};

int main() {
    return 0;
}