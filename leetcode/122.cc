//No.122
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
//Best Time to Buy and Sell Stock II

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int result = 0;
        for(int i=1; i<n; i++){
            result += std::max(prices[i]-prices[i-1],0);
        }
        return result;
    }
};
