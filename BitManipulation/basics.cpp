/*
Q1. Check if the i-th bit is Set or Not
Given two integers n and i, return true if the ith bit in the 
binary representation of n (counting from the least significant bit, 0-indexed) is set (i.e., equal to 1). 
Otherwise, return false.

Example 1

Input: n = 5, i = 0
Output: true
Explanation: Binary representation of 5 is 101. The 0-th bit from LSB is set (1).

Example 2

Input: n = 10, i = 1
Output: true
Explanation: Binary representation of 10 is 1010. The 1-st bit from LSB is set (1).

Constraints
1 <= n <= 109
0 <= i <= 31

Q2. Given a non-negative integer n, determine whether it is odd.
Return true if the number is odd, otherwise return false.
A number is odd if it is not divisible by 2 (i.e., n % 2 != 0).

Example 1

Input: n = 7
Output: true
Explanation: 7 is not divisible by 2. Hence, it is odd.

Example 2

Input: n = 0
Output: false
Explanation: 0 is divisible by 2. Hence, it is not odd.

Constraints
0 <= n <= 104

Q3. Power of Two
Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1

Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16

Example 3:

Input: n = 3
Output: false

Constraints: -231 <= n <= 231 - 1

Q4. Count the Number of Set Bits
Given an integer n, return the number of set bits (1s) in its binary representation.
Can you solve it in O(log n) time complexity?

Example 1

Input: n = 5
Output: 2
Explanation: The binary representation of 5 is 101, which has 2 set bits.

Example 2

Input: n = 15
Output: 4
Explanation: The binary representation of 15 is 1111, which has 4 set bits.

Constraints: 0 ≤ n ≤ 10⁹

Q5. Swap two numbers
Given two integers a and b, swap them in-place using only 2 variables 
(without using a temporary variable).
Can you solve it using:
Arithmetic operations?
Bitwise XOR?

Example 1

Input: a = 5, b = 10
Output: a = 10, b = 5

Example 2

Input: a = -100, b = -200
Output: a = -200, b = -100
*/

#include<stdio.h>
#include<iostream>
using namespace std;

bool checkIfSet(int n, int i) {
    return (n & (1<<i)) != 0;
}

bool checkIfOdd(int n) {
    return (n%2) != 0;
}

bool isPowerOfTwo(int n) {
    return (n>0 && (n&(n-1)) == 0);
}

int countSetBits(int n) {
    int count = 0;
    while(n>0) {
        count += (n&1);
        n = n>>1;
    }
    return count;
}

void swap(int &a, int &b) {
    a = a^b;
    b = a^b;
    a = a^b;
}

int main() {
    // Q1. Solution
    int n1=1000000008, i=18;
    bool isSet = checkIfSet(n1, i);
    if(isSet) cout << n1 << " is set." << "\n";
    else cout << n1 << " is not set." << "\n";

    // Q2. Solution
    int n2 = 126351831;
    bool isOdd = checkIfOdd(n2);
    if(isOdd) cout << n2 << " is odd." << "\n";
    else cout << n2 << " is not odd." << "\n";

    // Q3. Solution
    int n3 = 1025;
    bool isPowerofTwo = isPowerOfTwo(n3);
    if(isPowerofTwo) cout << n3 << " is a power of 2." << "\n";
    else cout << n3 << " is not a power of 2." << "\n";

    // Q4. Solution
    int n4 = 15;
    int ans = countSetBits(n4);
    cout << "No. of bits set in " << n4 << " is : " << ans << "\n";

    // Q5. Solution
    int a=145, b=98;
    swap(a, b);
    cout << "After swapping: " << "\n";
    cout << "a: " << a << "\n";
    cout << "b: " << b << "\n";

    return 0;
}