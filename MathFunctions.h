#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <math.h>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

/*struct myclass
{
	bool operator() (size_t i, size_t j) { return (i<j); }
}   myobject;  */

string to_string(double x)
{
	std::ostringstream ss;
	ss << x;
	return ss.str();
} 

bool primeCheck(size_t x)
{
	if(x == 2)
		return true;
	else if(x % 2 == 0 || x < 2 )
		return false;
	for(size_t k = 3; k <= sqrt(x); k+= 2)
				if( x % k == 0 )
					return false;
	return true;
}

size_t digits(size_t x)
{
	assert(x >= 0 && x < pow(10,73));
	if(x < 10)
		return 1;
	else if(x < 100)
		return 2;
	else if(x < 1000)
		return 3;
	else if(x < 10000)
		return 4;
	else if(x < 100000)
		return 5;
	else if(x < 1000000)
		return 6;
	else if(x < 10000000)
		return 7;
	else if(x < 100000000)
		return 8;
	else if(x < 1000000000)
		return 9;
	else if(x < 10000000000)
		return 10;
	else if(x < pow(10,11))
		return 11;
	else if(x < pow(10,12))
		return 12;
	else if(x < pow(10,13))
		return 13;
	else if(x < pow(10,14))
		return 14;
	else if(x < pow(10,15))
		return 15;
	else if(x < pow(10,16))
		return 16;
	else if(x < pow(10,17))
		return 17;
	else if(x < pow(10,18))
		return 18;
	else if(x < pow(10,19))
		return 19;
	else if(x < pow(10,20))
		return 20;
	else if(x < pow(10,21))
		return 21;
	else if(x < pow(10,22))
		return 22;
	else if(x < pow(10,23))
		return 23;
	else if(x < pow(10,24))
		return 24;
	else if(x < pow(10,25))
		return 25;
	else if(x < pow(10,26))
		return 26;
	else if(x < pow(10,27))
		return 27;
	else if(x < pow(10,28))
		return 28;
	else if(x < pow(10,29))
		return 29;
	else if(x < pow(10,30))
		return 30;
	else if(x < pow(10,31))
		return 31;
	else if(x < pow(10,32))
		return 32;
	else if(x < pow(10,33))
		return 33;
	else if(x < pow(10,34))
		return 34;
	else if(x < pow(10,35))
		return 35;
	else if(x < pow(10,36))
		return 36;
	else if(x < pow(10,37))
		return 37;
	else if(x < pow(10,38))
		return 38;
	else if(x < pow(10,39))
		return 39;
	else if(x < pow(10,40))
		return 40;
	else if(x < pow(10,41))
		return 41;
	else if(x < pow(10,42))
		return 42;
	else if(x < pow(10,43))
		return 43;
	else if(x < pow(10,44))
		return 44;
	else if(x < pow(10,45))
		return 45;
	else if(x < pow(10,46))
		return 46;
	else if(x < pow(10,47))
		return 47;
	else if(x < pow(10,48))
		return 48;
	else if(x < pow(10,49))
		return 49;
	else if(x < pow(10,50))
		return 50;
	else if(x < pow(10,51))
		return 51;
	else if(x < pow(10,52))
		return 52;
	else if(x < pow(10,53))
		return 53;
	else if(x < pow(10,54))
		return 54;
	else if(x < pow(10,55))
		return 55;
	else if(x < pow(10,56))
		return 56;
	else if(x < pow(10,57))
		return 57;
	else if(x < pow(10,58))
		return 58;
	else if(x < pow(10,59))
		return 59;
	else if(x < pow(10,60))
		return 60;
	else if(x < pow(10,61))
		return 61;
	else if(x < pow(10,62))
		return 62;
	else if(x < pow(10,63))
		return 63;
	else if(x < pow(10,64))
		return 64;
	else if(x < pow(10,65))
		return 65;
	else if(x < pow(10,66))
		return 66;
	else if(x < pow(10,67))
		return 67;
	else if(x < pow(10,68))
		return 68;
	else if(x < pow(10,69))
		return 69;
	else if(x < pow(10,70))
		return 70;
	else if(x < pow(10,71))
		return 72;
	else
		return 73;	
}

void primeFactors(size_t x, size_t factors[], size_t count, size_t a)
{ // begin with a = 0 and count = 2
	if(a != 5000){
	if(!primeCheck(x))
	{
		if(x % count == 0)
		{
			x /= count;
			factors[a] = count;
			count = 2;
				do
				{
					if(primeCheck(count))
					{
						primeFactors(x, factors, count, a+1);
						a = 5000;
					}
					count++;
					if(count > x)
						count = 2;
				}while(a != 5000);
		}
		else
		{
			count++;
			do
			{
				if(primeCheck(count))
				{
					primeFactors(x, factors, count, a);
					a = 5000;
				}
				count++;
				if(count > x)
					count = 2;
			}while(a != 5000);
		}
	}
	else
	{
		factors[a] = x;	
		a = 5000;
	}
	}
}

size_t *toBinary(size_t x)
{
	size_t n = 0;
	for(size_t i = 1; pow(2,i) <= x; i++)
		n++;
	size_t *binPtr = new size_t[n+2];
	for(size_t i = n; i >= 0; i--)
	{
		if(x >= pow(2,i))
		{
			binPtr[i] = 1;
			x -= pow(2,i);
		}
		else
			binPtr[i] = 0;
	}
	binPtr[n+1] = 99;
	return binPtr;
}

bool isPalindrome(size_t x)
{
	size_t d = digits(x);
	size_t dig[d];
	for(size_t k = 1; k <= d; k++)
	{
		size_t mod = pow(10, k);
		size_t div = mod / 10;
		dig[k-1] = x % mod;
		dig[k-1] /= div;
	}
	size_t n = d - 1;
	bool isPossible = true;
	for(size_t k = 0; k <= n; k++)
	{
		if(dig[k] != dig[n])
		{
			isPossible = false;
			k = n + 2;
		}
		n--;
	}
	return isPossible;
}

bool isPalindrome(size_t* &dig)
{		// Looks for '99' as the terminating number
	size_t n = 0;
	bool isPossible = true;
	do{ n++; }while(dig[n] != 99);
	n--;
	for(size_t k = 0; k <= n; k++)
	{
		if(dig[k] != dig[n])
			isPossible = false;
		n--;
	}
	
	return isPossible;
}

size_t factorial(size_t x)
{
	assert(x >= 0);
	size_t f = 1;
	for(size_t i = 1; i <= x; i++)
		f *= i;
	return f;
}

void toDigits(size_t x, size_t dig[])
{
	for(size_t i = 0; i < digits(x); i++)
	{
		size_t num = pow(10, i+1);
		dig[digits(x)-i-1] = x % num;
		num /= 10;
		dig[digits(x)-i-1] /= num;
	}
}

/*
void toDigits(size_t x, size_t dig[])
{
	for(size_t i = 0; i < digits(x); i++)
	{
		size_t num = pow(10, i+1);
		dig[digits(x)-i-1] = x % num;
		num /= 10;
		dig[digits(x)-i-1] /= num;
	}
} */

size_t digitsToNumber(size_t dig[], size_t size)
{	// size tells the function how large the array is
	size_t x = 0;
	for(size_t i = 0; i < size; i++)
	{
		size_t n = pow(10,size - i - 1);
		x += dig[i]*n;
	}
	return x;
}

bool isSquare(size_t x)
{
	double dS = sqrt(x);
	size_t iS = dS;
	if(iS == dS)
		return true;
	else
		return false;
}

void getTriangleNumbers(unsigned long long triangle[], size_t size)
{
	for(unsigned long long i = 0; i < size; i++)
		triangle[i] = (i*(i+1))/2;
}

void getPentagonalNumbers(size_t pentegonal[], size_t size)
{
	for(size_t i = 0; i < size; i++)
		pentegonal[i] = (i*((3*i)-1))/2;
}

void getHexagonalNumbers(size_t hexagonal[], size_t size)
{
	for(size_t i = 0; i < size; i++)
		hexagonal[i] = i*((2*i)-1);
}

bool isTriangle(size_t check)
{
	double n = (sqrt((8*check + 1) -1))/2;
	size_t x = sqrt((8*check + 1) -1)/2;
	if(n == x)
		return true;
	else
		return false;
}

bool isPentagonal(size_t check)
{
	double n = (sqrt(24*check + 1) + 1)/6;
	size_t x = (sqrt(24*check + 1) + 1)/6;
	if(n == x)
		return true;
	else
		return false;
}

bool isHexagonal(size_t check)
{
	double n = (sqrt(8*check + 1)+1)/4;
	size_t x = (sqrt(8*check + 1)+1)/4;
	if(n == x)
		return true;
	else
		return false;
}

size_t gcd(size_t n, size_t d)
{
	while(d != 0)
	{
		size_t x = d;
		d = n % x;
		n = x;
	}
	return n;		
}

size_t phi(size_t d)
{
	if(primeCheck(d))
			return d - 1;
		else
		{
			size_t factors[100] = {0};
			size_t a = 0;
			size_t c = 2;
			size_t temp = d;
			primeFactors(d, factors, c, a);
			for(size_t i = 0; factors[i] != 0; i++)
				for(size_t k = 0; factors[k] != 0; k++)
					if(i != k && factors[i] == factors[k])
						factors[k] = 90;

			for(size_t i = 0; factors[i] != 0; i++)
				if(factors[i] != 90)
					temp -= temp/factors[i];
			return temp;
		}
}

bool isPermutation(size_t x, size_t y)
{
	if(digits(y) != digits(x))
		return false;
	size_t digx[digits(x)];
	size_t digy[digits(y)];
	toDigits(x, digx);
	toDigits(y, digy);
	size_t dx[10] = {0};
	size_t dy[10] = {0};
	bool isPossible = true;
	for(size_t i = 0; i < digits(x); i++)
		dx[digx[i]]++;
	for(size_t i = 0; i < digits(y); i++)
		dy[digy[i]]++;
	for(size_t i = 0; i < 10; i++)
		if(dx[i] != dy[i])
			isPossible = false;
	return isPossible;
}

size_t psr(size_t x)
{
	for(size_t i = sqrt(x); i > 1; i--)
	{
		size_t d = x;
		if(d % i == 0)
			return i;
	}
		
}

void getPrimes(size_t array[], size_t max)
{
	array[0] = 2;
	size_t count = 1;
	
	for(double i = 3; i <= max; i += 2)
		if(primeCheck(i))
		{
			array[count] = i;
			count++;
		}
//		2323218950681478446587187180516779545
//		2305567963945518424753102147331756070
}

size_t productOfArray(size_t array[])
{
	size_t answer = 1;
	for(size_t i = 0; array[i] != 0; i++)
	{
		answer *= array[i] % 10000000000000000;
		std::cout << std::setprecision(16) << array[i] << ",  " << answer << endl;
	}
		
	return answer;
}

long long partitions(long long n)
{
	long long answer = 0;
	long long temp = 0;
	for(int k = 1; k <=n; k++)
	{
		temp += pow(-1,k+1);
		long long temp2 = 0;
		temp2 = partitions(n-((1/2)*k*(3*k-1)));
		temp2 += partitions(n-((1/2)*k*(3*k+1)));
		temp *= temp2;
		answer += temp;
	}
	
	
	
	return answer;
}

size_t reverse(size_t n)
{
	size_t answer = 0;
	size_t num = digits(n);
	size_t dig[100] = {0};
	toDigits(n,dig);
	size_t test = 0;
	if(num % 2 == 0)
		test = num/2;
	else
		test = num/2 + 1;
	for(int i = 0; i < test; i++)
	{
		size_t temp = dig[i];
		dig[i] = dig[num - i - 1];
		dig[num - i - 1] = temp;
	}
	for(int i = 0; i < num; i++)
	{
		size_t x = pow(10,num - i - 1);
		answer += dig[i]*x;
	}
	
		answer =  digitsToNumber(dig, num);
	return answer;
	
}

bool isLychrel(size_t n)
{
	bool answer = true;
	for(int i = 1; i <= 30; i++)
	{
		size_t k = reverse(n);
		n += k;
		
		if(isPalindrome(n))
		{
			return false;
		}
			
	}
	return answer;
}

bool isReversible(size_t n)
{
	size_t x = reverse(n);
	if(digits(n) == digits(x))
	{
		size_t dig[100] = {0};
		size_t k = n + x;
		toDigits(k, dig);
		for(int i = 0; i < digits(k); i++)
			if((dig[i]) % 2 == 0)
				return false;				
	}
	else
		return false;
	return true;
}
