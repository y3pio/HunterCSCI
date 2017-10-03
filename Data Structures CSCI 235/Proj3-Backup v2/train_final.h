#include <string.h>
#ifndef GROUP_TRAIN_H
#define GROUP_TRAIN_H
#include "queue_final.h"
#include "time_final.h"
#include <string>
using namespace std;

class Train
{
	private:
		Passenger* car1;
		Passenger* car2;
		Passenger* car3;
		int numberInCar1;
		int numberInCar2;
		int numberInCar3;
		int startingTime;
		char line;
		char direction;
		string location;

	public:

		Passenger* find(int carNum, int pos);
		//precondition: position must be valid.
		//postcondition: returns pointer to passenger at position pos in car carNum.
		Passenger* remove(int carNum, int pos);
		//precondition: valid passenger on the train. pass position in car and car number.
		//postcondition: gives control of this passenger to calling function.

		Train();
		//default constructor: not needed
		Train(string location, char direction, char line);
		//constructor that will be used.
		Train(const Train& anotherTrain);
		//not expecting to use the copy constructor.
		~Train();
		//destructor: needed for avoiding memory leaks.
		void load(Passenger passenger, int carNumber);
		//precondtion: takes a passenger and a carNumber requires valid train object and valid passenger
		//postcondition: returns void, places passenger into the car specified
		void unload();
		//precondition: will check to make sure car is not empty. Needs a valid train object
		//postcondition: returns control of the passenger that is leaving the train to the caller.
		string getLocation();
		//precondition: valid train object
		//postcondition: returns location
		char getLine();
		//precondition: valid train object
		//postcondition: returns line color.
		char getDirection();
		//precondition: valid train object
		//postcondition: returns train direction
		int getNumberInCar(int carNumber);
		//precondition: valid train object, and car number.
		//postcondition: returns number in specified car.
		void setDirection(char direction);
		//precondition: direction can never be anything but n or s. This will be checked.
		//postcondition: direction will be set if it is valid.
		void setLocation(string location);
		//precondition: Please only pass valid location. Locations will not be checked.
		//postcondition: sets location member data to parameter.
		void setStartingTime(int minutes);
		//precondition: minutes needs to be positive (will not be checked)
		//postcondition: sets data startingTime to value of minutes.
		int getStartingTime();
		//precondition: none.
		//postcondition: returns startingTime.

};

#endif

