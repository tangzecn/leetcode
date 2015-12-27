#include<cmath>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        // low may be larger than high
        return max(0, countStrobogrammatic(high) - countStrobogrammatic(low) + isStrobogrammatic(low));
    }
    
private:
    static const vector<pair<char, char> > PAIRS;
   
    int countStrobogrammatic(const string &num) {
        vector<int> cnt;
        // when len = 0,
        cnt.push_back(1);
        // when len = 1, "0", "1", "8"
        cnt.push_back(3);
        for (int i=2; i<num.length(); i++) {
            cnt.push_back(cnt[i & 1] * int(pow(PAIRS.size(), i / 2)));
        }

        int res = 0;
        for (int i=1; i<num.length(); i++) {
        	if (i <= 1) {
        		res += cnt[i];
        	} else {
        		// when num.length() > 1, first digit can't be '0'
        		res += cnt[i - 2] * (PAIRS.size() - 1);
        	}
        }
        int i = 0, j = num.length() - 1;
        while (i <= j) {
            int pair_ptr = 0;
            while (pair_ptr < PAIRS.size() && num[i] > PAIRS[pair_ptr].first) pair_ptr++;

            int cnt_curr_pos = 0;
            // when num.length() > 1, the first digit can't be '0'
            if (i == 0 && num.length() > 1) {
                // num = "0" is a special case, so use max here
                cnt_curr_pos = max(0, pair_ptr - 1);
            } else {
                cnt_curr_pos = pair_ptr;
            }
            // '6' can't be at center position
            if (i == j && PAIRS[pair_ptr].first > '6') {
                cnt_curr_pos--;
            }
            int remain_len = num.length() - (i + 1) * 2 + (i == j);
            res += cnt_curr_pos * cnt[remain_len];

            if (pair_ptr < PAIRS.size() && num[i] == PAIRS[pair_ptr].first) {
                i++; j--;
            } else {
                break;
            }
        }
        res += isStrobogrammatic(num);
        return res;
    }
    
    bool isStrobogrammatic(const string &num) {
        int i = 0, j = num.length() - 1;
        while (i <= j) {
            bool validPair = false;
            for (int k=0; k<PAIRS.size(); k++)
                if (PAIRS[k].first == num[i] && PAIRS[k].second ==num[j]) {
                    validPair = true;
                    break;
                }
            if (!validPair) return false;
            i++; j--;
        }
        return true;
    }
    
};

const vector<pair<char, char> > 
    Solution::PAIRS = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

int main() {
    return 0;
}
