#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    /*------------------------------------
        sort(nums.begin(),nums.end()); O(nlogn)

        for(int val : nums){
            cout<<val<<" ";
        }
    -------------------------------------*/
    /*-------------------------------------
        int n  = nums.size();
        int count0 = 0 , count1 = 0 , count2 = 3;
        for(int i = 0 ; i <  n ; i++){
            if(nums[i] == 0) count0++;
            else if(nums[i] == 1) count1++;
            else count2++;
        }
        int idx=0;
        for(int i = 0 ; i < count0 ; i++){
            nums[idx++] = 0;
        }
        for(int i = 0 ; i < count1 ; i++){
            nums[idx++] = 1;
        }
        for(int i = 0 ; i < count2 ; i++){
            nums[idx++] = 2;
        }

        for(int val : nums){
            cout<<val<<" ";
        }
    -------------------------------------------*/
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[high], nums[mid]);
            high--;
        }
    }
    for(int val : nums){
        cout<<val<<" ";
    }
}

int main()
{
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    vector<int> nums2 = {2, 0, 1};

    sortColors(nums1);
    cout << endl;
    sortColors(nums2);

    return 0;
}