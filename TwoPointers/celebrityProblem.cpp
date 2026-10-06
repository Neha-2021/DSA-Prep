/*

244. Celebrity Problem
A celebrity is a person who is known by everyone else at the party but does not know anyone in return. 
Given a square matrix M of size N x N where M[i][j] is 1 if person i knows person j, and 0 otherwise, determine if there is a celebrity at the party. Return the index of the celebrity or -1 if no such person exists.

Note that M[i][i] is always 0.

Example 1:
Input: M = [ [0, 1, 1, 0], [0, 0, 0, 0], [1, 1, 0, 0], [0, 1, 1, 0] ]
Output: 1
Explanation: Person 1 does not know anyone and is known by persons 0, 2, and 3. 
Therefore, person 1 is the celebrity.

Example 2:
Input: M = [ [0, 1], [1, 0] ]
Output: -1
Explanation: Both persons know each other, so there is no celebrity.
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Brute force
int celebrityBruteForce(vector<vector<int>> &M){
    int n = M.size();
    int celeb = -1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(M[i][j]==0 && M[j][i]==1) {
                celeb = i;
            } 
            if(celeb != -1) {
                break;
            }
        }
    }
    return celeb;
}

// Optimized solution using two-pointers
int celebrity(vector<vector<int>> &M){
    int n = M.size();
    int celeb = -1;
    int left = 0, right = n-1;

    while(left < right) {
        if(M[left][right]==1) { // left can never be a celebrity as left knows right
            left++;
        } else { // left does not know right, so right cannot be a celebrity
            right--;
        }
    }

    celeb = left;

    for(int i=0; i<n; i++) {
        if(i==celeb) continue; // if celeb is potential celebrity, then M[celeb][celeb] should be ignored

        if(M[celeb][i] == 1 || M[i][celeb] == 0) {
            // if celeb knows i or i does not know celeb, then celeb cannot be a celebrity
            return -1;
        }
    }
    return celeb;
}

int main() {
    vector<vector<int>> nums1 = {{0, 1, 1, 0}, {0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}};
    vector<vector<int>> nums2 = {{0, 1}, {1, 0} };

    cout << "celebrityBruteForce:1. Celebrity is person: " << celebrityBruteForce(nums1) << "\n";
    cout << "celebrityBruteForce:2. Celebrity is person: " << celebrityBruteForce(nums2) << "\n";

    cout << "celebrityOptimized:1. Celebrity is person: " << celebrity(nums1) << "\n";
    cout << "celebrityOptimized:2. Celebrity is person: " << celebrity(nums2) << "\n";

    return 0;
}