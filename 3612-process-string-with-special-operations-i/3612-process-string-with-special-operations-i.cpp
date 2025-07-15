class Solution {
public:
    string processStr(string s) {
        string r;
        r.reserve(100);

        for(char c:s){
            switch(c){
                case '*':
                    if(!r.empty()){
                        r.pop_back();
                    }
                    break;
                
                case '#':
                    {
                        string a=r;
                        r+=a;
                        break;
                    }
                
                case '%':
                reverse(r.begin(), r.end());
                break;

                default:
                r+=c;
            }
        }
        return r;
    }
};