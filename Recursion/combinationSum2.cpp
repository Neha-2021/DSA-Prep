/*
Combination Sum II
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.
 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: [[1,1,6],[1,2,5],[1,7],[2,6]]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: [[1,2,2],[5]]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

#include<stdio.h>
#include<iostream>
using namespace std;

void recurse(vector<int>& nums, int k, vector<int>& combo, vector<vector<int>>& res, int currIdx, int currSum) {

    if(currSum == k) {
        res.push_back(combo);
        return;
    }

    for(int i=currIdx; i<nums.size(); i++) {
        if(i > currIdx && nums[i] == nums[i-1]) continue;

        if(currSum+nums[i] > k) break;

        combo.push_back(nums[i]);
        recurse(nums, k, combo, res, i+1, currSum+nums[i]);
        combo.pop_back();
    }
    
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> combo{};
    recurse(candidates, target, combo, res, 0, 0);
    return res;
}

int main() {
    vector<int> nums = {10,1,2,7,6,1,5};
    int k = 8;
    vector<vector<int>> res = combinationSum2(nums, k);
    
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}