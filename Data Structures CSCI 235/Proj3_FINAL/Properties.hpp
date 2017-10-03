#ifndef _Properties_h_
#define _Properties_h_


#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;


// -----------------------------------------------------------------------------
// Properties
// ==========
// A useful object to hold all properties (from a property file, for example)
// for later access.
// Properties is implemented as a singleton so that clients don't need to
// have many (inefficient) instances.
// -----------------------------------------------------------------------------


typedef map <string, string, less< string > > kvpStore;


class Properties {


public:

        // Constructor is private, as this is a singleton.
                               ~Properties ();

	// Use "getInstance()" to get a reference to the singleton.
	static Properties     * getInstance();

	bool                    readPropertyFile (string fileName);
	bool                    addProperty (string key, string value);

		// Most clients just need to get a value based on a key. 
	string                  getProperty (string key);

private:

        // Constructor is private, as this is a singleton.
                                Properties ();

	// Data members
        static Properties     * instance;
        bool                    readFile;

	// members to support Standard Template Library map, if we choose
	// to use that instead of PropertyNode
	kvpStore                store;
	kvpStore :: iterator    iterator;


};


#endif


