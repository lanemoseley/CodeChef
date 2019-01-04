/*

Chef is practising his typing skills since his current typing speed is very low.
He uses a training application that displays some words one by one for Chef to type.
When typing a word, Chef takes 2 seconds to type the first character; for each
other character of this word, he takes 2 seconds to type this character if it is
written with a different hand than the previous character, or 4 seconds if it is
written with the same hand. The time taken to type a word is the sum of times
taken to type all of its characters. However, if a word has already appeared
during practice, Chef can type it in half the time it took him to type this
word for the first time.
Currently, Chef is practising in easy mode, which only uses words that consists
of characters 'd', 'f', 'j' and 'k'. The characters 'd' and 'f' are written using
the left hand, while the characters 'j' and 'k' are written using the right hand.
Given the words that appeared during Chef's practice, calculate the total time
taken by Chef to type all the words.
Input:
The first line of the input contains a single integer T denoting the number of
test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the number
of words Chef had to type.
Each of the following N lines contains a single string - a word Chef has to type.
Output:
For each test case, print a single line containing one integer - the time taken
by Chef to type all the words, in the units of tenths of seconds.
Constraints:
1<=T<=100
1<=N<=100
each word contains only characters 'd', 'f', 'j', 'k'
the length of each word does not exceed 20
Example Input:
1
5
fdjkd
dfjdk
dfd
fdjkd
kkjjk
Example Output:
61

 */

import java.util.Scanner

fun main( ) {
    val reader = Scanner( System.`in` )

    var cases:Int = reader.nextInt()     // # of test cases
    var numWords:Int                     // # of words in the test case
    var words = mutableListOf<String>()  // list of words
    var times = mutableListOf<Int>()     // list of times to type each word
    var newWord:String                   // variable to store word until it is added to list

    while ( cases > 0 ) {
        numWords = reader.nextInt()      // get number of words in test case
        words.clear()                    // clear both lists for each test case
        times.clear()

        for ( i in 0 until numWords ) {
            newWord = readLine()!!

            // if the word has already been typed, new time = 1/2 the first time
            if ( newWord in words ) {
                times.add( times[ words.indexOf( newWord ) ] / 2 )
                words.add( newWord )
            }

            // if word has not already been typed calculate time taken to type word
            else {
                words.add( newWord )
                times.add( 2 )

                for ( j in 1 until words[ i ].count() ) {
                    times[ i ] += 2

                    if ( ( words[ i ][ j ] == 'd' || words[ i ][ j ] == 'f' ) and ( words[ i ][ j - 1 ] == 'd' || words[ i ][ j - 1 ] == 'f' ) ) {
                        times[ i ] += 2
                    }

                    else if ( ( words[ i ][ j ] == 'j' || words[ i ][ j ] == 'k' ) and ( words[ i ][ j - 1 ] == 'j' || words[ i ][ j - 1 ] == 'k' ) ) {
                        times[ i ] += 2
                    }
                }
            }

        }

        println( times.sum() )

        cases -= 1
    }
}