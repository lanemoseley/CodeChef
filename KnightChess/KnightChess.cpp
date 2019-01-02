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

	bool operator==(coords &c);
};

// structure for holding the knight's location and range of movement
class theKnight{

public:
	theKnight(int x = 0, int y = 0);
	~theKnight();

	vector<coords> possible_moves;

private:
	int max_choices = 8;
	int range[8][2] = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2} };

	coords pos;
};

// structure for holding the king's location and range of movement
class theKing{

public:
	theKing(int x = 0, int y = 0);
	~theKing();

	vector<coords> possible_moves;

private:
	int max_choices = 8;
	int range[8][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

	coords pos;
};




int main()
{
	unsigned int i, j;
    int cases, num, temp_x, temp_y;
	vector<theKnight> knights;
	vector<coords> kings_moves, invalid_squares;
	bool is_valid;
	
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

		// gathering all invalid squares
		for (i = 0; i < knights.size(); ++i)
		{
			for (j = 0; j < knights[i].possible_moves.size(); ++j)
			{
				invalid_squares.push_back(knights[i].possible_moves[j]);
			}
		}

		is_valid = false;

		for (i = 0; i < kg.possible_moves.size() && !is_valid; ++i)
		{
			is_valid = true;
			for (j = 0; j < invalid_squares.size(); ++j)
			{
				if (invalid_squares[j] == kg.possible_moves[i])
				{
					// move invalid
					is_valid = false;
				}
			}
		}

		if (is_valid)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
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


// overloaded operator for coords struct
bool coords::operator==(coords &c)
{
	return (x == c.x && y == c.y);
}