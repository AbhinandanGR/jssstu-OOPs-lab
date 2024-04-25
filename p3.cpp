#include<iostream>
using namespace std;
class complex{
	float real, imag;
	public:
		void getdata(float n1, float n2);
		friend complex add(int num, complex s2);
		friend complex add(complex s1, complex s2);
		friend ostream &operator <<(ostream &output, complex &c);
};
void complex :: getdata(float n1, float n2){
	real = n1;
	imag = n2;
}
complex add(int num, complex s2){
	complex result;
	result.real = num + s2.real;
	result.imag = s2.imag;
	return result;
}
complex add(complex s1, complex s2){
	complex result;
	result.real = s1.real + s2.real;
	result.imag = s1.imag + s2.imag;
	return result;
}
ostream &operator<<(ostream & output, complex &c){
	output << c.real << " + " << c.imag << "i";
	return output;
}
int main(){
	int n1, n2, n3;
	complex c1, c2, c3, c4;	
	cout << "Enter the real and imaginary part of the 1st complex number : ";
	cin >> n1 >> n2;
	c1.getdata(n1, n2);	
	cout << "Enter the real and imaginary part of the 2nd complex number : ";
	cin >> n1 >> n2;
	c2.getdata(n1, n2);	
	cout << "Enter the number to be added to second complex number : ";
	cin >> n3;	
	c3 = add(n3, c2);
	c4 = add(c1, c2);	
	cout << "\nThe sum of two Complex number is : " << endl;
	cout << "\tC1 : " << c1 << endl;
	cout << "\tC2 : " << c2 << endl;
	cout << "\tResult : " << c4 << endl;	
	cout << "\nThe sum of an integer and complex number is : " << endl;
	cout << "\tInteger : " << n3 << endl;
	cout << "\tC2 : " << c2 << endl;
	cout << "\tResult : " << c3 << endl; 
	return 0;
}

