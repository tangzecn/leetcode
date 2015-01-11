#include<cstring>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s == NULL) {
            return 0;    
        }
        
        int len = strlen(s);
        int endIndex = len - 1;
        while (endIndex >= 0 && s[endIndex] == ' ') {
            endIndex--;
        }
        if (endIndex < 0) {
            return 0;
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