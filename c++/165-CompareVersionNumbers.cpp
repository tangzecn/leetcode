#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int index1 = 0, nextNum1 = 0;
        int index2 = 0, nextNum2 = 0;
        while (index1 < version1.length() || index2 < version2.length()) {
            nextNum1 = getNextNum(version1, index1);
            nextNum2 = getNextNum(version2, index2);
            if (nextNum1 < nextNum2) return -1;
            else
            if (nextNum1 > nextNum2) return 1;
        }
        return 0;
    }
    
    int getNextNum(const string &version, int &index) {
        if (index >= version.length()) return 0;
        
        int start = index;
        while (index < version.length() && version[index] != '.') {
            index++;
        }
        int num = std::stoi(version.substr(start, index - start));
        if (index < version.length()) index++;
        return num;
    }
};

int main() {
    return 0;
}
