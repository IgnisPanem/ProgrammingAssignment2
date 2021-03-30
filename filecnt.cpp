#include <iostream>
#include <filesystem>
#include "version.cpp"
using namespace std;

int main(int argc, char *argv[]) {
	
	//Display verison
	displayVersion();
	// Set the given path to a string;
	string arg_path = argv[1];
	//Set variables to hold number of items
	int dir_num = 0, file_num = 0, byte_num;
	
	//loop through each item in the directory.
	for(auto& cur_path: std::filesystem::recursive_directory_iterator(arg_path, std::filesystem::directory_options::skip_permission_denied))
	{
		//Check if the path leads to a directory.
		if (std::filesystem::is_directory(cur_path.path()))
		{
			//increase the directory count.
			dir_num++;
		}
		//otherwise its a file.
		else if (std::filesystem::is_regular_file(cur_path))
		{
			//increase the file count and number of bytes.
			file_num++;
			byte_num += std::filesystem::file_size(cur_path);
		}
	}
	cout << "The total number of directories in directory " << arg_path << " is : " << dir_num << endl;
	cout << "The total number of files in directory " << arg_path << " is : " << file_num << endl;
	cout << "The total number of bytes occupied by all files in directory " << arg_path << " is : " << byte_num << endl;
	return 0;
}
