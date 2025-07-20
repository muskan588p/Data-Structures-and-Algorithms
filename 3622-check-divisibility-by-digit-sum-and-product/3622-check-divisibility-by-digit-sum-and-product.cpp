class Solution {
public:
    bool checkDivisibility(int n) {
        int temp=n;
        int digsum=0, digpro=1;

        while(temp>0){
            int dig=temp%10;
            digsum+=dig;
            digpro*=dig;
            temp/=10;
        }

        int total=digsum+digpro;
        return n%total==0;
    }
};