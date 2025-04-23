# include <bits/stdc++.h>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxCandies = *max_element(candies.begin(), candies.end());
    vector<bool> result;

    for (int i = 0; i < candies.size(); i++) {
        if (candies[i] + extraCandies >= maxCandies)
            result.push_back(true);
        else
            result.push_back(false);
    }

    return result;
    
}
void printVecotr(vector<int> &candies,int extraCandies){
    for(bool val : kidsWithCandies(candies,extraCandies)){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> nums1 = {2,3,5,1,3};
    int extraCandies1 = 3;
    vector<int> nums2 = {4,2,1,1,2};
    int extraCandies2 = 1;
    vector<int> nums3 = {12,1,12};
    int extraCandies3 = 10;

    printVecotr(nums1,extraCandies1);
    printVecotr(nums2,extraCandies2);
    printVecotr(nums3,extraCandies3);

    return 0;

}