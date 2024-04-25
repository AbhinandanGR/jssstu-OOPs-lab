#include<iostream>
using namespace std;

template<class T>
void swapping(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
int partition(T arr[], int low, int high){
	T pivot = arr[low];
	int i = low;
	int j = high;
	while(i < j){
		while(arr[i] <= pivot && i < high)
			i++;
		while(arr[j] > pivot && j > low)
			j--;
		if(i<j)
			swapping(arr[i], arr[j]);
	}
	swapping(arr[low], arr[j]);
	return j;
}

template<class T>
void quickSort(T arr[], int low, int high){
	if(low < high){
		int p = partition(arr, low, high);
		quickSort(arr, low, p-1);
		quickSort(arr, p+1, high);
	}
}
 
int main(){
	int choice, size, A[100];
	double B[100];
	
	cout << "\nChoose the data type to sort : ";
	cout << "\n1.Integers\n2.Double" << endl;
	cin >> choice;
	
	cout << "Enter the size of the array : ";
	cin >> size;
	
	switch(choice){
		case 1 : cout << "Enter " << size << " integers : " << endl;
			 for(int i = 0; i < size; i++)
			 	cin >> A[i];
			 
			 quickSort(A, 0, size-1);
			 
			 cout << "Sorted elements : " << endl;
			 for(int i = 0; i < size; i++)
			 	cout << A[i] << " ";
			 cout << endl;
			 break;
			 
		case 2 : cout << "Enter " << size << " double : " << endl;
			 for(int i = 0; i < size; i++)
			 	cin >> B[i];
			 
			 quickSort(B, 0, size-1);
			 
			 cout << "Sorted elements : " << endl;
			 for(int i = 0; i < size; i++)
			 	cout << B[i] << " ";
			 cout << endl;
			 break;
		
		default : cout << "Invalid choice!!" << endl;
	}
	
	return 0;
}





