#ifndef NUMBERS_H
#define NUMBERS_H

//For references in this header:
//Linear Congruence: ax = b mod n  
//Inverse Modular: ax= 1 mod n
//GCD(a,b)

namespace Numbers
{
	template<typename T>
	T GCD(T a, T b);

	template<typename T>
	bool isPrime(T number);

	template<typename T>
	T LinearCongruence(T a, T b, T n);

	template<typename T>
	T InverseModular(T a, T n);

	template<typename T>
	T Inverse1(T a, T n);

	template<typename T>
	T Inverse2(T a, T n);

	template<typename T>
	T Inverse3(T a, T n2, T n);
};
#endif

template<typename T>
T Numbers::GCD(T a, T b)
{
	return b == 0 ? a : GCD(b, a % b);
}

template<typename T>
bool Numbers::isPrime(T number)
{
	if (number <= 2 || number % 2 == 0) return false;
	long long sqroot = static_cast<long long>(sqrt(number));
	for (int i = 3; i <= sqroot; i += 2)
		if (number%i == 0) return false;
	return true;
}

template<typename T>
T Numbers::LinearCongruence(T a, T b, T n)
{
	T inverse = InverseModular(a, n);
	return (inverse*b) % n;
}

template<typename T>
T Numbers::InverseModular(T a, T n)
{
	if (isPrime(n)) return Inverse3(a, n - 2, n);
	else if (GCD(a, n) == 1) return Inverse2(a, n);
	else return Inverse1(a, n);
}

template<typename T>
T Numbers::Inverse1(T a, T n)
{
	a %= n;
	for (int x = 1; x < n; x++)
		if ((a*x) % n == 1)
			return x;
}

template<typename T>
T Numbers::Inverse2(T a, T n)
{
	T m0 = n, t, q;
	T x0 = 0, x1 = 1;

	if (n == 1)
		return 0;

	while (a > 1)
	{
		q = a / n;
		t = n;
		n = a % n, a = t;
		t = x0;
		x0 = x1 - q * x0;
		x1 = t;
	}

	if (x1 < 0)
		x1 += m0;

	return x1;
}

template<typename T>
T Numbers::Inverse3(T a, T n2, T n)
{
	if (n2 == 0)
		return 1;
	T p = Inverse3(a, n2 / 2, n) % n;
	p = (p * p) % n;
	return (n2 % 2 == 0) ? p : (a * p) % n;
}
