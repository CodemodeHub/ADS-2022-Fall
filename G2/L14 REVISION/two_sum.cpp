#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,n=numbers.size(),r=n-1;
        int index1,index2;
        for(int i=l;i<=r;i++){
            int l1=0,r1=r;
            while(l1<=r1){
                int m1=l1+(r1-l1)/2;
                if(numbers[i]+numbers[m1]==target&&m1!=i){
                    index1=i+1,index2=m1+1;
                    break;
                }else if(numbers[i]+numbers[m1]<target)
                    l1=m1+1;
                else
                    r1=m1-1;
            }
        }
        return {min(index1,index2),max(index1,index2)};
    }
};