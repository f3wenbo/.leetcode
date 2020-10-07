#include <vector>
#include <stack>
/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */
// @lc code=start
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses);
    stack<int> s;
    for (auto pre: prerequisites) {
      graph[pre[1]].push_back(pre[0]);
      indegree[pre[0]]++;
    }
    for (int i = 0; i < indegree.size(); ++i) {
      if (indegree[i] == 0) s.push(i);
    }

    int count = 0;
    while (!s.empty()) {
      int cur = s.top(); s.pop();
      count++;
      for (int i = 0; i < graph[cur].size(); ++i) {
        if (--indegree[graph[cur][i]] == 0)
          s.push(graph[cur][i]);
      }
    }
    return count == numCourses;
  }
};
// @lc code=end

