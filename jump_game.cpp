class Solution {
public:
    bool canJump(vector<int>& nums){
        int n=nums.size(),maxReach=0;
        for(int i=0;i<n;i++){
            if(maxReach>=n-1)   
                return 1;
            if(i>maxReach)
                return 0;
            maxReach=max(maxReach,i+nums[i]);
        }
        return 0;
    }
};

//ordering inside for loop is very imp, don't think about where you can reach, just think about upto where you can reach