class MinStack {
public:
    long min;
    stack<long> sta;
    void push(int x) {
        if(sta.empty()){
            sta.push(0L);
            min=x;
        }else{
           sta.push(x-min);
           if(x<min) min=x;
        }
    }
    void pop() {
        if(sta.empty()) return;
        long pop1=sta.top();
        sta.pop();
        if(pop1<0)
        min=min-pop1;
    }

    int top() {
        long top=sta.top();
        if(top>0)
        return (int)(top+min);
        else
        return (int)min;
    }

    int getMin() {
        return (int)min;
    }
};
