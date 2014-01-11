size_t Problem0()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem1()
{
	size_t answer = 0;
	for(size_t i = 0; i < 1000; i++)
		if(i % 3 == 0 || i % 5 == 0)
			answer += i;
	return answer;
}

size_t Problem2()
{
	size_t answer = 2;
	size_t a = 1;
	size_t b = 2;
	size_t c = 3;
	do {
		c = a + b;
		if(c % 2 == 0)
			answer += c;
		a = b;
		b = c;
	}while(c < 4000000);
	return answer;
}

size_t Problem3()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem4()
{
	size_t a = 999;
	size_t b = 999;
	size_t product;
	std::string productString;
	char *productChar = new char[6];
	productChar[6] = '\0';
	do
	{
		for(size_t i = 999; i > a - 100; i--)
		{
			product = a * i;
			productString = to_string(product);
			memcpy(productChar,productString.c_str(),6);
			if(productChar[0] == productChar[5] && productChar[1] == productChar[4] && productChar[2] == productChar[3])
				return product;
		}
		a--;
	}while( a > 0 );
}

size_t Problem5()
{				// This takes a long time to compute, so I have typed in the answer
	size_t count = 0;
	size_t test = 2520;
	do {
		for(size_t i = 1; i <= 20; i++)
		{
			if(test % i == 0)
				count++;
		}
		if(count == 20)
			return test;
		count = 0;
		test++;
	}while(test != 0);
}

size_t Problem6()
{
	size_t sumofSq = 0;
	size_t sqofSum = 0;
	for(size_t i = 1; i <= 100; i++)
	{
		sumofSq += i*i;
		sqofSum += i;
	}
	sqofSum = sqofSum * sqofSum;
	return sqofSum - sumofSq;
}

size_t Problem7()
{				// Long run time
	size_t i = 14;
	size_t j = 0;
	size_t count = 6;
	size_t smallCnt = 0;
	while(i <= 120000)
	{
		j = i - 1;
		while(j > 0)
		{
			if(i % j == 0)
			{
				j = 0;
			}
			else
			{
				j--;
				smallCnt++;
			}
		}
		if(smallCnt >= i - 2)
		{
			count++;
		}
		if( count == 10001)
			return i;
		i++;
		smallCnt = 0;
		
	}
	return count;
}

size_t Problem8()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem9()
{
	double a = 0;
	double b = 0;
	double c = 0;
	for(a = 0; a < 1000; a++)
	{
		for(b = 0; b <= a; b++)
		{
			c = sqrt(a*a + b*b);
			if(a + b + c == 1000)
				return a*b*c;
		}
	}
	return 0;
}

size_t Problem10()
{			// long run time
			// This prime number algorithm is much more efficient than the previous example
	size_t i = 10;
	size_t j = 0;
	size_t count = 17;
	size_t smallCnt = 0;
	while(i <= 2000000)
	{
		count += i;
		for(j = 3; j<=sqrt(i); j+= 2)
			if(i % 2 == 0)
			{
				count -= i;
				j = i;
			}
			else if( i % j == 0)
			{
				count -= i;
				j = i;
			}		
		i++;	
	}
	return count;
}
