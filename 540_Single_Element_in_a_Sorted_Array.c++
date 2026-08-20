# include <iostream>
# include <vector>
using namespace std;

int singleNonDuplicate(vector<int> &nums){
    int n = nums.size();

    if(n == 1) return nums[0];

    int st = 0 , end = n-1;

    while(st <= end){
        int mid = st + (end-st)/2;

        if(mid == 0 && nums[0] != nums[1]) return nums[mid];
        if(mid == n-1 && nums[n-1] != nums[n-2]) return nums[mid];

        if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) return nums[mid];

        if(mid % 2 == 0){ // Even
            if(nums[mid-1] == nums[mid]){ // left
                end = mid-1;
            }else{ // right
                st = mid+1;
            }
        }else{ // Odd
            if(nums[mid-1] == nums[mid]){ // right
                st = mid+1;
            }else{ // left
                end = mid-1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> num1 = {1}; // n = 1
    vector<int> num2 = {1,2,2}; // mid = 0
    vector<int> num3 = {2,2,3}; // mid = n-1
    vector<int> num4 = {1,1,2,3,3,4,4,8,8}; // even left
    vector<int> num5 = {1,1,2,2,3,3,4,8,8}; // even right
    vector<int> num6 = {3,3,7,7,10,11,11}; // odd right
    vector<int> num7 = {3,3,5,7,7,11,11}; // odd left

    cout<<singleNonDuplicate(num1)<<endl;
    cout<<singleNonDuplicate(num2)<<endl;
    cout<<singleNonDuplicate(num3)<<endl;
    cout<<singleNonDuplicate(num4)<<endl;
    cout<<singleNonDuplicate(num5)<<endl;
    cout<<singleNonDuplicate(num6)<<endl;
    cout<<singleNonDuplicate(num7)<<endl;

    return 0;
}