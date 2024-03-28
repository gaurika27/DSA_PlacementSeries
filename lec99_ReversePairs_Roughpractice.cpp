//Reverse pairs in an array
#include <bits\stdc++.h>
using namespace std;
int main(){
  int count=0;
  int arr[]={40,25,19,12,9,6,2};
  for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
    for(int j=i+1; j<sizeof(arr)/sizeof(arr[0]); j++){
      if(arr[i]>2*arr[j]){
        cout<<arr[i]<<" "<<arr[j]<<endl; 
        count++;
      }
    } 
  }
  cout<<count;
}