#ifndef CPU_H
#define CPU_H
#include "Globaldata.h"
#include "Process.h"

class Cpu
{
    public:
        Cpu()
        {
            curr=NULL;
            isIdle=true;
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
                cout << "Set Memory start location (int):";
                cin >> input;
                if(integerChecker(input)==true)
                    curr->setStartMem(stringConvertInt(input));
                else
                    cout << "Error input!! Please try again" << endl;
            }while(integerChecker(input)==false);

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
            }
            else
            {
                do
                {
                    cout << "Set Read/Write status(r/w):";
                    cin >> input;
                    if(input.length()>1 || (input[0]!='r' && input[0]!='w'))
                        cout << "Error input..please try again." << endl;
                    else
                        curr->setRW(input[0]);
                }while(input.length()>1 || (input[0]!='r' && input[0]!='w'));
            }
        }
        int cpudebug()
        {
            return curr->getPID();
        }
    //    virtual ~Cpu() {}
    //protected:
    private:
        Process *curr;
        bool isIdle;
};

#endif // CPU_H
