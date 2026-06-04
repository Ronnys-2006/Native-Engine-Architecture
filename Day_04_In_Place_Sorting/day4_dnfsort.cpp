#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0;
        int high = nums.size()-1;

        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};

int main()
{
    Solution s1;
    int i = 0;
    vector<int> nums = {2,0,1};

    cout<<"Before Sorting : " ;
    while( i < nums.size() )
    {
        cout<< nums[i] << " "; 
        i++;
    }

    s1.sortColors(nums) ;

    cout<<"\nAfter Sorting : ";
    i = 0;
    while( i < nums.size())
    {
        cout<< nums[i] << " "; 
        i++;
    }

    return 0;
}