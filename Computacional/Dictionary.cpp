#include "Dictionary.h"

Dictionary::Dictionary() : lower_limit(32), upper_limit(255)
{
}

Dictionary::~Dictionary()
{
}

bool Dictionary::isInDictionary(char c)
{
	int temp = static_cast<int>(c);
	if (temp > upper_limit) return false;
	else if (temp < lower_limit) return false;
	else return true;
}

int Dictionary::getLowerLimit()
{
	return lower_limit;
}

int Dictionary::getUpperLimit()
{
	return upper_limit;
}
