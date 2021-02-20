#include <iostream>
#include <cmath>
int pascal_triangle_recursive(int row);
int pascal_triangle_recursive(int row) {
		if(row <= 0) {
			std::cout<<12;
			return (row+1)*(row)/2;
		}else {
			std::cout<<1;
			std::cout<<std::endl;
			--row;
			pascal_triangle_recursive(row);
		}
	return (row+1)*(row)/2;
}

int pascal_triangle(int row);
int pascal_triangle(int row) {
	std::cout<<1<<std::endl;
		row++;
		if (row > 0) {
			for(int n{1}; n != row; n++) {
				std::cout<< 1 << " ";
				int B{1};
				for(int k{0}; k<=n; k++ ) {
					B = (B*(n-k))/(k+1);
					if(B != 0) {
						std::cout<<B<<" ";
					}
				}
			std::cout<<std::endl;
			}
		}

	return 0;
}
#ifndef	MARMOSET_TESTING
int main();
#endif

#ifndef	MARMOSET_TESTING
int main() {
	int row{};
	std::cout<< "Please enter a number of rows:" << std::endl;
	std::cin>> row;
	//pascal_triangle(row);
	pascal_triangle_recursive(row);

}
#endif
