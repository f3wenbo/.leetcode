/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (39.87%)
 * Likes:    4088
 * Dislikes: 184
 * Total Accepted:    303K
 * Total Submissions: 693.8K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * You are given an array of integers nums, there is a sliding window of size k
 * which is moving from the very left of the array to the very right. You can
 * only see the k numbers in the window. Each time the sliding window moves
 * right by one position.
 * 
 * Return the max sliding window.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation: 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,-1], k = 1
 * Output: [1,-1]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums = [9,11], k = 2
 * Output: [11]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: nums = [4,-2], k = 2
 * Output: [4]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i = 0;i < nums.size(); ++i) {
            while (!dq.empty() && dq.back() < nums[i]) dq.pop_back();
            dq.push_back(nums[i]);
            if (i >= k - 1) {
                ans.push_back(dq.front());
                if (nums[i - k + 1] == dq.front()) dq.pop_front();
            }
        }
        return ans;
    }
};
// @lc code=end

