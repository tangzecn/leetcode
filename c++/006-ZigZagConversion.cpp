#include<iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 0) return "";
        if (nRows == 1) return s;
        
        string *rows;
        rows = new string[nRows];
        for (int i=0; i<nRows; i++)
            rows[i] = "";
        
        int current_row = 0, direction = 1;
        for (int i=0; i<s.length(); i++) {
            rows[current_row] += s[i];
            current_row += direction;
            if (current_row >= nRows || current_row < 0) {
                current_row -= direction;
                direction = -direction;
                current_row += direction;
            }
        }
        
        string ans = "";
        for (int i=0; i<nRows; i++) 
            ans += rows[i];
            
        delete[] rows;
        return ans;
    }
};

int main() {
	return 0;
}