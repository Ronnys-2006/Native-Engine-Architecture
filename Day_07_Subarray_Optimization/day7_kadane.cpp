#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxsum = INT_MIN;
        int currsum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            currsum += nums[i];
            maxsum = max(currsum , maxsum);

            if(currsum < 0)
            {
                currsum = 0;
            }
        }
        
        return maxsum;
    }
};

int main()
{
    Solution sol;

    vector<int> test1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Test 1 (mixed):        " << sol.maxSubArray(test1) << "  (expected 6)" << endl;

    vector<int> test2 = {-3, -1, -2};
    cout << "Test 2 (all negative): " << sol.maxSubArray(test2) << "  (expected -1)" << endl;

    vector<int> test3 = {5};
    cout << "Test 3 (single elem):  " << sol.maxSubArray(test3) << "  (expected 5)" << endl;

    vector<int> test4 = {1, 2, 3, 4, 5};
    cout << "Test 4 (all positive): " << sol.maxSubArray(test4) << "  (expected 15)" << endl;

    return 0;
}
