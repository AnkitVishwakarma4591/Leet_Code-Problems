# include <bits/stdc++.h>
using namespace std;

class Solution {
    class SegmentTree {
    public:
        int size;
        vector<int> totalSum;
        vector<int> minPref;
        vector<int> maxPref;

        SegmentTree(int n) {
            size = n;
            totalSum.assign(4 * n, 0);
            minPref.assign(4 * n, 0);
            maxPref.assign(4 * n, 0);
        }

        void recalculate(int node) {
            int leftChild = node * 2;
            int rightChild = node * 2 + 1;

            totalSum[node] = totalSum[leftChild] + totalSum[rightChild];

            minPref[node] = min(
                minPref[leftChild],
                totalSum[leftChild] + minPref[rightChild]
            );

            maxPref[node] = max(
                maxPref[leftChild],
                totalSum[leftChild] + maxPref[rightChild]
            );
        }

        void update(int index, int value) {
            update(1, 0, size - 1, index, value);
        }

        void update(int node, int left, int right, int index, int value) {
            if (left == right) {
                totalSum[node] = value;
                minPref[node] = value;
                maxPref[node] = value;
                return;
            }

            int mid = (left + right) / 2;

            if (index <= mid)
                update(node * 2, left, mid, index, value);
            else
                update(node * 2 + 1, mid + 1, right, index, value);

            recalculate(node);
        }

        bool canContainTarget(int node, int sumBefore, int target) {
            int needed = target - sumBefore;
            return minPref[node] <= needed && needed <= maxPref[node];
        }

        int findRightmostIndexWithPrefixSum(int target) {
            return findRightmostIndexWithPrefixSum(1, 0, size - 1, 0, target);
        }

        int findRightmostIndexWithPrefixSum(int node, int left, int right,
                                            int sumBefore, int target) {

            if (!canContainTarget(node, sumBefore, target))
                return -1;

            if (left == right)
                return left;

            int mid = (left + right) / 2;
            int leftChild = node * 2;
            int rightChild = node * 2 + 1;

            int sumBeforeRight = sumBefore + totalSum[leftChild];

            if (canContainTarget(rightChild, sumBeforeRight, target)) {
                return findRightmostIndexWithPrefixSum(
                    rightChild, mid + 1, right, sumBeforeRight, target
                );
            }

            return findRightmostIndexWithPrefixSum(
                leftChild, left, mid, sumBefore, target
            );
        }
    };

public:
    int longestBalanced(vector<int>& nums) {

        int n = nums.size();
        SegmentTree segmentTree(n);

        unordered_map<int, int> firstOccurrence;
        int maxLen = 0;

        for (int left = n - 1; left >= 0; left--) {
            int num = nums[left];

            if (firstOccurrence.count(num)) {
                int oldIndex = firstOccurrence[num];
                segmentTree.update(oldIndex, 0);
            }

            firstOccurrence[num] = left;

            int weight = (num % 2 == 0) ? 1 : -1;
            segmentTree.update(left, weight);

            int right = segmentTree.findRightmostIndexWithPrefixSum(0);

            if (right >= left) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }
};


int main(){
    Solution s1;
    vector<int> nums = {2,5,4,3};

    cout<<s1.longestBalanced(nums)<<endl;
    
    return 0;
}