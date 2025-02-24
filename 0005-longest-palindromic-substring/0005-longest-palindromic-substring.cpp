#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, maxLen = 1;
        
        for (int i = 0; i < s.length(); i++) {
            // Case 1: Odd-length palindrome
            int p1 = i, p2 = i;
            while (p1 >= 0 && p2 < s.length() && s[p1] == s[p2]) {
                if (p2 - p1 + 1 > maxLen) {
                    start = p1;
                    maxLen = p2 - p1 + 1;
                }
                p1--;
                p2++;
            }
            
            // Case 2: Even-length palindrome
            p1 = i, p2 = i + 1;
            while (p1 >= 0 && p2 < s.length() && s[p1] == s[p2]) {
                if (p2 - p1 + 1 > maxLen) {
                    start = p1;
                    maxLen = p2 - p1 + 1;
                }
                p1--;
                p2++;
            }
        }
        
        return s.substr(start, maxLen);
    }
};

