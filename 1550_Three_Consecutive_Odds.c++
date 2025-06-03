    # include <bits/stdc++.h>
    using namespace std;
    
    bool threeConsecutiveOdds(vector<int>& arr) {

        int n = arr.size();

        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(arr[i] % 2 != 0){
                count++;
                if(count == 3) return true;
            }
            else{
                count = 0;
            }
        }
        return false;
    }

    int main(){
        vector<int> arr = {2,6,4,1};
        cout<<threeConsecutiveOdds(arr)<<endl;
        return 0;
    }