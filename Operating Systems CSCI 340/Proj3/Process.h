#ifndef PROCESS_H
#define PROCESS_H
#include "Globaldata.h"

class Process
{
    public:
        Process()
        {
            PID=g_PID;
            startMem="0";
            cpuTime=0;
            Tau=0;
            diskCylinder=0;
            procName="";
            fileName="";
            readWrite=' ';
            procMem=0;
        }
        //Overloaded processor to set default -1 procs
        Process(int x)
        {
            PID=x;
            startMem="0";
            cpuTime=0;
            Tau=0;
            diskCylinder=0;
            procName="";
            fileName="";
            readWrite=' ';
            procMem=0;

        }
        void setPID(int x)
        {
            PID=x;
        }
        int getPID()
        {
            return PID;
        }
        void setStartMem(string x)
        {
            startMem=x;
        }
        string getStartMem()
        {
            return startMem;
        }
        void setProcName(string name)
        {
            procName=name;
        }
        string getProcName()
        {
            return procName;
        }
        void setFileName(string name)
        {
            fileName=name;
        }
        string getFileName()
        {
            return fileName;
        }
        void setRW(char rw)
        {
            readWrite=rw;
        }
        char getRW()
        {
            return readWrite;
        }
        void setDiskCylinder(int x)
        {
            diskCylinder=x;
        }
        int getDiskCylinder()
        {
            return diskCylinder;
        }
        float setCpuTime(float x)
        {
            cpuTime+=x;
        }
        float getCpuTime()
        {
            return cpuTime;
        }
        void setTau(float x)
        {
            Tau=x;
        }
        float getTau()
        {
            return Tau;
        }
        void setProcMem(int x)
        {
            procMem=x;
        }
        int getProcMem()
        {
            return procMem;
        }

        //virtual ~process() {}
        //process(const process& other) {}
        //process& operator=(const process& other) { return *this; }
    //protected:
    private:
        int PID;
        string startMem;
        int diskCylinder;
        float Tau;
        float cpuTime;
        string procName;
        string fileName;
        char readWrite;
        int procMem;
};

#endif // PROCESS_H

