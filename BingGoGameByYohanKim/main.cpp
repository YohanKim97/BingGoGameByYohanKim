#include <iostream>
#include <time.h>

using namespace std;

int main()
{



	// Creating 5 X 5 BingGo Game

	srand((unsigned int)time(0));

	// 25 numbers
	int iNumber[25] = {};

	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
	}

	//Suffling to prevent repeated numbers
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

	}


	//Print out 5 X 5 BingGo Board
	cout << "=================== Player ===================" << endl;

	while (true)
	{
		system("cls");

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				
				if (iNumber[i * 5 + j] == INT_MAX)
				{
					cout << " * \t ";
				}
				else
				{
					cout << iNumber[i * 5 + j] << " \t ";
				}
			}

			cout << endl;
			
		}
		

		cout << "Type Number (0 == EXIT) : ";

		int iInput;
		
		cin >> iInput;;

		//EXIT the Game
		if (iInput == 0)
		{
			break;
		}
		//Take input between 1 ~ 25  numbers
		else if (iInput < 1 || iInput > 25)
		{
			continue;
		}

		// Check repeated numbers
		bool bRepeatedNumber = true;

		for (int i = 0; i < 25; ++i)
		{
			if (iInput == iNumber[i])
			{
				bRepeatedNumber = false;

				iNumber[i] = INT_MAX;

				break;
			}
		}

		if (bRepeatedNumber)
		{
			continue;
		}

	}
	return 0;
}