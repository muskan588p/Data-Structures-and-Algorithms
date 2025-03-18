class StockSpanner {
public:
    stack<pair<int, int>> st;     //val,idx
    int idx;

    StockSpanner() {
        idx=-1;    //initialize idx to -1
    }
    
    int next(int price) {
        idx++;
        int span=1;

        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        if(st.empty()){
            span= idx + 1;
        }
        else{
            span = idx - st.top().second;
        }
        st.push({price, idx});   
        return span;         
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */