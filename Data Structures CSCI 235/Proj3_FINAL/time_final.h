/************************************************************************
 Title         : time_final.h
 Author        : Kevin Gallagher, Ye Paing and Ruth Hauptman
 Created on    : December 05 2012 
 Description   : declares the global variables g_Min, nOfRedTrains, and 
		 nOfBlueTrains
 Purpose       : keeps track of time and the number of trains present.
 Usage         : ./<program name> <propertiesfile name>
 Build with    : g++ -o <program name> main_final.cpp queue_final.cpp 
	 	 station_final.cpp system_final.cpp train_final.cpp
		 PassengerLinkedList.cpp Properties.cpp
 Modifications :
 *************************************************************************/
#ifndef TIME_FINAL_H
#define TIME_FINAL_H

extern int g_Min;
extern int g_Pass;
extern int nOfRedTrains;
extern int nOfBlueTrains;

#endif
