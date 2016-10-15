#include "Message.h"
#include "Numbers.h"

Dictionary Message::Dic = Dictionary();

Message::Message(std::string mes, long long p, long long q)
{
	message = mes;
	this->p = p;
	this->q = q;
	n = p*q;
	z = (q - 1)*(p - 1);
}

Message::~Message()
{
}

std::string Message::getMessage()
{
	return message;
}

std::string Message::getEncryptedMessage()
{
	return encryptedmessage;
}

std::string Message::getDesencryptedMessage()
{
	return desencryptedmessage;
}

long long Message::getQ()
{
	return q;
}

long long Message::getP()
{
	return p;
}

long long Message::getN()
{
	return n;
}

long long Message::getZ()
{
	return z;
}

long long Message::getD()
{
	return d;
}

long long Message::getE()
{
	return e;
}

bool Message::isInDictionary(char c)
{
	return Dic.isInDictionary(c);
}

int Message::getDictionarySize()
{
	return Dic.getDictionarySize();
}

char Message::getChar(int position)
{
	return Dic.getChar(position);
}

int Message::getLowerLimit()
{
	return Dic.getLowerLimit();
}

int Message::getUpperLimit()
{
	return Dic.getUpperLimit();
}

void Message::setMessage(std::string message)
{
	this->message = message;
}

void Message::setQ(long long q)
{
	this->q = q;
}

void Message::setP(long long p)
{
	this->p = p;
}

void Message::setN(long long n)
{
	this->n = n;
}

void Message::setZ(long long z)
{
	this->z = z;
}

void Message::generatePublicKey()
{
	e = Numbers::InverseModular(d, z);
}

void Message::generatePrivateKey()
{

}