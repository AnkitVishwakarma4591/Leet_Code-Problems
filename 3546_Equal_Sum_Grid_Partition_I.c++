# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkHorizontal(vector<vector<int>> &nums){
        int m = nums.size();
        int n = nums[0].size();

        long long totalSum = 0;
        for(auto mat : nums){
            for(int val : mat){
                totalSum += val;
            }
        }

        int top = 0, bottom = m-1;
        int left = 0, right = n-1;

        long long topSum = 0;

        while(top <= bottom){
            long long currSum = 0;
            for(int i = left ; i <= right ; i++){
                currSum += nums[top][i];
            }
            top++;
            topSum += currSum;
            if(topSum == totalSum - topSum) return true;
        }
        return false;
    }
    bool checkVertical(vector<vector<int>> &nums){
        int m = nums.size();
        int n = nums[0].size();

        long long totalSum = 0;
        for(auto mat : nums){
            for(int val : mat){
                totalSum += val;
            }
        }

        int top = 0, bottom = m-1;
        int left = 0, right = n-1;

        long long leftSum = 0;
        while(left <= right){
            long long currSum = 0;
            for(int i = top ; i <= bottom ; i++){
                currSum += nums[i][left];
            }
            left++;
            leftSum += currSum;
            if(leftSum == totalSum - leftSum) return true;
        }
        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        return checkHorizontal(grid) || checkVertical(grid);
    }
};

int main(){
    Solution s1;

    vector<vector<int>> grid = {{1,4},{2,3}};

    cout<<s1.canPartitionGrid(grid)<<endl;

    return 0;
}