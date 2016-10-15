#pragma once
#include <vector>

using namespace std;

class Diccionario
{
private:
	static const vector<char>Dictionary;
	static const int lower_limit;
	static const int upper_limit;
	static vector<char>generateDictionary();
public:
	Diccionario();
	~Diccionario();
	bool isInDictionary(char c);
	int getDictionarySize();
	char getChar(int position);
	int getLowerLimit();
	int getUpperLimit();
};

