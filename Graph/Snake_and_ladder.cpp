#include<bits/stdc++.h>
using namespace std;

// int snakesAndLadders(vector<vector<int>> arr) {
//    int n= arr.size();
// }

// int main()
// {
	
//     // vector<vector<int>> adj={
//     // 	{-1,-1,-1,-1,-1,-1},
//     // 	{-1,-1,-1,-1,-1,-1},
//     // 	{-1,-1,-1,-1,-1,-1},
//     // 	{-1,35,-1,-1,13,-1},
//     // 	{-1,-1,-1,-1,-1,-1},
//     // 	{-1,15,-1,-1,-1,-1}
//     // };
    

//     cout<<snakesAndLadders(adj);
   
// }

int ladderSnake(map<int,int> l,map<int,int> s)
{
	int moves = 0;
	queue<int> q;
	q.push(1);
	bool found=false;
	vector<int> vis(101,0);
	vis[0]=vis[1]=1;
	while(!q.empty() && !found)
	{
		int t = q.size();
		while(t--)
		{
			int temp = q.front();
			q.pop();
			for(int i=1;i<=6;i++)
			{
				if(temp+i == 100) found=true;
				else if(temp+i>100) break;
				else if(l[temp+i] && vis[l[temp+i]]!=1){
					vis[l[temp+i]]=true;
					q.push(l[temp+i]);

					if(l[temp+i]==100) found=true;
				}
				else if(s[temp+i] && vis[s[temp+i]]!=1){
					vis[s[temp+i]]=true;
					q.push(s[temp+i]);

					if(s[temp+i]==100) found=true;
				}
				else if(!s[temp+i] && !l[temp+i] && vis[temp+i]!=1){
					vis[temp+i]=true;
					q.push(temp+i);
				}
			}

			if(found==true) 
				break;
		}
		moves++;
	}

	if(found == false) return -1;

	return moves;
}


int main()
{
	int ladder;
	cin>>ladder;
	map<int,int> l;
	for(int i=0;i<ladder;i++)
	{
		int r,t;
		cin>>r>>t;
		l[r]=t;
	}

	int snakes;
	cin>>snakes;
	map<int,int> s;
	for(int i=0;i<snakes;i++)
	{
		int r,t;
		cin>>r>>t;
		s[r]=t;
	}

   cout<<"total moves to reach 100 block = "<<ladderSnake(l,s);
}