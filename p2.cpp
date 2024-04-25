#include<iostream>
using namespace std;
#define max 25

class student{
	char name[10], usn[20];
	float m1, m2, m3;
	public:
		void getdata();
		void putdata();
};

void student :: getdata(){
	cout << "Enter the USN : ";
	cin >> usn;
	cout << "Enter the name : ";
	cin >> name;
	cout << "Enter three marks : ";
	cin >> m1 >> m2 >> m3;
}

void student :: putdata(){
	float min = 0, avg;
	if((m1 <= m2) && (m1 <= m3))
		min = m1;
	else if((m2 <= m1) && (m2 <= m3))
		min = m2;
	else 
		min = m3;
	avg = ((m1 + m2 + m3) - min)/2;
	cout << "USN : " << usn << endl;
	cout << "Name : " << name << endl;
	cout << "Average : " << avg << endl;
}

int main(){
	student obj[max];
	int n;
	cout << "Enter the number of students : ";
	cin >> n;
	cout << endl;	
	for(int i = 0; i < n; i++){
		cout << "Enter the student " << i+1 << " information : " << endl;
		obj[i].getdata();
		cout << endl;
	}	
	cout << "Students information : " << endl;
	for(int i = 0; i < n; i++){
		obj[i].putdata();
		cout << endl;
	}	
	return 0;
}




