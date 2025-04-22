# include <bits/stdc++.h>
using namespace std;

int maximumWealth(vector<vector<int>>& accounts){
    int row = accounts.size();
    int col = accounts[0].size();

    int maximum = INT_MIN;

    for(int i = 0 ; i < row ;i++){
        int sum = 0;
        for(int j = 0 ; j < col ; j++){
            sum += accounts[i][j];
        }

        maximum = max(maximum,sum);
    }

    return maximum;

}

int main(){
    vector<vector<int>> account1 = {{1,2,3},{3,2,1}}; 
    vector<vector<int>> account2 = {{1,5},{7,3},{3,5}};
    vector<vector<int>> account3 = {{2,8,7},{7,1,3},{1,9,5}}; 

    cout<<maximumWealth(account1)<<endl;
    cout<<maximumWealth(account2)<<endl;
    cout<<maximumWealth(account3)<<endl;

    return 0;
}