//No.121
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//Best Time to Buy and Sell Stock
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<=1)
            return 0;
        int min = prices[0];
        int profit = 0;
        for(int i=1; i<prices.size(); i++){
            min = std::min(min,prices[i]);
            profit = std::max(profit, prices[i]-min);
        }
        return profit;
    }
};
