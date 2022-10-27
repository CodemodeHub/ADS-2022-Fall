#include<bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    int first_pos = -1, last_pos = -1;
    int l = 0, r = nums.size() - 1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(nums[m] == target) {
            first_pos = m;
            r = m - 1;
        } else if(nums[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    if(first_pos == -1) {
        return {-1, -1};
    }
    l = first_pos, r = nums.size() - 1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(nums[m] == target) {
            last_pos = m;
            l = m + 1;
        } else if(nums[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return {first_pos, last_pos};
}