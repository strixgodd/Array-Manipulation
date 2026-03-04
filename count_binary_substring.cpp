//brute force

// class Solution {
// public:
//     int countBinarySubstrings(string s) {
//         int n=s.size(),ans=0;
//         int count;
//         for(int i=0;i<n-1;i++){
//             count=0;
//             if(s[i]=='0' && s[i+1]=='1'){
//                 int j=i;
//                 int k=i+1;
//                 while(s[j]=='0' && s[k]=='1'){
//                     count++;
//                     j--;
//                     k++;
//                     if(j<0 || k>=n)
//                         break;
//                 }
//             }
//             else if(s[i]=='1' && s[i+1]=='0'){
//                 int j=i;
//                 int k=i+1;
//                 while(s[j]=='1' && s[k]=='0'){
//                     count++;
//                     j--;
//                     k++;
//                     if(j<0 || k>=n)
//                         break;
//                 }
//             }
//             ans+=count;
//         }
//         return ans;
//     }
// };


//optimized

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        int count=1;
        int j=0,ans=0;
        int curr=0,prev=0;
        //creating groups of 0's and 1's
        for(int i=0;i<n-1;i++){
            if(s[i+1]==s[i]){
                count++;
            }
            else{
                prev=curr;
                curr=count;
                ans+=min(prev,curr);
                count=1;
            }
        }
        ans+=min(curr,count);
        return ans;
    }
};

//optimized aproach -> first think of grouping the 0's and 1's and then storing it in an array and then take of sum of minimum of adjacent elements
// then think is storing the groups required or can i do something with curr and prev?