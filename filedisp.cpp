#include <iostream>
#include <filesystem>
#include "version.cpp"
using namespace std;

int main(int argc, char *argv[]) {

	//Display verison
    displayVersion();

	// put the given argument into a string.
	string arg_op=argv[1];
	
	// create a string to hold the answer;
	string answer;
	
	//create a boolean if an answer was found and there was a proper argument.
	bool found = false, inp = false;
	
	//while there is stuff in the input
	while (getline(cin,answer))
	{
		//if the argument -d was passed.
		if (arg_op == "-d")
		{
			inp = true;
			//if the word directories is in the input.
			if (answer.find("directories") != string::npos)
			{
				cout << answer << endl;
				found = true;
				break;
			};
		}
		//if the argument -f was passed.
		else if (arg_op == "-f")
		{
			inp = true;
			//If the word files is in the input.
			if (answer.find("files")  != string::npos)
			{
				cout << answer << endl;
				found = true;
				break;
			}
		}
		//if the argument -b was passed.
		else if (arg_op == "-b")
		{
			inp = true;
			//if the word bytes was in the input.
			if (answer.find("bytes")  != string::npos)
			{
				cout << answer << endl;
				found = true;
				break;
			}
		}
	}
	//If we did not find an answer from input.
	if (found == false)
	{
		//if there was an invalid option argument
		if (inp == false)
		{
			cout << "An invalid argument was passed, please input -d, -f, or -b." << endl;
		}
		//if there wasnt an invalid option argument;
		else
		{
			cout << "could not find \"directories\", \"files\" or \"bytes\" in the input." << endl;
		}
	}
	return 0;		
}
