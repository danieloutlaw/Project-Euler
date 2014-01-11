#include "contents.h"

using namespace std;

size_t Problem142()
{
	size_t answer = 0;
	if(isSquare(205))
		return 7;
	size_t j = 1;
	for(size_t x = 2000000; x <= 3000000; x+= j)
	{
		for(size_t y = x - 1; y >= 1; y--)
			if(isSquare(x + y) && isSquare(x - y))
			//	cout << x << ", " << y << endl;
		
	
			
			
				for(size_t z = y - 1; z >= 1; z--)
					if(isSquare(x + z) && isSquare(x - z) && isSquare(y + z) && isSquare(y - z))
						cout << x << ", " << y << ", " << z << endl;
	
	j += 2;
   }
	return answer;
} 

size_t Problem46()
{
	size_t answer = 0;
	
/*	for(size_t i = 1001; i < 100000; i += 2)
		if(!primeCheck(i))
		{
			
		}
	*/
	return answer;
}
/*
size_t Problem266()
{
	size_t answer = 0;
	size_t primes = 1;
	size_t primeArray[100] = {0};
	getPrimes(primeArray, sqrt(190));
	primes = productOfArray(primeArray);
	cout << setprecision(16) << primes << endl;
//	for(size_t i )
	size_t test = 5397346292805549782720214077673687806275517530364350655459511599582614290 % 10000000000000000;
	answer = psr(primes);
	std::cout << std::setprecision(16) << answer << endl;
	return answer;
}
*/

// Array of posize_ters to the problem functions

size_t Problem145()
{
	size_t answer = 0;
	for(int i = 1; i <= 1000000000; i++)
		if(isReversible(i))
			answer++;
	
	return answer;
}

size_t Problem162()
{
	size_t answer = 0;
	for(int i = 4; i <= 4; i++)
		answer += (15*16*((i-1))) + (41*(14*(i-1))) - (((43*(15*(i-1))) + (13*i)));
	return answer;
}

size_t Problem762()
{
	size_t answer = 0;
	
	size_t partitions[101] = {0};
	partitions[0] = 1;
 
	for (int i = 1; i <= 99; i++) 
    	for (int j = i; j <= 100; j++) 
	        partitions[j] += partitions[j - i];
	answer = partitions[100];
	
	return answer;
}

size_t Problem772()
{
	size_t answer = 0;
	
	size_t partitions[10001] = {0};
	partitions[0] = 1;
 
	for (int i = 1; i <= 99; i++) 
    	for (int j = i; j <= 100; j++) 
	        partitions[j] += partitions[j - i];
	answer = partitions[100];
	
	return answer;
}

size_t Problem782()
{
	size_t answer = 0;
	
	
	
	return answer;
}

size_t Problem522()
{
	size_t answer = 0;
	size_t x = 1;
	bool found = false;
	while(!found)
	{
		x *= 10;
		for(int i = x; i < x * 10 / 6; i++)
		{
			found = true;
			for(int j = 2; j <= 6; j++)
				if(!isPermutation(i, j * i))
				{
					found = false;
					break;
				}
			if(found)
			{
				answer = i;
				break;
			}
		}
	}
	
	return answer;
}

double sqrtIteration(double n)
{
	if(n == 0)
		return 0;
	return 1/(2 + sqrtIteration(n-1));
}

size_t Problem572()
{
	size_t answer = 0;
	
	size_t n = 3;
	size_t d = 2;
	size_t c = 0;
	 
	for (int i = 2; i <= 1000; i++)
	{
		n = n + (d * 2);
		d = n + d;
//		n = temp;
//		d = temp2;
		if(digits(n) > digits(d))
			answer++;
	}

	
//	answer = 1 + sqrtIteration(1000);
		
	
	return answer;
}

size_t Problem692()
{
	size_t answer = 0;
	size_t primes[5000];
	getPrimes(primes, 50000);
	for(int i = 0; i <= 5000; i++)
	
	return answer;
}

void computePossibleResult(int result[], size_t faces, size_t dice, size_t sum, int next)
{
	if(dice == 0)
	{
		next++;
		result[next] = sum;
	}	
	else
		for(int i = 1; i <= faces; i++)
			computePossibleResult(result, faces, dice-1, i+sum, next);
}


double Problem205()
{
	
	for(int i = 1; i <= 4; i++)
	for(int j = 1; j <= 4; j++)
	for(int k = 1; k <= 4; k++)
	for(int l = 1; l <= 4; l++)
	for(int m = 1; m <= 4; m++)
	for(int n = 1; n <= 4; n++)
	for(int o = 1; o <= 4; o++)
	for(int p = 1; p <= 4; p++)
	for(int q = 1; q <= 4; q++)
	for(int g = 1; g <= 4; g++)
		pcount = pcount + 1;
	
	double answer = 0;
//	size_t petef = 4;
//	size_t peted = 9;
//	size_t colinf = 6;
//	size_t colind = 6;
	int peter[262144];
	int colin[46656];
	int next = 0;
	
	computePossibleResult(peter, 4, 9, 0, next);
	next = 0;
	computePossibleResult(colin, 6, 6, 0, next);
	
	for(int i = 0; i < 262144; i++)
		for(int j = 0; j < 46656; j++)
			if(peter[i] > colin[j])
				answer++;
	
	size_t temp = 12230590464;
	answer /= temp;
	
	return answer;
}

typedef size_t (*FunctionList)();

int main(int argc, char *argv[]) 
{
	FunctionList functptr[101] = { Problem0,
	Problem1, Problem2, Problem3, Problem4, Problem5, Problem6, Problem7, Problem8, Problem9, Problem10,
	Problem11, Problem12, Problem13, Problem14, Problem15, Problem16, Problem17, Problem18, Problem19, Problem20,
	Problem21, Problem22, Problem23, Problem24, Problem25, Problem26, Problem27, Problem28, Problem29, Problem30,
	Problem31, Problem32, Problem33, Problem34, Problem35, Problem36, Problem37, Problem38, Problem39, Problem40,
	Problem41, Problem42, Problem43, Problem44, Problem45, Problem46, Problem47, Problem48, Problem49, Problem50,
	Problem51, Problem52, Problem53, Problem54, Problem55, Problem56, Problem57, Problem58, Problem59, Problem60,
	Problem61, Problem62, Problem63, Problem64, Problem65, Problem66, Problem67, Problem68, Problem69, Problem70,
	Problem71, Problem72, Problem73, Problem74, Problem75, Problem76, Problem77, Problem78, Problem79, Problem80,
	Problem81, Problem82, Problem83, Problem84, Problem85, Problem86, Problem87, Problem88, Problem89, Problem90,
	Problem91, Problem92, Problem93, Problem94, Problem95, Problem96, Problem97, Problem98, Problem99, Problem100
	};
	
	int choice = 0;
	do
	{
	cout << "Enter the number of the problem you want to run (up to 100) or type 0 to quit. ";
	cin >> choice;
	if(choice == 0)
		return 0;
	while(choice > 100)
	{
		cout << "I have not done any problems over 100. Please pick a smaller number. ";
		cin >> choice;
	}

	cout << "The answer to Problem " << choice << " is: " << functptr[choice]() << endl;
	}while(choice != 0);

	return 0;
}




