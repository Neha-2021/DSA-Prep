/*
Count all subsequences with sum K
Given an array nums and an integer k.
Return the number of non-empty subsequences of nums such that the sum of all elements 
in the subsequence is equal to k.

Example 1

Input : nums = [4, 9, 2, 5, 1] , k = 10
Output : 2
Explanation : The possible subsets with sum k are [9, 1] , [4, 5, 1].

Example 2

Input : nums = [4, 2, 10, 5, 1, 3] , k = 5
Output : 3
Explanation : The possible subsets with sum k are [4, 1] , [2, 3] , [5].

*/

#include<stdio.h>
#include<iostream>
using namespace std;

int recurse(vector<int>& nums, int k, int currSum, int idx) {
    if(idx == nums.size()) {
        if(currSum == k) return 1;
        else return 0;
    }
    int take = recurse(nums, k, currSum+nums[idx], idx+1);
    int notTake = recurse(nums, k, currSum, idx+1);
    return take + notTake;
}

int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    return recurse(nums, k, 0, 0);
}

int main() {
    vector<int> nums = {4, 2, 10, 5, 1, 3};
    int k = 5;
    cout << "Ans: " << countSubsequenceWithTargetSum(nums, k) <<"\n";
    return 0;
}

