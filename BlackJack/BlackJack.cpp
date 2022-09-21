#include <iostream>
#include <stdlib.h>
#include <time.h>

class Card
{
private:
	int value;
	int suit;
public:
	void GenValSui()
	{
		value = (rand() % 13) + 2;
		suit = rand() % 4;
	}

	void ShowCards()
	{
		if (value > 10)
		{
			switch (value)
			{
			case 11: std::cout << "J"; break;
			case 12: std::cout << "Q"; break;
			case 13: std::cout << "K"; break;
			case 14: std::cout << "A"; break;
			}
		}
		else
		{
			std::cout << value;
		}
		switch (suit)
		{
		case 0:
			std::cout << "\03"; break;
		case 1:
			std::cout << "\04"; break;
		case 2:
			std::cout << "\05"; break;
		case 3:
			std::cout << "\06"; break;
		}
	}

	int AddInitScore(int, Card, Card);
	int AddScore(int, Card);
};

int Card::AddInitScore(int totalScore, Card card1, Card card2)
{
	int sc1 = card1.value, sc2 = card2.value;

	if (sc1 > 10)
	{
		if (sc1 == 11)
		{
			sc1 = 2;
		}
		else if (sc1 == 12)
		{
			sc1 = 3;
		}
		else if (sc1 == 13)
		{
			sc1 = 4;
		}
		else if (sc1 == 14)
		{
			if (totalScore > 10)
			{
				sc1 = 1;
			}
			else
			{
				sc1 = 11;
			}
		}

	}

	if (sc2 > 10)
	{
		if (sc2 == 11)
		{
			sc2 = 2;
		}
		else if (sc2 == 12)
		{
			sc2 = 3;
		}
		else if (sc2 == 13)
		{
			sc2 = 4;
		}
		else if (sc2 == 14)
		{
			if (totalScore > 10)
			{
				sc2 = 1;
			}
			else
			{
				sc2 = 11;
			}
		}

	}

	totalScore += sc1 + sc2;
	return totalScore;
}

int Card::AddScore(int totalScore, Card card)
{
	int sc = card.value;

	if (sc > 10)
	{
		if (sc == 11)
		{
			sc = 2;
		}
		else if (sc == 12)
		{
			sc = 3;
		}
		else if (sc == 13)
		{
			sc = 4;
		}
		else if (sc == 14)
		{
			if (totalScore > 10)
			{
				sc = 1;
			}
			else
			{
				sc = 11;
			}
		}

	}

	totalScore += sc;
	return totalScore;
}



int main()
{
	srand(time(0));
	int blackjack = 21;
	const int MAX = 10;
	Card card[MAX];
	char isExit, addCard;
	int score = 0, n = 0;
	
	std::cout << "Console BlackJack by Hayk4500! Have a nice day!" << std::endl;
	std::cout << std::endl;

	do
	{
		score = 0;
		n = 0;
		std::cout << "Okay, let's see your first two cards..." << std::endl;
		card[n].GenValSui(); card[n+1].GenValSui();
		card[n].ShowCards(); std::cout << " and "; card[n+1].ShowCards();

		std::cout << std::endl;

		std::cout << "Your total score: ";
		score = card[n+1].AddInitScore(score, card[n], card[n+1]); std::cout << score << std::endl;
		n = 3;

		if (score == blackjack)
		{
			std::cout << std::endl;
			std::cout << "21!!! YOU PERFECT WIN!"; break;
		}

		do
		{
			std::cout << "One more card? (y/n): "; std::cin >> addCard;
			if (addCard == 'y')
			{
				for (int j = 2; j < n; j++)
				{
					card[j].GenValSui();
					std::cout << "You pulled: "; card[j].ShowCards(); std::cout << std::endl;
					std::cout << "Your total score: ";
					score = card[j].AddScore(score, card[j]); std::cout << score << std::endl;
					std::cout << std::endl;
				}
			}

			if (score > 21)
			{
				std::cout << "YOU LOSE!" << std::endl; break;
			}

			if (score == blackjack)
			{
				std::cout << std::endl;
				std::cout << "21!!! YOU WIN!";
				std::cout << std::endl; break;
			}
		} while (addCard != 'n');

		std::cout << "One more game? (y/n): "; std::cin >> isExit;
	} while (isExit != 'n');
	
	return 0;
}

