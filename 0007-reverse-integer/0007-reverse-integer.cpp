class Solution {
public:
    int reverse(int x) {
        string s = to_string(x); // Convert number to string
        int i = (s[0] == '-') ? 1 : 0; // Start index after '-' if negative
        int j = s.size() - 1;

        while (i < j) {
            swap(s[i], s[j]); // Reverse the string's digits
            i++;
            j--;
        }
        try {
            long long ans = stoll(s); // Use long long to handle large numbers temporarily
            if (ans > INT_MAX || ans < INT_MIN) {
                return 0; // Return 0 if out of 32-bit integer range
            }
            return static_cast<int>(ans); // Safe cast back to int
        } catch (out_of_range&) {
            return 0; // Handle overflow during conversion
        }
    }
};
