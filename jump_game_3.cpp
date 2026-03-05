class Solution {
public:
    bool solveRecursively(vector<int> &arr,int index,int no_of_jumps,int n){
        //base case
        if(index>=n||index<0)
            return 0;
        if(arr[index]==0)
            return 1;
        if(no_of_jumps>=n-1)
            return 0;
        int move_right=solveRecursively(arr,index+arr[index],no_of_jumps+1,n);
        int move_left=solveRecursively(arr,index-arr[index],no_of_jumps+1,n);
        return max(move_right,move_left);
    }
    
    
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        return solveRecursively(arr,start,0,n);
    }



   class Solution {
public:
     bool canReach(vector<int>& arr, int start) {//optimized approach
        queue<int> q;
        int n=arr.size();
        q.push(start);
        int i;
        while(!q.empty()){
            i=q.front();
            q.pop();
            if(i>=0 && i<n && arr[i]>=0){
                if(arr[i]==0)
                    return 1;
                q.push(i-arr[i]);
                q.push(i+arr[i]);
                arr[i]*=-1;//mark as visited
            }
        }
        return 0;
    }


    //Some observations: max number of jumps to reach an index with 0 as element is arr.size().
};