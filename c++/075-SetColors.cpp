#include<iostream>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        int red = 0;
        int blue = n - 1;
        while (red < n && A[red] == 0) red++;
        while (blue >= 0 && A[blue]  == 2) blue--;
        
        int index = red;
        while (index <= blue) {
            switch (A[index]) {
                case 0:
                    std::swap(A[red], A[index]);
                    red++; index++;
                    break;
                case 1:
                    index++;
                    break;
                case 2:
                    std::swap(A[blue], A[index]);
                    blue--;
                    break;
            }
        }
    }
};

int main() {
	return 0;
}
