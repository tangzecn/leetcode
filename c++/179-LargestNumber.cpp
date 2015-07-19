#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Compare {
public:
    bool operator() (const int x, const int y) {
        string sx = std::to_string(x);
        string sy = std::to_string(y);
        return sx + sy > sy + sx;
    }    
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.size() == 0) return "";
        sort(nums.begin(), nums.end(), Compare());
        if (nums[0] == 0) return "0";
        
        string ans = "";
        for (int i=0; i<nums.size(); i++) {
            ans.append(std::to_string(nums[i]));
        }
        return ans;
    }
};

int main() {
	return 0;
}
