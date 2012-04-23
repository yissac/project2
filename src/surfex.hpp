#ifndef SURFEX_HPP
#define SURFEX_HPP

#include "QList"
#include "QVector"
#include "math.h"

class Surfex {
public:
    Surfex();
    Surfex(int N, int tol);
    Surfex(int _N, double _domainMin=0, double _domainMax=1, int _s=4);
    void setSampleNumber(int _s); //Set the number of sample points per ordinate
    int getSampleNumber();
    void setVariableNumber(int _N); //Set the number of variables expected by mFunction
    int getVariableNumber();

    bool setDefaultDomain(double _domainMin, double _domainMax, int entry=0);
    //Set the min and max values for the domain of each variable (indicate the variable with "entry")
    //Set entry to 0 (or don't specify it at all) to apply the min and max to all variables
    double getDefaultMax(int entry);
    double getDefaultMin(int entry);

    void setPrecision(double _prec); //Set the desired precision for the solutions which are returned
    double getPrecision();
    void setCostTolerance(int _tol); //Set the cost tolerance to be used
    int getCostTolerance();

    void setLiveFeed(bool _feed); //Set whether or not results should be returned while they are found
    bool getLiveFeed();

    QList< QVector<double> > maxima; //A list of all the maxima, stored as QVarLengthArrays
    QList< QVector<double> > minima; //A list of all the minima, stored as QVarLengthArrays

    int maximize();
    int minimize();


private:

    //User-defined settings
    int s;
    int N;
    double prec;
    int tol;
    bool livefeed;
    QList<double> domainMin;
    QList<double> domainMax;
    bool rref(QList< QList<double> > &M, QList<double> &F);
    ///////////////////////


    //Optimization functions
    int dive(int cSign, QList<double> rDomainMin, QList<double> rDomainMax,
             QVector<double> target, int cost);
    bool cascading(QVector<int> &ind, QVector<int> branches);
    bool surfit(QList<double> &polyfit, QList<double> rDomainMin, QList<double> rDomainMax);




protected:
    virtual double mFunction( QVector<double> input );
    //This function must be overwriten with the multivariable function which is to be inspected

    double parseInput( QVector<double> input, int entry );
    //This function will help to convert the input vector into a series of scalars if desired

};

#endif // SURFEX_HPP
