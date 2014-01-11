
size_t Problem51()
{
	size_t answer = 0;
//	size_t x = 54321;
//	size_t dig[5] = {0};
//	size_t* pass[5] = dig;
//	toDigits(x, dig);
	//dig = *pass;
//	cout << dig[0] << dig[1] << dig[2] << dig[3] << dig[4] << endl;
	/*
	for(size_t i = 50000; i <= 60000; i++)
	{
		if(primeCheck(i))
		{
			size_t dig[digits(i)] = {0};
			toDigits(i, dig);
			for(size_t k = 0; k <= 9; k++)
				for(size_t m = 0; m <= digits(i); m++)
				{
					// THIS IS WHERE I STOPPED
				}
		}
	}
	*/
	return answer;
}

size_t Problem52()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem53()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem54()
{
	size_t answer = 0;
	size_t player[2][5];
	char playerSuit[2][5];
	char c;
	long double playerOneScore = 0;
	long double playerTwoScore = 0;
	
	ifstream myfile;
	myfile.open("poker.txt");
	while(!myfile.eof())
	{
		playerOneScore = 0;
		playerTwoScore = 0;
		for(size_t k = 0; k < 2; k++)
		{
			size_t n = 0;
			size_t m = 0;
			
			// Puts the cards in the player's hand
			do
			{
				myfile.get(c); 
				if(c == '2') { player[k][n]	= 2; n++; }
				if(c == '3') { player[k][n]	= 3; n++; }
				if(c == '4') { player[k][n]	= 4; n++; }
				if(c == '5') { player[k][n]	= 5; n++; }
				if(c == '6') { player[k][n]	= 6; n++; }
				if(c == '7') { player[k][n]	= 7; n++; }
				if(c == '8') { player[k][n]	= 8; n++; }
				if(c == '9') { player[k][n]	= 9; n++; }
				if(c == 'T') { player[k][n]	= 10; n++; }
				if(c == 'J') { player[k][n]	= 11; n++; }
				if(c == 'Q') { player[k][n]	= 12; n++; }
				if(c == 'K') { player[k][n]	= 13; n++; }
				if(c == 'A') { player[k][n]	= 14; n++; }
			
				if(c == 'C') { playerSuit[k][m] = 'C'; m++; }
				if(c == 'S') { playerSuit[k][m] = 'S'; m++; }
				if(c == 'D') { playerSuit[k][m] = 'D'; m++; }
				if(c == 'H') { playerSuit[k][m] = 'H'; m++; }
							
			}while( m <= 4 );
			
			// Sorting the hand low to high	
			for(size_t i = 0; i <= 100; i++)
			{
				for(size_t j = 0; j < 4; j++)
				{
					if(player[k][j] > player[k][j + 1])
					{
						size_t temp;
						temp = player[k][j];
						player[k][j] = player[k][j + 1];
						player[k][j + 1] = temp;
					}			
				}
			}
	
			// Setting up variables
			bool isStraight = false;
			bool isFlush = false;
			long double handScore = 0;
			size_t pairs = 0;
			if( playerSuit[k][0] == playerSuit[k][1] == playerSuit[k][2] == playerSuit[k][3] == playerSuit[k][4] )
				isFlush = true;
			if( player[k][4] == player[k][3] + 1 && player[k][3] == player[k][2] + 1 && player[k][2] == player[k][1] + 1 && player[k][1] == player[k][0] + 1)
				isStraight = true;
			if( player[k][0] == player[k][1])
				pairs++;
			if( player[k][1] == player[k][2])
				pairs++;
			if( player[k][2] == player[k][3])
				pairs++;
			if( player[k][3] == player[k][4])
				pairs++;
				
			// Giving a value to the hand		
			// Straight flush (and Royal Flush)
			if( isFlush && isStraight)
			{
				size_t multiplier = player[k][0] - 1;
				handScore += 10000000000000*multiplier;
			}
			// Four of a Kind
			else if(player[k][0] == player[k][3] || player[k][1] == player[k][4])
				handScore += 100000000000*player[k][2];
			// Full House
			else if(( player[k][0] == player[k][2] && player[k][3] == player[k][4]) || player[k][0] == player[k][1] && player[k][2] == player[k][4] )
				{
					size_t pair = 0;
					if( player[k][0] == player[k][2] )
						pair = player[k][4];
					else
						pair = player[k][0];
					pair *= 10000000;
					handScore += 1000000000*player[k][2] + pair;
				}
			// Flush
			else if( isFlush )
				handScore += 10000000*player[k][4] + 100000*player[k][3] + 1000*player[k][2] + 10*player[k][1] + .1*player[k][0];
			// Straight
			else if( isStraight )
			{
				size_t multiplier = player[k][0] - 1;
				handScore += 1000000*multiplier;
			}
			// Three of a Kind
			else if( player[k][0] == player[k][2] || player[k][2] == player[k][4] || player[k][1] == player[k][3] )
			{
				size_t highcard = 0;
				size_t lowcard = 0;
				if( player[k][0] == player[k][2] )
				{
					lowcard = player[k][3];
					highcard = player[k][4];
				}
				else if( player[k][1] == player[k][3] )
				{
					lowcard = player[k][0];
					highcard = player[k][4];
				}
				else
				{
					lowcard = player[k][0];
					highcard = player[k][1];
				}
				handScore += 10000*player[k][2] + 100*lowcard + highcard;
			}
			// Two Pair
			else if( pairs == 2)
			{
				size_t pairOne;
				size_t pairTwo;
				size_t highCard;
				if( player[k][0] == player[k][1])
				{
					if( player[k][2] == player[k][3] )
					{
						pairOne = player[k][0];
						pairTwo = player[k][3];
						highCard = player[k][4];
					}
					else
					{
						pairOne = player[k][0];
						pairTwo = player[k][4];
						highCard = player[k][2];
					}
				}
				else
				{
					pairOne = player[k][1];
					pairTwo = player[k][4];
					highCard = player[k][0];
				}
				handScore = 100*pairTwo + pairOne + highCard*.01;
			}  
			// One Pair
			else if( pairs == 1 )
			{
				size_t pair;
				size_t highcard = 0;
				size_t nextcard = 0;
				size_t lastcard = 0;
				if( player[k][0] == player[k][1] )
				{
					pair = player[k][0];
					highcard = player[k][4];
					nextcard = player[k][3];
					lastcard = player[k][2];
				}
				else if( player[k][1] == player[k][2] )
				{
					pair = player[k][1];
					highcard = player[k][4];
					nextcard = player[k][3];
					lastcard = player[k][0];
				}
				else if( player[k][2] == player[k][3] )
				{
					pair = player[k][2];
					highcard = player[k][4];
					nextcard = player[k][1];
					lastcard = player[k][0];
				}
				else if( player[k][3] == player[k][4] )
				{
					pair = player[k][4];
					highcard = player[k][2];
					nextcard = player[k][1];
					lastcard = player[k][0];
				}
				handScore = pair + .01*highcard + .0001*nextcard + .000001*lastcard;
			}
			// High Card
			else
				handScore = player[k][4]*.01 + player[k][3]*.0001 + player[k][2]*.000001 + player[k][1]*.00000001 + player[k][0]*.0000000001;
		
			// Assign the appropriate player their handscore
			if( k == 0 )
				playerOneScore = handScore;
			else
				playerTwoScore = handScore;	
		}	
		
			if( playerOneScore > playerTwoScore )
				answer++;
	}
	return answer - 1; // Last entry is invalid, but gives a posize_t to player one, so we take one off the final number.
}

size_t Problem55()
{
	size_t answer = 0;
	for(int i = 1; i <= 10000; i++)
		if(isLychrel(i))
			answer++;
	return answer;
}

size_t Problem56()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem57()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem58()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem59()
{
	size_t answer = 0;
	
	return answer;
}

size_t Problem60()
{
	size_t answer = 0;
	
	return answer;
}
