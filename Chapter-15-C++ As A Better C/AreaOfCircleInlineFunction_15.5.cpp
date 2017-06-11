#include <iostream>
using namespace std;

#define PI 3.14
#define SQUARE(x) x * x
inline double CircleArea(int radius);

int main(){
	int r;
	cout<<endl<<"Enter your choice (in cm) :";
	cin>> r;

	double area = CircleArea(r);
	cout<<endl<<"Area of circle : "<<area<<endl;
}

inline double CircleArea(int radius){
	return PI * SQUARE(radius);
}