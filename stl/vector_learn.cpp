#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;     //create vector
    v.assign(5, 10);  //[10,10,10,10,10]  create vector of size 5 and fill 10 in all of them
    

    vector<int> vect;
    vect.push_back(1);   //push elements in vector
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);
    

   //input through user
   /*
      vector<int> arr;
       for (int i = 1; i <= 5; i++)
       {  int k;
          cin>>k;
          arr.push_back(k);
       }
   */
   

   
   //ascending sort
    sort(vect.begin(),vect.end());
   
    //output method 1
    cout<<"ascending order = ";
   for (auto i = vect.begin(); i != vect.end(); i++)
        cout << *i << " ";
    cout<<endl;


    //descending sort
    sort(vect.begin(),vect.end(),greater<int>()); 

    //output method 2
    cout<<"descending order = ";
    for (int i = 0; i < vect.size(); i++)
       cout<<vect[i]<<" ";
    cout<<endl;
    


    vect.pop_back();                                         //remove last element

    cout <<"count = 
    "<<count(vect.begin(),vect.end(),10)<<endl;          //count no of '10' in vector

    reverse(vect.begin(),vect.end());                        //reverse the vector

    cout <<"max ele = " <<*max_element(vect.begin(), vect.end())<<endl;    //max element in vector
    cout <<"min ele = " <<*min_element(vect.begin(), vect.end())<<endl;    //min element in vector

    if(find(vect.begin(), vect.end(),5) != vect.end())       //if '5' present in vector or not
    cout<<"found 5"<<endl;
    else cout<<"not found 5"<<endl;

    cout << "Size : " << vect.size();                        //size of vector
    
    if (vect.empty() == false) cout << "\nVector is not empty";  //empty or not
    else cout << "\nVector is empty";



    cout << "\nfront() : vect.front() = " << vect.front();     //first ele of vector
  
    cout << "\nback() : vect.back() = " << vect.back();         //last ele of vector

}
 