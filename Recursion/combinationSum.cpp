/*
Combination Sum I
Given an array of distinct integers candidates and a target integer target, 
return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.
 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.


Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]


Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
*/
#include<stdio.h>
#include<iostream>
using namespace std;

void validSum(vector<int>& nums, vector<vector<int>>& res, vector<int>& combo, int currSum, int target, int idx) {
    if(idx == nums.size()) {
        if(currSum == target) {
            res.push_back(combo);
        }
        return;
    }
    if(currSum <= target) {
        combo.push_back(nums[idx]);
        validSum(nums, res, combo, currSum+nums[idx], target, idx);
        combo.pop_back();
    }

    validSum(nums, res, combo, currSum, target, idx+1);  
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;  
    vector<int> combo{};
    validSum(candidates, res, combo, 0, target, 0);
    return res;
}

int main() {
    vector<int> nums = {2,3,6,7};
    int k = 7;
    vector<vector<int>> res = combinationSum(nums, k);
    
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

