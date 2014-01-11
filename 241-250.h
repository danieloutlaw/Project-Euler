
size_t Problem243()
{
	for(size_t n = 95000; n <= 1500000000; n+=2)
	{
		size_t count = 1;
		for(size_t i = 2; i < n; i++)
		{	
			bool resilient = false;
			for(size_t k = 2; k <= i; k++)
			{
				if( i % k == 0 && n % k == 0 )
				{
					resilient = false;
					k = i;
				}
				else
					resilient = true;
			}
			if(resilient == true)
				count++;
		}
		double x = n - 1;
		double y = count / x;
		double t1 = 15499;
		double t2 = 94744;
		double z = t1 / t2;
		cout << count << "/" << x << ": " << y << " < " << z << endl;
		if( y < z )
			return n;	
	//	if( n % 10 == 0)
	//		system("pause");	
	}
	return 0;
}
