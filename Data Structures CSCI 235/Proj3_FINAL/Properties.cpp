#include "Properties.hpp"


Properties * Properties::instance = 0;


// -----------------------------------------------------------------------------
// Properties
// The default constructor.
// -----------------------------------------------------------------------------
Properties::Properties () {
	readFile = false;
}


// -----------------------------------------------------------------------------
// Properties destructor
// Cleans up.
// -----------------------------------------------------------------------------
Properties::~Properties () {
	readFile = false;
}


// -----------------------------------------------------------------------------
// getInstance
// Used for clients to get access to the singleton instance of Properties.
// -----------------------------------------------------------------------------
Properties *
Properties::getInstance () {
	if (instance == 0) {
		instance = new Properties ();
	}
	return instance;
}


// -----------------------------------------------------------------------------
// readPropertyFile
// Processes an MLMTD property file. Returns true when the file was correctly
// processed; false otherwise.
// -----------------------------------------------------------------------------
bool
Properties::readPropertyFile (string fileName) {
	string            line;
	ifstream          infile;

	unsigned int      token;
	string            key;
	string            value;

	if (readFile) {
		return true;
	}

	readFile = true;  // Set false later on errors

	infile.open(fileName.c_str());
	if (infile == NULL)
		readFile = false;

	while (readFile && getline(infile, line, '\n')) {
		if ((line[0] != '#') && (line.length() > 2)) {
			token = line.find("=", 0);
			if ((token > 0) && (token < line.length())) {
				key = line.substr(0, token);
				value = line.substr(token+1, (line.length()-token));

				if ((key.length() < 1))
					cout << "Invalid property key" << endl;
				else if ((value.length() < 1))
					cout << "Invalid property value" << endl;
				else if (! (addProperty(key, value))) {
					readFile = false;
				}
			}
		}
	}

	if (! readFile)
		cout << "Properties::readPropertyFile failed." << endl;

	return readFile;
}


// -----------------------------------------------------------------------------
// addProperty
// Adds a new property to the currect property store. Returns true if the 
// property was correctly added; false otherwise.
// -----------------------------------------------------------------------------
bool
Properties::addProperty (string key, string value) {
	store.insert(kvpStore :: value_type(key, value));
	return true;
}


// -----------------------------------------------------------------------------
// getProperty
// Returns the value associated with the key passed as argument. May return an
// empty string if no such key exists.
// -----------------------------------------------------------------------------
string
Properties::getProperty (string key) {
	iterator = store.find(key);
	if (iterator == store.end())
		return "";
	else
		return(iterator->second);
}


