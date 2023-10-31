/*
Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.
Example 1:

Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].
Example 2:

Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subsequence must be non-empty, so we choose the largest number.
Example 3:

Input: nums = [10,-2,-10,-5,20], k = 2
Output: 23
Explanation: The subsequence is [10, -2, -5, 20].
*/
/*  Alternate soln: Use a priority_queue< pair<sum_val till ind i, ind(i))>
    when we done with k indices, need to remove the i - k th ind val from
    priority queue, so we get the max if it is i - k remove it and insert new sum
    Note: this is armotrized operation as all indices will at max remove all n 
    values from pq */


#include <bits/stdc++.h>
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n , 0);
        map <int, int, std::greater<int> > pq;
        int rsl = INT_MIN;
        int tot_ele = 0;
        for(int i = 0; i < n; i++){
            int cur = 0;

            //Brute force approach
            /*for(int j = 1; j <= k; j++){
                if(i - j <= 0)
                    continue;
                cur = max(dp[i - j]);
            }*/
            if (pq.size()) {
                cur = pq.begin()->first;
            }
            if(cur >= 0) {
                dp[i] = nums[i] + cur;
            }
            else {
                dp[i] = nums[i];
            }
            //cout<<dp[i]<<" ";
            rsl = max(rsl, dp[i]);
            if (tot_ele == k) {
                //remove element
                int ind = i - k;
                pq[dp[ind]]--;
                tot_ele--;
                if (pq[dp[ind]] == 0)
                    pq.erase(dp[ind]);
            }
            pq[dp[i]]++;
            tot_ele++;
        }
        return rsl;
    }
};