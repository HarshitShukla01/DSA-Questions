#include<bits/stdc++.h>
using namespace std;

int maxMeetings(int start[], int end[], int n)
{
    vector<vector<int>> arr;

    for(int i=0;i<n;i++)
    arr.push_back({start[i],end[i]});

    sort(arr.begin(),arr.end(),[&](vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    });
    int count = 1;
    int st = arr[0][1];
    for(int i=0;i<n;i++)
    {
        if(arr[i][0]>=st)
        {
            count++;
            st=arr[i][1];
        }
    }
    return count;
}

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int n;
  cin>>n;
  int a1[n],a2[n];
  for(int i=0;i<n;i++)
  cin>>a1[i];

  for(int i=0;i<n;i++)
  cin>>a2[i];

  cout<<maxMeetings(a1,a2,n);

}