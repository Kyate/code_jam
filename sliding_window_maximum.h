/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
 Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
 You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
 Could you solve it in linear time?

Hint:
 1.How about using a data structure such as deque (double-ended queue)?
2.The queue size need not be the same as the window’s size.
3.Remove redundant elements and the queue should store only elements that need to be considered.
*/


class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> res;
        if (k < 1)
            return res;
        MaxQueue mq;
        for (int i = 0; i != k; ++i)
            mq.push(nums[i]);
        res.push_back(mq.getMax());
        for (int i = k; i != nums.size(); ++i) {
            mq.pop();
            mq.push(nums[i]);
            res.push_back(mq.getMax());
        }
        return res;
    }
private:
    class MaxQueue {
    public:
        void push(int x) {
            nums.push(x);
            while (!maxs.empty() && maxs.back() < x)
                maxs.pop_back();
            maxs.push_back(x);
        }
        void pop() {
            if (nums.front() == maxs.front())
                maxs.pop_front();
            nums.pop();
        }
        int getMax() {
            return maxs.front();
        }
    private:
        std::queue<int> nums;
        std::deque<int> maxs;
    };
};
