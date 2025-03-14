class MinStack {
public:
    stack<long long int> st;
    long long int minval;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            minval=val;
            st.push(val);
        }
        else{
            if(val>minval){
                st.push(val);
            }
            else{               // val<minval
                st.push(2*val - minval);   //minval = prevminval
                minval=val;
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        if(st.top()<minval){
            minval=2*minval-st.top();    //prev val is obtained
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        if(st.top()>minval){
            return st.top();
        }
        else{
            return minval;     //here minval is prevval as calculated above
        }
    }
    
    int getMin() {
        return minval;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */