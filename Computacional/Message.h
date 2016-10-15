#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <vector>
#include "Dictionary.h"

class Message
{
private:
	static Dictionary Dic;

	std::string message;

	std::string encryptedmessage;
	std::string desencryptedmessage;

	long long q;
	long long p;
	long long n;
	long long z;

	long long d;
	long long e;

	void generatePrivateKey();
	void generatePublicKey();

public:
	Message(std::string message, long long p, long long q);
	~Message();

	std::string getMessage();
	std::string getEncryptedMessage();
	std::string getDesencryptedMessage();

	long long getQ();
	long long getP();
	long long getN();
	long long getZ();
	long long getD();
	long long getE();

	void setMessage(std::string message);
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
#endif