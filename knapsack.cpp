//0-1 Knapsack Problem
#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#include<climits>
#include<iomanip>
using namespace std;

  int knrecur(int wts[],int pri[],int n,int w)
   {
      if(n==0 || w==0)
          return 0;
      else
       {
          int exc;
          int inc=exc=0;
          if(wts[n-1]<=w)
           {
             inc=pri[n-1]+knrecur(wts,pri,n-1,w-wts[n-1]);
           }
             exc=knrecur(wts,pri,n-1,w);
             return max(inc,exc);
       }
   }

  int knbup(int wts[],int pri[],int n,int w)
    {
        int dp[n][w+1];
        memset(dp,0,sizeof(dp));
        int i,j,x,y,k;
        int z;
        for(i=0;i<n;i++)
         {
            for(j=1;j<=w;j++)
              {
                  if(i-1>=0)
                     x=dp[i-1][j];
                  else
                     x=0;
                  if(j-wts[i]>=0 && i-1>=0)
                    y=dp[i-1][j-wts[i]];
                  else
                     y=0;
                if(j-wts[i]>=0) 
                  k=pri[i]+y;
                else
                  k=y;
                if(k>x)
                  dp[i][j]=k;
                else
                   dp[i][j]=x;
              }
         }
   
          cout<<endl;
          for(i=0;i<n;i++)
            {
               for(j=0;j<=w;j++)
                 {
                    cout<<setw(4)<<dp[i][j];
                 }
                  cout<<endl;

             }
     
        return dp[n-1][w];

  }
            
  
  int main()
   {
      int n,w;
      cout<<"Enter the no. of items: "<<endl;
       cin>>n;
      cout<<"Enter  the prices of items : "<<endl;
      int pri[n];
       int i,j;
       for(i=0;i<n;i++)
         cin>>pri[i];
       cout<<"Enter the weights of items  "<<endl;
        int wts[n];
        for(i=0;i<n;i++)
         {
            cin>>wts[i];
         }
       
      cout<<"Enter the weight you want : "<<endl;
      cin>>w;

     cout<<"Anwer by recursion is : "<<knrecur(wts,pri,n,w)<<endl;
     cout<<"Answer by bottomup is : "<<knbup(wts,pri,n,w)<<endl;


    return 0;

 }
     
     