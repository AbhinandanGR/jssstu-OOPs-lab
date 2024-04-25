#include<iostream>
using namespace std;

class date{
	int dd, mm, yy;
	public:
		void getdate();
		int operator -(date);
		date operator +(int);
};

void date :: getdate(){
	cout << "Enter the valid date (dd mm yyyy) : ";
	start:
	cin >> dd >> mm >> yy;
	
	if((mm == 2) && (dd > 28)){
		cout << "Wrong input!!" << endl;
		cout << "Enter the date again : ";
		goto start;
	}
	if((mm > 12) || (dd > 31)){
		cout << "Wrong input!!" << endl;
		cout << "Enter the date again : ";
		goto start;
	}
	if ((mm==4||mm==6||mm==9||mm==11) && (dd > 30)){
		cout << "Wrong input!!" << endl;
		cout << "Enter the date again : ";
		goto start;
	}
	if((yy%4 != 0) && (mm == 2) && (dd > 28)){
		cout << "Wrong input!!" << endl;
		cout << "Enter the date again : ";
		goto start;
	}
}

int date :: operator -(date d2){
	int i, nod1, nod2, noly, lc, no_of_days;
	nod1 = nod2 = lc = 0;
	for(i = 0; i < mm; i++){
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
			nod1+=31;
		else if(i == 2)
			nod1+=28;
		else
			nod1+=30;
	}
	nod1+=dd;
	for(i = 0; i < d2.mm; i++){
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
			nod2+=31;
		else if(i == 2)
			nod2+=28;
		else
			nod2+=30;
	}
	nod2+=d2.dd;
	
	noly = (yy - d2.yy)*365;
	for(i = d2.yy; i < yy; i++)
		if(i%4 == 0)
			lc++;
	
	int y4 = yy - d2.yy;
	while(y4 > 400){
		lc++;
		y4-=400;
	}
	
	if((mm > 2) && (yy%4 == 0))
		lc++;
	if((d2.mm > 2) && (d2.yy%4==0))
		lc--;
	no_of_days = nod1 + noly - nod2 + lc;
	if(no_of_days > 0){
		cout << "Number of days between these dates is " ;
		return no_of_days;
	}	
	else
		return no_of_days;
}

date date :: operator +(int nd){
	date dd3;
	while(nd > 365){
		yy++;
		nd-=365;
	}
	while(nd > 30){
		if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12){
			mm++;
			nd-=31;
		}
		else if (mm == 2){
			mm++;
			nd -=28;
		}
		else{
			mm++;
			nd -=30;
		}
		if(mm > 12){
			yy++;
			mm = 1;
		}
	}
	dd = dd + nd;
	if(dd > 30){
		if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12){
			mm++;
			dd-=31;
		}
		else if (mm == 2){
			mm++;
			dd -=28;
		}
		else{
			mm++;
			dd -=30;
		}
		if(mm > 12){
			yy++;
			mm = 1;
		}
	}
	dd3.dd = dd;
	dd3.mm = mm;
	dd3.yy = yy;
	cout << "New date is : ";
	cout << dd << "-" << mm << "-" << yy;
	return dd3; 	

}

int main(){
	int res, num;
	date dd1, dd2;
	
	begin:
		dd1.getdate();
		dd2.getdate();
		res = dd1 - dd2;
		
	if(res < 0){
		cout<<"The first date should be greater than the second date\n";
      		cout<<"So enter the dates again\n";
      		goto begin;
	} 
	cout << res << endl;
	cout << "Enter no of days to be added to first date : ";
	cin >> num;
	dd2 = dd1 + num;
	cout << endl;
	return 0;
}







