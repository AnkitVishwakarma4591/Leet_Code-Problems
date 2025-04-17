# include <iostream>
# include <vector>
using namespace std;

int MissingNum(vector<int> &nums){
    int n = nums.size();
    
    int ans = 0;
    for(int i = 1 ; i <= n ; i++){

        bool isParsent = false;

        for(int j = 0 ; j < n ; j++){

            if(nums[j] == i){
                isParsent = true;
                break;
            }
            
        }

        if(isParsent == false){
            return ans = i;
        }
    }
    return ans;
}

int main(){
    vector<int> nums1 = {3,0,1};
    vector<int> nums2 = {0,1};
    vector<int> nums3 = {9,6,4,2,3,5,7,0,1};

    cout<<MissingNum(nums1)<<endl;
    cout<<MissingNum(nums2)<<endl;
    cout<<MissingNum(nums3)<<endl;

    return 0;
}