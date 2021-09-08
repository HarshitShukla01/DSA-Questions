//#include<bits/stdc++.h>
#include <iostream>
#include <typeinfo>
using namespace std;

//template -> code reusualibility(DRY) , Generic Programming (forall datatypes) 


//normal funtion
/*
template <typename T>  //template <class T> 
T myMax(T x, T y)
{
   return (x > y)? x: y;
}
 
int main()
{
  cout << myMax<int>(3, 7) << endl;  
  cout << myMax<double>(3.0, 7.0) << endl; 
  cout << myMax<char>('g', 'e') << endl;  
  return 0;
}

*/

//using two temlate variable
/*
template <typename T,typename U>  //template <class T,class U> 
void myMax(T x, U y)
{
   cout<<x<<" "<<y<<endl;
}
 
template <typename T,typename U = char>  //default 
void chk(T x, U y)
{
  cout<<x<<" "<<y<<endl;
}

int main()
{
  myMax<int,double>(3, 7.6); 
  chk<double>(3.2, 'r');
  chk<int,int>(2,3); 
  return 0;
}
*/




//using class with template
/*

template <typename T>
class vector{
    private:
    
    T size;
    public:
    T* ptr;
     vector(T n)
     {
        ptr = new T[n];
        size= n ;
        for(int i = 0; i < size; i++)
        ptr[i]=i+4;
     }
     int leng() {return size;}

     void print();
};

template <typename T>
void vector<T> :: print(){
    for (int it=0;it<size;it++) {
        cout <<ptr[it] << " ";
    }
}


int main()
{
  int n =5;
  vector<int> arr(n);
  //for(int it=0;it<n;it++)
  for (auto it=0;it<arr.leng();it++) {
        cout << arr.ptr[it] << " ";
    }
    cout<<endl;
   arr.print();
}


*/