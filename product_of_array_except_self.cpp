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
    //without division
    vector<int> productExceptSelf_WD(vector<int>& nums) {//SC=O(n)
            int n=nums.size();
            vector<int> ans(n);
            vector<int> prefix(n);
            vector<int> suffix(n);
            //create the prefix and suffix array
            prefix[0]=1;
            suffix[n-1]=1;
            for(int i=1;i<n;i++){
                prefix[i]=nums[i-1]*prefix[i-1];
            }
            for(int i=n-2;i>=0;i--){
                suffix[i]=nums[i+1]*suffix[i+1];
            }
            for(int i=0;i<n;i++){
                ans[i]=prefix[i]*suffix[i];
            }
            return ans;
        }
        //without division space optimization
        vector<int> productExceptSelf_WDSO(vector<int>& nums) {//SC=O(1)
            int n=nums.size();
            vector<int> ans(n);
            //take nums as prefix and ans as suffix
            //create the suffix
            ans[n-1]=1;
            for(int i=n-2;i>=0;i--){
                ans[i]=nums[i+1]*ans[i+1];
            }
            //create the prefix
            int temp=1;
            int curr;
            for(int i=1;i<n;i++){
                curr=nums[i];
                nums[i]=nums[i-1]*temp;
                temp=curr;
            }
            nums[0]=1;
            //now the op array
            for(int i=0;i<n;i++){
                ans[i]=ans[i]*nums[i];
            }
            return ans;
        }
};