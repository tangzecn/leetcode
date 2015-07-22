#include<cmath>
#include<iostream>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        unique_ptr<bool[]> prime(new bool[n]);
        for (int i=2; i<n; i++) {
            prime[i] = true;
        }
        
        int sqrtN = (int)sqrt(n);
        for (int i=2; i<=sqrtN; i++) {
            if (prime[i]) {
                int j = i * i;
                while (j < n) {
                    prime[j] = false;
                    j += i;
                }
            }
        }
        
        int res = 0;
        for (int i=2; i<n; i++)
            res += prime[i];
            
        return res;
    }
};

int main() {
   return 0;
}
