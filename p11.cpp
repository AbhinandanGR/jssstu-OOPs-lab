#include<iostream>
using namespace std;

class DLIST{
	int data;
	DLIST *next, *prev;
	public:
		DLIST(int val){
			data = val;
			next = NULL;
			prev = NULL;
		}
		friend class DLL;
};

class DLL{
	DLIST *head, *tail;
	public:
		DLL(){
			head = NULL;
			tail = NULL;
		}
		void create(int n);
		void insert(int val, int pos);
		void del(int pos);
		void display();
};

void DLL :: create(int n){
	int val;
	for(int i = 0; i<n; i++){
		cout << "Enter the node data : ";
		cin >> val;
		DLIST *newNode = new DLIST(val);
		if(head == NULL)
			head = tail = newNode;
		else{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
	}
}

void DLL :: insert(int val, int pos){
	DLIST *newNode = new DLIST(val);
	if(head == NULL)
		head = tail = newNode;
	else if(pos <= 1){
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else{
		DLIST *temp = head;
		for(int i = 1; i < pos-1 && temp != NULL; i++)
			temp = temp->next;
		if(temp == NULL){
			cout << "Invalid position!!" << endl;
			return;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		if(temp->next != NULL)
			temp->next->prev = newNode;
		else
			tail = newNode;
		temp->next = newNode;
	}
}

void DLL :: del(int pos){
	DLIST *temp = head;
	if(head == NULL){
		cout << "List is empty!!" << endl;
		return;
	}
	
	if(pos<=1){
		head = head->next;
		if(head!=NULL)
			head->prev = NULL;
		else 
			tail = NULL;
		delete temp;
	}
	else{
		for(int i = 1; i < pos && temp != NULL; i++)
			temp = temp->next;
		if(temp == NULL){
			cout << "Invalid position!!" << endl;
			return;
		}
		if(temp->prev != NULL)
			temp->prev->next = temp->next;
		if(temp->next != NULL)
			temp->next->prev = temp->prev;
		else
			tail = temp->prev;
		delete temp;
	}
}

void DLL :: display(){
	if(head == NULL)
		cout << "List is empty" << endl;
	else{
		DLIST *temp = head;
		cout << "the contents are : ";
		while(temp != NULL){			
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
}

int main(){
	int choice, ele, pos, n;
	DLL obj;
	
	do{
		cout << "Doubly Linked List Operation\n\t1.Create \n\t2.Insert\n\t3.Delete\n\t4.Display\n\t5.exit" << endl;
		cout << "Enter the choice : ";
		cin >> choice;
		
		switch(choice){
			case 1 : cout << "Enter the number of nodes : ";
				 cin >> n;
				 obj.create(n);
				 break;
			case 2 : cout << "Enter the element to insert : ";
				 cin >> ele;
				 cout << "Enter the position to insert : ";
				 cin >> pos;
				 obj.insert(ele, pos);
				 break;
			case 3 : cout << "Enter the postion to delete : ";
				 cin >> pos;
				 obj.del(pos);
				 break;
			case 4 : obj.display();
				 break;
			case 5 : cout << "Exiting the program" << endl;
				 break;
			default : cout <<"Invaild choice" << endl;								 
		}
	}while(choice != 5);
	return 0;
}






