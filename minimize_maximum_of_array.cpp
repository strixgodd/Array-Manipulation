class Solution {// brute force soln- still not perfect can fail in extremely extremely rate cases.
public:
    int minimizeArrayValue(vector<int>& nums){
        int prevMax=INT_MAX;
        int max_index,second_max_index=-1;
        int maxi=0,second_max=0;
        while(1){
            //find max 
            maxi=nums[0];
            max_index=0;
            for(int i=1;i<nums.size();i++){
                if(nums[i]>maxi){
                    maxi=nums[i];
                    max_index=i;
                }
            }
            //find second max
            second_max=INT_MIN;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>second_max && i!=max_index){
                    second_max=nums[i];
                    second_max_index=i;
                }
            }
            // std::cout<<maxi<<" "<<second_max<<" "<<max_index<<" "<<second_max_index<<endl;
            // doing the computation in the max index
            if(maxi<=prevMax && max_index!=0 && nums[max_index]!=0){
                nums[max_index]--;
                nums[max_index-1]++;
            }
            else if(second_max<=prevMax && nums[second_max_index]!=0){
                nums[second_max_index]--;
                nums[second_max_index-1]++;
            }
            if(maxi>prevMax)
                break;
            prevMax=maxi;
        }
        return prevMax;
    }




    //optimal
    #include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int res=nums[0];
        long total=nums[0];
        int b;
        for(int i=1;i<nums.size();i++){
            total=total+nums[i];
            b=ceil(double(total)/(i+1));
            res=max(res,b);
        }
        return res;
    }
};
};