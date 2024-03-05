#include <iostream>
using namespace std;

int main(){

  int num;
  cin>>num;
  double arr[num][2];
  for(int i=0;i<num;i++){
    for(int j=0;j<2;j++){
      cin>>arr[i][j];
    }
  }

  for(int i=0;i<num;i++){
      cout<<"("<<arr[i][0]<<", "<<arr[i][1]<<")"<<endl;
  }
  return 0;
}