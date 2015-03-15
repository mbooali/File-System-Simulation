#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Dir.h"
using namespace std;

void File_c(Dir* root,string dir)
{
	int slash = 0,flag = 0;
	size_t found=0,found2=0;
	string str("/"),x;
	Dir* now;
	Dir* temp;
	now = root;
	fstream out;
	out.open("output.txt",fstream::out | fstream::app);
	for(int i = 0; i < dir.length(); i++)
	{
		if(dir[i] == '/')
		slash++;
	}

	for(int j = 0; j < slash; j++)
	{
		
		found = found2 + 1;
		found2 = dir.find('/',found);
		x = dir.substr(found,found2-found);
		if(now->getBache() == NULL)
		{
			if(j < slash-1)
				now->setBache(new Dir(1,x,now));		// if khandadash was NULL this means this node is khandadash
			else
				now->setBache(new Dir(0,x,now));
			temp = now->getBache();
		}
		else
		{
			temp = now->getBache();
			flag = 0;

			if(temp->getName() == x)
			{
				flag = 1;
				break;
			}
			while(temp->getDadash() != NULL && flag == 0)
			{	
				if(temp->getName() == x)
				{
					flag = 1;
					break;
				}
				temp = temp->getDadash();
			}

			if(flag == 0)
			{
				if(j < slash-1)
					temp = new Dir(1,x,now);
				else
					temp = new Dir(0,x,now);
			}
		}
		now = temp;
	}
	out << "File " << dir << " created" << endl; 
	out.close();
}

void File_d(Dir* root,string dir)
{
	int slash = 0,flag = 0;
	size_t found=0,found2=0;
	string str("/"),x;
	Dir* now;
	Dir* temp;
	now = root;
	fstream out;
	out.open("output.txt",fstream::out | fstream::app);
	for(int i = 0; i < dir.length(); i++)
	{
		if(dir[i] == '/')
		slash++;
	}

	for(int j = 0; j < slash - 1; j++)
	{
		
		found = found2 + 1;
		found2 = dir.find('/',found);
		x = dir.substr(found,found2-found);
		if(now->getBache() == NULL)
		{
			out << dir<<"  does not exist" << endl;
			return;
		}
		else
		{
			temp = now->getBache();
			flag = 0;

			if(temp->getName() == x)
			{
				flag = 1;
			}
			while(temp->getDadash() != NULL && flag == 0)
			{	
				if(temp->getName() == x)
				{
					flag = 1;
					break;
				}
				temp = temp->getDadash();
			}

			if(flag == 1)
			{
				now = temp;
			}
			else if(flag == 0)
			{
				out << dir<<"  does not exist" << endl;
				return;
			}
		}
		
	}
	found = found2 + 1;
	found2 = dir.find('/',found);
	x = dir.substr(found,found2-found);
	Dir* t;
	if(now->getBache() == NULL)
	{
		out << dir<<"  does not exist" << endl;
		return;
	}
	else if(now->getBache()->getName() == x)
	{
		temp = now->getBache();
		now->setBache(temp->getDadash());
		delete temp;
		out << dir << " has been deleted...!" << endl; 
	}
	else
	{
		temp = now->getBache();
		while(temp->getDadash() != NULL)
		{
			if(temp->getDadash()->getName() == x)
			{
				t = temp->getDadash();
				temp->setDadash(t->getDadash());
				delete t;
				out << dir << " has been deleted...!" << endl;
				break;
			}
			temp = temp->getDadash();
		}
		 
	}
	out.close();
	
}

void Folder_c(Dir* root,string dir)
{
	int slash = 0,flag = 0;
	size_t found=0,found2=0;
	string str("/"),x;
	Dir* now;
	Dir* temp;
	now = root;
	fstream out;
	out.open("output.txt",fstream::out | fstream::app);
	for(int i = 0; i < dir.length(); i++)
	{
		if(dir[i] == '/')
		slash++;
	}

	for(int j = 0; j < slash; j++)
	{
		
		found = found2 + 1;
		found2 = dir.find('/',found);
		x = dir.substr(found,found2-found);
		if(now->getBache() == NULL)
		{
			now->setBache(new Dir(1,x,now));
			temp = now->getBache();
		}
		else
		{
			temp = now->getBache();
			flag = 0;

			if(temp->getName() == x)
			{
				flag = 1;
				break;
			}
			while(temp->getDadash() != NULL && flag == 0)
			{	
				if(temp->getName() == x)
				{
					flag = 1;
					break;
				}
				temp = temp->getDadash();
			}

			if(flag == 0)
			{
				temp = new Dir(1,x,now);
			}
		}
		now = temp;
	}
	out << "Folder " << dir << " created" << endl; 
	out.close();
}



Dir* Search(Dir* root,string node)
{
	Dir* now;
	Dir* temp;
	now = root;
	Dir* flag = NULL;
	while ( now != NULL )
	{
		if ( now->getName() == node )
		{
			fstream out;
			out.open("output.txt",fstream::out | fstream::app);
			vector<string> direct;
			vector<string>::reverse_iterator it;
			temp = now;
			while(temp->getName() != "/" )
			{
				
				direct.push_back(temp->getName());
				temp = temp->getBaba();
			}
			out << node << "  founded in   /";
			for(it = direct.rbegin(); it != direct.rend(); ++it)
				out << *it << "/";
			out << endl;
		}
		if ( now->getBache() != NULL )
			if ( (flag = Search(now->getBache(),node) ) != NULL )
				return flag;
			now = now->getDadash();
	}
	return NULL;
}

void Modify_name(Dir* root,string dir,string name)
{
	int slash = 0,flag = 0;
	size_t found=0,found2=0;
	string str("/"),x;
	Dir* now;
	Dir* temp;
	now = root;
	fstream out;
	out.open("output.txt",fstream::out | fstream::app);
	for(int i = 0; i < dir.length(); i++)
	{
		if(dir[i] == '/')
			slash++;
	}
	
	for(int j = 0; j < slash; j++)
	{
		
		found = found2 + 1;
		found2 = dir.find('/',found);
		x = dir.substr(found,found2-found);
		if(now->getBache() == NULL)
		{
			out << "not found " << endl;
			return;
		}
		else
		{
			temp = now->getBache();
			flag = 0;
			
			if(temp->getName() == x)
			{
				flag = 1;
			}
			while(temp->getDadash() != NULL && flag == 0)
			{	
				if(temp->getName() == x)
				{
					flag = 1;
					break;
				}
				temp = temp->getDadash();
			}
			
			if(flag == 0)
			{
				out << "not found " << endl;
				return;
			}
			else if(flag == 1)
			{
				now = temp;
				if(j == slash-1)
				{
					now->setName(name);
					out << dir << " name changed to " << name << endl;
				}
			}
		}
	}
	out.close();
	
}

void Modify_cont(Dir* root,string dir,string name)
{
	int slash = 0,flag = 0;
	size_t found=0,found2=0;
	string str("/"),x;
	Dir* now;
	Dir* temp;
	now = root;
	fstream out;
	out.open("output.txt",fstream::out | fstream::app);
	for(int i = 0; i < dir.length(); i++)
	{
		if(dir[i] == '/')
			slash++;
	}
	
	for(int j = 0; j < slash; j++)
	{
		
		found = found2 + 1;
		found2 = dir.find('/',found);
		x = dir.substr(found,found2-found);
		if(now->getBache() == NULL)
		{
			out << "not found " << endl;
			return;
		}
		else
		{
			temp = now->getBache();
			flag = 0;
			
			if(temp->getName() == x)
			{
				flag = 1;
			}
			while(temp->getDadash() != NULL && flag == 0)
			{	
				if(temp->getName() == x)
				{
					flag = 1;
					break;
				}
				temp = temp->getDadash();
			}
			
			if(flag == 0)
			{
				out << "not found " << endl;
				return;
			}
			else if(flag == 1)
			{
				now = temp;
				if(j == slash-1)
				{
					now->setCont(name);
					out << dir << " content changed to " << name << endl;
				}
			}
		}
	}
	out.close();
}



void EXT(Dir* root,string dir)
{
	int slash = 0,flag = 0;
	size_t found=0,found2=0;
	string str("/"),x;
	Dir* now;
	Dir* temp;
	now = root;
	fstream out;
	out.open("output.txt",fstream::out | fstream::app);
	for(int i = 0; i < dir.length(); i++)
	{
		if(dir[i] == '/')
			slash++;
	}
	
	for(int j = 0; j < slash; j++)
	{
		
		found = found2 + 1;
		found2 = dir.find('/',found);
		x = dir.substr(found,found2-found);
		if(now->getBache() == NULL)
		{
			out << "  not exist " << endl;
			return;
		}
		else
		{
			temp = now->getBache();
			flag = 0;
			
			if(temp->getName() == x)
			{
				flag = 1;
			}
			while(temp->getDadash() != NULL && flag == 0)
			{	
				if(temp->getName() == x)
				{
					flag = 1;
					break;
				}
				temp = temp->getDadash();
			}
			
			if(flag == 0)
			{
				out << "  not exist " << endl;
				return;
			}
			else if(flag == 1)
			{
				now = temp;
				if(j == slash-1)
				{
					out << dir << "   exists" << endl;
				}
			}
		}
	}
	out.close();
}

void Move(Dir* root,string dir1,string dir2)
{
	int slash1 = 0, slash2 = 0,flag = 0;
	size_t found=0,found2=0;
	string str("/"),x;
	Dir* now;
	Dir* temp;
	Dir* source = NULL;
	Dir* desti = NULL;
	now = root;
	fstream out;
	out.open("output.txt",fstream::out | fstream::app);
	for(int i = 0; i < dir1.length(); i++)
	{
		if(dir1[i] == '/')
			slash1++;
	}
	for(int k = 0; k < dir1.length(); k++)
	{
		if(dir2[k] == '/')
			slash2++;
	}
	//  source
	for(int j = 0; j < slash1; j++)
	{
		found = found2 + 1;
		found2 = dir1.find('/',found);
		x = dir1.substr(found,found2-found);
		if(now->getBache() == NULL)
		{
			out << "not found " << endl;
			return;
		}
		else
		{
			temp = now->getBache();
			flag = 0;
			
			if(temp->getName() == x)
			{
				flag = 1;
			}
			while(temp->getDadash() != NULL && flag == 0)
			{	
				if(temp->getName() == x)
				{
					flag = 1;
					break;
				}
				temp = temp->getDadash();
			}

			if(flag == 0)
			{
				out << "not found " << endl;
				return;
			}
			else if(flag == 1)
			{
				now = temp;
			}
		}
	}

	if(now->getName() == now->getBaba()->getBache()->getName())
	{
		now->getBaba()->setBache(now->getDadash());
	}
	else
	{
		temp = now->getBaba()->getBache();
		while(temp->getDadash() != NULL)
		{
			if(temp->getDadash()->getName() == now->getName())
			{
				temp->setDadash(temp->getDadash()->getDadash());
				break;
			}
			temp = temp->getDadash();
		}
	}
	source = now;
	now = root;
	found=0;
	found2=0;
	// destinition	
	for(int jp = 0; jp < slash2-1; jp++)
	{
		found = found2 + 1;
		found2 = dir2.find('/',found);
		x = dir2.substr(found,found2-found);
		if(now->getBache() == NULL)
		{
			out << "not found " << endl;
			return;
		}
		else
		{
			temp = now->getBache();
			flag = 0;
			
			if(temp->getName() == x)
			{
				flag = 1;
			}
			while(temp->getDadash() != NULL && flag == 0)
			{	
				if(temp->getName() == x)
				{
					flag = 1;
					break;
				}
				temp = temp->getDadash();
			}

			if(flag == 0)
			{
				out << "not found " << endl;
				return;
			}
			else if(flag == 1)
			{
				now = temp;
			}
		}
	}
	if(now->getBache() == NULL)
	{
		now->setBache(source);
		source->setDadash(NULL);
	}
	else 
	{
		temp = now->getBache();
		while(temp->getDadash() != NULL)
		{
			temp = temp->getDadash();
		}
		source->setDadash(NULL);
		temp->setDadash(source);
	}
	out.close();
}
