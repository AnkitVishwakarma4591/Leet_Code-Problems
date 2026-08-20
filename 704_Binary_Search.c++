# include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr ,int tar, int st ,int end){
    
    if(st <= end){
        int mid = st + (end-st)/2;
        if(tar == arr[mid]) return mid;
        else if(tar >= arr[mid]) return binarySearch(arr,tar,mid+1,end);
        else return binarySearch(arr,tar,st,mid-1);
    }
    return -1;
}

int search(vector<int>& arr, int tar) {
    return binarySearch(arr,tar,0,arr.size() -1);
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int tar = 3;

    cout<<search(arr,tar)<<endl;

    return 0;
}