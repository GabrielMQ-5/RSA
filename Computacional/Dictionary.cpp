#include "Dictionary.h"

Dictionary::Dictionary() : lower_limit(65), upper_limit(90), D(generateDictionary())
{
}

Dictionary::~Dictionary()
{
}

bool Dictionary::isInDictionary(char c)
{
	if (c > upper_limit) return false;
	else if (c < lower_limit) return false;
	else return true;
}

int Dictionary::getDictionarySize()
{
	return D.size();
}

char Dictionary::getChar(int c)
{
	return D[c];
}

int Dictionary::getLowerLimit()
{
	return lower_limit;
}

int Dictionary::getUpperLimit()
{
	return upper_limit;
}

std::vector<char>Dictionary::generateDictionary()
{
	std::vector<char>v;
	for (int i = lower_limit; i <= upper_limit; ++i)
		v.push_back(i);
	return v;
}
