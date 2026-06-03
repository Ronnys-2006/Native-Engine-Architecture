#include <iostream>
#include <vector>

using namespace std;

// from Leetcode 704.
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start,mid,end;
        start = 0;
        end = nums.size()-1;

        while(end>=start)
        {
            mid = start + ((end-start)/2);

            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return -1;
    }
};

int main()
{
    // Test Case
    vector<int> nums = {-1,0,3,5,9,12}; 
    int target = 9;
    Solution s1;
    
    // Printing the answer 
    int ans = s1.search(nums, target);
    cout << "Answer is : " <<ans;
    return 0;
}