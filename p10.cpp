#include<iostream>
using namespace std;
#define max 5

template<class T>
class queue{
	T q[max];
	int front, rear;
	public:
		queue(){
			front = rear = -1;
		}
		void insert(T);
		void remove();
		void display();
};

template<class T>
void queue<T> :: insert(T ele){
	if(rear == max-1)
		cout << "Queue overflow" << endl;
	else{
		if(front == -1 && rear == -1){
			front = rear = 0;
			q[rear] = ele;
		}			
		else
			q[++rear] = ele;
	}
}

template<class T>
void queue<T> :: remove(){
	if(front == -1 && rear == -1)
		cout << "Oueue underflow" << endl;
	else if(front == rear){
		cout << "The deleted element is " << q[front] << endl;
		front = rear = -1;
	}
	else
		cout << "The deleted element is " << q[front++] << endl;
}

template<class T>
void queue<T> :: display(){
	if(front == -1 && rear == -1)
		cout << "Oueue underflow" << endl;
	else{
		cout << "Queue contents are : ";
		for(int i = front; i <= rear; i++)
			cout << q[i] << " ";
		cout << endl;
	}
}

int main(){
	queue<int> i;
	queue<double> d;
	double ele1;
	int ch, choice, ele;
	
	cout << "Enter the data type to perform queue operation\n1.Integers\n2.Double\n";
	cin >> ch;
	
	cout << "\n1.Insert\n2.Delete\n3.Display\n4.exit\n";
	do{
		cout << "Enter your choice : ";
		cin >> choice;
		
		switch(choice){
			case 1 : if(ch == 1){
					cout << "Enter the element to insert : ";
					cin >> ele;
					i.insert(ele);
					i.display();
				 }
				 else{
				 	cout << "Enter the element to insert : ";
					cin >> ele1;
					d.insert(ele1);
					d.display();
				 }
				 break;
			case 2 : if(ch == 1){
				 	i.remove();
				 	i.display();
				 }
				 else{
				 	d.remove();
				 	d.display();
				 }
				 break;
			case 3 : if(ch == 1)
				 	i.display();
				 else
				 	d.display();
				 break;
			case 4 : cout << "Exiting the program " << endl;
			 	 break;
			default : cout << "Invaild choice!!" << endl;			
		}		
	}while(choice != 4);
	return 0;
}








