//============================================================================
// Name        : Classes.cpp
// Author      : Albert Ndur-Osei
// Version     :
// Copyright   : 
// Description :
//============================================================================

#include <iostream>
#include <algorithm>
struct hex{
	char digit1{'0'};
	char digit2{'0'};
};

hex deci_hex(int num);
hex deci_hex(int num){
	hex r_hex;
	double result{0};
	double remainder{num};

	while(remainder > 0 && remainder >= 16){
		remainder = remainder - 16.00 ;
		++result;
	}
	remainder *= (remainder < 0)? -1: 1;
	r_hex.digit2 = char((int)remainder + '0');
	r_hex.digit1 = char((int)result + '0');
	switch((int)remainder){
		case 10: r_hex.digit2 = 'A';
				break;
		case 11: r_hex.digit2 = 'B';
				break;
		case 12: r_hex.digit2 = 'C';
				break;
		case 13: r_hex.digit2 = 'D';
				break;
		case 14: r_hex.digit2 = 'E';
				break;
		case 15: r_hex.digit2 = 'F';
				break;
	}
	switch((int)result){
		case 10: r_hex.digit1 = 'A';
				break;
		case 11: r_hex.digit1 = 'B';
				break;
		case 12: r_hex.digit1 = 'C';
				break;
		case 13: r_hex.digit1 = 'D';
				break;
		case 14: r_hex.digit1 = 'E';
				break;
		case 15: r_hex.digit1 = 'F';
				break;
	}
	return r_hex;


}
char * hexcolor(int red, int green, int blue);
char * hexcolor(int red, int green, int blue){
	char * hexcode{new char[8]{'#','0','0','0','0','0','0','\0'}};

	hex hex_red {deci_hex(red)};
		hexcode[1] = hex_red.digit1;
		hexcode[2] = hex_red.digit2;
	hex hex_green {deci_hex(green)};
		hexcode[3] = hex_green.digit1;
		hexcode[4] = hex_green.digit2;
	hex hex_blue {deci_hex(blue)};
		hexcode[5] = hex_blue.digit1;
		hexcode[6] = hex_blue.digit2;
	return hexcode;
}

char *blend(char *color1, char *color2);
char *blend(char *color1, char *color2){

}

int main(){
	char * p_code = hexcolor(255,99,71);
	for(std::size_t i; i < 7; ++i){
		std::cout<<p_code[i];
	}
	delete[] p_code;
	p_code = nullptr;

}
