/*
1. Print array
2. Reverse array
3. Check palindrome
4. Fibonacci
5. Factorial
*/
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

void printArray(vector<int>& nums, int n, int i) {
    if(i == n) return;

    cout << nums[i] << "\n";
    printArray(nums, n, i+1);
}

void reverseArray(vector<int>& nums, int i, vector<int>& res) {
    if(i < 0) return;
    res.push_back(nums[i]);
    reverseArray(nums, i-1, res);
}

bool isPalindrome(string s, int i, int j) {
    if(i>j) return true;

    if(s[i] != s[j]) return false;
    return isPalindrome(s, i+1, j-1);
}

int fibonacci(int n, int prev1, int prev2) {
    if(n==0) return 0;
    if(n==1) return 1;

    int curr = prev1 + prev2;
    cout << curr << "   ";
    return fibonacci(n-1, prev2, curr);
}

int factorial(int n) {
    if(n==0) return 1;

    return n*factorial(n-1);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};

    // 1. Print array
    cout << "Print array" << "\n";
    printArray(nums, nums.size()-1, 0);
    cout << "\n";

    // 2. Reverse an array
    vector<int> res;
    cout << "Reverse an array" << "\n";
    reverseArray(nums, nums.size()-1, res);
    for(auto r: res) {
        cout << r << "\n";
    }
    cout << "\n";

    // 3. Check palindrome
    string str1 = "goat";
    string str2 = "racecar";
    string str3 = "madam";
    cout << "Check palindrome" << "\n";
    bool ans1 = isPalindrome(str1, 0, str1.size()-1);
    bool ans2 = isPalindrome(str2, 0, str2.size()-1);
    bool ans3 = isPalindrome(str3, 0, str3.size()-1);
    cout << "Is " << str1 << " a palindrome: " << (ans1 == 0 ? "NO" : "YES") << "\n";
    cout << "Is " << str2 << " a palindrome: " << (ans2 == 0 ? "NO" : "YES") << "\n";
    cout << "Is " << str3 << " a palindrome: " << (ans3 == 0 ? "NO" : "YES") << "\n";
    cout << "\n";

    // 4. Fibonacci series
    int n=6;
    cout << "Fibonacci series of " << n << "\n";
    fibonacci(n, 0, 1);
    cout << "\n";

    // 5. Factorial
    int N=5;
    int ans = factorial(N);
    cout << "\n" << "Factorail of " << N << " is : " << ans <<"\n";
    cout << "\n";
    return 0;
}

