﻿/*

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
using namespace std;

bool inCheck(int a, int b, int x, int y);

int main()
{
    int cases, num, xKing, yKing, *xKnight, *yKnight, i, j;

    cin >> cases;
    
    while (cases--)
    {
        cin >> num;
    
        xKnight = new (nothrow) int[num];
        yKnight = new (nothrow) int[num];

        if (xKnight == nullptr || yKnight == nullptr)
        {
            delete[] xKnight;
            delete[] yKnight;
        }

        for (i = 0; i < num; ++i)
        {
            cin >> xKnight[i];
            cin.ignore(1);
            cin >> yKnight[i];
        }

        cin >> xKing;
        cin.ignore(1);
        cin >> yKing;

        for (i = 0; i < num; ++i)
        {
            if ( inCheck(xKing, yKing, xKnight[i], yKnight[i]) )
            {
                for (j = 0; j < num; ++j)
                {
                    if ( inCheck(xKing + 1, yKing, xKnight[j], yKnight[j] ) )
                    {
                        cout << "YES";
                    }

                    else if ( inCheck(xKing - 1, yKing, xKnight[j], yKnight[j] ) )
                    {
                        cout << "YES";
                    }

                    else if ( inCheck(xKing, yKing + 1, xKnight[j], yKnight[j] ) )
                    {
                        cout << "YES";
                    }

                    else if ( inCheck(xKing, yKing - 1, xKnight[j], yKnight[j] ) )
                    {
                        cout << "YES";
                    }

                    else if ( inCheck(xKing + 1, yKing + 1, xKnight[j], yKnight[j] ) )
                    {
                        cout << "YES";
                    }

                    else if ( inCheck(xKing + 1, yKing - 1, xKnight[j], yKnight[j] ) )
                    {
                        cout << "YES";
                    }

                    else if ( inCheck(xKing - 1, yKing + 1, xKnight[j], yKnight[j] ) )
                    {
                        cout << "YES";
                    }

                    else if ( inCheck(xKing - 1, yKing - 1, xKnight[j], yKnight[j] ) )
                    {
                        cout << "YES";
                    }

                    else
                    {
                        cout << "NO";
                    }
                }
            }

            else
            {
                cout << "NO";
            }
        }
    }

    return 0;
}

bool inCheck(int a, int b, int x, int y)
{
    // check left up and down
    if ( (x - 2 == a && y + 1 == b) || (x - 2 == a && y - 1 == b) )
    {
        return true;
    }

    // check right up and down
    if ( (x + 2 == a && y + 1 == b) || (x + 2 == a && y - 1 == b) )
    {
        return true;
    }
    
    // check up left and right
    if ( (y + 2 == b && x - 1 == a) || (y + 2 == b && x + 1 == a) )
    {
        return true;
    }
    
    // check down left
    if ( (y - 2 == b && x - 1 == a) || (y - 2 == b && x + 1 == a) )
    {
        return true;
    }

    return false;

}