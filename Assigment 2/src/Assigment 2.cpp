#include <iostream>
#include <string>

void illegal_interval(double a, double b);
void illegal_interval(double a, double b){
	if(a>b){
		throw -1;
	}
}
int main() {
	double a {3.0};
	double b{1.0};
	try{
		illegal_interval(a, b);
	}catch(const int exception){
		double tempa = b;
		double tempb = a;
		a = tempa;
		b = tempb;
		std::cout<<tempa<<","<<tempb<<std::endl;
	}
	return 0;
}


