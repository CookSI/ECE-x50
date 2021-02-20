//============================================================================
// Name        : Polynomial.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include "Polynomial.h"

void init_poly(poly_t &p, double const init_coeffs[], unsigned int const init_degree) {
	destroy_poly(p);

	p.degree = init_degree;
	p.a_coeffs = new double[p.degree + 1];
	for(int i=0;i<=p.degree;i++)
	{
		p.a_coeffs[i] = init_coeffs[i];
	}
}

void destroy_poly(poly_t &p) {
	if (p.a_coeffs != nullptr){
		delete[] p.a_coeffs;
		p.a_coeffs=nullptr;
	}

	p.degree = 0;
}

unsigned int poly_degree(poly_t const &p) {
    if(&p==nullptr)
        return 0;
    else
        return p.degree;
}

double poly_coeff(poly_t const &p, unsigned int n) {
    if(&p==nullptr)
        return 0;
    else if (n>p.degree)
        return 0;
    else
        return p.a_coeffs[n];
}

double poly_val(poly_t const &p, double const x) {
	if (p.a_coeffs == nullptr) return 0;

	double val = 0;

	for (int i = 0; i <= p.degree; i++) {
		val += p.a_coeffs[i] * pow(x, i);
	}

	return val;
}

void poly_add(poly_t &p, poly_t const &q) {
	if (p.a_coeffs == nullptr || q.a_coeffs == nullptr) throw 0;


	int new_degree = p.degree >= q.degree ? p.degree : q.degree;
	double* new_coeffs = new double[new_degree+1];

	for (int i = 0; i <= new_degree; i++) {
		if (i > p.degree) new_coeffs[i] = q.a_coeffs[i];
		else if (i > q.degree) new_coeffs[i] = p.a_coeffs[i];
		else new_coeffs[i] = q.a_coeffs[i] + p.a_coeffs[i];
	}

	for (int i = new_degree; i >= 0; i--) {
		if (new_coeffs[i] != 0) {
			new_degree = i;
			break;
		}
	}

	init_poly(p, new_coeffs, new_degree);

	delete[] new_coeffs;
}

void poly_subtract(poly_t &p, poly_t const &q) {
	if (p.a_coeffs == nullptr || q.a_coeffs == nullptr) throw 0;

	int new_degree = p.degree >= q.degree ? p.degree : q.degree;
	double* new_coeffs = new double[new_degree + 1];

	for (int i = 0; i < new_degree; i++) {
		if (i > p.degree) new_coeffs[i] = -q.a_coeffs[i];
		else if (i > q.degree) new_coeffs[i] = p.a_coeffs[i];
		else new_coeffs[i] = p.a_coeffs[i] - q.a_coeffs[i];
	}

	int highest_degree = 0;
	for (int i = highest_degree; i >= 0; i--) {
		if (new_coeffs[i] != 0) {
			highest_degree = i;
			break;
		}
	}

	init_poly(p, new_coeffs, highest_degree);

	delete[] new_coeffs;
}

void poly_multiply(poly_t &p, poly_t const &q) {
	if (p.a_coeffs == nullptr || q.a_coeffs == nullptr) throw 0;
	int new_degree = p.degree + q.degree;

	double *new_coeffs = new double[p.degree + q.degree + 1];

	for (int i = 0; i <= p.degree; i ++) {
		for (int j = 0; j <= q.degree; j++) {
			new_coeffs[i] += p.a_coeffs[i] * q.a_coeffs[j];
		}
	}

	destroy_poly(p);
	init_poly(p, new_coeffs, new_degree);
	delete[] new_coeffs;
}

double poly_divide(poly_t &p, double r){
    if(p.a_coeffs == nullptr) throw 0;
    if(p.degree == 0)
    	return p.a_coeffs[0];

    double remainder = 0;

    for(int i = p.degree; i >= 0; i --){
        remainder += p.a_coeffs[i];
        remainder *= -r;
    }

    return remainder;
}

void poly_diff(poly_t &p){
    if(p.a_coeffs == nullptr) throw 0;

    if(p.degree == 0)
    	init_poly(p, new double[1], 0);
    else{
        double* new_coeffs = new double[p.degree];
        for(int i = 1; i <= p.degree; i++){
            new_coeffs[i] = p.a_coeffs[i] * i;
        }
        init_poly(p, new_coeffs, p.degree - 1);
        delete[] new_coeffs;
    }
}


double poly_approx_int(poly_t const &p, double a, double b, unsigned int n){
    if(p.a_coeffs == nullptr) throw 0;

    double area = 0;

    for(double i = a; i <= b; i+= (b-a)/n){
        if(i == a || i >=b)
        	area += poly_val(p, i);
        else
        	area += poly_val(p, i)*2;
    }

    return area * ((b-a)/n);
}

int main();
int main(){
	poly_t one{nullptr,0};
	poly_t two{nullptr,0};
	double my_array[]{0,0,0,0,0};
	double your_array[]{0,0,0,0,0};
	init_poly(one,my_array,4);
	init_poly(two,your_array,4);
	for(std::size_t i{0}; i <= one.degree; ++i){
		std::cout<<one.a_coeffs[i]<<",";
	}
	std::cout<<std::endl;
	for(std::size_t i{0}; i <= two.degree; ++i){
				std::cout<<two.a_coeffs[i]<<",";
	}
	std::cout<<std::endl;


	poly_subtract(one, two);
	//poly_add(one,two);
	//poly_diff(one);
	for(std::size_t i{0}; i <= one.degree; ++i){
			std::cout<<one.a_coeffs[i]<<",";
		}
	std::cout<<"\n"<<poly_degree(one);
	//destroy_poly(one);
	//destroy_poly(two);
		return 0;
	}
