#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0 ;
        int end = numbers.size() - 1 ;
        vector<int> vec = {-1,-1};

        while(start < end)
        {
            if(numbers[start] + numbers[end] == target)
            {
                // LeetCode 167 asks for 1-indexed arrays, so we add 1
                vec = {start + 1, end + 1};
                return vec;
            }
            else if(numbers[start] + numbers[end] < target)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return vec;  
    }
};

int main() {
    // 1. Create the test data 
    vector<int> testNumbers = {2, 7, 11, 15};
    int testTarget = 9;

    // 2. Instantiate the Solution class
    Solution solver;

    // 3. Execute your algorithm and capture the returned vector
    vector<int> result = solver.twoSum(testNumbers, testTarget);

    // 4. Print the raw output to the terminal
    cout << "Target: " << testTarget << endl;
    cout << "Found at Indices (1-indexed): [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}