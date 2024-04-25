#include<iostream>
using namespace std;

class publication{
	public:
		string title;
		publication(){
			title = "IEEEOP";
		}
		void print(){
			cout << "\nTitle : " << title;
		}
};

class book : public publication{
	public:
		float an;
		book(){
			an = 681.3;
		}
		void print(){
			publication :: print();
			cout << "\nAccession number : " << an;
		}
};

class magzine : public publication{
	public:
		int vol;
		magzine(){
			vol = 1;
		}
		void print(){
			cout << "\nVolume : " << vol;
		}
};

class jaurnal : public book, magzine{
	public:
		void print(){
			book :: print();
			magzine :: print();
		}
};

int main(){
	jaurnal IEEEOP;
	IEEEOP.print();
	cout << endl;
	return 0;
}


