#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    // BFS
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        if (numCourses <= 0) return true;
        
        vector<vector<int> > graph(numCourses, vector<int>(0, 0));
        vector<int> degree(numCourses, 0);
        for (int i=0; i<prerequisites.size(); i++) {
            int x = prerequisites[i].second;
            int y = prerequisites[i].first;
            if (x == y) return false;
            graph[x].push_back(y);
            degree[y]++;
        }
        
        queue<int> available;
        for (int i=0; i<numCourses; i++) {
            if (degree[i] == 0) {
                available.push(i);
            }
        } 
        for (int i=0; i<numCourses; i++) {
            if (available.empty()) return false;
            int x = available.front();
            available.pop();
            for (int j=0; j<graph[x].size(); j++) {
                int y = graph[x][j];
                degree[y]--;
                if (degree[y] == 0) {
                    available.push(y);
                }
            }
        }
        return true;
    }
};

int main() {
    return 0;
}
