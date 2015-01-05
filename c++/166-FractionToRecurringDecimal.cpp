#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) return "";
        if (numerator == 0) return "0";
        
        string ans = "";
        if ((long long)numerator * denominator < 0) ans.append(1, '-');
        long long num = llabs(numerator);
        long long den = llabs(denominator);
        
        ans.append(std::to_string(num / den));
        
        long long remain = num % den;
        if (remain > 0) {
            unordered_map<long long, int> index_map;  
            ans.append(1, '.');
            while (remain > 0) {
                if (index_map.find(remain) != index_map.end()) {
                    ans.insert(index_map[remain], 1, '(');
                    ans.append(1, ')');
                    break;
                }
                
                index_map[remain] = ans.length();
                remain *= 10;
                ans.append(std::to_string(remain / den));
                remain = remain % den;
            }
        }
        
        return ans;
    }
};

int main() {
	return 0;
}