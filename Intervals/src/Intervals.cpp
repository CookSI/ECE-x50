//============================================================================
// Name        : Intervals.cpp
// Author      : Albert Ndur-Osei
//============================================================================

#include <iostream>
#include <algorithm>
#include <math.h>

double interval_calculator();
int main();

double interval_calculator() {
	std::string operation{}; double entry1{}; double entry2{};//The possible inputs from the user
	double value1{}; double value2{}; double value1_stored{}; double value2_stored{}; bool initalized{false}; bool storage_initalized{false}; //Immediate Interval and Stored Interval
		while(operation != "exit") {
			std::cout <<"input :> ";
			std::cin >> operation;
//Enter Operation
				if(operation == "enter") {
				std::cin >> entry1 >> entry2;
					if(entry1>entry2) {
						std::cout <<"Error: invalid interval as"<< entry1 << " > " << entry2 <<std::endl;
						if(initalized) {
							std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
						}else{
							std::cout << "--" << std::endl;
						}

					}else{
						value1 = entry1;
						value2 = entry2;
						std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;\
						initalized = true;
				}
			}else if(operation == "negate"){
				if(initalized) {
					double value1_negate = value1*-1;
					double value2_negate = value2*-1;
					value1 = value2_negate;
					value2 = value1_negate;
					std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;

				}else{
					std::cout << "--" << std::endl;
				}
			}else if(operation == "invert"){
				if((initalized)&&((value1<0 && value2<0) || (value1>0 && value2>0))){
					double value1_invert = 1/value1;
					double value2_invert = 1/value2;
					value1 = value2_invert;
					value2 = value1_invert;
					std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;

				}else if((initalized)&&((value1>0 && value2<0) || (value1<0 && value2>0))){
					std::cout << "Error: division by zero" << std::endl;
					value1 = 0;
					value2 = 0;
					initalized = false;
					std::cout << "--" << std::endl;
				}else if(!(initalized)){
					std::cout << "--" << std::endl;
				}
			}else if(operation == "ms"){
				if(initalized){
					value1_stored = value1;
					value2_stored = value2;
					std::cout << "["<< value1_stored << ", "<< value2_stored <<"]"<<std::endl;
					storage_initalized = true;

				}else{
					std::cout << "--" << std::endl;
				}
			}else if(operation == "mr"){
				if(storage_initalized){
					value1 = value1_stored;
					value2 = value2_stored;
					std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
					initalized = true;
				}else if(initalized){
					std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
				}else if(!initalized){
					std::cout << "--" << std::endl;
				}
			}else if(operation == "m+"){
				if((storage_initalized)&&(initalized)){
					value1_stored = value1_stored + value1;
					value2_stored = value2_stored + value2;
					std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
				}else if(!(initalized)){
					std::cout << "--" << std::endl;
				}
			}else if(operation == "mc"){
				storage_initalized = false;
				if(initalized){
						std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
				}else if(!initalized){
						std::cout << "--" << std::endl;
				}

			}else if(operation == "m-"){
				if((storage_initalized)&&(initalized)){
					value1_stored = value1_stored - value1;
					value2_stored = value2_stored - value2;

				}else if(!initalized){
					std::cout << "--" << std::endl;
				}
			}else if(operation == "scalar_add") { //scalar_add
				std::cin >> entry1;
				if(initalized){
					value1 = value1 + entry1;
					value2 = value2 + entry1;
					std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
				}else{
					std::cout << "--" << std::endl;
				}
			}else if(operation == "scalar_subtract") { //scalar_subtract
				std::cin >> entry1;
				if(initalized){
					value1 = value1 - entry1;
					value2 = value2 - entry1;
					std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
				}else{
					std::cout << "--" << std::endl;
				}
			}else if(operation == "scalar_multiply"){  //scalar_multiply
				std::cin >> entry1;
				if(initalized){
					double value1Xentry1 = value1*entry1;
					double value2Xentry1 = value2*entry1;
					if(entry1 > 0){
						value1 = value1*entry1;
						value2 = value2*entry1;
					}else if(entry1 <= 0){
						value1 = value2Xentry1;
						value2 = value1Xentry1;
					}
					std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
				}else{
					std::cout << "--" << std::endl;
				}
			}else if(operation == "scalar_divide"){
					std::cin >> entry1;
					if(initalized){
						double value1Xentry1 = value1/entry1;
						double value2Xentry1 = value2/entry1;
						if(entry1 == 0){
							std::cout << "Error: division by zero" << std::endl;
							std::cout << "--" << std::endl;
							value1 = 0;
							value2 = 0;
							initalized = false;
						}else if(entry1 > 0){
							value1 = value1/entry1;
							value2 = value2/entry1;
							std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
						}else if(entry1 < 0){
							value1 = value2Xentry1;
							value2 = value1Xentry1;
							std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
						}
					}else{
						std::cout << "--" << std::endl;
					}
				}else if(operation == "scalar_divided_by"){
					std::cin >> entry1;
					if(initalized){
						double value1Xentry1 = entry1/value1;
						double value2Xentry1 = entry1/value2;

						if(value1 > 0 && value2 > 0){
							value1 =  value1Xentry1;
							value2 =  value2Xentry1 ;
							std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
						}else if(value1 < 0 && value2 < 0){
							value1 = value2Xentry1;
							value2 = value1Xentry1;
							std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
						}else if((value1 <= 0 && value2 >= 0) || (value1 >= 0 && value2 <= 0)){
							std::cout << "Error: division by zero" << std::endl;
							std::cout << "--" << std::endl;
							value1 = 0;
							value2 = 0;
							initalized = false;
						}
					}else{
						std::cout << "--" << std::endl;
					}
				}else if(operation == "interval_add"){
					std::cin >> entry1 >> entry2;
						if(entry1>entry2){
							std::cout <<"Error: invalid interval as"<< entry1 << " > " << entry2 <<std::endl;
							if(initalized){
								std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
							}else{
								std::cout << "--" << std::endl;
							}
						}else{
							if(initalized){
								value1 = value1 + entry1;
								value2 = value2 + entry2;
								std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
							}else{
								std::cout << "--" << std::endl;
							}

						}

				}else if(operation == "interval_subtract") {
					std::cin >> entry1 >>entry2;
					if(entry1>entry2){
						std::cout <<"Error: invalid interval as"<< entry1 << " > " << entry2 <<std::endl;
						if(initalized){
							std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
						}else{
							std::cout << "--" << std::endl;
						}
					}else{
						if(initalized){
							value1 = value1 - entry2;
							value2 = value2 - entry1;
							std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
						}else{
							std::cout << "--" << std::endl;
						}
					}
				}else if(operation == "interval_multiply"){
					std::cin >> entry1 >> entry2;
					if(entry1>entry2){
						std::cout <<"Error: invalid interval as"<< entry1 << " > " << entry2 <<std::endl;
						if(initalized){
							std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
						}else{
							std::cout << "--" << std::endl;
						}
					}else{
						if(initalized){
							double value1Xentry1 = value1*entry1;
							double value1Xentry2 = value1*entry2;
							double value2Xentry1 = value2*entry1;
							double value2Xentry2 = value2*entry2;
							double min1{0};
							double min2{0};
							double values[4]{value1Xentry1,value1Xentry2,value2Xentry1,value2Xentry2};
							for(std::size_t i{0}; i <= 2; i++){
								if(values[i] > values[i+1]){
									value2 = values[i];
								}else if(values[i] < values[i+1]){
									value2 = values[i+1];
								}
							}
							min1 = std::min(value1Xentry1,value1Xentry2);
							min2 = std::min(value2Xentry1,value2Xentry2);
							value1 = std::min(min1,min2);
							std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
						}else{
							std::cout << "--" << std::endl;
						}
					}
				}else if(operation == "interval_divide"){
					std::cin >> entry1 >> entry2;
					if(entry1>entry2){
						std::cout <<"Error: invalid interval as"<< entry1 << " > " << entry2 <<std::endl;
						if(initalized){
							std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
						}else{
							std::cout << "--" << std::endl;
						}
					}else if(entry1 <= 0 && entry2 >= 0){
						std::cout << "Error: division by zero" << std::endl;
						std::cout << "--" << std::endl;
						value1 = 0;
						value2 = 0;
						initalized = false;

					}else{
						if(initalized){
							double value1Xentry1 = value1/entry1;
							double value1Xentry2 = value1/entry2;
							double value2Xentry1 = value2/entry1;
							double value2Xentry2 = value2/entry2;
							double min1{0};
							double min2{0};
							double values[4]{value1Xentry1,value1Xentry2,value2Xentry1,value2Xentry2};
							for(std::size_t i{0}; i <= 2; i++){
								if(values[i] > values[i+1]){
									value2 = values[i];
								}else if(values[i] < values[i+1]){
									value2 = values[i+1];
								}
							}
							min1 = std::min(value1Xentry1,value1Xentry2);
							min2 = std::min(value2Xentry1,value2Xentry2);
							value1 = std::min(min1,min2);
							std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
						}else{
							std::cout << "--" << std::endl;
						}
					}
				}else if(operation == "intersect"){
					std::cin >> entry1 >> entry2;
					if(entry1>entry2){
						std::cout <<"Error: invalid interval as"<< entry1 << " > " << entry2 <<std::endl;
						if(initalized){
							std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
						}else{
							std::cout << "--" << std::endl;
						}
					}else{
						if(initalized){
							if(entry1 > value1 && entry1 < value2){
								value1 = entry1;
							}
							if(entry2 > value1 && entry2 < value2){
								value2 = entry2;
							}
							std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
							if(!(entry1 > value1 && entry1 < value2) && !(entry2 > value1 && entry2 < value2)){
								value1 = 0;
								value2 = 0;
								initalized = false;
							}
						}else{
							std::cout << "--" << std::endl;
						}
					}
				}else if(operation == "integers"){
					if(initalized){
						double first = ceil (value1);
						double last = floor (value2);
						while(first <= last){
							if(first < last){
								std::cout << first <<  ", " ;
							}else if(first == last){
								std::cout << first<< std::endl;
							}
							++first;
						}
						std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
					}else{
						std::cout << "--" << std::endl;
					}
				}else if(operation == "cartesian_integers"){
					std::cin >> entry1 >> entry2;
					if(entry1>entry2){
						std::cout <<"Error: invalid interval as"<< entry1 << " > " << entry2 <<std::endl;
						if(initalized){
							std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
						}else{
							std::cout << "--" << std::endl;
						}
					}else if(initalized){
						double value_first = ceil (value1);
						double value_last = floor (value2);
						double entry_first = ceil (entry1);
						double entry_last = floor (entry2);

						if(entry1 > value2){
							std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
						}else{
							while(value_first <= value_last){
								while(entry_first <= entry_last){
									std::cout << "(" << value_first <<", " << entry_first;
									if((value_first < value_last) || (entry_first < entry_last)){
										std::cout<<"), ";
									}else if((value_first == value_last) && (entry_first == entry_last)){
										std::cout<<")";
									}
									++entry_first;
								}
							entry_first = ceil (entry1);
							++value_first;
							}
							std::cout<<std::endl;
							std::cout << "["<< value1 << ", "<< value2 <<"]"<<std::endl;
						}
					}else if(!initalized){
						std::cout << "--" << std::endl;
					}


				}else{
					if(operation != "exit"){
						std::cout << "Error: illegal command" << std::endl;
					}
				}
		}
		std::cout <<"Bye bye: Terminating interval calculator program.";
	return 0;
}

int main() {
		interval_calculator();
		return 0;
}
