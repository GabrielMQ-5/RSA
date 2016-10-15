#include "Message.h"
#include "Numbers.h"
#include <random>

Dictionary Message::Dic = Dictionary();

Message::Message(std::string mes, long long p, long long q)
{
	message = mes;
	this->p = p;
	this->q = q;
	z = (q - 1)*(p - 1);
	n = p*q;
	generatePrivateKey();
	generatePublicKey();
	encryptMessage();
	desencryptMessage();
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
	std::mt19937_64 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937_64::result_type> dist(2, z - 1);
	// distribution in range [2, z-1] since d < z && GCD(d,z)=1
	do
	{
		d = dist(rng);
	} while (Numbers::GCD(d, z) != 1);
}

void Message::encryptMessage()
{
	for (size_t i = 0; i < message.size(); ++i)
	{
		int m = static_cast<int>(message[i]);
		char c = static_cast<char>(Numbers::ModularExponentiation(static_cast<long long>(m), e, n));
		encryptedmessage.push_back(c);
	}
}

void Message::desencryptMessage()
{
	for (size_t i = 0; i < encryptedmessage.size(); ++i)
	{
		int c = static_cast<int>(encryptedmessage[i]);
		char m = static_cast<char>(Numbers::ModularExponentiation(static_cast<long long>(c), d, n));
		desencryptedmessage.push_back(m);
	}
}

