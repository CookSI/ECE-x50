//============================================================================
// Name        : Polynomial.cpp
// Author      : Albert Ndur-Osei
// Version     :
// Description : Polynomial Math
//============================================================================

#include <iostream>
#ifndef MARMOSET_TESTING
int main();
#endif


struct poly_t	{
	double *a_coeffs;		//array of coefficents
	unsigned int degree;	//the degree of the polynomial
};

void init_poly(poly_t &p, double const init_coeffs[], unsigned int const init_degree);
void init_poly(poly_t &p, double const init_coeffs[], unsigned int const init_degree)
{
	if(p.a_coeffs == nullptr)
	{
		p.degree = init_degree;
		p.a_coeffs = new double[p.degree + 1];
		for (std::size_t k{0}; k <= p.degree; ++k)
		{
			p.a_coeffs[k] = init_coeffs[k];
		}
	}else{
		delete[] p.a_coeffs;
		p.degree = init_degree;
		p.a_coeffs = new double[p.degree + 1];
		for (std::size_t k{0}; k <= p.degree; ++k)
		{
			p.a_coeffs[k] = init_coeffs[k];
		}
	}
}

void destroy_poly(poly_t &p);
void destroy_poly(poly_t &p)
{
	delete[] p.a_coeffs;
	p.a_coeffs = nullptr;
	p.degree = 0;
}

unsigned int poly_degree(poly_t const &p);
unsigned int poly_degree(poly_t const &p)
{
	if(p.a_coeffs == nullptr){
		throw 0;
	}else{
		return p.degree;
	}
}

double poly_coeff(poly_t const &p, unsigned int n);
double poly_coeff(poly_t const &p, unsigned int n)
{
	if(p.a_coeffs == nullptr){
		throw 0;
	}else{
		return p.a_coeffs[n];
	}
}

double poly_val(poly_t const &p, double const x);
double poly_val(poly_t const &p, double const x)
{
	if(p.a_coeffs == nullptr){
		throw 0;
	}else{
		double value{0};
		for(std::size_t i {p.degree+1}; i > 0; --i){
			value = p.a_coeffs[i - 1] + (x*value);
		}
		return value;
	}
}
void poly_add(poly_t &p, poly_t const &q);
void poly_add(poly_t &p, poly_t const &q){

	if(p.a_coeffs == nullptr || q.a_coeffs == nullptr){
		throw 0;
	}else{
		unsigned int res_degree{0};
		//Adding polynomials
		if(q.degree <= p.degree)
		{
			res_degree = p.degree;
			double  *res_poly{new double[res_degree+1]};
			for(std::size_t i {0}; i <= res_degree; ++i){
				res_poly[i] = 0;
			}
			for(std::size_t index{0}; index <= p.degree; ++index){
				if(index <= q.degree){
					res_poly[index] = p.a_coeffs[index] + q.a_coeffs[index];
				}else{
					res_poly[index] = p.a_coeffs[index];
				}
			}
			for(std::size_t index{res_degree}; index >= 0; --index)
			{
				if(res_poly[index] == 0){
					res_degree -= 1;
				}else{
					break;
				}
			}
			// Replacing old array

			delete[] p.a_coeffs;
			p.a_coeffs = res_poly;
			res_poly = nullptr;
			p.degree = res_degree;


		}
		else if(q.degree > p.degree)
		{
			res_degree = q.degree;
			double  *res_poly{new double[res_degree + 1]};
			for(std::size_t i {0}; i <= res_degree; ++i){
				res_poly[i] = 0;
			}

			for(std::size_t index{0}; index <= q.degree; ++index)
			{
				if(index <= p.degree){
					res_poly[index] = q.a_coeffs[index] + p.a_coeffs[index];
				}else{
					res_poly[index] = q.a_coeffs[index];
				}
			}
			for(std::size_t index{res_degree}; index > 0; --index)
			{
				if(res_poly[index] == 0){
					res_degree -= 1;
				}else{
					break;
				}
			}
			// Replacing old array

			delete[] p.a_coeffs;
			p.a_coeffs = res_poly;
			res_poly = nullptr;
			p.degree = res_degree;

		}
	}
}
void poly_subtract(poly_t &p, poly_t const &q);
void poly_subtract(poly_t &p, poly_t const &q){

if(p.a_coeffs == nullptr || q.a_coeffs == nullptr){
	throw 0;
}else{
	unsigned int res_degree{0};
	if(q.degree <= p.degree)
	{
		res_degree = p.degree;
		double  *res_poly{new double[res_degree + 1]};
		for(std::size_t i {0}; i <= res_degree; ++i){
			res_poly[i] = 0;
		}
		for(std::size_t index{0}; index <= p.degree; ++index){
			if(index <= q.degree){
				res_poly[index] = p.a_coeffs[index] - q.a_coeffs[index];
			}else{
				res_poly[index] = p.a_coeffs[index];
			}
		}
		for(std::size_t index{res_degree}; index >= 0; --index)
		{
			if(res_poly[index] == 0){
				res_degree -= 1;
			}else{
				break;
			}
		}
		// Replacing old array

		delete[] p.a_coeffs;
		p.a_coeffs = res_poly;
		res_poly = nullptr;
		p.degree = res_degree;


	}
	else if(q.degree > p.degree)
	{
		res_degree = q.degree;
		double  *res_poly{new double[res_degree + 1]};
		for(std::size_t i {0}; i <= res_degree; ++i){
			res_poly[i] = 0;
		}

		for(std::size_t index{0}; index <= q.degree; ++index)
		{
			if(index <= p.degree){
				res_poly[index] = p.a_coeffs[index] - q.a_coeffs[index];
			}else{
				res_poly[index] = -q.a_coeffs[index] ;
			}
		}
		for(std::size_t index{res_degree}; index > 0; --index)
		{
			if(res_poly[index] == 0){
				res_degree -= 1;
			}else{
				break;
			}
		}
		// Replacing old array

		delete[] p.a_coeffs;
		p.a_coeffs = res_poly;
		res_poly = nullptr;
		p.degree = res_degree;

	}
}

}
void poly_multiply(poly_t &p, poly_t const &q);
void poly_multiply(poly_t &p, poly_t const &q){
	if(p.a_coeffs == nullptr || q.a_coeffs == nullptr){
		throw 0;
	}else{
		unsigned int res_degree = p.degree + q.degree;
		double *res_poly{new double[res_degree + 1]};
		for(std::size_t index {0}; index <= res_degree; ++index){
					res_poly[index] = 0;
		}
		if(p.degree >= q.degree){
			for(std::size_t i{0}; i <= p.degree; ++i){
				for(std::size_t j{0}; j <= p.degree; ++j){
					res_poly[i+j] = res_poly[i+j] + p.a_coeffs[i] * q.a_coeffs[j];
				}
			}
		}else{
			for(std::size_t i{0}; i <= q.degree; ++i){
				for(std::size_t j{0}; j <= q.degree; ++j){
					res_poly[i+j] = res_poly[i+j] + p.a_coeffs[i] * q.a_coeffs[j];
				}
			}

		}

		// Replacing old array
		for(std::size_t index{res_degree}; index > 0; --index)
			{
				if(res_poly[index] == 0){
					res_degree -= 1;
				}else{
					break;
				}
			}

		delete[] p.a_coeffs;
		p.a_coeffs = res_poly;
		res_poly = nullptr;
		p.degree = res_degree;

	}
}
double poly_divide(poly_t &p, double r);
double poly_divide(poly_t &p, double r){
	if(p.a_coeffs == nullptr){
			throw 0;
		}else{

		if(p.degree == 0){
			double result =  p.a_coeffs[0];
			p.a_coeffs[0] = 0;
			 return result;
		}
		double result = r * p.a_coeffs[p.degree];
		double *result_poly{new double[p.degree]};
		result_poly[p.degree - 1] = p.a_coeffs[p.degree];
		for(std::size_t index{p.degree}; index > 0; --index){
			result = result + p.a_coeffs[index - 1];
			if(index > 1){
			 result_poly[index - 2] = result;
			 result = result * r;
			}
		}
		delete[] p.a_coeffs;
		p.a_coeffs = result_poly;
		delete[] result_poly;
		result_poly = nullptr;
		p.degree = p.degree-1;

		return result;
		}
}
void poly_diff( poly_t &p );
void poly_diff( poly_t &p ){
	if(p.a_coeffs == nullptr){
		throw 0;
	}else{
		if(p.degree == 0){
			p.a_coeffs[0] = 0;
		}else{
			double *deriv{new double[p.degree]};

			for(std::size_t index{0}; index < p.degree; ++index){
				deriv[index] = p.a_coeffs[index + 1]*(index + 1);
			}
			delete[] p.a_coeffs;
			p.a_coeffs = deriv;
			delete[] deriv;
			deriv = nullptr;
			p.degree = p.degree - 1;

		}
	}
}

double poly_approx_int( poly_t const &p, double a, double b, unsigned int n );
double poly_approx_int( poly_t const &p, double a, double b, unsigned int n ){
	if(p.a_coeffs == nullptr){
		throw 0;
	}else{
		double sum{0}, top{0}, bottom{0}, area{0};
		double h = (b-a)/n;
		for(std::size_t i{0}; i < n; ++i){
			top = poly_val(p, a + (i*h) );
			bottom = poly_val(p, a + (i+1)*h);
			area = ((top+bottom)/2)/h;
			sum += area;
		}
		return sum;
	}
}

#ifndef	MARMOSET_TESTING
int main() {
}
#endif
