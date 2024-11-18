#include<iostream>
using namespace std;
void display(int **mat,int num){
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(mat[i][j]==1){
                cout<<"Q ";
            }
            else if(mat[i][j]==0){
                cout<<". ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

bool check(int **mat,int row,int col,int num){
    int i,j;
    for(i=row;i>=0;i--)
        if(mat[i][col]==1) return false;
    for(i=row,j=col;i>=0&&j>=0;i--,j--)
        if(mat[i][j]==1) return false;
    for(i=row,j=col;i>=0&&j<num;i--,j++)
        if(mat[i][j]==1) return false;
    return true;
}

void nqueen(int **mat,int num,int row){
    int col;
    if(row==num){
        display(mat,num);
        return;
    }
    else{
        for(col=0;col<num;col++){
            if(check(mat,row,col,num)){
                mat[row][col]=1;
                nqueen(mat,num,row+1);
                mat[row][col]=0;
            }
        }
    }
}
int main(){
    int num;
    if(!(cin>>num)){
        cout<<"Invalid input";
        return 0;
    }
    if(num>=9){
        cout<<"Invalid input";
        return 0;
    }
    if(num==2||num==3){
        cout<<"No solution exists";
        return 0;
    }
    int **mat =new int*[num];
    for(int ind=0;ind<num;ind++)
    mat[ind]=new int[num];
    nqueen(mat,num,0);
    return 0;
}
