#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int ind = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }

    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = n - 1; i > ind; i--)
    {
        if (nums[i] > nums[ind])
        {
            swap(nums[i], nums[ind]);
            break;
        }
    }

    reverse(nums.begin() + ind + 1, nums.end());
}

int main(){
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {3,2,1};
    vector<int> nums3 = {1,1,5};


    return 0 ;

}