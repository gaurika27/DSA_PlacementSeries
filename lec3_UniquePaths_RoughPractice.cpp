//M1 

#include <bits\stdc++.h>
using namespace std;
int countPaths(int i, int j, int n, int m){
  if(i==(n-1) && j==(m-1)) return 1;
  if(i>=n || j>=m) return 0;
  else return countPaths(i+1,j,n,m)+countPaths(i,j+1,n,m);
}

int main(){
  cout<<countPaths(0,0,2,3);
}

//M2

#include <bits\stdc++.h>
using namespace std;
int countPaths(int i, int j, int n, int m, vector<vector<int>> &dp){
  if(i==(n-1) && j==(m-1)) return 1;
  if(i>=n || j>=m) return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  else return dp[i][j]=countPaths(i+1,j,m,n,dp)+countPaths(i,j+1,m,n,dp);
}

int main(){
  vector<vector<int>> dp(2,vector<int>(3,-1));
  cout<<countPaths(0,0,2,3,dp);
}

// M3: optimal solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=n+m-2;
        int r=m-1;
        double res=1;

        for(int i=1; i<=r; i++){
            res*=(N-r+i)/i;
        }
        return (int)res;
        
    }
};

//Working solution
class Solution {
public:


    int f(int i, int j,vector<vector<int>>& dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=f(i-1,j,dp);
        int left=f(i,j-1,dp);
        return dp[i][j]=(up+left);

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp);

        
    }
};