class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {//brute force using hash map
        vector<int> ans;
        
        unordered_map<int,int> hash;
        //edge case
        if(x==1 && y==1){
            if(2<=bound)
            ans.push_back(2);
            return ans;
        }
        int sum=0,i=0;
        if(x==1){
            while(sum<=bound){
                sum=1+pow(y,i);
                if(sum<=bound && hash.find(sum)==hash.end())
                    hash.insert({sum,1});
                i++;
            }
        }
        else if(y==1){
            while(sum<=bound){
                sum=1+pow(x,i);
                if(sum<=bound && hash.find(sum)==hash.end())
                    hash.insert({sum,1});
                i++;
            }
        }
        //above are edge cases
        else{
            while(sum<=bound){
                int j=0;
                while(sum<=bound){       
                    sum=pow(x,i)+pow(y,j);
                    if(sum<=bound && hash.find(sum)==hash.end())
                        hash.insert({sum,1});
                    j++;
                    // cout<<sum<<" "<<i<<" "<<j<<" "<<endl;

                }
                i++;
                sum=pow(x,i)+pow(x,0);
            }

        }
        for(auto i:hash){
            // cout<<i.first<<" ";
            ans.push_back(i.first);
        }
        return ans;
    }
};