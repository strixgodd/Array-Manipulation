class Solution {
public:
    int gcd(int a, int b){
        if(a==0)
            return b;
        return gcd(b%a,a);
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int no_of_ones=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1)
                no_of_ones++;
        }
        if(no_of_ones)
            return n-no_of_ones;
        else{
            int minimum=INT_MAX;
            for(int i=0;i<n;i++){
                int a=nums[i];
                for(int j=i+1;j<n;j++){
                    a=gcd(a,nums[j]);
                    if(a==1){
                        minimum=min(minimum,j-i+1);
                        break;
                    }
                }
            }
            if(minimum!=INT_MAX)
                return (minimum-1)+(n-1);//cost to make a 1 + spreading that 1 across the whole array
        }
        return -1;
    }
    // find the shortest subarray whose gcd is 1,if there is no such subarray then return -1.
    
};