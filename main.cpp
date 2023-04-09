#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <filesystem>
using namespace std;

int main(int argc, char* argv[])
{
		string match;

		for (int i = 1; i < argc; i++)
		{
			string argi = argv[i];

			if (argi.find("test") == 0)
				match = argi.substr(0, 4);
		}

		bool found = false;

		for (int i = 1; i < argc; i++)
		{
			string argi = argv[i];

			if (argi.find("test") == 0)
				if (argi == match)
					found = true;
		}

		if (found)
		{
			cout << "\n\"Test\" argument initiated" << endl;

			int count;
			cout << "\nCommand-line arguments:\n";
			for (count = 1; count < argc; count++)
				cout << "  argv[" << count << "]   " << argv[count] << "\n";
		}
		else
		{
			cout << "\nUsage: appwithParameters.exe test\n" << endl;
			exit(1);
		}

	cout << endl;

	//ifstream testtxt;

	//testtxt.open("test.txt");

	if (std::filesystem::exists("test.txt"))
	{
		cout << "test.txt detected\n\n";
	}
	else
	{
		cout << "test.txt not detected\n\n";
	}

	//adding string check for "=" sign

	for (int i = 1; i < argc; i++)
	{
		string argi = argv[i];

		

		if (argi.find('=') != string::npos)
			{
				ofstream writearg;
				writearg.open("test1.txt");
				writearg << argv[i];
				writearg.close();
				
				ifstream in("test1.txt");
				stringstream buffer;
				buffer << in.rdbuf();
				string test = buffer.str();
				cout << "Equal sign found at "<< test << " argument." << endl << endl;

				size_t pos1 = 0;
				size_t pos2;

				string str;
				string str2;
				pos2 = test.find("=", pos1); 

				str = test.substr(pos1, (pos2 - pos1)); 
				cout << "Argument: \"" << str << "\" initiated with its: ";

				pos2 = pos2 + 1;
				str2 = test.substr(pos2, (pos1 - pos2));
				cout << "\"" << str2 << "\" optional argument\n" << endl;
				
			} 
		
	}

	const int result = remove("test1.txt");
	/*
	if (result == 0) {
		cout << "success\n";
	}
	else {
		cout << "unsuccsessfull";
	}
	*/
	return 0;

}