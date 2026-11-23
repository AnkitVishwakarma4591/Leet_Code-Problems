#include <bits/stdc++.h>
using namespace std;

// better approach
// class ProductOfNumbers {
// public:
//     vector<int> nums;
//     int n;
//     ProductOfNumbers() {
//         nums.clear();
//         n = 0;
//     }
    
//     void add(int num) {
//         nums.push_back(num);
//         n++;
//     }
    
//     int getProduct(int k) {
//         int prod = 1;
//         for(int i = n-k ; i < n ; i++){
//             prod *= nums[i];
//         }
//         return prod;
//     }
// };

// /**
//  * Your ProductOfNumbers object will be instantiated and called as such:
//  * ProductOfNumbers* obj = new ProductOfNumbers();
//  * obj->add(num);
//  * int param_2 = obj->getProduct(k);
//  */

class ProductOfNumbers {
public:
    vector<int> nums;
    int n;

    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }

    void add(int num) {
        if (num == 0) {
            nums.clear();
            n = 0;
        } else {
            if (nums.empty()) {
                nums.push_back(num);
            } else {
                nums.push_back(nums[n - 1] * num);
            }
            n++;
        }
    }

    int getProduct(int k) {
        if (k > n) {
            return 0;
        } else if (n == k) {
            return nums[n - 1];
        }

        return nums[n - 1] / nums[n - k - 1];
    }
};

int main() {
    ProductOfNumbers p1;
    p1.add(3);
    p1.add(0);
    p1.add(2);
    p1.add(5);
    p1.add(4);

    cout << p1.getProduct(2) << "\n"; // 20 (5 * 4)
    cout << p1.getProduct(3) << "\n"; // 40 (2 * 5 * 4)
    cout << p1.getProduct(4) << "\n"; // 0  (includes the 0)

    p1.add(8);
    cout << p1.getProduct(2) << "\n"; // 32 (4 * 8)

    return 0;
}