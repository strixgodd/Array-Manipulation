#include<bits/stdc++.h>
using namespace std;
class Solution {

public:
    void rotate_90_deg(vector<vector<int>>& mat){
        int n=mat.size();
        int temp;
        //transpose
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==j)
                    continue;
                temp=mat[i][j];
                mat[i][j]=mat[j][i];
                mat[j][i]=temp;
            }
        }
        //exchange columns
        int i=0,j=n-1;
        while(i<=j){
            if(i==j)
                break;
            for(int m=0;m<n;m++){
                temp=mat[m][i];
                mat[m][i]=mat[m][j];
                mat[m][j]=temp;
            }
            i++;
            j--;
        }
    }
    bool isMatrixEqual(vector<vector<int>>& mat, vector<vector<int>>& target){
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=target[i][j])
                    return 0;
            }
        }
        return 1;
    }
    void printMatrix(vector<vector<int>>& mat){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target){
        int n=mat.size();
        int count=0;
        int i,j,k;
        for(i=0;i<4;i++){
            printMatrix(mat);
            if(isMatrixEqual(mat,target))
                return 1;
            rotate_90_deg(mat);
        }
        return 0;             
    }
};
int main(){
    Solution s;
    vector<vector<int>> mat={{1,1},{0,1}};
    vector<vector<int>> target={{1,1},{1,0}};
    cout<<s.findRotation(mat,target);
    return 0;
}