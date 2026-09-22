#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> answer(n,1);

        for (int i = 1; i<n; i++)
        {
            answer[i] = answer[i-1] * nums[i-1] ;
        }

        int suffix = 1;
        for (int i = n-2; i>=0; i--)
        {
            suffix *= nums[i+1] ;
            answer[i] *= suffix ; 
        }

        return answer ;
    }
};

void printVec(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Case 1: standard example
    {
        vector<int> nums = {1,2,3,4};
        auto res = sol.productExceptSelf(nums);
        cout << "Test 1 (standard): ";
        printVec(res); // expect [24,12,8,6]
    }

    // Case 2: contains a zero
    {
        vector<int> nums = {-1,1,0,-3,3};
        auto res = sol.productExceptSelf(nums);
        cout << "Test 2 (single zero): ";
        printVec(res); // expect [0,0,9,0,0]
    }

    // Case 3: two zeros -> everything should be 0
    {
        vector<int> nums = {0,4,0};
        auto res = sol.productExceptSelf(nums);
        cout << "Test 3 (two zeros): ";
        printVec(res); // expect [0,0,0]
    }

    // Case 4: all negative
    {
        vector<int> nums = {-2,-3,-4,-5};
        auto res = sol.productExceptSelf(nums);
        cout << "Test 4 (all negative): ";
        printVec(res); // expect [-60,-40,-30,-24]
    }

    // Case 5: minimum size (2 elements)
    {
        vector<int> nums = {5,7};
        auto res = sol.productExceptSelf(nums);
        cout << "Test 5 (size 2): ";
        printVec(res); // expect [7,5]
    }

    return 0;
}
