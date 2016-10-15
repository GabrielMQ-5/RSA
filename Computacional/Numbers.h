#pragma once
class Numbers
{
public:
	Numbers();
	~Numbers();

	template<typename T>
	static T MCD(T a, T b);

	template<typename T>
	static bool isPrime(T number);

	template<typename T>
	static T LinearCongruence(T a, T b, T m);

	template<typename T>
	static T InverseModular(T a, T b);

	template<typename T>
	static T Inverse1(T a, T b);

	template<typename T>
	static T Inverse2(T a, T b);

	template<typename T>
	static T Inverse3(T a, T b, T c);
};

template<typename T>
T Numbers::MCD(T a, T b)
{
	return b == 0 ? a : MCD(b, a % b);
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
T Numbers::LinearCongruence(T a, T b, T m)
{
	T inverse = InverseModular(a, m);
	return ( inverse*b ) % m ;
}

template<typename T>
T Numbers::InverseModular(T a, T b)
{
	if (isPrime(b) && MCD(a, b) == 1) return Inverse3(a, b - 2, b);
	else if (MCD(a, b) == 1) return Inverse2(a, b);
	else return Inverse1(a, b);
}

template<typename T>
T Numbers::Inverse1(T a, T b)
{
	a %= b;
	for (int x = 1; x < b; x++)
		if ((a*x) % b == 1)
			return x;
}

template<typename T>
T Numbers::Inverse2(T a, T b)
{
	T m0 = b, t, q;
	T x0 = 0, x1 = 1;

	if (b == 1)
		return 0;

	while (a > 1)
	{
		q = a / b;
		t = b;
		b = a % b, a = t;
		t = x0;
		x0 = x1 - q * x0;
		x1 = t;
	}

	if (x1 < 0)
		x1 += m0;

	return x1;
}

template<typename T>
T Numbers::Inverse3(T a, T b, T c)
{
	if (b == 0)
		return 1;
	T p = Inverse3(a, b / 2, c) % c;
	p = (p * p) % c;
	return (b % 2 == 0) ? p : (a * p) % c;
}
