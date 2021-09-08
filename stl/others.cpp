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
   

   //output method 1
   /*
   for (auto i = arr.begin(); i != arr.end(); i++)
        cout << *i << " ";
    */


    //output method 2
    /*
    for (int i = 1; i <= 5; i++)
       arr.push_back(i);
    */

   
   //sort
    sort(vect.begin(),vect.end());  //ascending
    sort(vect.begin(),vect.end(),greater<int>()); //descending

    


    vect.pop_back();                                         //remove last element

    cout <<count(vect.begin(),vect.end(),10)<<endl;          //count no of '10' in vector

    reverse(vect.begin(),vect.end());                        //reverse the vector

    cout << *max_element(vect.begin(), vect.end())<<endl;    //max element in vector
    cout << *min_element(vect.begin(), vect.end())<<endl;    //min element in vector

    if(find(vect.begin(), vect.end(),5) != vect.end())       //if '5' present in vector or not
    cout<<"found"<<endl;
    else cout<<"not found"<<endl;

    cout << "Size : " << vect.size();                        //size of vector
    
    if (vect.empty() == false) cout << "\nVector is not empty";  //empty or not
    else cout << "\nVector is empty";



    cout << "\nfront() : vect.front() = " << vect.front();     //first ele of vector
  
    cout << "\nback() : vect.back() = " << vect.back();         //last ele of vector

}
