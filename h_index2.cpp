using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l=0;
        int n=citations.size();
        int r=n-1;
        int m=l+(r-l)/2;
        while(l<=r){
            std::cout<<l<<" "<<m<<" "<<r<<endl;
            if(citations[m]<(n-m)){
                l=m+1;
            }
            else if(citations[m]>(n-m)){
                r=m-1;
            }
            else{
                return citations[m];
            }
            m=l+(r-l)/2;
        }
        std::cout<<l<<" "<<m<<" "<<r<<endl;        

        return n-l;
    }
};