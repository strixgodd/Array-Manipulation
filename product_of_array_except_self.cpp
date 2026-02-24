class Solution {
public:
    //with using the division operator (optimized brute force)
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int p=1,n=nums.size();
        int countZeros =0;
        //find product of the array
        for(int i=0;i<n;i++){
            if(nums[i]!=0)
                p*=nums[i];
            else
                countZeros++;
        }
        if(countZeros){
            for(int i=0;i<n;i++){
                if(nums[i]!=0){
                    ans.push_back(0);
                }
                else{
                    if(countZeros==1)
                        ans.push_back(p);
                    else
                        ans.push_back(0);
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(nums[i]!=0)
                    p=p/nums[i];// without the division operator try to think of something bitwise
                ans.push_back(p);
                p*=nums[i];
            }
        }
        return ans;
    }
};