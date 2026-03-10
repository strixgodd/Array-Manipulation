class Solution {//brute force using hash map.
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {//brute force using hash map
        int sum=0;
        unordered_map<int,int> hash;

        int i=0;
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
        vector<int> ans;
        for(auto i:hash){
            cout<<i.first<<" ";
            ans.push_back(i.first);
        }
        return ans;
    }
};