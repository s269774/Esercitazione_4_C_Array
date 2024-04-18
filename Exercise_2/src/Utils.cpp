#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"

using namespace std;

bool ImportData(const string& inputFilePath,
                double& S,
                size_t& n,
                double*& w,
                double*& r)
{
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    string line;
    string FirstPart;
    string wi;
    string ri;
    istringstream W;
    istringstream R;
    int i = 1;

    while(!file.eof())
    {
        //Get S
        if(i==1)
        {
            getline(file, FirstPart, ';'); //skip the part before ;
            getline(file,line);
            istringstream s;
            s.str(line);
            s >> S;
        }

        //Get n
        else if(i==2)
        {
            getline(file,FirstPart, ';');
            getline(file,line);
            istringstream N;
            N.str(line);
            N >> n;
            w = new double[n];
            r = new double[n];
        }

        else if(i==3)
        {
            getline(file,FirstPart);
        }
        //Get w & r
        else if(i>3)
        {
            getline(file,wi, ';');
            getline(file,ri);
            W.str(wi);
            R.str(ri);
            W.clear();
            R.clear();
            W >> w[i-4];
            R >> r[i-4];
        }
        i = i+1;
    }
    file.close();
    return true;
}


void RateOfReturn(const double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  double& rateOfReturn ,
                  double& V)
{
    V=0;
    for (unsigned int i=0; i<n; i++)
        V += (1+r[i])*S*w[i];
    rateOfReturn = (V/S)-1;
}


bool ExportData(const string& outputFilePath,
                const double& S,
                const size_t& n,
                const double* const& w,
                const double* const& r,
                const double& rateOfReturn,
                const double& V)
{

    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }
    else
    {
        file << "S = "<< S << ", n = "<< n<< endl;
        file << "w = "<< ArrayToString(n,w)<< endl;
        file << "r = "<< ArrayToString(n,r)<< endl;
        file <<  "Rate of return of the portfolio: "<< rateOfReturn<< endl;
        file <<  "V: "<< V<< endl;
    }

    file.close();

    return true;
}


string ArrayToString(const size_t& n,
                     const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";
    return toString.str();
}
