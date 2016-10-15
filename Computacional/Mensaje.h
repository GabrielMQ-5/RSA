#pragma once
#include <string>
#include <vector>
#include "Diccionario.h"

using namespace std;

class Mensaje
{
private:
	static Diccionario Dic;

	string message;

	string encryptedmessage;
	string desencryptedmessage;

	long long q;
	long long p;
	long long n;
	long long z;

	long long d;
	long long e;

	void generatePrivateKey();
	void generatePublicKey();

public:
	Mensaje(string message, long long p, long long q);
	~Mensaje();

	string getMessage();
	string getEncryptedMessage();
	string getDesencryptedMessage();

	long long getQ();
	long long getP();
	long long getN();
	long long getZ();
	long long getD();
	long long getE();

	void setMessage(string message);
	void setQ(long long q);
	void setP(long long p);
	void setN(long long n);
	void setZ(long long z);


	//Delegation: Software Pattern Design
	bool isInDictionary(char c);
	int getDictionarySize();
	char getChar(int position);
	int getLowerLimit();
	int getUpperLimit();
};

