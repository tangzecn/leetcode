#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) {
            return vector<int>(0);
        }
        vector<int> row(rowIndex + 1); 
        for (int i=0; i<=rowIndex; i++) {
            row[0] = 1; row[i] = 1;
            for (int j=i-1; j>0; j--) {
                row[j] = row[j - 1] + row[j];
            }
        }
        return row;
    }
};

int main() {
	return 0;
}