#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if (input.length() == 0) return res;
        
        for (int i=0; i<input.size(); i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> leftRes = diffWaysToCompute(input.substr(0, i));
                vector<int> rightRes = diffWaysToCompute(input.substr(i + 1, input.size() - i - 1));
                for (int j = 0; j<leftRes.size(); j++) 
                    for (int k=0; k<rightRes.size(); k++) {
                        switch (input[i]) {
                            case '+':
                                res.push_back(leftRes[j] + rightRes[k]);
                                break;
                            case '-':
                                res.push_back(leftRes[j] - rightRes[k]);
                                break;
                            case '*':
                                res.push_back(leftRes[j] * rightRes[k]);
                                break;
                            default: 
                                break;
                        }
                    }
            }
        }
        if (res.size() == 0) {
            res.push_back(std::stoi(input));
        }
        
        return res;
    }
};

int main() {
    return 0;
}