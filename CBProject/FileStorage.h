#ifndef FileStorage_H
#define FileStorage_H
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include "IStorage.h"

using namespace std;


class FileStorage : public IStorage
{
public:
	string file_name;
	map <string, string> myFile;
	
	FileStorage(string txt) : file_name(txt) {
		ifstream file(txt);
		string token1;
		string token2;
		string temp_str;
		int counter = 0;
		while (!file.eof()) {
			file >> temp_str;
			std::istringstream ss(temp_str);
			getline(ss, token1, ':');
			getline(ss, token2, '\n');
			myFile.insert(make_pair(token1, token2));

		}

	};

	string get(string id) {

		return myFile[id];
	};

	void set(string id, string val) {
		myFile[id] = val;
	
	};

	~FileStorage() {
		string value;
		ofstream file;
		file.open(file_name);
		try {
			if (file.is_open())
			{
		
				for (map<string, string>::const_iterator iter = myFile.begin(); iter != myFile.end(); ++iter)
				{
					value = iter->first + ":" + iter->second;
					
					file << value << "\n";
				}
			}
			else throw "Unable to open file";
		}
		catch (string str){

			cout << "Exception_" << str << "\n";
		}
		file.close();
	};

	int  getLastId() {
		int i = 0;
		for (map<string, string>::const_iterator iter = myFile.begin(); iter != myFile.end(); ++iter)
		{
			i++;
		}
		return i;
	}
};

#endif