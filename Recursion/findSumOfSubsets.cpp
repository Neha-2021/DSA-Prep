/*
SubSets I
Given an array nums of n integers. Return array of sum of all subsets of the array nums.
Output can be returned in any order.


Example 1

Input : nums = [2, 3]
Output : [0, 2, 3, 5]

Explanation :
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then sum = 2+3 = 5.

Example 2

Input : nums = [5, 2, 1]
Output : [0, 1, 2, 3, 5, 6, 7, 8]

Explanation :
When no elements is taken then Sum = 0.
When only 5 is taken then Sum = 5.
When only 2 is taken then Sum = 2.
When only 1 is taken then Sum = 1.

When element 2 and 1 are taken then sum = 2+1 = 3.

Constraints:
1 <= n <= 15
0 <= nums[i] <= 104
*/

#include<stdio.h>
#include<iostream>
using namespace std;

void recurse(vector<int>& nums, int currIdx, vector<int>& res, int currSum) {
    if(currIdx == nums.size()) {
        res.push_back(currSum);
        return;
    }

    recurse(nums, currIdx+1, res, currSum+nums[currIdx]);
    recurse(nums, currIdx+1, res, currSum);
}

vector<int> subsetSums(vector<int>& nums) {
    vector<int> res;
    recurse(nums, 0, res, 0);
    return res;
}

int main() {
    vector<int> nums = {5, 2, 1};
    vector<int> res = subsetSums(nums);
    for(auto r: res) {
        cout << r << " ";
    }
    cout << "\n";
    return 0;
}