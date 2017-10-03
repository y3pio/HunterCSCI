#ifndef GLOBALDATA_H
#define GLOBALDATA_H
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

extern int g_PID;
extern int g_ProcessCounter;
extern int g_PCount;
extern int g_DCount;
extern int g_CCount;

extern float g_SystemAvg;
extern float g_CompletedProcess;

extern float g_Tau;
extern float g_Alpha;

extern int g_TotalMem;
extern int g_ProcMem;
extern int g_PageSize;
extern int g_MemInUse;

extern int g_DiskHeadLocation; //Current DiskHead location
extern int g_CylinderMax;//Max bound for LOOK Algorithm
extern int g_CylinderMin;//Min bound for LOOK Algorithm


int stringConvertInt(string raw)
{
    int sum=0, power=0;
    power=raw.length()-1;
    for(int i=0; i<raw.length(); i++)
    {
        sum=sum+(pow(10,power)*(raw[i]-48));
        power--;
    }
    return sum;
};

bool integerChecker(string raw)
{
    for(int i=0; i<raw.length(); i++)
    {
        if(raw[i]<48 || raw[i]>57)
            return false;
    }
    return true;
};

bool floatChecker(string raw)
{
    for(int i=0; i<raw.length(); i++)
    {
        if((raw[i]<48 || raw[i]>57) && raw[i]!='.')
            return false;
    }
    return true;
};

bool commandChecker(string raw)
{
    if( raw[0]!='A' && raw[0]!='S' &&
        raw[0]!='P' && raw[0]!='p' &&
        raw[0]!='D' && raw[0]!='d' &&
        raw[0]!='C' && raw[0]!='c' &&
        raw[0]!='t' && raw!="help" &&
        raw!="exit" && raw!="clear" && raw[0]!='K') //Last edit added K for PID delete
        return false;

    else if(raw[0]=='P' || raw[0]=='p')
    {
        for(int i=1; i<raw.length(); i++)
        {
            if(raw[i]<48 || raw[i]>57)
                return false;
        }
    }

    else if(raw[0]=='D' || raw[0]=='d')
    {
        for(int i=1; i<raw.length(); i++)
        {
            if(raw[i]<48 || raw[i]>57)
                return false;
        }
    }

    else if((raw[0]=='C' || raw[0]=='c')&&raw!="clear")
    {
        for(int i=1; i<raw.length(); i++)
        {
            if(raw[i]<48 || raw[i]>57)
                return false;
        }
    }

    else if(raw[0]=='K')
    {
        for(int i=1; i<raw.length(); i++)
        {
            if(raw[i]<48 || raw[i]>57)
                return false;
        }
    }

    return true;
};

bool isPowerOfTwo(int x)
{
    return (x>0 && (x&(x-1)));
}

bool hexChecker(string raw)
{
    if(raw.find_first_not_of("0123456789abcdefABCDEF")!=string::npos)
        return false;
    return true;
}

int hexConvertInt(string raw)
{
    int x;
    stringstream iss(raw);
    iss >> hex >> x;
    return x;
}
#endif // GLOBALDATA_H

