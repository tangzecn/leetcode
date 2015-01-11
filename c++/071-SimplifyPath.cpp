#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> directories;
        int i = 0, len = path.length();
        while (i < len) {
            if (path[i] != '/') {
                // Error data, should not happen.
                return "";
            }
            int j = i + 1;
            while (j < len && path[j] != '/') {
                j++;
            }
            string directory = path.substr(i + 1, j - i - 1);
            i = j;
            if (directory == "" || directory == ".") continue;
            if (directory == "..") {
                if (!directories.empty()) {
                    directories.pop_back();
                }
                continue;
            }
            directories.push_back(directory);
        }
        
        string ans = "/";
        for (int i=0; i<directories.size(); i++) {
            if (i > 0) ans.append(1, '/');
            ans.append(directories[i]);
        }
        
        return ans;
    }
};

int main() {
	return 0;
}
