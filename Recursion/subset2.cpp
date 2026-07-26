/*
Subset II
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
 
Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:

Input: nums = [0]
Output: [[],[0]]
 
Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

/*
Brute force apporach can be find all subsets of the input array and storing it in set to avoid duplicates.
Then convert set to vector for final result.
*/

#include<stdio.h>
#include<iostream>
using namespace std;

void recurse(vector<int>& nums, vector<int>& currSet, vector<vector<int>>& subsets, int idx) {
    subsets.push_back(currSet);

    for(int i=idx; i<nums.size(); i++) {
        if(i>idx && nums[i]==nums[i-1]) continue;
        
        currSet.push_back(nums[i]);
        recurse(nums, currSet, subsets, i+1);
        currSet.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> subsets;
    vector<int> currSet;
    sort(nums.begin(), nums.end());
    recurse(nums, currSet, subsets, 0);
    return subsets;
}

int main() {
    vector<int> nums = {1, 2, 2} ;
    vector<vector<int>> res;

    res = subsetsWithDup(nums);

    cout << "[" << "\n";
    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }       
    cout << "]" << "\n";

    return 0;
}