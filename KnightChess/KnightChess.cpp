/*

Abhineet the Chess master of NIT Kurukshetra got bored of 8x8 chess board and
invented the new variation of Chess, the one on an infinite chess board.
There is only a white king and N black knights.
The white king has to avoid checkmate as long as it can.

A situation is given. Determine if white king is in checkmate or not.
The white king is in checkmate if and only if it is in check and it is not able
to move to any of its neighboring positions which is not in check.

Input:
The first line will contain T, number of test cases. Then the test cases follow.
The first line of each test case contains a single integer N.
The next N line contains 2 space-separated integers Xi and Yi denoting the position of knights.
The next line contains 2 space-separated integers A and B denoting the position of king

Output:
Print a single line corresponding to each test case — “YES” (without quotes) – if the king is in checkmate and “NO” (without quotes) – if the king is not in checkmate.

Constraints:
1≤T≤5
1≤N≤105
−109≤Xi,Yi,A,B≤109

Sample Input:
2
6
1 0
0 2
2 5
4 4
5 0
6 2
3 2
4
5 6
3 5
2 8
-8 -8
0 0

Sample Output:
YES
NO

EXPLANATION:
In the first test case, the king is in cannot move to any valid position In second test case, the king can easily make a valid move.

*/

#include <iostream>
#include <vector>
using namespace std;


// structure for holding the coordinates of a given piece
struct coords{
		int x;
		int y;
};

// structure for holding the knight's location and range of movement
class theKnight{

public:
	theKnight(int x = 0, int y = 0);
	~theKnight();

	vector<coords> getMoves();

private:
	int max_choices = 8;
	int range[8][2] = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2} };

	coords pos;
	vector<coords> possible_moves;
};

// structure for holding the king's location and range of movement
class theKing{

public:
	theKing(int x = 0, int y = 0);
	~theKing();

	vector<coords> getMoves();
	bool inCheck( vector<coords> threats );
	bool getUnchecked( vector<coords> threats );

private:
	int max_choices = 8;
	int range[8][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

	coords pos;
	vector<coords> possible_moves;
};




int main()
{
	unsigned int i;
    int cases, num, temp_x, temp_y;
	vector<theKnight> knights;
	bool in_check, still_in_check;
	
    cin >> cases;
    
    while (cases--)
    {
        cin >> num;

        // getting knight locations
        for (i = 0; (int) i < num; ++i)
        {
            cin >> temp_x;
            cin.ignore(1);
            cin >> temp_y;

			// initializing knight and putting the knight in a vector
            theKnight kt(temp_x, temp_y);

            knights.push_back(kt);
        }

        // getting king location
        cin >> temp_x;
        cin.ignore(1);
        cin >> temp_y;

		// initializing king
		theKing kg(temp_x, temp_y);

		in_check = false;
		for (i = 0; i < knights.size() && !in_check; ++i)
        {
			in_check = kg.inCheck(knights[i].getMoves());
        }

		if (in_check)
		{
			still_in_check = true;

			for (i = 0; i < knights.size() && still_in_check; ++i)
			{
				still_in_check = kg.getUnchecked(knights[i].getMoves());
			}

			if (still_in_check)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		
		else
			cout << "NO" << endl;
    }

    return 0;
}




// knight class functions
theKnight::theKnight(int x, int y)
{
	int i;
	coords temp;
	
	pos.x = x;
	pos.y = y;

	for (i = 0; i < max_choices; ++i)
    {
		temp.x = pos.x + range[i][0];
		temp.y = pos.y + range[i][1];

		possible_moves.push_back(temp);
    }
}

theKnight::~theKnight()
{

}

vector<coords> theKnight::getMoves()
{
	return possible_moves;
}




// king class functions
theKing::theKing(int x, int y)
{
	int i;
	coords temp;
	
	pos.x = x;
	pos.y = y;

	for (i = 0; i < max_choices; ++i)
    {
		temp.x = pos.x + range[i][0];
		temp.y = pos.y + range[i][1];

		possible_moves.push_back(temp);
    }
}

theKing::~theKing()
{

}

vector<coords> theKing::getMoves()
{
	return possible_moves;
}

bool theKing::inCheck(vector<coords> threats)
{
	unsigned int i;

	for (i = 0; i < threats.size(); ++i)
    {
        if (threats[i].x == pos.x && threats[i].y == pos.y)
        {
			return true;
        }
    }

	return false;
}

bool theKing::getUnchecked(vector<coords> threats)
{
	unsigned int i, j;
	
	for (i = 0; i < possible_moves.size(); ++i)
	{
		for (j = 0; j < threats.size(); ++j)
		{
			if (threats[j].x == possible_moves[i].x && threats[j].y == possible_moves[i].y)
			{
				return true;
			}
		}
	}

	return false;
}