//============================================================================
// Name        : Lab.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
int max(int data[], std::size_t capacity);
int max(int data[], std::size_t capacity)	{
	int maximum{0};
	for(int i; i < capacity; ++i){
		if(data[i] > data[i+1]){
			maximum = data[i];
		}else{
			maximum = data[i+1];
		}
	}
	return maximum;
}
int main() {
	int array[]{1,2,3,4,5,6,7};
	max(array, 6);
}
