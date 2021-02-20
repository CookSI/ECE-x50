#include <iostream>
using namespace std;

int main();

int main(){
	int array[4]{150,108,250,406};
	int *p_array{array};
	for (std::size_t i{0}; i<4; ++i)	{
		std::cout << &p_array[i] <<":"
					<< p_array[i]<< std::endl;
	}
	return 0;
}
