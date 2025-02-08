class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxwater=0;
        int i=0, j=n-1;
        while(i<j){
            int wid=j-i;
            int hei= min(height[i], height[j]);
            int area=wid * hei;
            maxwater= max(area, maxwater);
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxwater;
    }
};