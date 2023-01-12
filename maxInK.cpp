#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
void PrintMax(int arr[],int n, int k){
	for(int i=0;i<n-k+1;i++){
	int mx=arr[i];
	for(int j=i+1;j<i+k;j++){
	mx=fmax(mx,arr[j]);
	}
	cout<<mx<<" ";
	}
}
void printMaxEfficient(int arr[],int n, int k){
  deque<int>dq;
  dq.push_back(0);
  for(int i=1;i<k;i++){
    if(arr[i]>=arr[dq.front()]&& !dq.empty())
        dq.pop_back();
    else
        dq.push_back(i);
  }

  for(int i=k;i<n;i++){
    cout<<arr[dq.front()]<<" ";
    while(!dq.empty() && dq.front()<=i-k)
        dq.pop_front();
    while(!dq.empty() && arr[i]>=arr[dq.back()])
        dq.pop_back();

    dq.push_back(i);

  }
  cout<<arr[dq.front()]<<" ";
}

int main(){
    //cout<<"s";
	int arr[]={10,8,5,12,15,7,6};
	int k=3;
	int n=7;
	PrintMax(arr,n,k);
    printMaxEfficient(arr,n,k);
    return 0;
}
