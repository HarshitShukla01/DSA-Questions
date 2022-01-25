#include<bits/stdc++.h>
using namespace std;

 int ladderLength(string bw, string ew, vector<string>& arr) {
     int n = arr.size();
     unordered_set<string> s;
     
     int c=0;
     for(int i=0;i<n;i++){
     	if(arr[i]==ew) c++;
     	s.insert(arr[i]);
     }

     if(c==0) return 0;

     queue<string> q;
     q.push(bw);
     
     int depth = 0;
     while(!q.empty())
     {
     	depth++;
     	int t = q.size();

     	while(t--)
     	{
     		string str = q.front();
     		q.pop();

     		for(int i=0;i<str.size();i++)
     		{
     			string value = str;
     			for(char ch = 'a';ch<='z';ch++)
     			{
     				value[i]=ch;
     				if(str==value) continue;
     				if(value==ew) return depth+1;
     				if(s.find(value)!=s.end()){
     					q.push(value);
     					s.erase(value);
     				}
     			}
     		}
     	} 
     }
     return 0;
 }


int main()
{
	string beginWord = "hit", endWord = "cog";
	vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

	cout<<ladderLength(beginWord,endWord,wordList);

}