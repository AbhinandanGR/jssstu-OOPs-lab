#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
};

class list{
	node* head;
	public:
		list(){
			head = NULL;
		}
		void insert(int ele);
		void deleteNode();
		void display();
};

void list :: insert(int ele){
	node* newNode = new node;
	newNode->data = ele;
	newNode->next = head;
	head = newNode;
}

void list :: deleteNode(){
	node* temp = head;
	if(head == NULL)
		cout << "List is empty!!" <<endl;
	else{
		cout << "Deleted element is " << head->data << " Deleted successfully!!" <<endl;;
		head = head->next;
		delete temp;
	}
}

void list :: display(){
	node* temp = head;
	if(head == NULL)
		cout << "List is empty!!" <<endl;
	else{
		cout << "List elements are : " << endl;
		while(temp != NULL){
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
}

int main(){
	int ele, choice;
	list obj;
	
	do{
		cout << "\nMENU : \n\t1.Insertion\n\t2.Deletion\n\t3.Display\n\t4.Exit" << endl;
		cout << "Enter the choice : ";
		cin >> choice;
		
		switch(choice){
			case 1 : cout << "Enter the element to be inserted : ";
				 cin >> ele;
				 obj.insert(ele);
				 break;
				
			case 2 : obj.deleteNode();
				 break;
				 
			case 3 : obj.display();
				 break;
			
			case 4 : cout << "Exiting the program" << endl;
				 break;
			
			default : cout << "Invalid choice!!" << endl; 
		}
	}while(choice != 4);
	
	
	return 0;
}




