size_t Problem31()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem32()
{
	size_t answer = 0;
	size_t holder[10] = {0};
	size_t spot = 0;
	
	for(size_t i = 12; i <= 98; i++)
		for(size_t k = 123; k < 987; k++)
		{
		if(i*k < 10000)
		{
			size_t dig1[2] = {0};
			size_t dig2[3] = {0};
			size_t dig3[4] = {0};
			size_t dig4[9] = {0};
			toDigits(i, dig1);
			toDigits(k, dig2);
			toDigits(i*k, dig3);
			bool isPossible = true;
			
			dig4[0] = dig1[0];
			dig4[1] = dig1[1];
			dig4[2] = dig2[0];
			dig4[3] = dig2[1];
			dig4[4] = dig2[2];
			dig4[5] = dig3[0];
			dig4[6] = dig3[1];
			dig4[7] = dig3[2];
			dig4[8] = dig3[3];
			
			bool here = false;
			for(size_t m = 0; m <= 8; m++)
				for(size_t n = 0; n <= 8; n++)
					if((dig4[n] == dig4[m] || dig4[n] == 0) && m != n)
					{
						here = true;
						m = 9;
						n = 9;
					}
			size_t check = digitsToNumber(dig3, 4);
			for(size_t p = 0; p < 10; p++)
				if(check == holder[p])
					here = true;
			if(!here)
			{
				answer += check;
				holder[spot] = check;
				spot++;
			}
		}
		}
	for(size_t i = 1; i <= 9; i++)
		for(size_t k = 1234; k < 9876; k++)
		{
		if(i*k < 10000)
		{
			size_t dig1 = i;
			size_t dig2[4] = {0};
			size_t dig3[4] = {0};
			size_t dig4[9] = {0};
			toDigits(k, dig2);
			toDigits(i*k, dig3);
			bool isPossible = true;
			
			dig4[0] = dig1;
			dig4[1] = dig2[0];
			dig4[2] = dig2[1];
			dig4[3] = dig2[2];
			dig4[4] = dig2[3];
			dig4[5] = dig3[0];
			dig4[6] = dig3[1];
			dig4[7] = dig3[2];
			dig4[8] = dig3[3];
			
			bool here = false;
			for(size_t m = 0; m <= 8; m++)
				for(size_t n = 0; n <= 8; n++)
					if((dig4[n] == dig4[m] || dig4[n] == 0) && m != n)
					{
						here = true;
						m = 9;
						n = 9;
					}
			size_t check = digitsToNumber(dig3, 4);
			for(size_t p = 0; p < 10; p++)
				if(check == holder[p])
					here = true;
			if(!here)
			{
				answer += check;
				holder[spot] = check;
				spot++;
			}
		}
		}	
	
	return answer;
}

size_t Problem33()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem34()
{
	size_t answer = 0;
	for(size_t i = 11; i <= 1000000; i++)
	{
		size_t d = digits(i);
		size_t dig[d];
		size_t count = 0;
		for(size_t k = 1; k <= d; k++)
			{
				size_t mod = pow(10, k);
				size_t div = mod / 10;
				dig[k-1] = i % mod;
				dig[k-1] /= div;
				count += factorial(dig[k-1]);
			}
		if(count == i)
			answer += i;
	}	
	return answer;
}

size_t Problem35()
{
	size_t answer = 4; 		// 2, 3, 5, and 7 are single digit circular primes
	for(size_t i = 11; i <= 1000000; i++)
		if(primeCheck(i))
		{
			size_t check = digits(i);
			size_t dig[check];
			for(size_t k = 1; k <= check; k++)
			{
				size_t mod = pow(10, k);
				size_t div = mod / 10;
				dig[k-1] = i % mod;
				dig[k-1] /= div;
			}
			bool isPossible = true;
			for(size_t k = 1; k <= check; k++)
			{
				if(dig[k-1] != 1 && dig[k-1] != 3 && dig[k-1] != 7 && dig[k-1] != 9)
					isPossible = false;
			}
			if(isPossible)
			{
				size_t temp = 0;
				if(check > 1)
				{
					for(size_t w = 1; w < check; w++)
					{
						temp = dig[0];
						for(size_t k = 1; k <= check; k++)
							dig[k-1] = dig[k];
						dig[check-1] = temp;
						size_t test = 0;
						for(size_t k = 1; k <= check; k++)
						{
						
							size_t mul = dig[k-1];
							mul *= pow(10,k-1);
							test += mul;
						}
						if(!primeCheck(test))
						{
							isPossible = false;
							w = check;
						}
					}	
				}
				if(isPossible)
					answer += 1;
			}
		}
	return answer;
}

size_t Problem36()
{
	size_t answer = 0;
	for(size_t i = 1; i < 1000000; i++)
	{
		size_t *ptr = toBinary(i);
		if(isPalindrome(i))
			if(isPalindrome(ptr))
				answer += i;
	}
	return answer;
}

size_t Problem37()
{
	size_t answer = 0;
	
	for(size_t i = 11; i <= 1000000; i+= 2)
		if( primeCheck(i) )
			if( primeCheck(i % 100000) )
				if( primeCheck(i % 10000) )
					if(primeCheck(i % 1000))
						if(primeCheck(i % 100))
							if(primeCheck(i % 10))
								if(primeCheck(i / 10000) || i < 10000 )
									if(primeCheck(i / 1000) || i < 1000 )
										if(primeCheck(i / 100) || i < 100 )
											if(primeCheck(i / 10) || i < 10)
												answer += i;
	return answer;
}

size_t Problem38()
{
	size_t answer = 0;
	for(size_t i = 9182; i < 9876; i++)
	{
		size_t t = i * 2;
		size_t dig[9] = {0};
		dig[0]= i % 10;
		dig[1] = i % 100;
		dig[1] /= 10;
		dig[2] = i % 1000;
		dig[2] /= 100;
		dig[3] = i % 10000;
		dig[3] /= 1000;
		dig[4] = t % 10;
		dig[5] = t % 100;
		dig[5] /= 10;
		dig[6] = t % 1000;
		dig[6] /= 100;
		dig[7] = t % 10000;
		dig[7] /= 1000;
		dig[8] = t % 100000;
		dig[8] /= 10000;
		size_t check = 0;
		for(size_t k = 0; k < 9; k++)
			check += dig[k];
		bool isPossible = true;
		for(size_t k = 0; k < 9; k++)
			for(size_t l = 0; l < 9; l++)
				if((dig[k] == dig[l] && l != k) || dig[l] == 0)
				{
					isPossible = false;
					k = 10;
					l = 10;
				}
		if(check == 45 && isPossible)
		{
			answer = i * 100000;
			answer += t;
		}		
	}
	return answer;
}

size_t Problem39()
{
	size_t answer = 0;
	
	return answer;
}


