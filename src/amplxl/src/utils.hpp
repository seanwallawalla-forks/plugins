#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <math.h>


bool double_is_int(double val);

// simple replacement for the to_string function since we are building for -std=c++03 
template <class T>
std::string numeric_to_string(T num){
	std::stringstream strs;
	strs << std::setprecision(std::numeric_limits<T>::digits10) << num;
	return strs.str();
};


// Convert a numeric value to a string with scientific notation in order not to lose precision when
// writing very large and very small numbers
template <class T>
std::string numeric_to_scientific(T num){
	std::stringstream strs;
	strs << std::uppercase << std::scientific << std::setprecision(std::numeric_limits<T>::digits10+1) << num;
	//~ strs << std::scientific << std::setprecision(std::numeric_limits<T>::digits10+1) << num;
	return strs.str();
};


// convert numeric to string with ndecdig decimal digits
// will be used mostly to print cpu times and such
template <class T>
std::string numeric_to_fixed(T num, int ndecdig){
	std::stringstream strs;
	strs << std::fixed << std::setprecision(ndecdig) << num;
	return strs.str();
};


