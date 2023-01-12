#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node(int x){
	 data=x;
	 next=NULL;
	}
};
struct Queue{
	Node *front,*rear;
	int size;
	Queue(){
	front=NULL;
	rear=NULL;
	size=0;
	}
	void enque(int x){
	Node *temp=new Node(x);
	size++;
	if(front==NULL){
	front=temp;
	rear=temp;
	return;
	}
	else{
	rear->next= temp;
	rear=temp;
       }
	}
	void deque(){
	if(front==NULL){
	return;
	}
	size--;
	Node *temp=front;
	front=front->next;
    if(front==NULL){
    rear=NULL;
    }
    delete(temp);
	}
	int getrear(){
	  return rear->data;
	}

};
int main(){

	Queue q;
	q.enque(5);
	q.enque(6);
	q.enque(7);
	q.enque(8);
	cout<<" "<<q.getrear();
	q.deque();
	cout<<q.size;

return 0;

}