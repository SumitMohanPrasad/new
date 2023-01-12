#include<iostream>
#include<queue>
using namespace std;
void reverse(queue<int>&q1){
    	if(q1.empty()){
    		return;
    	}
    	int x=q1.front();
    	q1.pop();
    	reverse(q1);
    	q1.push(x);
    }
int main(){
 
	queue<int>q;
	q.push(4);
	q.push(5);
	q.push(6);
	cout<<q.front()<<" "<<q.back()<<" ";
	//q.pop();
	cout<<q.size();
   
    reverse(q);
    while(q.empty()==false){
    cout<<" "<<q.front();
    q.pop();
    }
    return 0;


}