# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int st = 0, end = letters.size()-1;
        char ans = letters[0];
        while(st <= end){
            int mid = st + (end - st)/2;
            if(letters[mid] > target){
                ans = letters[mid];
                end = mid - 1;
            }else{
                st = mid+1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s1;
    vector<char> letters = {'c','f','g'};
    char target = 'a' ;

    cout<<s1.nextGreatestLetter(letters, target)<<endl;
    return 0;
}