class Solution {
public:
    int hIndex(vector<int>& citations) {
        // count sort 

        int n=citations.size();
        //modify the original array(clip the array at starting)-> it will be convenient in the later count sort steps-> no need for clipping in later count sort steps
        for(int i=0;i<n;i++){
            if(citations[i]>n)
                citations[i]=n;
        }
        //create an array of size n+1
        vector<int> count(n+1,0);// count size is n+1 because we know that the maximum value of ans is n
        //create the count array
        for(int i=0;i<n;i++){
            if(citations[i]<=n)
                count[citations[i]]++;
            // else //cap it
            //     count[n]++;
        }
        //cumulate
        for(int i=1;i<=n;i++){
            count[i]=count[i]+count[i-1];
        }
        // for(int i=0;i<=n;i++)
        //     cout<<count[i]<<" ";
        // cout<<endl;
        //create the sorted array
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--){
            ans[--count[citations[i]]]=citations[i];
        }
        // ans is the final sorted array
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
        //apply bin search on the sorted array
        int l=0,r=n-1;
        int mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(ans[mid]==n-mid){
                return n-mid;
            }
            else if(ans[mid]<n-mid){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return n-l;
    }
};