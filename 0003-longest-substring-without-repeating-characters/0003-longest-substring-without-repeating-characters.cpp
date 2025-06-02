class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;

        // Loop through each character as starting point
        for (int i = 0; i < s.length(); i++) {
            string temp = "";  // To store current substring
            for (int j = i; j < s.length(); j++) {
                // Check if s[j] already exists in temp
                bool found = false;
                for (int k = 0; k < temp.length(); k++) {
                    if (temp[k] == s[j]) {
                        found = true;
                        break;
                    }
                }

                // If repeated character is found, break the loop
                if (found) break;

                // Otherwise, add to temp and update maxLength
                temp += s[j];
                if (temp.length() > maxLength) {
                    maxLength = temp.length();
                }
            }
        }

        return maxLength;
    }
};