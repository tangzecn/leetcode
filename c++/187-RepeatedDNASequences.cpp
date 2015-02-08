#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    const static int KEY_LEN = 10;
    const static int MASK = (1 << (2 * KEY_LEN)) - 1;
    
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> countMap;
        unordered_map<int, int>::iterator it;
        int code = 0;
        for (int i=0; i < s.length(); i++) {
            code = ((code << 2) | encode(s[i])) & MASK;
            if (i < KEY_LEN - 1) continue;
            it = countMap.find(code);
            if (it == countMap.end()) {
                countMap[code] = 1;
            } else {
                it->second++;
            }
        }
        
        vector<string> ans;
        it = countMap.begin();
        while (it != countMap.end()) {
            if (it->second > 1) {
                ans.push_back(decode(it->first));
            }
            it++;
        }
        
        return ans;
    }
    
    char encode(char ch) {
        switch (ch) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }    
        // Should not reach here.
        return ' ';
    }
    
    string decode(int code) {
        string key(KEY_LEN, ' ');
        for (int i=KEY_LEN - 1; i>=0; i--) {
            switch (code & 3) {
                case 0: key[i] = 'A'; break;
                case 1: key[i] = 'C'; break;
                case 2: key[i] = 'G'; break;
                case 3: key[i] = 'T'; break;
            }
            code = code >> 2;
        }
        return key;
    }
};

int main() {
	return 0;
}