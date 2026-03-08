#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n=citations.size();
        //create an array of size n+1
        vector<int> count(n+1,0);// count size is n+1 because we know that the maximum value of ans is n
        //create the count array
        for(int i=0;i<n;i++){
            if(citations[i]<=n)
                count[citations[i]]++;
            else //cap it
                count[n]++;
        }
        for(int i=0;i<=n;i++)
            cout<<count[i]<<" ";
        //return 0;
    }
};
int main(){
    Solution s=Solution();
    vector<int> query={3,0,7,1,5};
    s.hIndex(query);
    return 0;
}
