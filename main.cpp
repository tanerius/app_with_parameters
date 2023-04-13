#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <filesystem>
#include "helpers.h"
using namespace std;

int main(int argc, char* argv[])
{
	if (!ArgumentParser(argc, argv))
		return 1;
	
	if (FileExists("test.txt"))
	{
		cout << "test.txt file detected\n\n";
	}
	else
	{
		cout << "test.txt file not detected\n\n";
	}

	return 0;

}