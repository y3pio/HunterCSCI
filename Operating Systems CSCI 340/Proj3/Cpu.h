#ifndef CPU_H
#define CPU_H
#include "Globaldata.h"
#include "Process.h"
#include <string>
#include <cstdlib>

class Cpu
{
    public:
        Cpu()
        {
            curr=NULL;
            isIdle=true;
            cpuTime=0;
        }
        bool isEmpty()
        {
            return isIdle;
        }
        void loadProc(Process *inProc)
        {
            curr=inProc;
            isIdle=false;
        }
        Process* getProc()
        {
            //Process* temp=new Process;
            //cout << "Returning PID:" << curr->getPID() << endl;
            //temp=curr;
            //curr=NULL;
            isIdle=true;
            return curr;
        }
        void terminateProc()
        {
            delete curr;
            isIdle=true;
        }
        void defineProc(char procType)
        {
            cout << "System call detected! Ending CPU Process burst, calculating new Tau." << endl;

            curr->setTau((g_Alpha*curr->getTau())+((1-g_Alpha)*curr->getTau()));
            //Tau.Next = Alpha*Tau.Prev + (1-Alpha)*Tau.Prev
            //Algorithm from assignment.
            //cout << "NEW TAU!!" << curr->getTau() << endl;
            string input;
            //DO ALL THIS WITH CPU FUNCTION!! TO AVOID CREATING MORE TEMPS
            cout << "Set Process name(string):";
            cin >> input;
            curr->setProcName(input);
            cout << "Set File name(string):";
            cin >> input;
            curr->setFileName(input);
            do
            {
                cout << "Set Memory start location (hex):";
                cin >> input;
                if(hexChecker(input)==true && hexConvertInt(input)<=g_TotalMem) //If hex and less than total memory
                    curr->setStartMem(input);
                else if(hexChecker(input)==false)
                    cout << "Error input!! Please try again" << endl;
                else if(hexConvertInt(input)>g_TotalMem)
                    cout << "Memory too big. Enter hex value less than " << hex << g_TotalMem << endl;
            }while(hexChecker(input)==false || hexConvertInt(input)>g_TotalMem);

            //HOW TO DO BURST TIME?

            if(procType=='p')
                curr->setRW('w');
            else if(procType=='d' || procType=='c')
            {
                do
                {
                    cout << "Set read/write value(r/w):";
                    cin >> input;
                    if(input.length()>1 || (input[0]!='r' && input[0]!='w'))
                        cout << "Error input please try again.." << endl;
                }while(input.length()>1 || (input[0]!='r' && input[0]!='w'));
                curr->setRW(input[0]);

            }
            //Calculate next tau upon exit.
            calculateTau();
        }
        //Over loaded define proc to take cylinder #
        void defineProc(char procType, int cylinder)
        {
            cout << "System call detected! Ending CPU Process burst, calculating new Tau." << endl;

            curr->setTau((g_Alpha*curr->getTau())+((1-g_Alpha)*curr->getTau()));
            //Tau.Next = Alpha*Tau.Prev + (1-Alpha)*Tau.Prev
            //Algorithm from assignment.
            //cout << "NEW TAU!!" << curr->getTau() << endl;

            string input;
            //DO ALL THIS WITH CPU FUNCTION!! TO AVOID CREATING MORE TEMPS
            cout << "Set Process name(string):";
            cin >> input;
            curr->setProcName(input);
            cout << "Set File name(string):";
            cin >> input;
            curr->setFileName(input);
            curr->setDiskCylinder(cylinder);
            do
            {
                cout << "Set Memory start location (hex):";
                cin >> input;
                if(hexChecker(input)==true && hexConvertInt(input)<=g_TotalMem) //If hex and less than total memory
                    curr->setStartMem(input);
                else if(hexChecker(input)==false)
                    cout << "Error input!! Please try again" << endl;
                else if(hexConvertInt(input)>g_TotalMem)
                    cout << "Memory too big. Enter hex value less than " << hex << g_TotalMem << endl;
            }while(hexChecker(input)==false || hexConvertInt(input)>g_TotalMem);

            /*do
            {
                cout << "Set time spent in CPU (int):";
                cin >> input;
                if(integerChecker(input)==true)
                    curr->setCpuTime(stringConvertInt(input));
                else
                    cout << "Error input!! Please try again" << endl;
            }while(integerChecker(input)==false);*/

            //HOW TO DO BURST TIME?

            if(procType=='p')
                curr->setRW('w');
            else if(procType=='d' || procType=='c')
            {
                do
                {
                    cout << "Set read/write value(r/w):";
                    cin >> input;
                    if(input.length()>1 || (input[0]!='r' && input[0]!='w'))
                        cout << "Error input please try again.." << endl;
                }while(input.length()>1 || (input[0]!='r' && input[0]!='w'));
                curr->setRW(input[0]);
            }

            //DO UPDATE TAU HERE
            calculateTau();

        }

        void interruptBurst()
        {
            string input;
            float burstTime=0;
            cout << "Interrupt Detected!! Enter CPU time spent:";
            do
            {
                cin >> input;
                if(floatChecker(input)==false || atof(input.c_str())<0)
                {
                    cout << "Error time input, please enter a positive number!" << endl;
                    cout << "CPU time spent:";
                }
            }while(floatChecker(input)==false || atof(input.c_str())<0);

            //DO UPDATE HERE
            burstTime=atof(input.c_str());
            curr->setCpuTime(burstTime); //Add to process time spent
            cpuTime+=burstTime;

            //cout << "BURST TIME:" << burstTime << endl;
        }

        void calculateTau()
        {
            float nextTau=(g_Alpha*curr->getTau())+((1-g_Alpha)*cpuTime);
            curr->setTau(nextTau);
            cpuTime=0;
        }

        //DEBUGGING CODE TO RETURN VALUES!
        int cpudebug()
        {
            return curr->getPID();
        }

    //    virtual ~Cpu() {}
    //protected:
    private:
        Process *curr;
        //processCount = # of process serviced by CPU. Used to calculate average.
        bool isIdle;
        float cpuTime;
};

#endif // CPU_H
