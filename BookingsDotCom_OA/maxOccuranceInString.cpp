/*
Question 1: Maximum Occurring Character

Problem Statement: You are given a string text containing only:
Lowercase letters (a–z), Uppercase letters (A–Z), Digits (0–9)
Your task is to:
Find the character that appears most frequently in the string.
The check is case-sensitive ('A' and 'a' are different).
If multiple characters have the same highest frequency, return the one that appears first in the string.

Return the character.

Input: text = "1223334444"
Output: 4

Constraints

1 ≤ length of text ≤ 10^4
text contains only letters and digits.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;

char maximumOccuranceCharacter(string text) {
    unordered_map<char, int> freq;
    int maxCount = 0;
    char maxCountChar = text[0];

    for(auto t: text) {
        freq[t]++;
    }

    for(auto t: text) {
        if(freq[t] > maxCount) {
            maxCount = freq[t];
            maxCountChar = t;
        }
    }
    return maxCountChar;
}

int main() {
    string text = "neHaAAA23aa";
    cout << "Char with max frequency = " << maximumOccuranceCharacter(text) << "\n";
    return 0;
}