class Solution {
public:
    bool ispalindrome(string s){
        string s2=s;
        reverse(s2.begin(), s2.end());

        if(s==s2){
            return true;
        }
        return false;
    }
    void getallparts(string s, vector<vector<string>> &ans, vector<string> &partitions){
        int n=s.size();
        if(s.size()==0){
            ans.push_back(partitions);
            return;
        }
        for(int i=0;i<n;i++){
            string part=s.substr(0,i+1);     //extract the parts
            if(ispalindrome(part)){          //check ifpart is palindrome
                partitions.push_back(part);
                getallparts(s.substr(i+1) ,ans, partitions);//recursively call for next parts(i+1 to n)

                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;

        getallparts(s, ans, partitions);
        return ans;
    }
};