class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int j = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < prices[j]) {
                j = i;
                continue;
            } 
            else if (prices[i] - prices[j] > maxProfit) {
                maxProfit = prices[i] - prices[j];
            }
        }
        return maxProfit;
    }
};