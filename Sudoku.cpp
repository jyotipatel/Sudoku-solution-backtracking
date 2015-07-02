//Sudoku
#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define scan(a) scanf("%d",&a)
#define scanl(a) scanf("%lld",&a)
#define print(a) printf("%d",a)
#define printl(a) printf("%lld",a)
#define fin(i,j,n) for(int i=j;i<n;i++)
#define f0n(i,n) fin(i,0,n)
#define MAX 100000
#define mod 10
#define unassigned 0
using namespace std;

typedef pair<int,int>pii;
typedef long long LL;

bool cmp(const pii &left,const pii &right)
{
	return left.second<right.second;
}
int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	else
		return gcd(b,a%b);
}
int findUnassignedGrid(int grid[10][10],int &row,int &col)
{
	for(row=0;row<9;row++)
	{
		for(col=0;col<9;col++)
		{
			if(grid[row][col]==unassigned)
				return true;
		}
	}
	return false;
}

bool usedInRow(int grid[10][10],int row,int num)
{
	f0n(i,9)
	{
		if(grid[row][i]==num)
			return true;
	}
	return false;
}
bool usedInColumn(int grid[10][10],int col,int num)
{
	f0n(i,9)
	{
		if(grid[i][col]==num)
			return true;
	}
	return false;
}
bool usedInBox(int grid[10][10],int row,int col,int num)
{
	f0n(i,3)
	{
		f0n(j,3)
		{
			if(grid[row+i][col+j]==num)
				return true;
		}
	}
	return false;
}
int isSafe(int grid[10][10],int row,int col,int num)
{
	return (!usedInRow(grid,row,num)&&!usedInColumn(grid,col,num)&&!usedInBox(grid,row-row%3,col-col%3,num));
}
int solve(int grid[10][10])
{
	int row,col;
	if(!findUnassignedGrid(grid,row,col))
		return true;
	fin(i,1,10)
	{
		if(isSafe(grid,row,col,i))
		{
			grid[row][col]=i;
			if(solve(grid))
				return true;
			grid[row][col]=unassigned;
		}
	
	}
		return false;
}
int main()
{
	int grid[10][10];
	f0n(i,9)
	{
		f0n(j,9)
		{
			scan(grid[i][j]);
		}
	}
	if(solve(grid))
	{
		cout<<"Solution :\n";
		f0n(i,9)
		{
			f0n(j,9)
			{
				cout<<grid[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else
	{
		cout<<"No Solution\n";
	}
}
