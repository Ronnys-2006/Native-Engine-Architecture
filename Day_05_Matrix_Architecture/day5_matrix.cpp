#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int rows = matrix.size();
       int cols = matrix[0].size();
       int mid;
       int left = 0;
       int right = (rows * cols) - 1;

       while(left <= right)
       {
            mid = left + (right -  left) / 2;
            int midval = matrix[mid/cols][mid%cols];

            if(midval == target)
            {
                return true;
            }
            else if(midval > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
       }

       return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}}; 
    int target = 3;

    Solution s1;

    bool result = s1.searchMatrix(matrix ,target);

    cout << "Result : " << result;

    return 0;
}
