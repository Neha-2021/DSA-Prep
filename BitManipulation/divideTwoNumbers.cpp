/*
Divide two integers without using multiplication, division and mod operator
Given the two integers, dividend and divisor. Divide without using the mod, division, or 
multiplication operators and return the quotient.
The fractional portion of the integer division should be lost as it truncates toward zero.
As an illustration, 8.345 and -2.7335 would be reduced to 8 and -2 respectively.
Note: Assume we are dealing with an environment that could only store integers within 
the 32-bit signed integer range: [−231, 231 − 1]. For this problem, 
if the quotient is strictly greater than 231 - 1, then return 231 - 1, 
and if the quotient is strictly less than -231, then return -231.

Example 1:
Input: Dividend = 10, Divisor = 3
Output: 3
Explanation: 10/3 = 3.33, truncated to 3.

Example 2:
Input: Dividend = 7, Divisor = -3
Output: -2
Explanation: 7/-3 = -2.33, truncated to -2.
*/

#include<stdio.h>
#include<iostream>
using namespace std;

int divide(int dividend, int divisor) {
    if(dividend==0) return 0;
    if(dividend == divisor) return 1;
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    if(divisor == 1) return dividend;

    int sign = 1;
    if(dividend < 0 || divisor < 0) sign = -1;
    if(dividend < 0 && divisor < 0) sign = 1;

    long long sum=0;
    long long ans=0;

    long long effDivisor = divisor;
    long long effDividend = dividend;
    effDivisor = abs(effDivisor);
    effDividend = abs(effDividend);

    while(sum + effDivisor <= effDividend) {
        ans++;
        sum += effDivisor;
    }
    
    if(ans*sign > INT_MAX) return INT_MAX;
    if(ans*sign < INT_MIN) return INT_MIN;
    return ans*sign;
}

int main() {
    int dividend = 20, divisor = 3;
    cout << "Quotient is :" << divide(dividend, divisor) << "\n";
    return 0;
}