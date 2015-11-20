#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int endIndex = s.length() - 1;
        while (endIndex >= 0 && s[endIndex] == ' ') {
            endIndex--;
        }
        int startIndex = endIndex;
        while (startIndex >= 0 && s[startIndex] != ' ') {
            startIndex--;
        }
        return endIndex - startIndex;
    }
};

int main() {
	return 0;
}