class Solution {
public:
    char solve(string&s, int pos, long long k, long long leng){
        for(int i=pos;i>=0;i--){
            char c=s[i];
            if(islower(c)){
                if(k==leng-1){
                    return c;
                }
                leng--;
            }
            else if(c=='*'){
                leng++;
            }
            else if(c=='%'){
                k=leng-1-k;
            }
            else if(c=='#'){
                if(k>=leng/2){
                    k-=leng/2;
                }
                leng=leng/2;
            }
        }
        return '.';
    }
    char processStr(string s, long long k) {
        long long leng=0;    
        

        for(char c:s){
            if(islower(c)){
                leng++;
            }
            else if(c=='*'){
                if(leng>0){
                    leng--;
                }
            }
            else if(c=='#'){
                leng*=2;
            }
            else if(c=='%'){
                // reverse(r.begin(), r.end());
            }         
        }
        if(k>=leng){
            return '.';
        }
        return solve(s, s.length()-1, k, leng);
    }
};