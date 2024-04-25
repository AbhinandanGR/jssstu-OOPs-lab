#include<iostream>
using namespace std;
#define size 25
class employee{
	char emp_name[20], emp_num[20];
	float basic, netsal, it, da;
	public:
		void getdata();
		void net_sal();
		void display();
};
void employee :: getdata(){
	cout << "Enter the employee number : ";
	cin >> emp_num;
	cout << "Enter the employee name : ";
	cin >> emp_name;
	cout << "Enter the basic salary : ";
	cin >> basic;
}
void employee :: net_sal(){
	da = (0.52 * basic);
	float gsal = basic + da;
	it = (0.30 * gsal);
	netsal = gsal - it;
}
void employee :: display(){
	cout << "Employee number : " << emp_num << endl;
	cout << "Employee name : "<< emp_name << endl;
	cout << "Net salary : " << netsal << endl;
}
int main(){
	employee obj[size];
	int n;	
	cout << "Enter the number of employees : ";
	cin >> n;	
	for(int i = 0; i < n; i++){
		obj[i].getdata();
		obj[i].net_sal();
	}	
	cout << "\nDisplaying the details : " << endl;
	for(int i = 0; i < n; i++){
		obj[i].display();
		cout << endl;
	}	
	return 0;
}
