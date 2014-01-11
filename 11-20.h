size_t Problem11()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem12()
{						// Extremely long brute force algorithm. Works but needs optimization.
	size_t count = 0;
	size_t triangle = 0;
	for(size_t i = 1; i <= 70000; i ++)
	{
		count = 0;
		triangle += i;
		for(size_t k = 1; k <= triangle; k++)
			if(triangle % k == 0)
				count++;
		if(count >= 200)
			cout << count << ":" << triangle << endl;
		if(count >= 500)
			return triangle;
	}
}

size_t Problem13()
{
	size_t answer = 0;
	char* s = new char[8500];
	long double a = 10;
	ifstream infile;
	infile.open("problem13.txt");
	for(size_t i=1; !infile.eof(); i++)
	{
		infile.get(s[i]);
		if(i % 51 == 0)
		{
			for(size_t k = 1; k <= 16; k++)
			{
				if(s[i-51 + k] == '1'){ answer += pow(a, 17-k); }
				if(s[i-51 + k] == '2'){ answer += 2*pow(a, 17-k); }
				if(s[i-51 + k] == '3'){ answer += 3*pow(a, 17-k); }
				if(s[i-51 + k] == '4'){ answer += 4*pow(a, 17-k); }
				if(s[i-51 + k] == '5'){ answer += 5*pow(a, 17-k); }
				if(s[i-51 + k] == '6'){ answer += 6*pow(a, 17-k); }
				if(s[i-51 + k] == '7'){ answer += 7*pow(a, 17-k); }
				if(s[i-51 + k] == '8'){ answer += 8*pow(a, 17-k); }
				if(s[i-51 + k] == '9'){ answer += 9*pow(a, 17-k); }
			}
		}
	}
	return answer;
}

size_t Problem14()
{
	size_t count = 0;
	size_t answer = 0;
	size_t high = 0;
	for(size_t i = 800000; i < 1000000; i++)
	{
		count = 0;
		size_t n = i;
		while(n != 1)
		{
			if(n % 2 == 0)
				n = n / 2;
			else
				n = 3*n +1;
			count++;
		}
		if(count > high)
		{
			high = count;
			answer = i;
		}
	}
	return answer;
}

size_t Problem15()
{
	size_t answer = 137846528820;
	return answer; // This is simply (40 choose 20)
}

size_t Problem16()
{
	size_t answer = 0;
	char n;
	ifstream myfile;
	myfile.open("problem16.txt");  //I got the number for 2^1000 using double n = pow(2,1000); prsize_tf("%lf\n", n); 
	while(!myfile.eof())
	{
		myfile.get(n);
		if(n == '1') { answer += 1;	}
		if(n == '2') { answer += 2;	}
		if(n == '3') { answer += 3;	}
		if(n == '4') { answer += 4;	}
		if(n == '5') { answer += 5;	}
		if(n == '6') { answer += 6;	}
		if(n == '7') { answer += 7;	}
		if(n == '8') { answer += 8;	}
		if(n == '9') { answer += 9;	}
		n = '0';
	}	
	return answer;
}

size_t Problem17()
{
	size_t answer = 11 + (3+3+5+4+4+3+5+5+4)*100 + 7*900 + 3*891 + (3+3+5+4+4+3+5+5+4)*90 + (3+6+6+8+8+7+7+9+8+8)*10 + (6+6+5+5+5+7+6+6)*100;
	return answer;
}

size_t Problem18()
{
	size_t answer = 1074; // I started in the middle and found the best case scenario and worked up, then worked down.
	return answer;
}

size_t Problem19()
{
	size_t month = 1;
	size_t weekday = 2; // This code could surely be optimized, but it works.
	size_t count = 0;	
	for(size_t i = 1901; i <= 2000; i++)
	{
		for(size_t j = 1; j <= 31; j++)
		{
			weekday++;
			if(weekday == 8)
				weekday = 1;
			if(j == 1 && weekday == 1)
				count++;
		}
		size_t febDays = 0;
		if(i % 4 == 0)
			febDays = 29;
		else
			febDays = 28;
		for(size_t f = 1; f <= febDays; f++)
		{
			weekday++;
			if(weekday == 8)
				weekday = 1;
			if(f == 1 && weekday == 1)
				count++;
		}
		for(size_t j = 1; j <= 31; j++)
		{
			weekday++;
			if(weekday == 8)
				weekday = 1;
			if(j == 1 && weekday == 1)
				count++;	
		}
		for(size_t j = 1; j <= 30; j++)
		{
			weekday++;
			if(weekday == 8)
				weekday = 1;
			if(j == 1 && weekday == 1)
				count++;
		}
		for(size_t j = 1; j <= 31; j++)
		{
			weekday++;
			if(weekday == 8)
				weekday = 1;
			if(j == 1 && weekday == 1)
				count++;
		}
		for(size_t j = 1; j <= 30; j++)
		{
			weekday++;
			if(weekday == 8)
				weekday = 1;
			if(j == 1 && weekday == 1)
				count++;	
		}
		for(size_t j = 1; j <= 31; j++)
		{
			weekday++;
			if(weekday == 8)
				weekday = 1;
			if(j == 1 && weekday == 1)
				count++;
		}
		for(size_t j = 1; j <= 31; j++)
		{
			weekday++;
			if(weekday == 8)
				weekday = 1;
			if(j == 1 && weekday == 1)
				count++;	
		}
		for(size_t j = 1; j <= 30; j++)
		{
			weekday++;
			if(weekday == 8)
				weekday = 1;
			if(j == 1 && weekday == 1)
				count++;	
		}
		for(size_t j = 1; j <= 31; j++)
		{
			weekday++;
			if(weekday == 8)
				weekday = 1;
			if(j == 1 && weekday == 1)
				count++;
		}
		for(size_t j = 1; j <= 30; j++)
		{
			weekday++;
			if(weekday == 8)
				weekday = 1;
			if(j == 1 && weekday == 1)
				count++;
		}
		for(size_t j = 1; j <= 31; j++)
		{
			weekday++;
			if(weekday == 8)
				weekday = 1;
			if(j == 1 && weekday == 1)
				count++;
		}
	}
	return count;
}

size_t Problem20()
{
	size_t answer = 0;
	char n;
	
	ifstream myfile;
	myfile.open("problem20.txt"); // 100! as obtained using a program with a big number library
	while(!myfile.eof())
	{
		myfile.get(n);
		if(n == '1') { answer += 1; }
		if(n == '2') { answer += 2; }
		if(n == '3') { answer += 3; }
		if(n == '4') { answer += 4; }
		if(n == '5') { answer += 5; }
		if(n == '6') { answer += 6; }
		if(n == '7') { answer += 7; }
		if(n == '8') { answer += 8; }
		if(n == '9') { answer += 9; }	
	}
	return answer;
}
