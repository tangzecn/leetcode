#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    // BFS
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> res;
        vector<vector<int> > graph(numCourses, vector<int>(0, 0));
        vector<int> degree(numCourses, 0);
        for (int i=0; i<prerequisites.size(); i++) {
            int y = prerequisites[i].first;
            int x = prerequisites[i].second;
            if (x == y) return res;
            graph[x].push_back(y);
            degree[y]++;
        }
        
        queue<int> available;
        for (int i=0; i<numCourses; i++) {
            if (degree[i] == 0) available.push(i); 
        }
        for (int i=0; i<numCourses; i++) {
            if (available.empty()) {
                res.clear();
                return res;
            }
            int x = available.front();
            available.pop();
            res.push_back(x);
            for (int j=0; j<graph[x].size(); j++) {
                int y = graph[x][j];
                degree[y]--;
                if (degree[y] == 0) available.push(y);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
