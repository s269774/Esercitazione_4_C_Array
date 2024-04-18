#pragma once
#include "iostream"

using namespace std;


// ImporData reads the input data from the data file
// inputFilePath: path name of the input file
// S: total sum
// n: number of assets
// w: vector of the fractions
// r: vector of the rates of return of assets
// the result of the reading: true is success, false is error
bool ImportData(const string& inputFilePath,
                double& S,
                size_t& n,
                double*& w,
                double*& r);

// RateOfReturn computes the rate of return of the portfolio and the final amount of wealth
// rateOfReturn: final rate of return of the portfolio
// V: final value of the portfolio
void RateOfReturn(const double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  double& rateOfReturn,
                  double& V);


// ExportData prints data on an output stream
// outputFilePath: path name of the output file
//return the result of the export, true is success, false is error
bool ExportData(const string& outputFilePath,
                const double& S,
                const size_t& n,
                const double* const& w,
                const double* const& r,
                const double& rateOfReturn,
                const double& V);


// Export a vector in a string
// n: size of the vector
// v: vector
// return the resulting string
string ArrayToString(const size_t& n,
                     const double* const& v);
