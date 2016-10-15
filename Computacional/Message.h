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

	long long p;
	long long q;
	long long z;
	long long n;

	long long d;
	long long e;

	void generatePrivateKey();
	void generatePublicKey();
	void encryptMessage();
	void desencryptMessage();

public:
	Message(std::string message, long long p, long long q);
	~Message();

	std::string getMessage();
	std::string getEncryptedMessage();
	std::string getDesencryptedMessage();

	long long getP();
	long long getQ();
	long long getZ();
	long long getN();
	long long getD();
	long long getE();

	void setMessage(std::string message);
	void setQ(long long q);
	void setP(long long p);
	void setN(long long n);
	void setZ(long long z);



	//Delegation: Software Pattern Design
	bool isInDictionary(char c);
	int getLowerLimit();
	int getUpperLimit();
};
#endif