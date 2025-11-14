class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int n=s.size();
        unordered_map<char, int> mp;

        int maxlen=0;
        int len=0;
        while(r<n){
            char ch=s[r];
            if(mp.find(ch) != mp.end() && mp[ch]>=l){
                l=mp[ch]+1;
            }
            mp[ch]=r;
            len=r-l+1;
            maxlen=max(len, maxlen);

            r++;
        }
        return maxlen;
    }
};