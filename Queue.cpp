
#include<iostream>
using namespace std;

struct Queue{
	int arr[4];
	int cap,size,front;
	Queue(int c){
	cap=c;
	size=0;
	front=0;
	}
	bool isFull(){
	return (size==cap);
	}
	bool isEmpty(){
	return (size==0);
	}
	int getFront(){
	if(isEmpty()) return -1;
	else
	   return arr[front];
	   }
    int getRear(){
    if(isEmpty()) return -1;
    else
      return arr[(front+size-1)%cap];
	}
	void enque(int x){
	 if(isFull()){
	    return ;
	 }
	 int rear=getRear();
	 rear=(rear+1)%cap;
     arr[rear]=x;
     size++;
	}
	void deque(){
	if(isEmpty()){
	return;
	}
	front=(front+1)%cap;
	size--;
	}

};
int main(){
	Queue q(4);
	q.enque(6);
	q.enque(5);
	q.enque(7);
	q.enque(8);
	cout<<q.size;
	cout<<q.getRear();
	cout<<q.getFront();
    q.deque();
    cout<<q.getRear();
	cout<<q.getFront();
return 0;
}
