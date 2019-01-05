/*

For a string S let the unique set of characters that occur in it one or more
times be C. Consider a permutation of the elements of C as (c1,c2,c3...).
Let f(c) be the number of times c occurs in S.

If any such permutation of the elements of C satisfies f(ci)=f(ci−1)+f(ci−2)
for all i≥3, the string is said to be a dynamic string.

Mr Bancroft is given the task to check if the string is dynamic, but he is busy
playing with sandpaper. Would you help him in such a state?

Note that if the number of distinct characters in the string is less than 3,
i.e. if |C|<3, then the string is always dynamic.

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, a string S.
Output:
For each testcase, output in a single line "Dynamic" if the given string is dynamic,
otherwise print "Not". (Note that the judge is case sensitive)

Constraints:
1≤T≤10
1≤|S|≤105
S contains only lower case alphabets: a, b, …, z

Sample Input:
3
aaaabccc
aabbcc
ppppmmnnoooopp

Sample Output:
Dynamic
Not
Dynamic

Explanation:
    Testase 1: For the given string, C={a,b,c} and f(a)=4,f(b)=1,f(c)=3.
    f(a)=f(c)+f(b) so the permutation (b,c,a) satisfies the requirement.

    Testcase 2: Here too C={a,b,c} but no permutation satisfies the requirement
    of a dynamic string.

    Testcase 3: Here C={m,n,o,p} and (m,n,o,p) is a permutation that makes it
    a dynamic string.

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// struct for holding each letter and its frequency count
struct letter
{
    char l;
    int count;
};

int main()
{
    int cases, i, j, size, t;
    bool dynamic, found;
    string s;                      // holds the test case string
    vector<letter> letters;        // vector of letters and their fequency counts
    vector<int> fib;               // vector of frequency counts only
    letter temp;
    
    cin >> cases;
    cin.ignore();
    
    while ( cases > 0 )
    {
        // reseting all vectors
        letters.clear();
        fib.clear();
        
        // get test case
        getline ( cin, s );
        
        for ( i = 0; i < int ( s.length() ); ++i )
        {
            // if the letter is a duplicate increment count
            found = false;
            
            for ( j = 0; j < int ( letters.size() ) && !found; ++j )
            {
                if ( !found && s[i] == letters[j].l )
                {
                    letters[j].count += 1;
                    found = true;
                }
            }
            
            // otherwise create instance of letter
            if ( !found )
            {
                temp.l = s[i];
                temp.count = 1;
                
                letters.push_back ( temp );
            }
        }
        
        // fill fib vector with letter counts
        for ( i = 0; i < int ( letters.size() ); ++i )
        {
            fib.push_back ( letters[i].count );
        }
        
        // sort fib vector in ascending order
        sort ( fib.begin(), fib.end() );
        
        // determine if string is dynamic or not
        size = fib.size();
        dynamic = true;
        
        for ( i = 2; i < size && dynamic; ++i )
        {
            if ( fib[i - 1] + fib[i - 2] != fib[i] )
            {
                // try swapping first two values and recheck (i.e. 1 2 3 4 = Not, but 2 1 3 4 = Dynamic)
                t = fib[0];
                fib[0] = fib[1];
                fib[1] = t;
                
                if ( fib[i - 1] + fib[i - 2] != fib[i] )
                {
                    dynamic = false;
                }
            }
        }
        
        cout << ( dynamic ? "Dynamic\n" : "Not\n" );
        
        --cases;
    }
    
    return 0;
}