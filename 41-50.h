size_t Problem40()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem41()
{
	size_t answer = 0;
	
	size_t count = 0;
	for(size_t i = 1234567; i <= 7654321; i++)
	{
		size_t dig[7] = {0};
		
		dig[0]= i % 10;
		dig[1] = i % 100;
		dig[1] /= 10;
		dig[2] = i % 1000;
		dig[2] /= 100;
		dig[3] = i % 10000;
		dig[3] /= 1000;
		dig[4] = i % 100000;
		dig[4] /= 10000;
		dig[5] = i % 1000000;
		dig[5] /= 100000;
		dig[6] = i % 10000000;
		dig[6] /= 1000000;
		bool areEqual = false;
		for(size_t k = 0; k < 7; k++)
			for(size_t l = 0; l < 7; l++)
				if(dig[k] == dig[l] && k != l)
				{
					areEqual = true;
					k = 10;
				}
		if(!areEqual)
		{
			size_t sum = 0;
			for(size_t k = 0; k < 7; k++)
				sum += dig[k];
			if(sum == 28)
			{
				size_t test = 1;
				for(size_t k = 0; k < 7; k++)
					test*= dig[k];
				if(test != 0)
				{
					if(primeCheck(i))
						answer = i;
				}
				
			}
		}	
	}

	return answer;
}

size_t Problem42()
{
	size_t answer = 0;
	string mystring[1786];
	size_t tri[50] = {0};
	char c;
	size_t count = 0;
	
	ifstream myfile;
	myfile.open("words.txt");
	while(!myfile.eof())
	{
		myfile.get(c);
		if(c != '"' && c != ',')
			mystring[count] += c;
		else if(c == ',')
			count++;
	}	
	for(size_t i = 1; i <= 50; i++)
		tri[i-1] = (i*(i+1))/2;
	for(size_t i = 0; i < 1786; i++)
	{
		char temp[mystring[i].size()];
		strcpy(temp, mystring[i].c_str());
		size_t value = 0;
		for(size_t k = 0; k < mystring[i].size(); k++)
		{
			if(temp[k] == 'A') { value += 1; }
			else if(temp[k] == 'B') { value += 2; }
			else if(temp[k] == 'C') { value += 3; }
			else if(temp[k] == 'D') { value += 4; }
			else if(temp[k] == 'E') { value += 5; }
			else if(temp[k] == 'F') { value += 6; }
			else if(temp[k] == 'G') { value += 7; }
			else if(temp[k] == 'H') { value += 8; }
			else if(temp[k] == 'I') { value += 9; }
			else if(temp[k] == 'J') { value += 10; }
			else if(temp[k] == 'K') { value += 11; }
			else if(temp[k] == 'L') { value += 12; }
			else if(temp[k] == 'M') { value += 13; }
			else if(temp[k] == 'N') { value += 14; }
			else if(temp[k] == 'O') { value += 15; }
			else if(temp[k] == 'P') { value += 16; }
			else if(temp[k] == 'Q') { value += 17; }
			else if(temp[k] == 'R') { value += 18; }
			else if(temp[k] == 'S') { value += 19; }
			else if(temp[k] == 'T') { value += 20; }
			else if(temp[k] == 'U') { value += 21; }
			else if(temp[k] == 'V') { value += 22; }
			else if(temp[k] == 'W') { value += 23; }
			else if(temp[k] == 'X') { value += 24; }
			else if(temp[k] == 'Y') { value += 25; }
			else if(temp[k] == 'Z') { value += 26; }
		}
		for(size_t k = 0; k < 50; k++)
			if(value == tri[k])
			{
				answer++;
				k = 50;
			}
	}	
	return answer;
}

size_t Problem43()
{
	size_t answer = 0;
	
	size_t seventeen[100] = {0};
	size_t thirteen[100] = {0};
	size_t eleven[100] = {0};
	size_t seven[200] = {0};
	size_t five[200] = {0};
	size_t three[333] = {0};
	size_t two[500] = {0};
	size_t count = 0;
	
	for(size_t i = 12; i <= 987; i++)
		if(i % 17 == 0)
		{
			seventeen[count] = i;
			count++;
		}
	count = 0;
	for(size_t i = 12; i <= 987; i++)
		if(i % 13 == 0)
		{
			thirteen[count] = i;
			count++;
		}
	count = 0;
	for(size_t i = 12; i <= 987; i++)
		if(i % 11 == 0)
		{
			eleven[count] = i;
			count++;
		}
	count = 0;
	for(size_t i = 12; i <= 987; i++)
		if(i % 7 == 0)
		{
			seven[count] = i;
			count++;
		}
	count = 0;
	for(size_t i = 12; i <= 987; i++)
		if(i % 5 == 0)
		{
			five[count] = i;
			count++;
		}
	count = 0;
	for(size_t i = 12; i <= 987; i++)
		if(i % 3 == 0)
		{
			three[count] = i;
			count++;
		}
	count = 0;
	for(size_t i = 12; i <= 987; i++)
		if(i % 2 == 0)
		{
			two[count] = i;
			count++;
		}
	count = 0;
		
	size_t step1[1000] = {0};
	for(size_t i = 0; seventeen[i] != 0; i++)
		for(size_t k = 0; thirteen[k] != 0; k++)
		{
			size_t dig1[3] = {0};
			size_t dig2[3] = {0};
			toDigits(thirteen[k], dig1);
			toDigits(seventeen[i], dig2);
			if(digits(thirteen[k]) == 2)
			{
				dig1[2] = dig1[1];
				dig1[1] = dig1[0];
				dig1[0] = 0;
			}
			if(digits(seventeen[i]) == 2)
			{
				dig2[2] = dig2[1];
				dig2[1] = dig2[0];
				dig2[0] = 0;
			}
			size_t dig3[4] = {0};
			if(dig1[1] == dig2[0] && dig1[2] == dig2[1] && dig1[0] != dig2[2])
			{
				dig3[0] = dig1[0];
				dig3[1] = dig1[1];
				dig3[2] = dig1[2];
				dig3[3] = dig2[2];
				step1[count] = digitsToNumber(dig3, 4);
				count++;
			}	
		}
	count = 0;

	size_t step2[1000] = {0};
	for(size_t i = 0; step1[i] != 0; i++)
		for(size_t k = 0; eleven[k] != 0; k++)
		{
			size_t dig1[3] = {0};
			size_t dig2[4] = {0};
			toDigits(eleven[k], dig1);
			toDigits(step1[i], dig2);
			if(digits(eleven[k]) == 2)
			{
				dig1[2] = dig1[1];
				dig1[1] = dig1[0];
				dig1[0] = 0;
			}
			if(digits(step1[i]) == 3)
			{
				dig2[3] = dig2[2];
				dig2[2] = dig2[1];
				dig2[1] = dig2[0];
				dig2[0] = 0;
			}
			size_t dig3[5] = {0};
			if(dig1[1] == dig2[0] && dig1[2] == dig2[1] && dig1[0] != dig2[2] && dig1[0] != dig2[3])
			{
				dig3[0] = dig1[0];
				dig3[1] = dig1[1];
				dig3[2] = dig1[2];
				dig3[3] = dig2[2];
				dig3[4] = dig2[3];
				step2[count] = digitsToNumber(dig3, 5);
				count++;
			}
		}
	count = 0;

	size_t step3[1000] = {0};
	for(size_t i = 0; step2[i] != 0; i++)
		for(size_t k = 0; seven[k] != 0; k++)
		{
			size_t dig1[3] = {0};
			size_t dig2[5] = {0};
			toDigits(seven[k], dig1);
			toDigits(step2[i], dig2);
			if(digits(seven[k]) == 2)
			{
				dig1[2] = dig1[1];
				dig1[1] = dig1[0];
				dig1[0] = 0;
			}
			if(digits(step2[i]) == 4)
			{
				dig2[4] = dig2[3];
				dig2[3] = dig2[2];
				dig2[2] = dig2[1];
				dig2[1] = dig2[0];
				dig2[0] = 0;
			}
			size_t dig3[6] = {0};
			if(dig1[1] == dig2[0] && dig1[2] == dig2[1])
			{
				dig3[0] = dig1[0];
				dig3[1] = dig1[1];
				dig3[2] = dig1[2];
				dig3[3] = dig2[2];
				dig3[4] = dig2[3];
				dig3[5] = dig2[4];
				step3[count] = digitsToNumber(dig3, 6);
				count++;
			}	
		}	
	count = 0;

	size_t step4[1000] = {0};
	for(size_t i = 0; step3[i] != 0; i++)
		for(size_t k = 0; five[k] != 0; k++)
		{
			size_t dig1[3] = {0};
			size_t dig2[6] = {0};
			toDigits(five[k], dig1);
			toDigits(step3[i], dig2);
			if(digits(five[k]) == 2)
			{
				dig1[2] = dig1[1];
				dig1[1] = dig1[0];
				dig1[0] = 0;
			}
			if(digits(step3[i]) == 5)
			{
				dig2[5] = dig2[4];
				dig2[4] = dig2[3];
				dig2[3] = dig2[2];
				dig2[2] = dig2[1];
				dig2[1] = dig2[0];
				dig2[0] = 0;
			}
			size_t dig3[7] = {0};
			if(dig1[1] == dig2[0] && dig1[2] == dig2[1] && dig1[0] != dig2[2] && dig1[0] != dig2[3] && dig1[0] != dig2[4] && dig1[0] != dig2[5])
			{
				dig3[0] = dig1[0];
				dig3[1] = dig1[1];
				dig3[2] = dig1[2];
				dig3[3] = dig2[2];
				dig3[4] = dig2[3];
				dig3[5] = dig2[4];
				dig3[6] = dig2[5];
				step4[count] = digitsToNumber(dig3, 7);
				count++;
			}	
		}
	count = 0;

	size_t step5[1000] = {0};
	for(size_t i = 0; step4[i] != 0; i++)
		for(size_t k = 0; three[k] != 0; k++)
		{
			size_t dig1[3] = {0};
			size_t dig2[7] = {0};
			toDigits(three[k], dig1);
			toDigits(step4[i], dig2);
			if(digits(three[k]) == 2)
			{
				dig1[2] = dig1[1];
				dig1[1] = dig1[0];
				dig1[0] = 0;
			}
			if(digits(step4[i]) == 6)
			{
				dig2[6] = dig2[5];
				dig2[5] = dig2[4];
				dig2[4] = dig2[3];
				dig2[3] = dig2[2];
				dig2[2] = dig2[1];
				dig2[1] = dig2[0];
				dig2[0] = 0;
			}
			size_t dig3[8] = {0};
			if(dig1[1] == dig2[0] && dig1[2] == dig2[1] && dig1[0] != dig2[2] && dig1[0] != dig2[3] && dig1[0] != dig2[4] && dig1[0] != dig2[5] && dig1[0] != dig2[6])
			{
				dig3[0] = dig1[0];
				dig3[1] = dig1[1];
				dig3[2] = dig1[2];
				dig3[3] = dig2[2];
				dig3[4] = dig2[3];
				dig3[5] = dig2[4];
				dig3[6] = dig2[5];
				dig3[7] = dig2[6];
				step5[count] = digitsToNumber(dig3, 8);
				count++;
			}	
		}
	count = 0;

	size_t step6[1000] = {0};
	for(size_t i = 0; step5[i] != 0; i++)
		for(size_t k = 0; two[k] != 0; k++)
		{
			size_t dig1[3] = {0};
			size_t dig2[8] = {0};
			toDigits(two[k], dig1);
			toDigits(step5[i], dig2);
			if(digits(two[k]) == 2)
			{
				dig1[2] = dig1[1];
				dig1[1] = dig1[0];
				dig1[0] = 0;
			}
			if(digits(step5[i]) == 7)
			{
				dig2[7] = dig2[6];
				dig2[6] = dig2[5];
				dig2[5] = dig2[4];
				dig2[4] = dig2[3];
				dig2[3] = dig2[2];
				dig2[2] = dig2[1];
				dig2[1] = dig2[0];
				dig2[0] = 0;
			}
			size_t dig3[9] = {0};
			if(dig1[1] == dig2[0] && dig1[2] == dig2[1] && dig1[0] != dig2[2] && dig1[0] != dig2[3] && dig1[0] != dig2[4] && dig1[0] != dig2[5] && dig1[0] != dig2[6] && dig1[0] != dig2[7])
			{
				dig3[0] = dig1[0];
				dig3[1] = dig1[1];
				dig3[2] = dig1[2];
				dig3[3] = dig2[2];
				dig3[4] = dig2[3];
				dig3[5] = dig2[4];
				dig3[6] = dig2[5];
				dig3[7] = dig2[6];
				dig3[8] = dig2[7];
				step6[count] = digitsToNumber(dig3, 9);
				count++;
			}	
		}

	for(size_t i = 0; i < count; i++)
	{
		size_t dig1[9] = {0};
		toDigits(step6[i], dig1);
		bool isPossible = true;
		for(size_t k = 0; k < 9; k++)
			for(size_t m = 0; m < 9; m++)
				if(dig1[k] == dig1[m] && k != m)
					isPossible = false;
		if(isPossible)
		{
			size_t dig2[10] = {0};
			size_t test = 0;
			for(size_t k = 0; k < 9; k++)
			{
				test += dig1[k];
				dig2[k+1] = dig1[k];
			}
			dig2[0] = 45 - test;
			unsigned long long test2 = digitsToNumber(dig2,10);
			answer += digitsToNumber(dig2, 10);
		}
	}
		
	return answer;
}

size_t Problem44()
{
	size_t answer = 0;
	size_t pent[3000];
	for(size_t n = 1; n <= 3000; n++)
	{
		size_t p = 3*n - 1;
		p *= n;
		p /= 2;
		pent[n - 1] = p;
	}
	for(size_t i = 1000; i < 3000; i++)
		for(size_t k = 999; k < i; k++)
		{
			size_t test1 = pent[i] + pent[k];
			size_t test2 = pent[i] - pent[k];
			bool pass1 = false;
			bool pass2 = false;
			for(size_t l = k; l < 3000; l++)
			{
				if(test1 == pent[l])
					pass1 = true;
				if(test2 == pent[l])
					pass2 = true;
			}
			if(pass1 && pass2)
				return test2;
		} 
	return answer;
}

size_t Problem45()
{
	size_t size = 120000;
	size_t triangle[size];
	getTriangleNumbers(triangle, size);
	for(size_t i = 286; i < size; i++)
		if(isPentagonal(triangle[i]) && isHexagonal(triangle[i]))
			return triangle[i];
}



size_t Problem47()
{
	size_t answer = 0;
	size_t a = 7;
	size_t fArray[100] = {0};
	size_t count = 2;
	size_t totalPrimes = 0;
	for(size_t x = 100000; x <= 1000000; x ++)
	{
		size_t check = x;
		size_t a = 0;
		size_t primes = 1;
		primeFactors(check, fArray, count, a);
		for(size_t i = 1; fArray[i] != 0; i++)
		{
			if(fArray[i] != fArray[i-1])
				primes++;
		}
		if(primes == 4)
			totalPrimes += 1;
		else
			totalPrimes = 0;
		if(totalPrimes == 4)
		{
			answer = x - 3;
			return answer;
		}
		for(size_t d = 0; fArray[d] != 0; d++)
			fArray[d] = 0;
		count = 2;
	}
}

size_t Problem48()
{
	size_t count = 0;
	size_t temp = 0;
	for(size_t k = 1; k < 1000; k++)
	{
		temp = k;
		for(size_t i = 1; i < k; i++)
			temp = temp * k % 10000000000;
		count += temp;
		count = count % 10000000000;
	}
		
	return count;
}

size_t Problem49()
{
	size_t answer = 0;
	for(size_t i = 1500; i < 4000; i++)
		if(primeCheck(i))
			for(size_t k = 333; k <= 9999; k++)
			{
				size_t test = i + k;
				size_t test2 = test + k;
				if(primeCheck(test) && test2 < 10000)
					if(primeCheck(test2))
					{
						size_t dig1[4] = {0};
						dig1[0] = i % 10000;
						dig1[0] /= 1000;
						dig1[1] = i % 1000;
						dig1[1] /= 100;
						dig1[2] = i % 100;
						dig1[2] /= 10;
						dig1[3] = i % 10;
						size_t count1 = dig1[0] + dig1[1] + dig1[2] + dig1[3];
						size_t dig2[4] = {0};
						dig2[0] = test % 10000;
						dig2[0] /= 1000;
						dig2[1] = test % 1000;
						dig2[1] /= 100;
						dig2[2] = test % 100;
						dig2[2] /= 10;
						dig2[3] = test % 10;
						size_t count2 = dig2[0] + dig2[1] + dig2[2] + dig2[3];
						size_t dig3[4] = {0};
						dig3[0] = test2 % 10000;
						dig3[0] /= 1000;
						dig3[1] = test2 % 1000;
						dig3[1] /= 100;
						dig3[2] = test2 % 100;
						dig3[2] /= 10;
						dig3[3] = test2 % 10;
						size_t count3 = dig3[0] + dig3[1] + dig3[2] + dig3[3];
						if(count1 == count2 && count2 == count3 && count1 == count3)
						{
							size_t totals1[10] = {0};
							size_t totals2[10] = {0};
							size_t totals3[10] = {0};
							for(size_t a = 0; a <= 3; a++)
								for(size_t b = 0; b <= 9; b++)
								{
									if(dig1[a] == b)
										totals1[b] += 1;
									if(dig2[a] == b)
										totals2[b] += 1;
									if(dig3[a] == b)
										totals3[b] += 1;
								}
							bool isPossible = true;
							for(size_t a = 0; a <= 9; a++)
								if(totals1[a] != totals2[a] || totals2[a] != totals3[a] || totals1[a] != totals3[a])
									isPossible = false;
							if(isPossible)
							{
								cout << i << test << test2 << endl;
								return 0;
							}
								
						}
					}
			}
}

size_t Problem50()
{
	size_t answer = 0;
	size_t primeList[30000] = {0};
	size_t a = 1;
	primeList[0] = 2;
	for(size_t i = 3; i < 30000; i += 2)
	{
		if(primeCheck(i))
		{
			primeList[a] = i;
			a++;
		}
	}
	size_t total = 0;
	for(size_t k = 0; k < 4; k++)
		for(size_t i = 3; total < 1000000; i++)
		{
		total += primeList[i];
		if(primeCheck(total))
			answer = total;
		}
	return answer;
}
