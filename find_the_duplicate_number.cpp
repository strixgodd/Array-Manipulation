class Solution {
public:
    int findDuplicate(vector<int>& nums){
        int n=nums.size();
        int i=0;
        int sl=0,f=0;
        while(1){
            sl=nums[sl];
            f=nums[nums[f]];
            if(sl==f)
                break;
        }
        sl=0;
        while(1){
            sl=nums[sl];
            f=nums[f];
            if(sl==f)
                return sl;
        }
    }
};






//trick is the range of array elements and the number of indices
//concept of slow and fast pointer