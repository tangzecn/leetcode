#include<iostream>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long area = ((long long)D - B) * ((long long)C - A) + ((long long)H - F) * ((long long)G - E);
        if (min(C, G) > max(A, E) && min(D, H) > max(B, F)) {
            area -= ((long long)min(C, G) - max(A, E)) * ((long long)min(D, H) - max(B, F));
        }
        return area;
    }
};

int main() {
    return 0;
}