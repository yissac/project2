#include "surfex.hpp"
#include <iostream>

double Surfex::mFunction(QVector<double> input)
{
    double x = parseInput(input,1);
    double y = parseInput(input,2);
    //double z = parseInput(input,3); ..etc...

    return pow(x-25.0,2.0) + pow(y-25.0,2.0) + 20.0 + 80.0*cos(10.0*(y-25.0)/(2*3.14159265)) + 80.0*sin(10.0*(x-25.0)/(2*3.14159265));
}






















Surfex::Surfex()
{
    N = 1;
    domainMin.clear();
    domainMin.append(0);
    domainMax.clear();
    domainMax.append(1);
    s = 4;

    prec = 0.01;
    tol = 3;
    livefeed = false;
}

Surfex::Surfex(int _N, double _domainMin, double _domainMax, int _tol)
{
    N = _N;

    domainMin.clear();
    domainMax.clear();
    for(int i=0; i<N; i++)
    {
        domainMin.append(_domainMin);
        domainMax.append(_domainMax);
    }
    s = 4;

    prec = 0.01;
    tol = _tol;
    livefeed = false;
}

Surfex::Surfex(int _N, int _tol)
{
    N = _N;

    domainMin.clear();
    domainMax.clear();
    for(int i=0; i<N; i++)
    {
        domainMin.append(0);
        domainMax.append(1);
    }
    s = 4;

    prec = 0.01;
    tol = _tol;
    livefeed = false;
}


void Surfex::setSampleNumber(int _s){s = _s;}
int Surfex::getSampleNumber(){return s;}
void Surfex::setVariableNumber(int _N)
{
    N = _N;
    domainMin.clear();
    domainMax.clear();
    for(int i=0; i<N; i++)
    {
        domainMin.append(0);
        domainMax.append(1);
    }
}
int Surfex::getVariableNumber(){return N;}

bool Surfex::setDefaultDomain(double _domainMin, double _domainMax, int entry)
{
    if(entry > domainMin.size())
        return false;

    if(entry == 0)
    {
        for(int i=0; i<N; i++)
        {
            domainMin[i] = _domainMin;
            domainMax[i] = _domainMax;
        }

    }
    else
    {
        domainMin.replace(entry,_domainMin);
        domainMax.replace(entry, _domainMax);
    }

    return true;
}

double Surfex::getDefaultMax(int entry) { return domainMax.value(entry, 1); }
double Surfex::getDefaultMin(int entry) { return domainMin.value(entry, 0); }

void Surfex::setPrecision(double _prec) { prec = _prec; }
double Surfex::getPrecision(){ return prec; }

void Surfex::setCostTolerance(int _tol) { tol = _tol; }
int Surfex::getCostTolerance() { return tol; }

void Surfex::setLiveFeed(bool _feed) { livefeed = _feed; }
bool Surfex::getLiveFeed() { return livefeed; }

double Surfex::parseInput(QVector<double> input, int entry){return input.value(entry-1, 0);}

int Surfex::maximize()
{

    maxima.clear();

    std::cout << "Maximizing function..." << std::endl;
    QVector<double> target;
    for(int i=0; i<N; i++)
        target.append(domainMin.value(i)-1000*tol);
    target.append(0);

    int count = dive(-1, domainMin, domainMax, target, 0);

    int i=0;
    while(i < maxima.size()-1)
    {
        int j=i+1;
        while(j < maxima.size())
        {
            double cnorm = 0;
            for(int k=0; k<=N; k++)
                cnorm += (maxima[i][k]-maxima[j][k])*(maxima[i][k]-maxima[j][k]);
            cnorm = sqrt(cnorm);
            if(cnorm <= prec)
            {
                maxima.removeAt(j);
                j--;
            }
            else if(maxima[i][N] < maxima[j][N])
                maxima.swap(i,j);
            j++;
        }
        i++;
    }


    std::cout << "Finished" << std::endl;
    return count;

}

int Surfex::minimize()
{
    minima.clear();

    std::cout << "Minimizing function..." << std::endl;

    QVector<double> target;
    for(int i=0; i<N; i++)
        target.append(domainMin.value(i)-1000*tol);
    target.append(0);

    int count = dive(1, domainMin, domainMax, target, 0);

    int i=0;
    while(i < minima.size()-1)
    {
        int j=i+1;
        while(j < minima.size())
        {
            double cnorm = 0;
            for(int k=0; k<=N; k++)
                cnorm += (minima[i][k]-minima[j][k])*(minima[i][k]-minima[j][k]);
            cnorm = sqrt(cnorm);
            if(cnorm <= prec)
            {
                minima.removeAt(j);
                j--;
            }
            else if(minima[i][N] > minima[j][N])
                minima.swap(i,j);
            j++;
        }
        i++;
    }

    std::cout << "Finished" << std::endl;

    return count;
}


int Surfex::dive(int cSign, QList<double> rDomainMin, QList<double> rDomainMax, QVector<double> target, int cost)
{
    int counter = 0;

//    std::cout << "Diving..." << "[" << rDomainMin[0] << ", " << rDomainMax[0] << "]" << std::endl;

    if(cost<tol)
    {
        QList<double> polyfit;
//        std::cout << "Fitting..." << std::endl;
        bool result = surfit(polyfit, rDomainMin, rDomainMax);

//        std::cout << "Fit!!!!" << std::endl;
        if(!result)
        {
            std::cout << "Fit failed" << std::endl;
            return counter;
        }

        QList< QList<double> > nextDomainMins;
        nextDomainMins.reserve(N);
        QList<double> temp;
        for(int i=0; i<N; i++)
            nextDomainMins.append(temp);

        QList< QList<double> > nextDomainMaxes;
        nextDomainMaxes.reserve(N);
        for(int i=0; i<N; i++)
            nextDomainMaxes.append(temp);

        QList<int> intemp;
        intemp.reserve(3);
        intemp.append(0); intemp.append(0); intemp.append(0);
        QList< QList<int> > penalties;//[N][3];
        penalties.reserve(N);
        for(int i=0; i<N; i++)
            penalties.append(intemp);

        double r1[N];
        double r2[N];
        QVector<int> branches;
        branches.reserve(N);
        for(int i=0; i<N; i++) branches.append(0);

//        std::cout << "Populating...";
        for(int j=0; j<N; j++)
        {
//            std::cout << " Iteration#" << j;
            r1[j] = rDomainMin[j] - prec*1000;
            r2[j] = rDomainMin[j] - prec*1000;

            double Dx_a[3];
            double Hx_a[2];

//            std::cout << polyfit[3] << "x^3 + " << polyfit[2] << "x^2 + " << polyfit[1] << "x + " << polyfit[0] << std::endl;

            Dx_a[0] = 3*polyfit.value(2*N+j+1);
            Dx_a[1] = 2*polyfit.value(N+j+1);
            Dx_a[2] = polyfit.value(j+1);

            Hx_a[0] = 2*Dx_a[0];
            Hx_a[1] = Dx_a[1];

//            std::cout << "Getting roots..." << std::endl;

            double cDomainMin = rDomainMin[j]; double cDomainMax = rDomainMax[j];
            if(abs(Dx_a[0]) > 1e-10)
            {
                if(Dx_a[1]*Dx_a[1] - 4*Dx_a[0]*Dx_a[2] >= 0)
                {
                    r1[j] = (-Dx_a[1] - sqrt(Dx_a[1]*Dx_a[1] - 4*Dx_a[0]*Dx_a[2]))/(2*Dx_a[0]);
                    r2[j] = (-Dx_a[1] + sqrt(Dx_a[1]*Dx_a[1] - 4*Dx_a[0]*Dx_a[2]))/(2*Dx_a[0]);

//                    std::cout << "r1: " << r1[j] << " | r2: " << r2[j] << std::endl;
                    double c1 = r1[j]; double c2 = r2[j];

                    if(cDomainMin<=c1&&c1<=cDomainMax && cDomainMin<=c2&&c2<=cDomainMax )
                    {
                        nextDomainMins[j].append(rDomainMin[j]);
                        nextDomainMaxes[j].append((r1[j]+r2[j])/2);

                        nextDomainMins[j].append((r1[j]+r2[j])/2);
                        nextDomainMaxes[j].append(rDomainMax[j]);

                        if( (Hx_a[0]*r1[j]+Hx_a[1])*cSign <= 0) //Punish if it is not optimal
                            penalties[j][0] = 1;
                        if((Hx_a[0]*r2[j]+Hx_a[1])*cSign <= 0)
                            penalties[j][1] = 1;
                    }
                    else if(cDomainMin<=c1&&c1<=cDomainMax) //Only ordinate 1 is inside domain
                    {
                        nextDomainMins[j].append(rDomainMin[j]);
                        nextDomainMaxes[j].append((rDomainMin[j]+r1[j])/2.0);

                        nextDomainMins[j].append((rDomainMin[j]+r1[j])/2.0);
                        nextDomainMaxes[j].append((r1[j]+rDomainMax[j])/2.0);

                        nextDomainMins[j].append((r1[j]+rDomainMax[j])/2.0);
                        nextDomainMaxes[j].append(rDomainMax[j]);

                        r2[j] = r1[j];

                        penalties[j][0] = 1;
                        if( (Hx_a[0]*r2[j]+Hx_a[1])*cSign <= 0)
                            penalties[j][1] = 1;
                        penalties[j][2] = 1;
                    }
                    else if(cDomainMin<=c2&&c2<=cDomainMax) //Only ordinate 2 is inside domain
                    {
                        nextDomainMins[j].append(rDomainMin[j]);
                        nextDomainMaxes[j].append((rDomainMin[j]+r2[j])/2.0);

                        nextDomainMins[j].append((rDomainMin[j]+r2[j])/2.0);
                        nextDomainMaxes[j].append((r2[j]+rDomainMax[j])/2.0);

                        nextDomainMins[j].append((r2[j]+rDomainMax[j])/2.0);
                        nextDomainMaxes[j].append(rDomainMax[j]);

                        penalties[j][0] = 1;
                        if( (Hx_a[0]*r2[j]+Hx_a[1])*cSign <= 0)
                            penalties[j][1] = 1;
                        penalties[j][2] = 1;
                    }
                    else
                    {
                        nextDomainMins[j].append(rDomainMin[j]);
                        nextDomainMaxes[j].append((rDomainMin[j]+rDomainMax[j])/2.0);

                        nextDomainMins[j].append((rDomainMin[j]+rDomainMax[j])/2.0);
                        nextDomainMaxes[j].append(rDomainMax[j]);

                        penalties[j][0] = 1;
                        penalties[j][1] = 1;
                    }
                }
                else
                {
                    nextDomainMins[j].append(rDomainMin[j]);
                    nextDomainMaxes[j].append((rDomainMin[j]+rDomainMax[j])/2.0);

                    nextDomainMins[j].append((rDomainMin[j]+rDomainMax[j])/2.0);
                    nextDomainMaxes[j].append(rDomainMax[j]);

                    penalties[j][0] = 1;
                    penalties[j][1] = 1;
                }
            }
            else
            {
                r2[j] = -Dx_a[2]/Dx_a[1];
//                std::cout << "r2: " << r2[j] << std::endl;

                double c2 = r2[j];

                if(cDomainMin<=c2&&c2<=cDomainMax)
                {
                    nextDomainMins[j].append(rDomainMin[j]);
                    nextDomainMaxes[j].append((rDomainMin[j]+r2[j])/2.0);

                    nextDomainMins[j].append((rDomainMin[j]+r2[j])/2.0);
                    nextDomainMaxes[j].append((r2[j]+rDomainMax[j])/2.0);

                    nextDomainMins[j].append((r2[j]+rDomainMax[j])/2.0);
                    nextDomainMaxes[j].append(rDomainMax[j]);

                    penalties[j][0] = 1;
                    if( (Hx_a[0]*r2[j]+Hx_a[1])*cSign <= 0)
                        penalties[j][1] = 1;
                    penalties[j][2] = 1;
                }
                else
                {
                    nextDomainMins[j].append(rDomainMin[j]);
                    nextDomainMaxes[j].append((rDomainMin[j]+rDomainMax[j])/2.0);

                    nextDomainMins[j].append((rDomainMin[j]+rDomainMax[j])/2.0);
                    nextDomainMaxes[j].append(rDomainMax[j]);

                    penalties[j][0] = 1;
                    penalties[j][1] = 1;
                }
            }
            branches[j] = nextDomainMins[j].size();
        }

        QVector<int> ind;
        ind.reserve(N);
        for(int i=0; i<N; i++)
            ind.append(0);

        QList<double> nDmnMin;
        nDmnMin.reserve(N);
        for(int i=0; i<N; i++) nDmnMin.append(0);

        QList<double> nDmnMax;
        nDmnMax.reserve(N);
        for(int i=0; i<N; i++) nDmnMax.append(0);

//        std::cout << "Splitting..." << std::endl;
        while(ind[N-1]<branches[N-1])
        {
            int penalty = cost;
            QVector<double> rc;
            rc.reserve(N);
            for(int i=0; i<N; i++) rc.append(0);

//            std::cout << N << " variables";
//            std::cout << "Assigning Penalty to ";
            for(int i=0; i<N; i++)
            {
//                std::cout << ind[i];
                nDmnMin[i] = nextDomainMins[i][ind[i]];
                nDmnMax[i] = nextDomainMaxes[i][ind[i]];
                if(ind[i]==0)
                    rc[i] = r1[i];
                else if(ind[i]==1)
                    rc[i] = r2[i];
                penalty += penalties[i][ind[i]];
            }
//            std::cout << " ...Assigned " << penalty << std::endl;

            double dnorm = 0;
            QVector<double> cTarget = target;

            if(penalty==cost) //If this critical point is a maximum
            {
//                std::cout << "Found maximum_________________________________________." << std::endl;
                for(int i=0; i<N; i++)
                    cTarget[i] = rc[i];

//                std::cout << " Copied over " << std::endl;
                cTarget[N] = mFunction(rc);
//                std::cout << " Function called " << std::endl;
                for(int k=0; k<N+1; k++)
                    dnorm += (target[k]-cTarget[k])*(target[k]-cTarget[k]);
                dnorm = sqrt(dnorm);

                if(dnorm <= prec)
                {
                    if(cSign<0)
                        maxima.append(cTarget);
                    else
                        minima.append(cTarget);

                    if(livefeed)
                    {
                        std::cout << "(" << cTarget[0];
                        for(int oi=1; oi<N; oi++)
                            std::cout << "," << cTarget[oi];
                        std::cout << "): " << cTarget[N] << std::endl;
                    }

                    counter++;
                }
                else
                    counter += dive(cSign, nDmnMin, nDmnMax, cTarget, penalty);
            }
            else
                counter += dive(cSign, nDmnMin, nDmnMax, cTarget, penalty);

            ind[0]++;
            cascading(ind,branches);

        }





    }
    return counter;
}

bool Surfex::cascading(QVector<int> &ind, QVector<int> branches)
{
    int casc = -1;
    int j = N-2;

    while(j>=0)
    {
        if(j <= casc)
            ind[j] = 0;

        if(j<N-1 && ind[j]>=branches[j])
        {
            casc = j;
            ind[j+1]++;
            j = j+2;
        }

        j--;
    }
    return true;
}


bool Surfex::surfit(QList<double> &polyfit, QList<double> rDomainMin, QList<double> rDomainMax)
{
    QList< QList<double> > x;
    x.reserve(s);
    for(int i=0; i<s; i++)
    {
        QList<double> temp;
        temp.reserve(N);
        for(int j=0; j<N; j++)
            temp.append(0);
        x.append(temp);
    }


    for(int p=0; p<s; p++)
    {
        for(int d=0; d<N; d++)
        {
            x[p][d] = rDomainMin[d] + (double)(p)/((double)(s)-1)*(rDomainMax[d]-rDomainMin[d]);
        }
    }
//    std::cout << "x done" << std::endl;

    QList< QList<double> > M;
    M.reserve(3*N+1);
    for(int i=0; i<=3*N; i++)
    {
        QList<double> temp;
        temp.reserve(3*N+1);
        for(int j=0; j<3*N+1; j++)
            temp.append(0);
        M.append(temp);
    }

//    std::cout << "M reserved" << std::endl;

    QList< QList<double> > da_f;
    da_f.reserve(s);
    for(int i=0; i<s; i++)
    {
        QList<double> temp;
        temp.reserve(3*N+1);
        for(int j=0; j<3*N+1; j++)
            temp.append(0);
        da_f.append(temp);
    }

//    std::cout << "daf reserved" << std::endl;
//    std::cout << "Size: " << x.size() << " x " << x[0].size() << std::endl;

    for(int j=0; j<=3*N; j++)
    {
//        std::cout << "j: " << j << std::endl;
        for(int i=0; i<s; i++)
        {
            da_f[i][j] = pow(x[i][j-((int)(ceil((double)(j)/(double)(N)))-1)*N-1],ceil((double)(j)/(double)(N)));
        }
    }
//    std::cout << "daf done" << std::endl;

    for(int k=0; k<=3*N; k++)
    {
        int k0 = k-(ceil((double)(k)/(double)(N))-1)*N;
        for(int m=k; m<=3*N; m++)
        {
            int m0 = m-(ceil((double)(m)/(double)(N))-1)*N;
            M[k][m] = 0;
            for(int c=1; c<=pow(s,N); c++)
            {
                int kc = (int)(ceil((double)(c)/(double)(pow(s,k0-1))-1))%s;
                int mc = (int)(ceil((double)(c)/(double)(pow(s,m0-1))-1))%s;
                M[k][m] = M[k][m] + da_f[kc][m]*da_f[mc][k];
            }
            M[m][k] = M[k][m];
        }
    }


//    std::cout << "M done" << std::endl;

    for(int k=0; k<=3*N; k++)
    {
        for(int m=0; m<=3*N; m++)
        {
//            std::cout << M[k][m] << " ";
        }
//        std::cout << std::endl;
    }

    QVector<int> ind;
    ind.reserve(N);
    for(int i=0; i<N; i++)
        ind.append(0);
    QVector<int> branches;
    branches.reserve(N);
    for(int i=0; i<N; i++)
        branches.append(s);

    QVector<double> z;
    z.reserve(pow(s,N));
    for(int i=0; i<pow(s,N); i++)
        z.append(0);

    int c = 0;
    while(c<pow(s,N))
    {
        QVector<double> xc;
        xc.reserve(N);
        for(int k=0; k<N; k++)
            xc.append(x[ind[k]][k]);

        z[c] = mFunction(xc);


        ind[0]++;
        cascading(ind,branches);
        c++;
    }

    QList<double> F;
    F.reserve(3*N+1);
    for(int i=0; i<3*N+1; i++)
        F.append(0);

    for(int j=0; j<=3*N; j++)
    {
        int j0 = j-(int)((ceil((double)(j)/(double)(N))-1)*N);
        for(int c=1; c<=pow(s,N); c++)
        {
            int jc = (int)(ceil((double)(c)/pow((double)(s),(double)(j0-1))-1))%s;
            F[j] = F[j] + z[c-1]*da_f[jc][j];
        }
    }

//    std::cout << "z:" << std::endl;
//    for(int j=0; j<pow(s,N); j++)
//        std::cout << z[j] << std::endl;

    polyfit.clear();
    if(!rref(M,F))
        return false;
    else
    {
        for(int i=0; i<=3*N; i++)
            polyfit.append(F[i]);
    }

    return true;
}

bool Surfex::rref(QList< QList<double> > &M, QList<double> &F)
{

    for(int i=0; i<3*N; i++)
    {
        double den = M[i][i];
        for(int j=i+1; j<=3*N; j++)
        {
            double num = M[j][i];
            for(int k=i; k<=3*N; k++)
            {
                M[j][k] = M[j][k] - num/den*M[i][k];
            }
            F[j] = F[j] - num/den*F[i];
        }
    }

    for(int i=3*N; i>0; i--)
    {
        double den = M[i][i];
        for(int j=i-1; j>=0; j--)
        {
            double num = M[j][i];
            for(int k=i; k>j; k--)
            {
                M[j][k] = M[j][k] - num/den*M[i][k];
            }
            F[j] = F[j] - num/den*F[i];
        }
    }

    for(int i=0; i<=3*N; i++)
    {
        F[i] = F[i]/M[i][i];
        M[i][i] = M[i][i]/M[i][i];
    }

    int check=0;

    for(int i=0; i<=3*N; i++)
    {
//        std::cout << std::endl;
        for(int j=0; j<=3*N; j++)
        {
            if(i!=j)
                if(M[i][j]>1e-6)
                    check++;
            if(i==j)
                if(abs(M[i][j]-1)>1e-6)
                    check++;
//            std::cout << M[i][j] << " ";

        }
    }

    if(check==0)
        return true;
    else
        return false;
}




