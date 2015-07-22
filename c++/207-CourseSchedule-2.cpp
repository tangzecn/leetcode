#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    // DFS
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        if (numCourses <= 0) return true;
        
        vector<vector<int> > graph(numCourses, vector<int>(0, 0));
        for (int i=0; i<prerequisites.size(); i++) {
            int x = prerequisites[i].second;
            int y = prerequisites[i].first;
            if (x == y) return false;
            graph[x].push_back(y);
        }
        
        vector<bool> visited(numCourses, false);
        vector<bool> inStack(numCourses, false);
        for (int i=0; i<numCourses; i++) {
            if (!visited[i] && !dfs(i, graph, visited, inStack)) return false;
        }
        return true;
    }

private:
    bool dfs(int x, const vector<vector<int> > &graph, vector<bool> &visited, vector<bool> &inStack) {
        if (inStack[x]) return false;
        inStack[x] = true;
        for (int i=0; i<graph[x].size(); i++) {
            int y = graph[x][i];
            if (!visited[y] && !dfs(y, graph, visited, inStack)) return false;
        }
        inStack[x] = false;
        visited[x] = true;
        return true;
    }
};

int main() {
    return 0;
}
