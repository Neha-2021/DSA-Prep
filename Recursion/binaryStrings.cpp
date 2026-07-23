/*
Generate Binary Strings Without Consecutive 1s

Given an integer n, return all binary strings of length n that do not contain consecutive 1s. 
Return the result in lexicographically increasing order.
A binary string is a string consisting only of characters '0' and '1'.


Example 1

Input: n = 3
Output: ["000", "001", "010", "100", "101"]
Explanation: All strings are of length 3 and do not contain consecutive 1s.

Example 2

Input: n = 2
Output: ["00", "01", "10"]

Example 3

Input: n = 5
Output: ["00000", "00001", "00010", "00100", "00101", "01000", "01001", "01010", "10000", "10001", "10010", "10100", "10101"]

*/

#include<stdio.h>
#include<iostream>
using namespace std;

void binaryStr(vector<string>& res, int n, string s) {
    if(s.size()==n) {
        res.push_back(s);
        return;
    }

    binaryStr(res, n, s+"0");
    if(s.empty() || s.back()!= '1') {
        binaryStr(res, n, s+"1");
    } 
}
vector<string> generateBinaryStrings(int n) {
    vector<string> res;
    binaryStr(res, n, "");
    return res;
}
int main() {
    int n = 5;
    vector<string> ans = generateBinaryStrings(n);
    for(auto s: ans) {
        cout << s << "  ";
    }
    return 0;
}