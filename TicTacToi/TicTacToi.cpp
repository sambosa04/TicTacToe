#include<iostream>
#include<vector>
using namespace std;


void view(string plane[]);
void play(string s[], char& c, int index);
void userPrompt(char c);
bool check(vector<int> set, int index);
bool isIn(int num, vector<int> player);
bool cheakWin(vector<int> player);

int main()
{
	string plane[5];
	plane[0] = "       |       |       ";
	plane[1] = "-----------------------";
	plane[2] = "       |       |       ";
	plane[3] = "-----------------------";
	plane[4] = "       |       |       ";


	vector<int> log;
	vector<int> player1;
	vector<int> player2;

	int index, counter = 0;
	bool game = true;
	char c = 'x';
	view(plane);

	while (counter < 9)
	{
		userPrompt(c);
		cin >> index;
		if (check(log, index))
		{
			log.push_back(index);
			if (c == 'x')
			{
				player1.push_back(index);
			}
			else
			{
				player2.push_back(index);
			}
		}
		else
		{
			cout << "your input is not correct" << endl;
			continue;
		}
		play(plane, c, index);
		view(plane);

		if (cheakWin(player1))
		{
			cout << "player 1 win";
			return -1;
		}

		if (cheakWin(player2))
		{
			cout << "player 2 win";
			return -1;
		}

		counter++;
	}


	cout << "Draw" << endl;

	return 0;
}

bool cheakWin(vector<int> player)
{
	int win[8][3] = {
	{ 1,2,3 },
	{ 4,5,6 },
	{ 7,8,9 },

	{ 1,4,7 },
	{ 2,5,8 },
	{ 3,6,9 },

	{ 1,5,9 },
	{ 3,5,7 },

	};

	for (int i = 0; i < 8; i++)
	{
		int c1 = win[i][0];
		int c2 = win[i][1];
		int c3 = win[i][2];

		if (isIn(c1, player) && isIn(c2, player) && isIn(c3, player))
		{
			return true;
		}

	}

	return false;
}

bool isIn(int num, vector<int> player)
{

	for (auto i = player.begin(); i != player.end(); i++)
	{
		if (*i == num)
			return true;
	}

	return false;
}


// veiw the plane
void view(string plane[])
{
	for (int i = 0; i < 5; i++)
	{
		cout << plane[i];
		cout << "\n";
	}
}

// check if the index is taken or not
bool check(vector<int> set, int index)
{
	for (auto i = set.begin(); i != set.end(); i++)
	{
		if (*i == index)
			return false;
	}

	return true;
}



void userPrompt(char c)
{
	if (c == 'x')
		cout << "player 1:";
	else
		cout << "player 2:";
}

void play(string s[], char& c, int index)
{
	switch (index)
	{
	case 1:
		s[0][3] = c;
		break;
	case 2:
		s[0][11] = c;
		break;
	case 3:
		s[0][19] = c;
		break;
	case 4:
		s[2][3] = c;
		break;
	case 5:
		s[2][11] = c;
		break;
	case 6:
		s[2][19] = c;
		break;
	case 7:
		s[4][3] = c;
		break;
	case 8:
		s[4][11] = c;
		break;
	case 9:
		s[4][19] = c;
		break;
	default:
		break;

	}

	if (c == 'x')
		c = 'o';
	else
		c = 'x';
}

