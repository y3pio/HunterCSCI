#ifndef PROCESS_H
#define PROCESS_H
#include "Globaldata.h"

class Process
{
    public:
        Process()
        {
            PID=g_PID;
            startMem=0;
            cpuTime=0;
            Tau=0;
            diskCylinder=0;
            procName="";
            fileName="";
            readWrite=' ';
        }
        void setPID(int x)
        {
            PID=x;
        }
        int getPID()
        {
            return PID;
        }
        void setStartMem(int x)
        {
            startMem=x;
        }
        int getStartMem()
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
            cpuTime=x;
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
        //virtual ~process() {}
        //process(const process& other) {}
        //process& operator=(const process& other) { return *this; }
    //protected:
    private:
        int PID;
        int startMem;
        int diskCylinder;
        float Tau;
        float cpuTime;
        string procName;
        string fileName;
        char readWrite;
};

#endif // PROCESS_H

