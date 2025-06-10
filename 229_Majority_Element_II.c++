# include <bits/stdc++.h>
using namespace std;


// // brute force solution O(n2)
// vector<int> majorityElement(vector<int>& nums) {

//         int n = nums.size();

//         set<int> ans;

//         for(int i = 0 ; i < n ; i++){
//             int count = 0;
            
//             for(int j = 0 ; j < n ; j++){
//                 if(nums[i] == nums[j]){
//                     count++;
//                 }
//             }
//             if(count > n/3){
//                 ans.insert(nums[i]);
//             }
//         }
//         return vector<int>(ans.begin(),ans.end());

// }

// Optimal SOlution O(n)

vector<int> majorityElement(vector<int>& nums){
    int n = nums.size();
    int cnt1 = 0 , cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;

    for(int i = 0 ; i < n ; i++){
        if(cnt1 == 0 && el2 != nums[i]){
            cnt1 = 1;
            el1 = nums[i];
        }
        else if(cnt2 == 0 && el1 != nums[i]){
            cnt2 = 1;
            el2 = nums[i];
        }
        else if(nums[i] == el1) cnt1++;
        else if(nums[i] == el2) cnt2++;
        else {
            cnt1--, cnt2--;
        }
    }
    vector<int> ls;
    cnt1 = 0 , cnt2 = 0;
    for(int i = 0 ; i < n ; i++){
        if(el1 == nums[i]) cnt1++;
        else if(el2 == nums[i]) cnt2++;
    }
    int mini = (int)(n/3) + 1;
    if(cnt1 >= mini) ls.push_back(el1);
    if(cnt2 >= mini) ls.push_back(el2);
    sort(ls.begin(),ls.end());

    return ls;
}

int main(){
    vector<int> nums = {3,2,3};

    for(auto val : majorityElement(nums)){
        cout<<val<<" ";
    }
    return 0;
}