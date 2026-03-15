#include <bits/stdc++.h>
using namespace std;

class Fancy {
public:
    typedef long long ll;

    ll M = 1e9+7;
    vector<ll> seq;
    ll add = 0;
    ll mult = 1;

    ll power(ll a, ll b) {
        if (b == 0) return 1;

        ll half = power(a, b / 2);
        ll result = (half * half) % M;

        if (b % 2 == 1)
            result = (result * a) % M;

        return result;
    }

    Fancy() {}

    void append(int val) {
        ll x = ((val - add) % M + M) % M;
        x = (x * power(mult, M - 2)) % M;
        seq.push_back(x);
    }

    void addAll(int inc) {
        add = (add + inc) % M;
    }

    void multAll(int m) {
        mult = (mult * m) % M;
        add = (add * m) % M;
    }

    int getIndex(int idx) {
        if (idx >= seq.size())
            return -1;

        return (seq[idx] * mult % M + add) % M;
    }
};

int main() {

    vector<string> operations = {
        "Fancy","append","addAll","append","multAll",
        "getIndex","addAll","append","multAll",
        "getIndex","getIndex","getIndex"
    };

    vector<vector<int>> values = {
        {},{2},{3},{7},{2},{0},{3},{10},{2},{0},{1},{2}
    };

    Fancy* obj = nullptr;

    for(int i = 0; i < operations.size(); i++) {

        if(operations[i] == "Fancy") {
            obj = new Fancy();
            cout << "null" << endl;
        }

        else if(operations[i] == "append") {
            obj->append(values[i][0]);
            cout << "null" << endl;
        }

        else if(operations[i] == "addAll") {
            obj->addAll(values[i][0]);
            cout << "null" << endl;
        }

        else if(operations[i] == "multAll") {
            obj->multAll(values[i][0]);
            cout << "null" << endl;
        }

        else if(operations[i] == "getIndex") {
            cout << obj->getIndex(values[i][0]) << endl;
        }
    }

    return 0;
}