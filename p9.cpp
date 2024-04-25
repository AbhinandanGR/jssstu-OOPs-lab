#include<iostream>
#include<math.h>
using namespace std;
class octal{
	int oct[15], count;
	public:
		octal(int x);
		int operator +(int);
		friend ostream &operator <<(ostream &, octal &);
};
octal :: octal(int x){
	int i = 0, rem, a[15];
	while(x != 0){
		rem = x%8;
		x = x/8;
		a[i++] = rem;
	}
	count = i;
	int n = count - 1;
	for(int i = 0; i < count; i++){
		oct[i] = a[n];
		n--;
	}
}
int octal :: operator +(int k){
	int x= 0, j = count-1;
	for(int i = 0; i < count; i++){
		x = x + oct[j] * pow(8,i);
		j--;
	}
	return (x + k);
}
ostream &operator <<(ostream &print, octal &oc){
	for(int i = 0; i < oc.count; i++)
		print << oc.oct[i];
	return print;
}
int main(){
	int x, k, y = 0;
	cout << "Enter the value of x in integers : ";
	cin >>x;	
	octal h = octal(x);	
	cout << "The correspounding equivalent to " << x << " is " << h <<endl;	
	cout << "Enter the value of k to be added : ";
	cin >> k;	
	y = h + k;	
	cout << h << "(octal) + " << k << "(decimal) = " << y << "(decimal)" << endl;
	return 0; 
	
}
