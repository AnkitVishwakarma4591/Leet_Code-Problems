#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class StockSpanner {
private:
    vector<int> prices;
    stack<int> st; // stores indices

public:
    StockSpanner() {}

    int next(int price) {
        prices.push_back(price);
        int i = prices.size() - 1;

        while (!st.empty() && prices[st.top()] <= price) {
            st.pop();
        }

        int span;
        if (st.empty()) {
            span = i + 1;
        } else {
            span = i - st.top();
        }

        st.push(i);
        return span;
    }
};

int main() {
    vector<int> testPrices = {100, 80, 60, 70, 60, 75, 85};

    StockSpanner* obj = new StockSpanner();

    cout << "Stock Span Output: ";
    for (int price : testPrices) {
        cout << obj->next(price) << " ";
    }
    cout << endl;

    delete obj;
    return 0;
}
