#include "Diccionario.h"

const int Diccionario::lower_limit = 65;

const int Diccionario::upper_limit = 90;

const vector<char>Diccionario::Dictionary = generateDictionary();

Diccionario::Diccionario()
{
}

Diccionario::~Diccionario()
{
}

bool Diccionario::isInDictionary(char c)
{
	if (c > upper_limit) return false;
	else if (c < lower_limit) return false;
	else return true;
}

int Diccionario::getDictionarySize()
{
	return Dictionary.size();
}

char Diccionario::getChar(int c)
{
	return Dictionary[c];
}

int Diccionario::getLowerLimit()
{
	return lower_limit;
}

int Diccionario::getUpperLimit()
{
	return upper_limit;
}

vector<char>Diccionario::generateDictionary()
{
	vector<char>v;
	for (int i = lower_limit; i <= upper_limit; ++i)
		v.push_back(i);
	return v;
}
