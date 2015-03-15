#include "Dir.h"
#include <fstream>
#include <iostream>
using namespace std;

void intro();
void File_c(Dir*,string);
void Folder_c(Dir* root,string dir);
void File_d(Dir* root,string dir);
void Modify_name(Dir* root,string dir,string name);
void Modify_cont(Dir* root,string dir,string name);
void EXT(Dir* root,string dir);
void Move(Dir* root,string dir1,string dir2);
Dir* Search(Dir* root,string node);


///////////////////////////////////////////////////////////////////////////////////
//		aghayoon khanuma in code copy nadare aziatesh nakonid
///////////////////////////////////////////////////////////////////////////////////
int main()
{
	intro();
	return 0;
}

void intro()
{
	fstream in;

	ofstream asghar;	
	asghar.open("output.txt");			// in system kollan file e output.txt ro khaaali mikonan
	asghar.close();
	char temp[60] = {0};
	in.open("input.txt",fstream::out | fstream::in);
	string command,dir,details;
	Dir root(1,"/",NULL);
	command = 'X';
	while(!(in.eof()))
	{
		in >> command;
		if(command == "Create")
		{
			in >> command;
			if(command == "File")
			{
				in >> dir;
				File_c(&root,dir);
			}
			else if(command == "Folder")
			{
				in >> dir;
				in >> command;
				Folder_c(&root,dir);
			}
		}
		if(command == "Delete")
		{
			in >> dir;
			in >> command;
			File_d(&root,dir);
			
		}
		else if(command == "Modify")
		{
			in >> command;
			if(command == "Name")
			{	in >> dir >> command;
			Modify_name(&root,dir,command);	
			}
			else if(command == "Content")
			{
				in >> dir;
				command.erase();
				in >> command;
				for(int j = 0; j < 60; j++)
					temp[j] = 0;
				in.getline(temp,60,'\n');
				for (int i = 0; i < strlen(temp); i++)
					command += temp[i];
				Modify_cont(&root,dir,command);
			}
		}
		else if(command == "Existense ")
		{
			EXT(&root,dir);	
		}
		else if(command == "Copy")
		{
			
		}
		else if(command == "Move")
		{
			in >> dir >> command;
			Move(&root,dir,command);
		}
		else if(command == "Search")
		{
			in >> command;
			Search(&root,command);
		}
	}
}

