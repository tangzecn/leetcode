#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        if (numRows < 1) return ans;
        for (int i=0; i<numRows; i++) {
            vector<int> row(i + 1);
            row[0] = 1; row[i] = 1;
            for (int j=1; j<i; j++) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(row);
        }
        return ans;
    }
};

int main() {
	return 0;
}