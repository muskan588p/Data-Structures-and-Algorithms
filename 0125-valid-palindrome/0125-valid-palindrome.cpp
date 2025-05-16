class Solution {
public:
    bool isalphanumeric(char ch){
        if(ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z'){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(!isalphanumeric(s[i])){
                i++;
                continue;
            }
            if(!isalphanumeric(s[j])){
                j--;
                continue;
            }
            if(tolower(s[i]) != tolower(s[j]) ){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};