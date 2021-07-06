#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
const int d=8;
  
 void solveknight(int board[d][d],int n,int i,int j,int k)
  {
     static int x=1;
     if(i<0 || j>=n || i>=n || j<0 || board[i][j]!=0)
         return  ;
     else
      {
          int rd[d]={1,2,2,1,-1,-2,-2,-1};
          int cd[d]={-2,-1,1,2,2,1,-1,-2};
          board[i][j]=x;
          x++;
       //  if(i+1<n && j-2>=0)
           solveknight(board,n,i+1,j-2,k);
        //   if(i+2<n && j-1>=0)
           solveknight(board,n,i+2,j-1,k);
       //     if(i+2<n && j+1<n)
           solveknight(board,n,i+2,j+1,k);
       //       if(i+1<n && j+2<n)
           solveknight(board,n,i+1,j+2,k);
      //        if(i-1>=0 && j+2<n)
           solveknight(board,n,i-1,j+2,k);
      //         if(i-2>=0 && j+1<n)
           solveknight(board,n,i-2,j+1,k);
      //          if(i-2>=0 && j-1>=0)
           solveknight(board,n,i-2,j-1,k);
      //         if(i-1>=0 && j-2>=0)
           solveknight(board,n,i-1,j-2,k);
           
         return ;
  }

}; 
  int main()
  {
    int n=8;
    int board[d][d];
    memset(board,0,sizeof(board));
    solveknight(board,n,0,0,1);

     for(int i=0;i<8;i++)
      {
         for(int j=0;j<8;j++)
          {
             cout<<board[i][j]<<" - ";
          }
          cout<<endl;
     }

    return 0;

  }