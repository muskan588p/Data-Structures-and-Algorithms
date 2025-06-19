// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int num) {
        // code here
        int temp=0;
        int sum=0;
        temp=num;
        while(temp!=0){
            int ld=temp%10;
            sum+=ld*ld*ld;
            temp=temp/10;
        }
        if(sum==num){
            return true;
        }
        return false;
    }
};
