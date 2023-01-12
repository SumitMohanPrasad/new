#include<iostream>
#include<queue>
//#include<string>
using namespace std;
void printFirstN(int n){
  queue<string>q;
  q.push("5");
  q.push("6");

  for(int i=0;i<n;i++){
   string curr;
   curr=q.front();
   q.pop();
   cout<<curr<<" ";
   q.push(curr+"5");
   q.push(curr+"6");
  }

}
int main(){

 printFirstN(10);
 return 0;
}
