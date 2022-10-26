#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int> nums, int threshold, int x) {
        int sum = 0;
        for(auto it:nums)
            sum+=ceil(double(it)/double(x));
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=1e9;
        while(r - l >= 1){ 
            int mid=l+(r-l)/2;
            if(check(nums, threshold, mid)){
                r=mid;
            }
            else
                l=mid+1;
        }
        return r;
    }
};