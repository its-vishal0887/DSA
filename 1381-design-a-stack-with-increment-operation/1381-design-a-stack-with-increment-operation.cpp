class CustomStack {
public:
    int top;
    int* arr;
    int size;

    CustomStack(int maxSize) {
        top = -1;
        size = maxSize;
        arr = new int[size];
    }

    void push(int x) {
        if (top == size - 1) {
            return;
        } else {
            top++;
            arr[top] = x;
        }
    }

    int pop() {
        if (top == -1) {
            return -1;
        }
        int topIdx = arr[top];
        top--;
        return topIdx;
    }

    // void solve(int cnt, int k, int val) {
    //     if (top == -1 || cnt == k) {
    //         return;
    //     }

    //     arr[top] += val;
    //     top--;

    //     solve(cnt + 1, k, val);

    //     top++;
    // }

    void increment(int k, int val) {
        int limit = min(k, top + 1);

        for (int i = 0; i < limit; i++) {
            arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */