#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;


#define NAME_SIZE 32

struct _tagPlayer
{
	char strPlayerName[NAME_SIZE];
};

enum GAME_MODE
{
	GM_EASY = 1,
	GM_HARD
};

enum LINE_NUMBER
{
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1, 
	LN_V2,
	LN_V3, 
	LN_V4, 
	LN_V5,
	LN_LT,
	LN_RT

};

int main()
{

	// Creating 5 X 5 BingGo Game

	srand((unsigned int)time(0));

	_tagPlayer tPlayer = {};

	cout << " Player Name :  " << endl;

	cin.getline(tPlayer.strPlayerName, NAME_SIZE - 1);

	// Player and AI BingGO Baord 25 numbers
	int iNumber[25] = {};
	int iAINumber[25] = {};

	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
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

		// Shuffling AI Number

		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iAINumber[idx1];
		iAINumber[idx1] = iAINumber[idx2];
		iAINumber[idx2] = iTemp;

	}

	//Print out 5 X 5 BingGo Board
	int iBingGoLine = 0;
	int iAIBingGoLine = 0;
	int iAIGameMode;

	//Select AI GameMode Level (Either Easy or Hard)
	while (true)
	{
		system("cls");

		cout << "1. Easy Game Level" << endl << endl;
		cout << "2. Hard Game Level" << endl << endl;
		cout << "Please, select Game Mode" << endl;

		cin >> iAIGameMode; 


		if (iAIGameMode >= GM_EASY && iAIGameMode <= GM_HARD)
		{
			break;
		}
	}

	/*
		In AI Game Mode, AI will be selecting a number randomly (among the numbers that have not been selected)
	*/

	// List or Array of unselected numbers
	int iNonSelectNumber[25] = {};

	// Save list of unselected numbers
	int iNonSelectNumberCount = 0;


	while (true)
	{
		system("cls");

		cout << "=================== Player ===================" << endl << endl;

		cout << " Name :  " << tPlayer.strPlayerName << endl << endl;
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

		cout << "=================== AI ===================" << endl;
		cout << " AI BingGo Line : " << iAIBingGoLine << endl << endl;
		switch (iAIGameMode)
		{
		case GM_EASY:
			cout << " AI GAME MODE : EASY " << endl << endl;
			break;
		case GM_HARD:
			cout << " AI GAME MODE : HARD " << endl << endl;
			break;
		}

		
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
	

		//Win Condition for Both Player and AI
		if (iBingGoLine >= 5)
		{
			cout << " Player Win!!!!! " << endl;
			break;
		}

		else if (iAIBingGoLine >= 5)
		{
			cout << " AI Win!!!!!! " << endl;
			break;
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

		// If Numberis not repeated, chage AI number into " * "
		for (int i = 0; i < 25; ++i)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;

				--iNonSelectNumberCount;

				break;
			}
		}

		// Function of AI
		switch (iAIGameMode)
		{
		case GM_EASY:
			// List of unselected number
			iNonSelectNumberCount = 0;
			for (int i = 0; i < 25; ++i)
			{
				// Current number which is not changed to " * "
				if (iAINumber[i] != INT_MAX)
				{
					iNonSelectNumber[iNonSelectNumberCount] = iAINumber[i];
					++iNonSelectNumberCount;
				}
			}

			iInput = iNonSelectNumber[rand() % iNonSelectNumberCount];

			break;

		case GM_HARD:

			// In Hard Mode, AI will select the number
			// Which has the highest percentage of get a BingGo Line	

			int iLine = 0;
			int iStarCount = 0;

			// Save the line which has the most number of " * "
			int iSaveCount = 0;

			//Search the most of number of Star line among Row and Column line
			for (int i = 0; i < 5; ++i)
			{
				iStarCount = 0;
				for (int j = 0; j < 5; ++j)
				{
					if (iAINumber[i * 5 + j] == INT_MAX)
						++iStarCount;
				}


				if (iStarCount < 5 && iSaveCount < iSaveCount)
				{
					iLine = i;
					iSaveCount = iSaveCount;
				}

			}

			for (int i = 0; i < 5; ++i)
			{
				for (int j = 0; j < 5; ++j)
				{
					if (iAINumber[j * 5 + i] == INT_MAX)
					{
						++iSaveCount;
					}
				}
				
				if (iStarCount < 5 && iSaveCount < iStarCount)
				{
					iLine = i + 5;
					iSaveCount = iStarCount;
				}

			} 

			iStarCount = 0;
			
			for (int i = 0; i < 25; i += 6)
			{
				if (iAINumber[i] == INT_MAX)
				{
					++iStarCount;
				}
			}

			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				iLine = LN_LT;
				iSaveCount = iStarCount;
			}

			iStarCount = 0;

			for (int i = 0; i <= 20; i += 4)
			{
				if (iAINumber[i] == INT_MAX)
				{
					++iStarCount;
				}
			}

			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				iLine = LN_RT;
				iSaveCount = iStarCount;
			}

			if (iLine <= LN_H5)
			{
				for (int i = 0; i < 5; ++i)
				{
					// Find number that is not a " * " in a line
					if (iAINumber[iLine * 5 + i] != INT_MAX)
					{
						iInput = iAINumber[iLine * 5 + i];
						break;
					}
				}
			}

			else if (iLine <= LN_V5)
			{
				for (int i = 0; i < 5; ++i)
				{
					if (iAINumber[i * 5 + (iLine - 5)] != INT_MAX)
					{
						iInput = iAINumber[i * 5 + (iLine - 5)];
						break;
					}
				}
			}

			else if (iLine == LN_LT)
			{
				for (int i = 0; i < 25; i += 6)
				{
					if (iAINumber[i] != INT_MAX)
					{
						iInput = iAINumber[i];
						break;
					}
				}
			}
			
			else if (iLine == LN_RT)
			{
				for (int i = 0; i <= 20; i += 4)
				{
					if (iAINumber[i] != INT_MAX)
					{
						iInput = iAINumber[i];
						break;
					}
				}
			}
			break;

		}

		// Change number into " * " selected by AI
		for (int i = 0; i < 25; ++i)
		{
			if (iNumber[i] == iInput)
			{
				iNumber[i] = INT_MAX;
				break;
			}
		}

		//
		for (int i = 0; i < 25; ++i)
		{
			if (iAINumber[i] == iInput)
			{
				iAINumber[i] = INT_MAX;
				break;
			}
		}

		// BingGO Line Check
		iBingGoLine = 0;
		iAIBingGoLine = 0;

		int iStar1 = 0, iStar2 = 0;
		int iAIStar1 = 0, iAIStar2 = 0;

		for (int i = 0; i < 5; ++i)
		{
			iStar1 = iStar2 = 0;
			iAIStar1 = iAIStar2 = 0;
			for (int j = 0; j < 5; ++j)
			{
				// Player Horizontal Line
				if (iNumber[i * 5 + j] == INT_MAX)
				{
					++iStar1;
				}

				// Player Vertical Line
				if (iNumber[j * 5 + i] == INT_MAX)
				{
					++iStar2;
				}

				// AI Horizontal Line
				if (iAINumber[i * 5 + j] == INT_MAX)
				{
					++iAIStar1;
				}

				//AI Vertical Line
				if (iAINumber[j * 5 + i] == INT_MAX)
				{
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
		iAIStar1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;

			if (iAINumber[i] == INT_MAX)
				++iAIStar1;
		}

		if (iStar1 == 5)
		{
			++iBingGoLine;
		}

		if (iAIStar1 == 5)
		{
			++iAIBingGoLine;
		}

		// Uper Right -> Lower Left
		iStar1 = 0;
		iAIStar1 = 0;
		for (int i = 0; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;

			if (iAINumber[i] == INT_MAX)
				++iAIStar1;
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
	return 0;
}