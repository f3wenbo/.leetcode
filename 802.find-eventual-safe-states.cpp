/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 *
 * https://leetcode.com/problems/find-eventual-safe-states/description/
 *
 * algorithms
 * Medium (45.98%)
 * Likes:    551
 * Dislikes: 90
 * Total Accepted:    29.1K
 * Total Submissions: 61.9K
 * Testcase Example:  '[[1,2],[2,3],[5],[0],[5],[],[]]'
 *
 * In a directed graph, we start at some node and every turn, walk along a
 * directed edge of the graph.  If we reach a node that is terminal (that is,
 * it has no outgoing directed edges), we stop.
 * 
 * Now, say our starting node is eventually safe if and only if we must
 * eventually walk to a terminal node.  More specifically, there exists a
 * natural number K so that for any choice of where to walk, we must have
 * stopped at a terminal node in less than K steps.
 * 
 * Which nodes are eventually safe?  Return them as an array in sorted order.
 * 
 * The directed graph has N nodes with labels 0, 1, ..., N-1, where N is the
 * length of graph.  The graph is given in the following form: graph[i] is a
 * list of labels j such that (i, j) is a directed edge of the graph.
 * 
 * 
 * Example:
 * Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
 * Output: [2,4,5,6]
 * Here is a diagram of the above graph.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * graph will have length at most 10000.
 * The number of edges in the graph will not exceed 32000.
 * Each graph[i] will be a sorted list of different integers, chosen within the
 * range [0, graph.length - 1].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int N = graph.size();
    vector<int> color(N);
    vector<int> ans;
    for (int i = 0 ; i < N; ++i) {
      if (dfs(i, color, graph))
        ans.push_back(i);
    }
    return ans;
  }

private:
  bool dfs(int node, vector<int>& color, vector<vector<int>>& graph) {
    if (color[node] > 0) return color[node] == 2;
    if (color[node] == 1) return false;
    color[node] = 1;
    for (auto neighbor : graph[node]) {
      if (color[neighbor] == 2)
        continue;
      if (color[neighbor] == 1 || !dfs(neighbor, color, graph))
        return false; 
    }
    color[node] = 2;
    return true;
  }
};
// @lc code=end

