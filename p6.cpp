#include<iostream>
using namespace std;

class stack{
	int a[100], top, size;
	public:
		stack(int n){
			size = n;
			top = -1;
		}
		friend stack operator +(stack s, int ele);
		friend stack operator --(stack &s, int ele);
		friend int isfull(stack s);
		friend int isempty(stack s);
		friend ostream &operator <<(ostream &, stack);
};

int isfull(stack s){
	if(s.top == s.size-1)
		return 1;
	return 0;
}

int isempty(stack s){
	if(s.top == -1)
		return 1;
	return 0;
}

stack operator +(stack s, int ele){
	if(isfull(s) == 1)
		cout << "Stack Overflow" << endl;
	else
		s.a[++s.top] = ele;
	return s;
}

stack operator --(stack &s, int ele){
	if(isempty(s) == 1)
		cout << "Stack underflow" << endl;
	else 
		cout << s.a[s.top--] << " is deleted" << endl;
	return s;
}

ostream &operator <<(ostream &out, stack s){
	if(isempty(s) == 1)
		out << "Stack underflow" << endl;
	else{
		out << "Stack elements are : " << endl;
		for(int i = s.top; i >= 0; i--)
			out << s.a[i] << " ";
		out << endl;
	}
	out << endl;
	return out;
}

int main(){
	int ele, size, choice;
	cout << "Enter the size of the stack : ";
	cin >> size;
	
	stack s(size);
	
	do{
		cout << "Menu: \n\t1. push\n\t2. pop\n\t3. display\n\t4. exit " << endl;
		cout << "Enter the choice : ";
		cin >> choice;
		
		switch(choice){
			case 1 : cout << "Enter the element to push : ";
				 cin >> ele;
				 s = s+ele;
				 break;
			case 2 : s = s--;
				 break;
			case 3 : cout << s;
				 break;
			case 4 : cout << "Exiting the program" << endl;
				 break;
			default : cout << "Invalid choice!!";
		}
	}while(choice != 4);
	
	
	return 0;
}






