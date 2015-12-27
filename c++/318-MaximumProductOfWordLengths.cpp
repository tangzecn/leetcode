#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> words_bit;
        for (int i=0; i<words.size(); i++) {
            int bit = 0;
            for (int j=0; j<words[i].length(); j++) {
                bit |= 1 << (words[i][j] - 'a');
            }
            words_bit.push_back(bit);
        }
        
        int res = 0;
        for (int i=0; i<words.size(); i++) {
            for (int j=i+1; j<words.size(); j++) {
                if ((words_bit[i] & words_bit[j]) == 0) {
                    res = max(res, (int)(words[i].length() * words[j].length()));
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}