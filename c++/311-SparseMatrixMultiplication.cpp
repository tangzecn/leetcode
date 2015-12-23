#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > multiply(vector<vector<int> >& A, vector<vector<int> >& B) {
        vector<vector<int> > res;
        if (A.size() == 0 || A[0].size() == 0) return res;
        if (B.size() == 0 || B[0].size() == 0) return res;
        if (A[0].size() != B.size()) return res;
        
        res.resize(A.size(), vector<int>(B[0].size(), 0));
        vector<vector<std::pair<int, int> > > A_columns(A[0].size());
        vector<vector<std::pair<int, int> > > B_lines(A[0].size());
        for (int i=0; i<A.size(); i++) 
            for (int j=0; j<A[0].size(); j++) 
                if (A[i][j] != 0) {
                    A_columns[j].push_back(std::make_pair(i, A[i][j]));
                }
        for (int i=0; i<B.size(); i++) 
            for (int j=0; j<B[0].size(); j++) {
                if (B[i][j] != 0) {
                    B_lines[i].push_back(std::make_pair(j, B[i][j]));
                }
            }
        for (int i=0; i<A[0].size(); i++) 
            for (int j=0; j<A_columns[i].size(); j++)
                for (int k=0; k<B_lines[i].size(); k++) {
                    int x = A_columns[i][j].first;
                    int y = B_lines[i][k].first;
                    res[x][y] += A_columns[i][j].second * B_lines[i][k].second; 
                }
        return res;
    }
};

int main() {
  return 0;
}
