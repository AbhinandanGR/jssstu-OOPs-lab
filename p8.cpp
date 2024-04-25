#include<iostream>
using namespace std;

class matrix{
	int r, c, a[10][10];
	public:
		matrix(int x, int y){
			r = x;
			c = y;
		}
		void getMatrix();
		int operator ==(matrix);
		matrix operator +(matrix);
		matrix operator -(matrix);
		friend ostream &operator <<(ostream&, matrix&);
};

void matrix :: getMatrix(){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout << "[ " << i << ", " << j <<"] : ";
			cin >> a[i][j];
		}
	}
}

int matrix :: operator ==(matrix m1){
	if(m1.r == r && m1.c == c)
		return 1;
	return 0;
}

matrix matrix :: operator +(matrix m1){
	matrix m2(r, c);
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++)
			m2.a[i][j] = a[i][j] + m1.a[i][j];
	}
	return m2;
}

matrix matrix :: operator -(matrix m1){
	matrix m2(r, c);
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++)
			m2.a[i][j] = a[i][j] - m1.a[i][j];
	}
	return m2;
}

ostream &operator<<(ostream &print, matrix &res){
	for(int  i = 0; i < res.r; i++){
		for(int j = 0; j < res.c; j++){
			print << "\t" << res.a[i][j] << " ";
		}
		print << endl;
	}
	return print;
}

int main(){
	int m, n, p, q;
	
	cout << "\nEnter the order of the first matrix : ";
	cin >> m >> n;
	matrix m1(m, n);
	
	cout << "Enter the order of the second matrix : ";
	cin >> p >> q;
	matrix m2(p, q);
	
	if(m1 == m2){
		cout << "Enter the elements into first matrix : " << endl;
		m1.getMatrix();
		
		cout << "Enter the elements into second matrix : " << endl;
		m2.getMatrix();
		
		matrix m3(m, n), m4(m, n);
		
		m3 = m1 + m2;
		m4 = m1 - m2;
		
		cout << "Addtion of two matrix is : " << endl;
		cout << m1 << " + " << m2 << " = " << m3 << endl;
		cout << "Subtration of two matrix is : " << endl;
		cout << m1 << " - " << m2 << " = " << m4 << endl;
	}
	else
		cout << "The matrix is incompatible!!" << endl;
	
	
	return 0;
}





