# include <iostream>
# include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target){
    int n = nums.size();
    int st = 0, end = n-1;

    int ans = 0;

    while(st <= end){ //O(log n)
        int mid = st + (end-st)/2;

        if(target == nums[mid]) return mid;

        if(target > nums[mid]){ //right search
            st = mid+1;
            if(target > nums[mid]){
                ans = mid+1;
            }
        }else{ // left search
            end = mid-1;
            if(target < nums[mid]){
                ans = mid;
            }
        
        }
    }
    return ans;
}

int main(){

    vector<int> nums = {1,3,5,6};

    cout<<searchInsert(nums,5)<<endl;
    cout<<searchInsert(nums,2)<<endl;
    cout<<searchInsert(nums,7)<<endl;
    return 0;
}