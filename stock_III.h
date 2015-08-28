/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int n = prices.size();
        if(n <= 1) {    return 0;   }
        else {
            vector<int> start_to_pivot(n);
            vector<int> pivot_to_end(n);

            int buy_in = prices[0];
            int left_max = 0;
            for(int i = 0; i < n; i++) {
                buy_in = min(buy_in, prices[i]);
                left_max = max(left_max, prices[i] - buy_in);
                start_to_pivot[i] = left_max;
            }

            int sell_out = prices[n-1];
            int right_max = 0;
            for(int j = n - 1; j >= 0; j--) {
                sell_out = max(sell_out, prices[j]);
                right_max = max(right_max, sell_out - prices[j]);
                pivot_to_end[j] = right_max;
            }

            int sum = 0;
            for(int k = 0; k < n; k++) {
                int cur = start_to_pivot[k] + pivot_to_end[k];
                sum = max(sum, cur);
            }
            return sum;
        }
    }
};
