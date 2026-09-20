#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        int left=0, right=height.size()-1;
        int maxwater = 0, currwater= 0;
        int width,h;

        while(left<right)
        {
            width = right - left;
            h = min(height[left],height[right]);
            currwater = h * width;
            maxwater = max(maxwater, currwater);

            height[left]<height[right] ? left++ : right--;
        }
        return maxwater ;
    }
};

int main() {
    Solution sol;
    vector<int> t1 = {1,8,6,2,5,4,8,3,7};
    cout << "Test 1: " << sol.maxArea(t1) << " (expected 49)" << endl;
    vector<int> t2 = {1,1};
    cout << "Test 2: " << sol.maxArea(t2) << " (expected 1)" << endl;
    vector<int> t3 = {4,3,2,1,4};
    cout << "Test 3: " << sol.maxArea(t3) << " (expected 16)" << endl;
    vector<int> t4 = {1,2,1};
    cout << "Test 4: " << sol.maxArea(t4) << " (expected 2)" << endl;
    return 0;
}
