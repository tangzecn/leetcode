#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int m = num.size();
        vector<vector<int> > ans;
        if (m < 4) return ans;
        
        sort(num.begin(), num.end());
        unordered_map<long long, int> count;
        int n = 0;
        for (int i=0; i<m; i++) {
            count[num[i]]++;
            if (i == 0 || num[i] != num[i - 1]) {
                num[n] = num[i];
                n++;
            }
        }
        
        unordered_map<long long, vector<pair<int ,int> > > leftPart;
        for (int i=0; i<n; i++) {
            int maxj = (count[num[i]] > 1) ? i : i - 1;
            for (int j=0; j<=maxj; j++) {
                long long leftSum = (long long)num[j] + num[i];
                leftPart[leftSum].push_back(make_pair(num[j], num[i]));
            }                
            
            int minj = (count[num[i]] > 1) ? i : i + 1;
            for (int j=minj; j<n; j++) {
                long long leftSum = (long long)target - num[i] - num[j];
                unordered_map<long long, vector<pair<int ,int> > >::iterator it = leftPart.find(leftSum);
                if (it != leftPart.end()) {
                    vector<pair<int, int> > &list = it->second;
                    for (int k=0; k<list.size(); k++) {
                        int a = list[k].first, b = list[k].second, c = num[i], d = num[j];
                        count[a]--; count[b]--; count[c]--; count[d]--;
                        if (count[a] >= 0 && count[b] >= 0 && count[c] >= 0 && count[d] >= 0) {
                            vector<int> solution;
                            solution.push_back(a);
                            solution.push_back(b);
                            solution.push_back(c);
                            solution.push_back(d);
                            ans.push_back(solution);
                        }
                        count[a]++; count[b]++; count[c]++; count[d]++;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
	return 0;
}