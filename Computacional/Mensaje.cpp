#include "Mensaje.h"
#include "Numbers.h"


Diccionario Mensaje::Dic = Diccionario();

Mensaje::Mensaje(string mes, long long p, long long q)
	: message(mes), p(p), q(q), n(p*q), z((q - 1)*(p - 1))
{
}

Mensaje::~Mensaje()
{
}

string Mensaje::getMessage()
{
	return message;
}

string Mensaje::getEncryptedMessage()
{
	return encryptedmessage;
}

string Mensaje::getDesencryptedMessage()
{
	return desencryptedmessage;
}

long long Mensaje::getQ()
{
	return q;
}

long long Mensaje::getP()
{
	return p;
}

long long Mensaje::getN()
{
	return n;
}

long long Mensaje::getZ()
{
	return z;
}

long long Mensaje::getD()
{
	return d;
}

long long Mensaje::getE()
{
	return e;
}

bool Mensaje::isInDictionary(char c)
{
	return Dic.isInDictionary(c);
}

int Mensaje::getDictionarySize()
{
	return Dic.getDictionarySize();
}

char Mensaje::getChar(int position)
{
	return Dic.getChar(position);
}

int Mensaje::getLowerLimit()
{
	return Dic.getLowerLimit();
}

int Mensaje::getUpperLimit()
{
	return Dic.getUpperLimit();
}

void Mensaje::setMessage(string message)
{
	this->message = message;
}

void Mensaje::setQ(long long q)
{
	this->q = q;
}

void Mensaje::setP(long long p)
{
	this->p = p;
}

void Mensaje::setN(long long n)
{
	this->n = n;
}

void Mensaje::setZ(long long z)
{
	this->z = z;
}

void Mensaje::generatePublicKey()
{
	e = Numbers::InverseModular(d, z);
}

void Mensaje::generatePrivateKey()
{

}