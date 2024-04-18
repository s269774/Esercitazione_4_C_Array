#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
    string inputFileName = "./data.csv";
    double S = 0.0;
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;

    if (!ImportData(inputFileName, S, n, w, r))
    {
        cerr<< "Something goes wrong with import"<< endl;
        return -1;
    }

    double rateOfReturn;
    double V;
    RateOfReturn(S, n, w, r, rateOfReturn, V);

    string outputFileName = "./result.txt";
    if (!ExportData(outputFileName, S, n, w, r, rateOfReturn, V))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }
    else
    {
        cout << "S = " << S << ", n = "<< n << endl;
        cout << "w = " << ArrayToString(n,w) << endl;
        cout << "r = " << ArrayToString(n,r) << endl;
        cout <<  "Rate of return of the portfolio: " << rateOfReturn<< endl;
        cout <<  "V: " << V << endl;
    }

    delete[] w;
    delete[] r;

    return 0;
}
