class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() > 0 && s.find(part) < s.length()){
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

// s.find(part) returns the index of the first occurrence of part in s
// s.erase(start_index, length) removes part from s starting at start_index