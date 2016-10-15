#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>

class Dictionary
{
private:
	const std::vector<char>D;
	const int lower_limit;
	const int upper_limit;
	std::vector<char>generateDictionary();
public:
	Dictionary();
	~Dictionary();
	bool isInDictionary(char c);
	int getDictionarySize();
	char getChar(int position);
	int getLowerLimit();
	int getUpperLimit();
};
#endif
