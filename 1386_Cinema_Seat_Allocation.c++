# include <bits/stdc++.h>
using namespace std;

// Optimal Approach
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for(auto &reservedSeat : reservedSeats){
            int row = reservedSeat[0];
            int seat = reservedSeat[1];

            mp[row] |= (1 << seat);
        }          

        int result = (n - mp.size()) * 2;

        int maskA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int maskB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int maskC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for(auto &m : mp){
            int row = m.first;
            int bookSeatsMask = m.second;

            bool groupA =(bookSeatsMask & maskA) == 0;
            bool groupB =(bookSeatsMask & maskB) == 0;
            bool groupC =(bookSeatsMask & maskC) == 0;

            if(groupA && groupC){
                result += 2;
            }else if(groupA || groupB || groupC){
                result += 1;
            }
        }

        return result;
    }
};


// Brute force Approach
// class Solution {
// public:
//     int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
//         unordered_map<int, unordered_set<int>> mp;

//         for(auto &reservedSeat : reservedSeats){
//             int row = reservedSeat[0];
//             int seat = reservedSeat[1];

//             mp[row].insert(seat);
//         }

//         int result = (n - mp.size()) * 2;

//         for(auto &m : mp){

//             int row = m.first;
//             unordered_set<int> bookSeats = m.second;

//             auto isAvailable = [&](int seat){
//                 return bookSeats.find(seat) == bookSeats.end();
//             };
            
//             bool groupA = isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);
//             bool groupB = isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);
//             bool groupC = isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);

//             if(groupA && groupC){
//                 result += 2;
//             }else if(groupA || groupB || groupC){
//                 result += 1;
//             }
//         }

//         return result;
//     }
// };

int main(){
    Solution s1;
    int n = 2;
    vector<vector<int>> reservedSeats = {{2,1}, {1,8}, {2,6}};

    cout<<s1.maxNumberOfFamilies(n, reservedSeats)<<endl;

    return 0;
}