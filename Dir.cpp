// Dir.cpp: implementation of the Dir class.
//
//////////////////////////////////////////////////////////////////////

#include "Dir.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Dir::Dir(int type_,string name_,Dir* baba_)
{							//file = 0   folder = 1
	name = name_;
	cont = "nothing";
	type = type_;
	bache = NULL;
	dadash = NULL;
	baba = baba_;
}

Dir::~Dir()
{

}

void Dir::setBache(Dir* bache_)
{
	bache = bache_;
}

void Dir::setDadash(Dir* dadash_)
{
	dadash = dadash_;
}

void Dir::setCont(string cont_)
{
	cont = cont_;
}

void Dir::setName(string name_)
{
	name = name_;
}

void Dir::setBaba(Dir* baba_)
{
	baba = baba_;
}

Dir* Dir::getBache()
{
	return bache;
}

Dir* Dir::getDadash()
{
	return dadash;
}

Dir* Dir::getBaba()
{
	return baba;
}

string Dir::getName()
{
	return name;
}

string Dir::getCont()
{
	return cont;
}
