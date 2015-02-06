#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        static char symbol[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        string ans;
        int symbolIndex = 0;
        while (num > 0) {
            int digit = num % 10;
            num /= 10;
            switch (digit) {
                case 1:
                case 2:
                case 3:
                    ans.insert(0, digit, symbol[symbolIndex]);
                    break;
                case 4:
                    ans.insert(0, 1, symbol[symbolIndex + 1]);
                    ans.insert(0, 1, symbol[symbolIndex]);
                    break;
                case 5:    
                    ans.insert(0, 1, symbol[symbolIndex + 1]);
                    break;
                case 6:
                case 7:
                case 8:
                    ans.insert(0, digit - 5, symbol[symbolIndex]);
                    ans.insert(0, 1, symbol[symbolIndex + 1]);
                    break;
                case 9:
                    ans.insert(0, 1, symbol[symbolIndex + 2]);
                    ans.insert(0, 1, symbol[symbolIndex]);
                    break;
            }
            symbolIndex += 2;
        }
        return ans;
    }
};

int main() {
	return 0;
}