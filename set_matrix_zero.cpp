class Solution {
public:
    void make_row_zero(vector<vector<int>>& matrix,int r,int c){
        for(int i=0;i<c;i++)
            matrix[r][i]=0;
    }
    void make_column_zero(vector<vector<int>>& matrix,int r,int c){
        for(int i=0;i<r;i++)
            matrix[i][c]=0;
    }
    void print_matrix(vector<vector<int>> matrix,int r,int c){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                cout<<matrix[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    void setZeroes(vector<vector<int>>& matrix){
        bool frhz=0,fchz=0;//frhz=first row has zero?
        int r=matrix.size();// no. of rows
        int c=matrix[0].size();//no. of cols
        for(int i=0;i<r;i++){
            if(matrix[i][0]==0)
                fchz=1;
        }
        for(int i=0;i<c;i++){
            if(matrix[0][i]==0)
                frhz=1;
        }
            
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        print_matrix(matrix,r,c);

        for(int i=1;i<r;i++){
            if(matrix[i][0]==0)
                make_row_zero(matrix,i,c);
        }
        for(int i=1;i<c;i++){
            if(matrix[0][i]==0)
                make_column_zero(matrix,r,i);
        }
        print_matrix(matrix,r,c);
        if(frhz && fchz){
            make_row_zero(matrix,0,c);
            make_column_zero(matrix,r,0);
        }
        else if(frhz && !fchz)
            make_row_zero(matrix,0,c);
        else if(!frhz && fchz)
            make_column_zero(matrix,r,0);
        print_matrix(matrix,r,c);
    }
};