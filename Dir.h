// Dir.h: interface for the Dir class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIR_H__6DE8DCA5_DA08_400A_B99B_771151AC3111__INCLUDED_)
#define AFX_DIR_H__6DE8DCA5_DA08_400A_B99B_771151AC3111__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <iostream>
#include <string>
using namespace std;

class Dir  
{
	int type;
	string name;
	string cont;
	Dir* bache;
	Dir* dadash;
	Dir* baba;
public:
	Dir(int type_,string name_,Dir* baba_);
	virtual ~Dir();
	void setBache(Dir*);
	void setDadash(Dir*);
	void setBaba(Dir*);
	void setCont(string);
	void setName(string);

	Dir* getBache();
	Dir* getDadash();
	Dir* getBaba();
	string getName();
	string getCont();
};

#endif // !defined(AFX_DIR_H__6DE8DCA5_DA08_400A_B99B_771151AC3111__INCLUDED_)
