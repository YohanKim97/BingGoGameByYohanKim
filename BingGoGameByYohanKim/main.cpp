#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

int main()
{

	// Creating 5 X 5 BingGo Game

	srand((unsigned int)time(0));

	// 25 numbers
	int iNumber[25] = {};
	int iAINumber[25] = {};

	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
	}

	//AI 25 numbers
	for (int i = 0; i < 25; ++i)
	{
		iAINumber[i] = i + 1;
	}


	//Shuffling to prevent repeated numbers
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;


		iTemp = iAINumber[idx1];
		iAINumber[idx1] = iAINumber[idx2];
		iAINumber[idx2] = iTemp;

	}


	////Shuffling AI number
	//int iTemp, idx1, idx2;
	//for (int i = 0; i < 100; ++i)
	//{
	//	idx1 = rand() % 25;
	//	idx2 = rand() % 25;

	//	iTemp = iAINumber[idx1];
	//	iAINumber[idx1] = iAINumber[idx2];
	//	iAINumber[idx2] = iTemp;

	//}


	//Print out 5 X 5 BingGo Board
	int iBingGoLine = 0;
	int iAIBingGoLine = 0;

	while (true)
	{
		system("cls");

		cout << "=================== AI ===================" << endl << endl;
		cout << " AI BingGo Line : " << iAIBingGoLine << endl << endl;
		//AI BingGo Board
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{

				if (iAINumber[i * 5 + j] == INT_MAX)
				{
					cout << " * \t ";
				}
				else
				{
					cout << iAINumber[i * 5 + j] << " \t ";
				}
			}

			cout << endl;

		}
	


		cout << "=================== Player ===================" << endl << endl;
		cout << " Player BingGo Line : " << iBingGoLine << endl << endl;

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


		// BingGO Line Check
		iBingGoLine = 0;
		iAIBingGoLine = 0;

		int iStar1 = 0, iStar2 = 0;
		int iAIStar1 = 0, iAIStar2 = 0;
		for (int i = 0; i < 5; ++i)
		{
			iStar1 = iStar2 = 0;
			for (int j = 0; j < 5; ++j)
			{
				//Row
				if (iNumber[i * 5 + j] == INT_MAX)
				{
					++iStar1;
					++iAIStar1;
				}

				//Column
				if (iNumber[j * 5 + i] == INT_MAX)
				{
					++iStar2;
					++iAIStar2;
				}
	
			}

			if (iStar1 == 5)
			{
				++iBingGoLine;
			}

			if (iAIStar1 == 5)
			{
				++iAIBingGoLine;
			}

			if (iStar2 == 5)
			{
				++iBingGoLine;
			}

			if (iAIStar2 == 5)
			{
				++iAIBingGoLine;
			}
		
			
		}

		// Uper Left -> Lower Right
		iStar1 = 0;
		iStar2 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}

		if (iStar1 == 5)
		{
			++iBingGoLine;
		}

		// Uper Right -> Lower Left
		iStar1 = 0;
		iStar2 = 0;
		for (int i = 0; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iStar2;
		}

		if (iStar2 == 5)
		{
			++iBingGoLine;
		}

	}
	return 0;
}