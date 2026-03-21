class Solution {
public:
    // brute force solution-> TC=O(n^2) ans SC=O(1)
    bool nice_pair(int a,int b){
        int n1=a;
        int n2=b;
        //reverse n1
        int d,r1=0;
        while(n1){
            d=n1%10;
            n1=n1/10;
            r1=r1*10+d;
        }
        //reverse n2
        int r2=0;
        while(n2){
            d=n2%10;
            n2=n2/10;
            r2=r2*10+d;
        }
        // cout<<a<<" "<<r2<<" "<<b<<" "<<r1<<endl;
        if(a+r2 == b+r1)
            return 1;
        return 0;
    }
    const int MOD=1e9+7;
    int countNicePairs(vector<int>& nums) {
        long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nice_pair(nums[i],nums[j]))
                    ans++;
            }
        }
        return (ans%MOD);
    }























    class Solution {//optimal solution-> TC=O(n) ans SC=O(n)
public:
    int rev(int a){
        //reverse a
        int d,r1=0;
        while(a){
            d=a%10;
            a=a/10;
            r1=r1*10+d;
        }
        return r1;
    }
    const int MOD=1e9+7;
    int countNicePairs(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        //the condition can be written as nums[i]-rev(nums[i])=nums[j]-rev(nums[j])

        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            nums[i]=nums[i]-rev(nums[i]);
            // cout<<nums[i]<<" ";
            um[nums[i]]++;
        }
        long long a;
        for(auto i:um){
            a=i.second;
            ans=ans+(a*(a-1))/2;
        }
        return ans%MOD;
    }
};


};