#include <iostream>
#include "Message.h"
#include "Numbers.h"

int main(array<System::String ^> ^args)
{
	Message M = Message("BACK TO CODING FEELSGOODMAN", 11, 13);
	std::cout << "Q: " << M.getQ() << std::endl;
	std::cout << "P: " << M.getP() << std::endl;
	std::cout << "N: " << M.getN() << std::endl;
	std::cout << "Z: " << M.getZ() << std::endl;
	std::cout << "D: " << M.getD() << std::endl;
	std::cout << "E: " << M.getE() << std::endl;
	std::cout << "MESSAGE: " << M.getMessage() << std::endl;
	std::cout << "INVERSE(D,Z): " << Numbers::InverseModular(M.getD(), M.getZ()) << std::endl;
	std::cout << "GCD(D,Z): " << Numbers::GCD(M.getD(), M.getZ()) << std::endl;
	std::cout << "ENCRYPTED MESSAGE: " << M.getEncryptedMessage() << std::endl;
	std::cout << "DESENCRYPTED MESSAGE: " << M.getDesencryptedMessage() << std::endl;
	system("pause");
	return 0;
}