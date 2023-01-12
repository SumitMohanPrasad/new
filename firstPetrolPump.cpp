#include<iostream>
using namespace std;
int firstPetrolPump(int petrol[],int dist[],int n){
 for(int start=0;start<n;start++){
   int curr_petrol=0;
   int end=start;
   while(true){
     curr_petrol += petrol[end]-dist[end];
       if(curr_petrol<0){
         break;
       }
       end=(end+1)%n;
       if(start==end)
        return start+1;
   }
 }
}
int EfirstPetrolPump(int petrol[],int dist[],int n){
  int start=0,curr_petrol=0,prev_petrol=0;
  for(int i=0;i<n;i++){
      curr_petrol+=petrol[i]-dist[i];
      if(curr_petrol<0){
        start=i+1;
        prev_petrol=curr_petrol;
        curr_petrol=0;
      }
  }
  return (curr_petrol+prev_petrol>=0)?start+1:-1;
}

int main(){
  int petrol[]={4,8,7,4};
  int dist[]={6,5,3,5};
  int n=4;
  cout<<firstPetrolPump(petrol,dist,n)<<"\n";
  cout<<EfirstPetrolPump(petrol,dist,n);
}
