class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        vector<int> pse(n);  //left
        vector<int> nse(n);  //right
        stack<int> s;

        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            pse[i]=s.empty() ? -1 : s.top();
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            nse[i]=s.empty() ? n : s.top();
            s.push(i);
        }
        int maxarea=0;

        for(int i=0;i<n;i++){
            int width=nse[i]-pse[i]-1;
            int area=arr[i] * width;
            maxarea=max(area, maxarea);
        }
        return maxarea;
    }
};