class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> nge(n);
        stack<int> st;
        
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && arr[i%n]>=st.top()) st.pop();
            if(i<n){
                if(st.empty()) nge[i]=-1;
                else nge[i]=st.top();
            }
            st.push(arr[i%n]);
        }   
        return nge;     
    }
};