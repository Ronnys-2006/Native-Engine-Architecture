#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0;
        int ans;
        for(int i=0; i<nums.size(); i++)
        {
            if(freq == 0)
            {
                ans = nums[i];
            }
            if(nums[i] == ans)
            {
                freq++;
            }
            else
            {
                freq--;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> t1 = {3,2,3};
    cout << "Test 1: " << sol.majorityElement(t1) << " (expected 3)" << endl;
    vector<int> t2 = {2,2,1,1,1,2,2};
    cout << "Test 2: " << sol.majorityElement(t2) << " (expected 2)" << endl;
    vector<int> t3 = {1};
    cout << "Test 3: " << sol.majorityElement(t3) << " (expected 1)" << endl;
    vector<int> t4 = {6,5,5};
    cout << "Test 4: " << sol.majorityElement(t4) << " (expected 5)" << endl;
    return 0;
}