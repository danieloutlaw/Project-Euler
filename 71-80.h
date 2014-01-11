size_t Problem71()
{
	size_t answer = 0;

	size_t n = 0;
	size_t d = 1;
	for(size_t i = 1000000; i > 999000; i--)
	{
		size_t x = (3 * i - 1) / 7;
		if(x*d > n*i)
		{
			d = i;
			n = x;
			answer = n;
		}
	}
	
	return answer;
}

size_t Problem72()
{
	size_t answer = 0;
	for(size_t d = 2; d <= 1000000; d++)
		answer += phi(d);
	return answer;
}

size_t Problem73()
{
	size_t answer = 0;
	
	for(size_t d = 12000; d >= 2; d--)
		for(size_t n = d/2; n >= d/3; n--)
		{
			double num = n;
			double den = d;
			double x = num/den;
			double one = 1;
			double three = 3;
			double third = one/three;
			if(x < .5 && x > third && gcd(n,d) == 1 )
				answer++;
		}
			
				
	
	return answer;
}

size_t Problem74()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem75()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem76()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem77()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem78()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem79()
{
	size_t answer = 73162890; // Deduced on paper
	
	return answer;
}

size_t Problem80()
{
	size_t answer = 0;
	
	return answer;
}
