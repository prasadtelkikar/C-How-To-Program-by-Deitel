#include <iostream>
using namespace std;

template <class T>
T Maximum(T value1, T value2, T value3){
	if(value1 > value2 && value1 > value3)
		return value1;
	else if(value2 > value1 && value2 > value3)
		return value2;
	else
		return value3;
}

template <class T>
T Minimum(T value1, T value2, T value3){
	if(value1 < value2 && value1 < value3)
		return value1;
	else if(value2 < value1 && value2 < value3)
		return value2;
	else
		return value3;
}

int main(){
	int i_v1, i_v2, i_v3;
	double d_v1, d_v2, d_v3;
	char c_v1, c_v2, c_v3;

	cout<<"Enter three integers: ";
	cin>> i_v1>>i_v2>>i_v3;
	cout<<endl<< "Greatest value :"<<Maximum(i_v1, i_v2, i_v3);
	cout<<endl<< "Smallest value :"<<Minimum(i_v1, i_v2, i_v3);
	cout<<endl<<endl;

	cout<<"Enter three doubles: ";
	cin>> d_v1>>d_v2>>d_v3;
	cout<<endl<< "Greatest value :"<<Maximum(d_v1, d_v2, d_v3);
	cout<<endl<< "Smallest value :"<<Minimum(d_v1, d_v2, d_v3);
	cout<<endl<<endl;

	cout<<"Enter three characters: ";
	cin>> c_v1>>c_v2>>c_v3;
	cout<<endl<< "Greatest value :"<<Maximum(c_v1, c_v2, c_v3);
	cout<<endl<< "Smallest value :"<<Minimum(c_v1, c_v2, c_v3);
	cout<<endl<<endl;	
	return 0;
}