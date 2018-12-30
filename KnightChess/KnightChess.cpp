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


struct knights{
    coords c;
    vector<coords> range;
};

struct coords{
    int x;
    int y;

    bool operator==(coords &c);
    void operator=(coords &c);
};

int main()
{
    vector<knights> k;
    knights temp_knight;
    coords temp, temp_k, king;
    int cases, num, i, j, m;
    bool checkMate = false;
    bool check = false;

    cin >> cases;
    
    while (cases--)
    {
        cin >> num;

        // getting knight locations
        for (i = 0; i < num; ++i)
        {
            cin >> temp.x;
            cin.ignore(1);
            cin >> temp.y;

            temp_knight.c = temp;

            // setting range

            // right, up
            temp_k = temp;
            temp_k.x += 2;
            temp_k.y += 1;

            temp_knight.range.push_back(temp_k);

            // right, down
            temp_k = temp;
            temp_k.x += 2;
            temp_k.y -= 1;

            temp_knight.range.push_back(temp_k);

            // left, up
            temp_k = temp;
            temp_k.x -= 2;
            temp_k.y += 1;

            temp_knight.range.push_back(temp_k);

            // left, down
            temp_k = temp;
            temp_k.x -= 2;
            temp_k.y -= 1;

            temp_knight.range.push_back(temp_k);

            // up, right
            temp_k = temp;
            temp_k.x += 1;
            temp_k.y += 2;

            temp_knight.range.push_back(temp_k);

            // up, left
            temp_k = temp;
            temp_k.x -= 1;
            temp_k.y += 2;

            temp_knight.range.push_back(temp_k);

            // down, right
            temp_k = temp;
            temp_k.x += 1;
            temp_k.y -= 2;

            temp_knight.range.push_back(temp_k);

            // down, left
            temp_k = temp;
            temp_k.x -= 1;
            temp_k.y -= 2;

            temp_knight.range.push_back(temp_k);


            k.push_back(temp_knight);
        }

        // getting king location
        cin >> king.x;
        cin.ignore(1);
        cin >> king.y;

        // in check?
        for (i = 0; i < k.size() && !check; ++i)
        {
            for (j = 0; j < k[i].range.size() && !check; ++j)
            {
                // in check?
                if (k[i].range[j] == king)
                {
                    check = true;
                }
            }
        }

        // in checkmate?
        check = false;
        
        temp_k.x = king.x + 1;
        temp_k.y = king.y;

        for (i = 0; i < k.size() && !check; ++i)
        {
            for (j = 0; j < k[i].range.size() && !check; ++j)
            {
                // in check?
                if (k[i].range[j] == temp_k)
                {
                    check = true;
                }
            }
        }

        check = false;
        
        temp_k.x = king.x - 1;
        temp_k.y = king.y;

        for (i = 0; i < k.size() && !check; ++i)
        {
            for (j = 0; j < k[i].range.size() && !check; ++j)
            {
                // in check?
                if (k[i].range[j] == temp_k)
                {
                    check = true;
                }
            }
        }

        check = false;
        
        temp_k.x = king.x;
        temp_k.y = king.y + 1;

        for (i = 0; i < k.size() && !check; ++i)
        {
            for (j = 0; j < k[i].range.size() && !check; ++j)
            {
                // in check?
                if (k[i].range[j] == temp_k)
                {
                    check = true;
                }
            }
        }

        check = false;
        
        temp_k.x = king.x;
        temp_k.y = king.y - 1;

        for (i = 0; i < k.size() && !check; ++i)
        {
            for (j = 0; j < k[i].range.size() && !check; ++j)
            {
                // in check?
                if (k[i].range[j] == temp_k)
                {
                    check = true;
                }
            }
        }

        check = false;
        
        temp_k.x = king.x + 1;
        temp_k.y = king.y + 1;

        for (i = 0; i < k.size() && !check; ++i)
        {
            for (j = 0; j < k[i].range.size() && !check; ++j)
            {
                // in check?
                if (k[i].range[j] == temp_k)
                {
                    check = true;
                }
            }
        }

        check = false;
        
        temp_k.x = king.x + 1;
        temp_k.y = king.y - 1;

        for (i = 0; i < k.size() && !check; ++i)
        {
            for (j = 0; j < k[i].range.size() && !check; ++j)
            {
                // in check?
                if (k[i].range[j] == temp_k)
                {
                    check = true;
                }
            }
        }

        check = false;
        
        temp_k.x = king.x - 1;
        temp_k.y = king.y + 1;

        for (i = 0; i < k.size() && !check; ++i)
        {
            for (j = 0; j < k[i].range.size() && !check; ++j)
            {
                // in check?
                if (k[i].range[j] == temp_k)
                {
                    check = true;
                }
            }
        }

        check = false;
        
        temp_k.x = king.x - 1;
        temp_k.y = king.y - 1;

        for (i = 0; i < k.size() && !check; ++i)
        {
            for (j = 0; j < k[i].range.size() && !check; ++j)
            {
                // in check?
                if (k[i].range[j] == temp_k)
                {
                    check = true;
                }
            }
        }

        if (check)
            cout << "YES";
        else
            cout << "NO";
    }

    return 0;
}

bool coords::operator==(coords &c)
{
    return ((x == c.x && y == c.y));
}

void coords::operator=(coords &c)
{
    x = c.x;
    y = c.y;
}