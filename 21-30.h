
size_t Problem21()
{
	size_t answer = 0;
	size_t group[30001];
	size_t count = 0;
	for(size_t n = 1; n <= 10000; n++)
	{
		count = 0;
		for(size_t i = 1; i < n; i++)
			if( n % i == 0)
				count += i;
		group[n] = count;
	}
	for(size_t n = 1; n <=10000; n++)
	{
		if(n == group[group[n]] && n != group[n])
		{
			answer += n;
			answer += group[n];
		}
	}
	answer /= 2;
	return answer;
}

size_t Problem22()
{
	size_t answer = 0;
	size_t count = 0;
	size_t num = 2;
	char c;
	string mystring[20000];
	
	ifstream myfile;
	myfile.open("problem22.txt");
	while(!myfile.eof())
	{
		myfile.get(c);
		if(c != '"' && c != ',')
			mystring[count] += c;
		else if(c == ',')
			count++;
	}

	std::sort(mystring, mystring+count+1);
	mystring[count+1] = '\0';

	for(size_t i = 0; i < count+1; i++)
	{
		char temp[mystring[i].size()];
		strcpy(temp, mystring[i].c_str());
		for(size_t k = 0; k < mystring[i].size(); k++)
		{
			if(temp[k] == 'A') { answer += i+1; }
			else if(temp[k] == 'B') { answer += (i+1)*2; }
			else if(temp[k] == 'C') { answer += (i+1)*3; }
			else if(temp[k] == 'D') { answer += (i+1)*4; }
			else if(temp[k] == 'E') { answer += (i+1)*5; }
			else if(temp[k] == 'F') { answer += (i+1)*6; }
			else if(temp[k] == 'G') { answer += (i+1)*7; }
			else if(temp[k] == 'H') { answer += (i+1)*8; }
			else if(temp[k] == 'I') { answer += (i+1)*9; }
			else if(temp[k] == 'J') { answer += (i+1)*10; }
			else if(temp[k] == 'K') { answer += (i+1)*11; }
			else if(temp[k] == 'L') { answer += (i+1)*12; }
			else if(temp[k] == 'M') { answer += (i+1)*13; }
			else if(temp[k] == 'N') { answer += (i+1)*14; }
			else if(temp[k] == 'O') { answer += (i+1)*15; }
			else if(temp[k] == 'P') { answer += (i+1)*16; }
			else if(temp[k] == 'Q') { answer += (i+1)*17; }
			else if(temp[k] == 'R') { answer += (i+1)*18; }
			else if(temp[k] == 'S') { answer += (i+1)*19; }
			else if(temp[k] == 'T') { answer += (i+1)*20; }
			else if(temp[k] == 'U') { answer += (i+1)*21; }
			else if(temp[k] == 'V') { answer += (i+1)*22; }
			else if(temp[k] == 'W') { answer += (i+1)*23; }
			else if(temp[k] == 'X') { answer += (i+1)*24; }
			else if(temp[k] == 'Y') { answer += (i+1)*25; }
			else if(temp[k] == 'Z') { answer += (i+1)*26; }
		}
	}
	return answer;
}

size_t Problem23()
{		// Testing determined that there are no abundant numbers below 20200.

size_t answer = 0;
size_t abundant = 0;
size_t x = 20200;
size_t z[x];
size_t l[20200];

for(x; x >= 12; x--)
{
	size_t y = 0;
	for(size_t k = x/2; k >= 1; k--)
		if( x % k == 0 )
			y += k;
	if(y > x)
	{
		z[abundant] = x;
		abundant++;
	}
}
abundant--;
bool isHere = false;
size_t test = 0;
for(size_t k = abundant; k >= 0; k--)
	for(size_t t = 0; t <= k; t++)
	{
		for(size_t w = 0; w <= test; w++)
			if(z[k] + z[t] == l[w])
			{
				isHere = true;
				w = test + 1;
			}
		if(z[k] + z[t] < 20200 && !isHere)
		{
			l[test] = z[k] + z[t];
			test++;
		}
		isHere = false;
	}
test--;
bool isPossible = true;
for(size_t i = 1; i < 20200; i++)
{
	for(size_t k = 0; k <= test; k++)
		if(i == l[k])
			isPossible = false;
	if(isPossible)
		answer += i;
	isPossible = true;
}
	return answer;
} 

size_t Problem24()
{
	size_t answer = 0;
	size_t lexi[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	for( size_t i = 1; i < 1000000; i++ )
	{
		for( size_t k = 9; k >= 0; k-- )
			if( lexi[k-1] < lexi[k] )
			{
				size_t temp = lexi[k-1];
				size_t lowestPos = 9;

				for( size_t w = k; w <= 9; w++ )
					if( lexi[w] < 10  && lexi[w] > lexi[k-1] )
					{

						lowestPos = w; 
					}

				lexi[k-1] = lexi[lowestPos];
				lexi[lowestPos] = temp;
				
				if(k != 9)
				for( size_t w = 0; w <= 100; w++ )
					for( size_t j = k; j < 9; j++ )
					{
						if( lexi[j] > lexi[j+1] )
						{
							size_t temp2 = lexi[j];
							lexi[j] = lexi[j+1];
							lexi[j+1] = temp2;		
						}	
					}			
				k = -1;
			}
	}
	answer = lexi[9] + lexi[8]*10 + lexi[7]*100 + lexi[6]*1000 + lexi[5]*10000 + lexi[4]*100000 + lexi[3]*1000000 + lexi[2]*10000000 + lexi[1]*100000000 + lexi[0]*1000000000;
	return answer;
}

size_t Problem25()
{
	size_t answer = 4782;  // This was found by narrowing down the number on paper
	return answer;
}

size_t Problem26()
{
	double x;
	for(size_t i = 2; i < 1000; i++)
	{
		if( i % 3 != 0 && i % 2 != 0 && i % 5 != 0)
		{
		double temp = i;
		x = 1 / temp;
		x *= 100;
		}
	}  // Narrowing it down determined that the number is 1/983 = 982 repeating digits.
	size_t answer = 983;
	return answer;
}

size_t Problem27()
{
	size_t answer = 0;
	size_t check = 0;
	size_t n = 0;
	size_t count = 0;
	for(size_t a = -999; a < 1000; a++)
		for(size_t b = -999; b < 1000; b++)
		{
			for(size_t n = 0; n < 1000; n++)
			{
				size_t test = n*n;
				size_t test2 = a*n;
				test += test2;
				test += b;
				if(primeCheck(test))
					count++;
				else
					n = 1000;
			}
			if(count > check)
			{
				check = count;
				answer = a*b;
			}
			count = 0;
		}
	
	return answer;
}

size_t Problem28()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem29()
{
	size_t answer = 0;
	size_t store[9801] = {0};
	size_t h = 0;
	for(size_t i = 2; i <= 100; i++)
		for(size_t k = 2; k <= 100; k++)
		{
			store[h] = i;
			for(size_t w = 1; w <= k; w++)
				store[h] *= i;
		//	store[h] = pow(i,k);			
			h++;
//			cout << i << "^" << k << " = " << store[h-1] << endl;
		}
	for(size_t i = 0; i <= 9801; i++)
		for(size_t k = 0; k <= 9801; k++)
		{
			if(store[i] == store[k] &&  i != k && store[k] != 0 /*&& store[k] != 0*/)
			{
				h--;
				store[i] = 0;
				k = 9900;
			}
		}

//	for(size_t i = 0; i <= 9801; i++)
//		cout << store[i] << " ";
	return h;
}

size_t Problem30()
{
	size_t answer = 0;
	for(size_t i = 1000; i <= 999999; i++)
	{
		size_t dig[digits(i)];
		toDigits(i, dig);
		size_t test = 0;
		for(size_t k = 0; k < digits(i); k++)
			test += pow(dig[k],5);
		if(test == i)
			answer += i;
	}
	return answer;
}
