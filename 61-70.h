
size_t Problem61()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem62()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem63()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem64()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem65()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem66()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem67()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem68()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem69()
{
	size_t answer = 0;
	double max = 0;
	for(double n = 2; n <= 1000000; n++)
	{
		double p = phi(n);
		double ratio = n / p;
		if( ratio > max)
		{
			max = ratio;
			answer = n;
		}
			
	}
	
	return answer;
}

size_t Problem70()
{
	size_t answer = 0;
	double min = 10;
	for(size_t n = 8000000; n <= 10000000; n++)
	{
		if(isPermutation(n,phi(n)))
		{
			double nD = n;
			double nP = phi(n);
			double ratio = nD/nP;
			if(ratio < min)
			{
				min = ratio;
				answer = n;
				cout << "n: " << n << "   Phi(n) = " << nP << "   n/Phi(n)= Ratio: " << ratio << endl;
			}
		}
	}
	
	return answer;
}
