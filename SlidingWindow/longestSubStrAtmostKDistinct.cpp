/*
Longest Substring With At Most K Distinct Characters
Given a string s and an integer k.Find the length of the longest substring with at most k 
distinct characters.

Example 1:
Input : s = "aababbcaacc" , k = 2
Output : 6
Explanation : The longest substring with at most two distinct characters is "aababb".
The length of the string 6.

Example 2:
Input : s = "abcddefg" , k = 3
Output : 4
Explanation : The longest substring with at most three distinct characters is "bcdd".
The length of the string 4.
*/


#include <iostream>
#include <algorithm>
using namespace std;
int kDistinctChar(string& s, int k) {
    int l = 0;
    int maxCount = 0;
    unordered_map<char, int> distinct;

    for(int r=0; r<s.size(); r++) {
        distinct[s[r]]++;

        if(distinct.size() > k) {
            distinct[s[l]]--;
            if(distinct[s[l]] == 0) distinct.erase(s[l]);
            l++;
        }

        maxCount = max(maxCount, r-l+1);
    }
    return maxCount;
}

int main() {
    string s1 = "aababbcaacc";
    int k1 = 2;

    string s2 = "abcddefg";
    int k2 = 3;

    cout << s1 << ": The size of longest substring with at most " << k1 << " distinct characters is : " << kDistinctChar(s1, k1) << "\n";

    cout << s2 << ": The size of longest substring with at most " << k2 << " distinct characters is : " << kDistinctChar(s2, k2) << "\n";
    
    return 0;
}
