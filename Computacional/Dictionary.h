#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>

class Dictionary
{
private:
	const int lower_limit;
	const int upper_limit;
public:
	Dictionary();
	~Dictionary();
	bool isInDictionary(char c);
	int getLowerLimit();
	int getUpperLimit();
};
#endif
