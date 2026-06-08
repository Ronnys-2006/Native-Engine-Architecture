#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            int second = target - first;

            // O(1) Lookup: Does the complement exist in our Hash Map?
            if(m.find(second) != m.end()) {
                ans.push_back(m[second]); // Push the older index first
                ans.push_back(i);         // Push the current index
                break;
            }

            // O(1) Insertion: Store the current number and its index
            m[first] = i;
        }
        return ans;
    }
};

int main() {
    Solution solver;
    
    // Simulating a game inventory constraint: find two item weights that perfectly equal the target capacity
    vector<int> inventoryWeights = {4, 7, 2, 9, 15};
    int targetCapacity = 11;

    cout << "Executing O(n) Hash Map search for target capacity " << targetCapacity << "..." << endl;
    
    vector<int> result = solver.twoSum(inventoryWeights, targetCapacity);

    if (!result.empty()) {
        cout << "Success: Found matching elements at indices [" << result[0] << ", " << result[1] << "]" << endl;
        cout << "Values: " << inventoryWeights[result[0]] << " + " << inventoryWeights[result[1]] << " = " << targetCapacity << endl;
    } else {
        cout << "Result: No valid combination found." << endl;
    }

    return 0;
}