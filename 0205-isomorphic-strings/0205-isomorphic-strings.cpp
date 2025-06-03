class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> mapST; // map from s to t
        unordered_map<char, char> mapTS; // map from t to s

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            // Check s → t mapping
            if (mapST.count(c1)) {
                if (mapST[c1] != c2) return false;
            } else {
                mapST[c1] = c2;
            }

            // Check t → s mapping
            if (mapTS.count(c2)) {
                if (mapTS[c2] != c1) return false;
            } else {
                mapTS[c2] = c1;
            }
        }

        return true;
    }
};
