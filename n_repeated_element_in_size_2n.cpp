class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        //edge cases
        if(nums[1]==nums[0] || nums[2]==nums[0])
            return nums[0];
        if(nums[2]==nums[1])
            return nums[1];
        
        for(int i=3;i<n;i++){
            if(nums[i]==nums[i-1]||nums[i]==nums[i-2]||nums[i]==nums[i-3])
                return nums[i];
        }
        return 0;
    }
};
//due to the property(constraint) of the array, two repeated elements cannot be spaced by more than 2 indexes.