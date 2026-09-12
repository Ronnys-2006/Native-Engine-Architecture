#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int bestbuy = prices[0];

        for(int i=1;i<prices.size(); i++)
        {
            if(prices[i] > bestbuy)
            {
                maxprofit = max( maxprofit, prices[i] - bestbuy);
            }

            bestbuy = min(bestbuy, prices[i]);
        }

        return maxprofit;
    }
};

int main() {
    Solution sol;
    vector<int> t1 = {7,1,5,3,6,4};
    cout << "Test 1: " << sol.maxProfit(t1) << " (expected 5)" << endl;
    vector<int> t2 = {7,6,4,3,1};
    cout << "Test 2: " << sol.maxProfit(t2) << " (expected 0)" << endl;
    vector<int> t3 = {1,2,3,4,5};
    cout << "Test 3: " << sol.maxProfit(t3) << " (expected 4)" << endl;
    vector<int> t4 = {2,4,1};
    cout << "Test 4: " << sol.maxProfit(t4) << " (expected 2)" << endl;
    vector<int> t5 = {1};
    cout << "Test 5: " << sol.maxProfit(t5) << " (expected 0)" << endl;
    return 0;
}