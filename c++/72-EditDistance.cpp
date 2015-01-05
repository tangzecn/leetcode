#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int *f0 = new int[word2.length() + 1];
        for (int i=0; i<=word2.length(); i++) 
            f0[i] = i;
        int *f1 = new int[word2.length() + 1];
        
        for (int i=1; i<=word1.length(); i++) {
            f1[0] = i;
            for (int j=1; j<=word2.length(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    f1[j] = f0[j - 1];
                } else {
                    f1[j] = f0[j - 1] + 1;
                }
                int insert = f1[j - 1] + 1;
                if (insert < f1[j]) f1[j] = insert;
                int del = f0[j] + 1;
                if (del < f1[j]) f1[j] = del;
            }
            int *tmp = f0;
            f0 = f1;
            f1 = tmp;
        }
        
        int ans = f0[word2.length()];
        delete[] f0;
        delete[] f1;
        
        return ans;
    }
};

int main() {
	return 0;
}