class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*int buyprice = 101;
        int sellprice = 0;
        int b = 0;
        int maxvalue=0;
        for(int a : prices) {
            buyprice = a;
            for(int i=b; i<prices.size(); i++)
                sellprice = max(prices[i],sellprice);
            maxvalue = max(maxvalue,sellprice-buyprice);
            sellprice = 0;
            b++;
        }
        return maxvalue;*/

        int maxvalue = 0;
        int minvalue = prices[0];

        for (auto temp : prices) {
            maxvalue = max(maxvalue, temp - minvalue);
            minvalue = min(minvalue, temp);
        }
        return maxvalue;
    }
};