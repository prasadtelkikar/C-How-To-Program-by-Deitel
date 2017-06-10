#include <iostream>
using namespace std;

int SquareByValue(int x);
void SquareByPointer(int* x);
void SquareByReference(int &x);

int main(){
	int x = 2, y =3, z = 4;

	//Square by value

	cout<< "Value of x before square by value =" <<x << endl;
	cout<< "Value returned by SquareByValue function =" << SquareByValue(x)<< endl;
	cout<< "Value of x after square by value function = "<<x<< endl<<endl;
	
	cout<< "Value of y before square by pointer =" <<y << endl;
	SquareByPointer(&y);
	cout<< "Value of y after square by pointer function = "<<y<< endl<<endl;

void SquareByPointer(int* x){
	cout<< "Value of z before square by reference =" <<z << endl;
	SquareByReference(z);
	cout<< "Value of z after square by reference function = "<<z<< endl<<endle;


	return 0;
}

int SquareByValue(int x){
	return (x * x);
}

 	*x *= *x;
}
void SquareByReference(int &z){
	z *= z;
}