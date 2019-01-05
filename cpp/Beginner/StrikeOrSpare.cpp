/*

Chef's company wants to make ATM PINs for its users, so that they could use the PINs
for withdrawing their hard-earned money. One of these users is Reziba, who lives in
an area where a lot of robberies take place when people try to withdraw their money.

Chef plans to include a safety feature in the PINs: if someone inputs the reverse
of their own PIN in an ATM machine, the Crime Investigation Department (CID) are
immediately informed and stop the robbery. However, even though this was implemented
by Chef, some people could still continue to get robbed. The reason is that CID is
only informed if the reverse of a PIN is different from that PIN
(so that there wouldn't be false reports of robberies).

You know that a PIN consists of N decimal digits. Find the probability that Reziba
could get robbed. Specifically, it can be proven that this probability can be
written as a fraction P/Q, where P>=0 and Q>=0 are coprime integers; you should
compute P and Q.

Input:
The first line of the input contains a single integer T denoting the number of
test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N denoting
the length of each PIN.

Output:
For each test case, print a single line containing two space-separated
integers - the numerator P and denominator Q of the probability.

Constraints:
1<=T<=100
1<=N<=105

Subtasks:
Subtask #1 (10 points): N<=18
Subtask #2 (20 points): N<=36
Subtask #3 (70 points): original constraints

Example Input:
1
1

Example Output:
1 1

Explanation:
Example case 1: A PIN containing only one number would fail to inform the CID,
				since when it's input in reverse, the ATM detects the same PIN as the correct one.
				Therefore, Reziba can always get robbed - the probability is 1=1/1.

*/


#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int cases, i, num;
	
    cin >> cases;
    
    while ( cases > 0 )
    {
        cin >> num;
        
		cout << "1 1";
        
		// if n is even
        if (num != 1 && num % 2 == 0)
        {
			for (i = 0; i < 1 + (num - 2) / 2; ++i)
			{
				cout << "0";
			}
        }

		// if n is odd
		else if (num != 1 && num % 2 != 0)
		{
			for (i = 0; i < 1 + (num - 3) / 2; ++i)
			{
				cout << "0";
			}
		}
        
		cout << endl;

        --cases;
    }
    
    return 0;
}


































/*




#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int cases, num;

    cin >> cases;
    while (cases > 0)
    {
        cin >> num;

        // if n equals 1, pin is always a palindrome
        if (num == 1)
        {
            cout << 1 << " " << 1 << endl;
        }

        else
        {
            cout << 1 << " "
                << (num % 2 == 0 ? (9 * pow(10, (num - 2) / 2)) : (9 * pow(10, (num - 3) / 2)))
                << endl;
        }

        --cases;
    }

    return 0;
}
*/