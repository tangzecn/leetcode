#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
      vector<int> index(primes.size(), 0);
      vector<long long> nums(1, 1);
      for (int i=1; i<n; i++) {
          long long nextNum = LLONG_MAX;
          for (int j=0; j<primes.size(); j++) {
              nextNum = min(nextNum, nums[index[j]] * primes[j]);
          }
          nums.push_back(nextNum);
          for (int j=0; j<primes.size(); j++) {
              long long s = nums[index[j]] * primes[j];
              while (s <= nextNum) {
                  index[j]++;
                  s = nums[index[j]] * primes[j];
              }
          }
      }
      return nums[n - 1];
    }
};

int main() {
    return 0;
}