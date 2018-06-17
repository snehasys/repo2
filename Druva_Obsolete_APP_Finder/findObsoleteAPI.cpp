/*
An Outdated API

A company has a number of mobile apps that they sell to customers, and each app uses one or more REST APIs. All REST APIs are given version numbers like v1, v2, v3, ... etc. which are incremented each time the REST API team releases a new version of the API to the app teams.

Consider a file input.txt which contains information about which versions of the various APIs are being used by the current release of each app of the company:

Mail App, Authentication API, v6
Video Call App, Authentication API, v7
Mail App, Data Storage API, v10
Chat App, Data Storage API, v11
Mail App, Search API, v6
Chat App, Authentication API, v8
Chat App, Presence API, v2
Video Call App, Data Storage API, v11
Video Call App, Video Compression API, v3
Each line of this file consists of 3 comma-separated fields. The first field is a app name, the second field is a API name, and the third field is the API version number used by that app. The example given above indicates that the Mail App, uses version v7 of the Authentication API, and the Video Call App uses version v7 of the Authentication API, and the Mail App also uses version v10 of the Data Storage API, and so on. For the purposes of this program, assume that all version numbers are of the form v<digits> where <digits> represents one or more decimal digits.

Write a program in a language of your choice (although we prefer C/C++/Python) that reads this file, figures out which is the latest version number of each API, and then prints the names of apps which are using an older version (i.e. a version that is not the latest version) of at least one API.

Thus, in case of the example input given above, the output of your program should be:
Mail App
Video Call App

because Mail App is using older versions of the Authentication API and the Data Storage API, and Video Call App is using an older version of the Authentication API. Please read the example carefully to understand exactly what you're expected to do.

Important notes:

You must write your program in a single file, and copy-paste the program below. In case you want to write a program with multiple-classes, use inner classes.

*/

#include <fstream>
#include <sstream>
#include <iostream>

#include <string>
#include <vector>
#include <set>
#include <tuple>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef string APPname;
typedef string API;
typedef int VERSION;

class ObsolateAppFinder
{
private:
    vector<tuple <APPname, API, VERSION>> all_records;
    unordered_map < API, VERSION >  latest_versions;
    
	int getVersion(const string vData) {
	    if(vData.at(0) == 'v')
	        return stoi(vData.substr(1) ); // return the integer after 'v'
	    return 0;
	}
	
	void removeSpaces(string& str){
	    str.erase(remove(str.begin(), str.end(), ' '), str.end());
	}
    
	void cook_metadata(ifstream& infile) {
	    APPname appName;
	    API apiType;
	    string apiVersion;
	    while( infile  ){ // while there exists input data
	        string line;
	        if (!getline( infile, line))     break;
	
	        istringstream streamForLine(line);
	        getline(streamForLine, appName, ',');    removeSpaces(appName);
	        getline(streamForLine, apiType, ',');    removeSpaces(apiType);
	        getline(streamForLine, apiVersion, ','); removeSpaces(apiVersion);
	        VERSION currentVersion = getVersion(apiVersion);        
	        this->all_records.push_back(make_tuple(appName, apiType, currentVersion));
	        
	        auto found = this->latest_versions.find( apiType) ;
	        if(found != latest_versions.end() && found->second < currentVersion) {
	            found->second = currentVersion; // Update entry with the latest version number 
	        }
	        else{
	            this->latest_versions[apiType] = currentVersion; // add new entry
	        }
	    }    
	}	
public:
	// remove default constructor
	ObsolateAppFinder() = delete;
	// parameterized constructor
	ObsolateAppFinder(const string filepath)
	{
		ifstream infile(filepath);
		cook_metadata(infile);
	}
	// only public method
	void get_obsolete_apps(set<APPname>& obsolete_apps)
	{    
	    APPname current_app;
	    API     current_api;
	    VERSION current_ver;
	    for(auto tuple_item : this->all_records)
		{
	        current_app = get<0>(tuple_item);
	        current_api = get<1>(tuple_item);
	        current_ver = get<2>(tuple_item);        
	
	        VERSION latest_ver = (latest_versions.find(current_api)) -> second ; // this will fetch the latest possible version of the API
	        
	        if(latest_ver > current_ver)     obsolete_apps.insert(current_app);
	    }    
	}
};
///

 ////////////////////////
////////////////////////
int main()
{    
    ObsolateAppFinder obj("input.txt");
    
    set<APPname> obsolete_apps;
	obj.get_obsolete_apps(obsolete_apps);
    
    for(APPname old : obsolete_apps)        cout << old << endl; // print all obsolete app names

    return 0;
}
 ////////////////////////
////////////////////////

