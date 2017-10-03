#include "Globaldata.h"
#include "Process.h"
#include "Cpu.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <queue>

using namespace std;


int g_PCount=0;
int g_DCount=0;
int g_CCount=0;
int g_PID=-1;
int g_ProcessCounter=0;

int lineCount=0;

void sysGen();
void helpMenu();
void screenShot(queue<Process> printQ);

int main()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    string repeatGen="n";
    do
    {
        sysGen();
        cout << "<SysGen#>"
             << "\n--------------------------"
             << "\nDevice Type          Count"
             << "\n--------------------------"
             << "\nPrinter              " << g_PCount
             << "\nDisk                 " << g_DCount
             << "\nCD/RW                " << g_CCount
             << "\n--------------------------"
             << "\nIs this configuration correct?(y/n):";

        do
        {
            cin >> repeatGen;
            if(repeatGen.length()>1 || (repeatGen[0]!='y' && repeatGen[0]!= 'Y'
               && repeatGen[0]!='n' && repeatGen[0]!='N'))
               {
                    cout << "SysGen#:Error input, please enter \"y\" or \"n\"!!" << endl;
                    cout << "#:";
               }

        }while(repeatGen.length()>1 || (repeatGen[0]!='y' && repeatGen[0]!= 'Y'
               && repeatGen[0]!='n' && repeatGen[0]!='N'));
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
    }while(repeatGen[0]=='n' || repeatGen[0]=='N');

    //SYSGEN ENDS HERE

    //START RUNNING
    //Create all the Queues and CPI
    queue<Process> Printers[g_PCount];
    queue<Process> Disk[g_DCount];
    queue<Process> Cdrw[g_CCount];
    queue<Process> ReadyQueue;
    Cpu cpu0;

    cout << "Running OS..." << endl;
    cout << "Type \"help\" for help menu." << endl;
    cout << "Press enter to continue..." << endl;
    cin.get();
    cin.ignore();

    Process tempBuffer;
    tempBuffer.setPID(g_PID);
    cpu0.loadProc(&tempBuffer);
    cpu0.getProc();
    g_PID++;

    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    string command;
    int deviceNum;
    do
    {
        //Before each command line is received
        //Do ReadyQueue/CPU Proc pushes here

        //If there is something in RQueue (After first run)
        //And cpu is idle.
        if(!ReadyQueue.empty() && cpu0.isEmpty())
        {
            //Process* temp=new Process;
            cpu0.loadProc(&ReadyQueue.front());
//            delete temp;
            ReadyQueue.pop();
        }
        cout << "#:";
        do
        {
            cin >> command;
            if(commandChecker(command)==false)
            {
                cout << "Error input. Type \"help\" for help menu."
                     << "\n#:";
            }
        }while(commandChecker(command)==false);

        if(command=="help")
        {
            helpMenu();
            #ifdef _WIN32
            system("cls");
            #else
            system("clear");
            #endif
        }

        else if(command=="clear")
        {
            #ifdef _WIN32
            system("cls");
            #else
            system("clear");
            #endif
        }

        else if(command=="A")
        {
            cout << "Queuing process..." << endl;
            //Process *temp=new Process;
            Process *temp=new Process;
            //temp->setPID(g_PID);
            temp->setPID(g_PID);
            //cout << "Queuing temp:" << temp->getPID() << endl;
            //cout << "TEMP'S PID-->" << temp->getPID() << endl; //Ok this works.

            if(cpu0.isEmpty())
            {
                cout << "Process queued into CPU!" << endl;
                cpu0.loadProc(temp);
            }
            else if(!cpu0.isEmpty())
            {
                cout << "Process queued into READYQUEUE!" << endl;
                ReadyQueue.push(*temp);
            }
            //Write Queue Process here.
            g_PID++;
            g_ProcessCounter++;
//            delete temp;
            //cout << "Current Process ID in CPU " << cpu0.cpudebug() << endl;
        }

        //Else if to check if there are Process Queued in System.
        //YOU SHALL NOT PASS...until you've queued a process.... :D
        else if(g_ProcessCounter==0 && command!="exit")
        {
            cout << "Error, No processes in the System!"
                    << "\nQueue processes with the \"A\" command." << endl;
        }

        else if(command=="t")
        {
            cout << "Terminating CPU Process." << endl;
            /*while(!ReadyQueue.empty())
            {
                cout << "Front:" << ReadyQueue.front().getPID() << endl;
                ReadyQueue.pop();
            }*/

            if(!cpu0.isEmpty()) //Means there's a process loaded
            {
                //cout << "ECHO SEG FAULT!!" << endl;
                cout << "Terminating PID:" << cpu0.getProc()->getPID() << endl;
                /*Process *temp=new Process;
                temp=cpu0.getProc();
                cout << "THIS IS THE PID>>>: " << temp->getPID() << endl;
                ReadyQueue.push(*temp);
                delete temp;*/
                g_ProcessCounter--;
            }
            else if(cpu0.isEmpty())
                cout << "Error termination. No process found in CPU." << endl;
            //cout << "PID CHECK-->" << cpu0.getProc()->getPID() << endl; Ok this works.
        }

        else if(command=="S")
        {
            string input;
            cout << "Taking Snapshot." << endl;
            do
            {
                cout << "Select r,p,d,c:";
                cin >> input;
                if(input.length()>1 || (input[0]!='r' && input[0]!='p'
                                        && input[0]!='d' && input[0]!='c'))
                    cout << "Error input please try again..." << endl;

            }while(input.length()>1 || (input[0]!='r' && input[0]!='p'
                                        && input[0]!='d' && input[0]!='c'));
            //Write Snapshot here.
            switch (input[0])
            {
                case 114:
                    //cout << "Echo r" << endl;
                    #ifdef _WIN32
                    system("cls");
                    #else
                    system("clear");
                    #endif
                    cout << left << setw(9) << "PID" << left << setw(24) << "Filename"
                    << left << setw(9) << "Memstart" << " R/W" << endl;
                    screenShot(ReadyQueue);
                    break;
                case 112:
                    //cout << "Echo p" << endl;
                    #ifdef _WIN32
                    system("cls");
                    #else
                    system("clear");
                    #endif
                    cout << left << setw(9) << "PID" << left << setw(24) << "Filename"
                    << left << setw(9) << "Memstart" << " R/W" << endl;
                    for(int i=0; i<g_PCount; i++)
                    {
                        cout << "p" << i+1 << "----" << endl;
                        screenShot(Printers[i]);
                    }
                    break;
                case 100:
                    //cout << "Echo d" << endl;
                    #ifdef _WIN32
                    system("cls");
                    #else
                    system("clear");
                    #endif
                    cout << left << setw(9) << "PID" << left << setw(24) << "Filename"
                    << left << setw(9) << "Memstart" << " R/W" << endl;
                    for(int i=0; i<g_PCount; i++)
                    {
                        cout << "d" << i+1 << "----" << endl;
			std::cerr << "TEST!\n";
                        screenShot(Disk[i]);
                    }
                    break;
                case 99:
                    //cout << "Echo c" << endl;
                    #ifdef _WIN32
                    system("cls");
                    #else
                    system("clear");
                    #endif
                    cout << left << setw(9) << "PID" << left << setw(24) << "Filename"
                    << left << setw(9) << "Memstart" << " R/W" << endl;
                    for(int i=0; i<g_PCount; i++)
                    {
                        cout << "cdrw" << i+1 << "----" << endl;
                        screenShot(Cdrw[i]);
                    }
                    break;
                default:
                    cout << "Hello Professor, if you are reading this please take points off." << endl;
                    break;
            }

        }

        //If the check gets to here, there is at least one PCB in the system.
        //Device Queue/Dequeue block. Error check to make sure process are there.
        else if(command[0]=='P' || command[0]=='p')
        {
            deviceNum=stringConvertInt(command.substr(1));
            //cout << "Calling Printer Device #:" << deviceNum << endl;
            if(deviceNum>g_PCount || deviceNum<=0)
            {
                cout << "Error Printer Device #..."
                     << "\nPlease enter a number from 1-" << g_PCount << endl;
            }
            else if(command[0]=='p' && cpu0.isEmpty())
            {
                cout << "Error no available process..."
                     << "\nPlease load a process with [A]" << endl;
            }
            else if(command[0]=='P' && Printers[deviceNum-1].empty())
            {
                cout << "No processes in Printer" << deviceNum << " queue to terminate." << endl;
            }
            else
            {
                if(command[0]=='P')
                {
                    cout << "Terminating Printer process." << endl;
                    //Maybe use front to access the set functions?? Instead of using temp
                    //Process *temp=&Printers[deviceNum-1].front();
                    Printers[deviceNum-1].front().setFileName("");
                    Printers[deviceNum-1].front().setProcName("");
                    Printers[deviceNum-1].front().setStartMem(0);
                    Printers[deviceNum-1].front().setRW(' ');
                    ReadyQueue.push(Printers[deviceNum-1].front());
                    Printers[deviceNum-1].pop();
                    //delete temp;
                }
                else if(command[0]=='p')
                {
                    cout << "Queuing process into printer[" << deviceNum << "]" << endl;
                    cout << "Enter all strings without spaces." << endl;
                    cpu0.defineProc('p');
                    Printers[deviceNum-1].push(*cpu0.getProc());
                    //cout << "ECHO SEG FAULT" << endl;
                    //cout << Printers[deviceNum-1].size() << endl;
                }
            }
        }

        else if(command[0]=='D' || command[0]=='d')
        {
            deviceNum=stringConvertInt(command.substr(1));
            cout << "Calling Disk Device #:" << deviceNum << endl;
            if(deviceNum>g_DCount || deviceNum<=0)
            {
                cout << "Error Disk Device #..."
                     << "\nPlease enter a number from 1-" << g_DCount << endl;
            }
            else if(command[0]=='d' && cpu0.isEmpty())
            {
                cout << "Error no available process..."
                     << "\nPlease load a process with [A]" << endl;
            }
            else if(command[0]=='D' && Disk[deviceNum-1].empty())
            {
                cout << "No processes in Disk" << deviceNum << " queue to terminate." << endl;
            }
            else
            {
                if(command[0]=='D')
                {
                    cout << "Terminating Disk process." << endl;
                    Disk[deviceNum-1].front().setFileName("");
                    Disk[deviceNum-1].front().setProcName("");
                    Disk[deviceNum-1].front().setStartMem(0);
                    Disk[deviceNum-1].front().setRW(' ');
                    ReadyQueue.push(Disk[deviceNum-1].front());
                    Disk[deviceNum-1].pop();
                }
                else if(command[0]=='d')
                {
                    //cout << "Process requesting Disk." << endl;
                    cout << "Queuing process into disk[" << deviceNum << "]" << endl;
                    cout << "Enter all strings without spaces." << endl;
                    cpu0.defineProc('d');
                    Disk[deviceNum-1].push(*cpu0.getProc());
                }
            }
        }


        else if(command[0]=='C' || command[0]=='c')
        {
            deviceNum=stringConvertInt(command.substr(1));
            cout << "Calling CD/RW Device #:" << deviceNum << endl;
            if(deviceNum>g_CCount || deviceNum<=0)
            {
                cout << "Error CD/RW Device #..."
                     << "\nPlease enter a number from 1-" << g_CCount << endl;
            }
            else if(command[0]=='c' && cpu0.isEmpty())
            {
                cout << "Error no available process..."
                     << "\nPlease load a process with [A]" << endl;
            }
            else if(command[0]=='C' && Cdrw[deviceNum-1].empty())
            {
                cout << "No processes in CD/RW" << deviceNum << " queue to terminate." << endl;
            }
            else
            {
                if(command[0]=='C')
                {
                    cout << "Terminating CD/RW process." << endl;
                    Cdrw[deviceNum-1].front().setFileName("");
                    Cdrw[deviceNum-1].front().setProcName("");
                    Cdrw[deviceNum-1].front().setStartMem(0);
                    Cdrw[deviceNum-1].front().setRW(' ');
                    ReadyQueue.push(Cdrw[deviceNum-1].front());
                    Cdrw[deviceNum-1].pop();
                }
                else if(command[0]=='c')
                {
                    //cout << "Process requesting CD/RW." << endl;
                    cout << "Queuing process into cd/rw[" << deviceNum << "]" << endl;
                    cout << "Enter all strings without spaces." << endl;
                    cpu0.defineProc('c');
                    Cdrw[deviceNum-1].push(*cpu0.getProc());
                }
            }
        }

    }while(command!="exit");

}

//Function Def

void sysGen()
{
    string input;
    cout << "-Running SysGen..." << endl;
    cout << "<SysGen#>" << endl;

    do
    {
        cout << "\nNumber of Printers:";
        cin >> input;

        if(integerChecker(input)==false || stringConvertInt(input)<=0)
            cout << "SysGen#:Error input. Please enter non-zero positive INTEGERS only!!" << endl;
        else
            g_PCount=stringConvertInt(input);

    }while(integerChecker(input)==false || stringConvertInt(input)<=0);

    do
    {
        cout << "\nNumber of Disks:";
        cin >> input;

        if(integerChecker(input)==false || stringConvertInt(input)<=0)
            cout << "SysGen#:Error input. Please enter non-zero positive INTEGERS only!!" << endl;
        else
            g_DCount=stringConvertInt(input);

    }while(integerChecker(input)==false || stringConvertInt(input)<=0);

    do
    {
        cout << "\nNumber of CD/RW:";
        cin >> input;

        if(integerChecker(input)==false || stringConvertInt(input)<=0)
            cout << "SysGen#:Error input. Please enter non-zero positive INTEGERS only!!" << endl;
        else
            g_CCount=stringConvertInt(input);

    }while(integerChecker(input)==false || stringConvertInt(input)<=0);
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
};

void helpMenu()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    cout << "------------"
         << "\nHelp Menu"
         << "\n------------"
         << "\nCommand List:"
         << "\n     [A]: Queue process"
         << "\n\n     [S]: Creates a snapshot of desired device."
         << "\n\n     [p(number)]: Sends current process in CPU to Printer (number)"
         << "\n     [d(number)]: Sends current process in CPU to Disk (number)"
         << "\n     [c(number)]: Send current process in CPU to CD/RW (number)"
         << "\n     *Upper case P/C/D will terminate process,"
         << "\n     *And returns the PCB to the ready queue."
         << "\n\n     -All other commands will be displayed when needed."
         << "\n     [clear]: Clears the screen."
         << "\n     [help]:  Prints this help menu"
         << "\n     [exit]:  Exits the OS."
         << "\n\n     Press enter to return to # command line..." << endl;
        cin.get();
        cin.ignore();
}

void screenShot(queue<Process> printQ)
{
std::cerr << "2TEST!\n";

    queue<Process> temp = printQ;
    while(!temp.empty())
    {
        cout << left << setw(9)  << temp.front().getPID()
             << left << setw(24) << temp.front().getFileName()
             << left << setw(10) << temp.front().getStartMem()
             << temp.front().getRW()
             << endl;
        temp.pop();
        lineCount++;
        if(lineCount==22)
        {
            lineCount=0;
            cout << "\nPress enter to continue..." << endl;
            cin.get();
            cin.ignore();
            #ifdef _WIN32
            system("cls");
            #else
            system("clear");
            #endif
            cout << left << setw(9) << "PID" << left << setw(24) << "Filename"
                 << left << setw(9) << "Memstart" << " R/W" << endl;
        }
    }
}
