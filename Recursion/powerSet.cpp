/* 
Power set
Given an array of integers nums of unique elements. 
Return all possible subsets (power set) of the array.
Do not include the duplicates in the answer.

Example 1

Input : nums = [1, 2, 3]
Output : [ [ ] , [1] , [2] , [1, 2] , [3] , [1, 3] , [2, 3] , [1, 2 ,3] ]

Example 2

Input : nums = [1, 2]
Output : [ [ ] , [1] , [2] , [1,2] ]

*/

#include<stdio.h>
#include<iostream>
using namespace std;

void generateSet(vector<int>& nums, vector<int>& currSet, vector<vector<int>>& res, int idx) {
    if(idx == nums.size()) {
        res.push_back(currSet);
        return;
    }

    generateSet(nums, currSet, res, idx+1);
    
    currSet.push_back(nums[idx]);
    generateSet(nums, currSet, res, idx+1);

    currSet.pop_back();
}

vector<vector<int>> powerSet(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> currSet{};
    generateSet(nums, currSet, res, 0);
    return res;
    
}

int main() {
    vector<int> nums = {1, 2, 3} ;
    vector<vector<int>> res;

    res = powerSet(nums);

    for(int i=0; i<res.size(); i++) {
        for(int j=0; j<res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}