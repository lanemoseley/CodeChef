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

fun main(args: Array<String>) {
    val reader = Scanner(System.`in`)
    val l_hand = arrayOf('d', 'f')
    val r_hand = arrayOf('j', 'k')

    var cases:Int = reader.nextInt()
    var numWords:Int = reader.nextInt()

    while (cases >= 0) {
        var words = arrayOfNulls<String>(numWords)
        var times = arrayOfNulls<Int>(numWords)

        var i = 0
        for (i in 0 until numWords) {
            var newWord = readLine()
            var dup = false

            if (newWord in words) {
                println("True")
            }
            else {
                println("False")
            }

        }

        cases -= 1
    }

}

    /*
    if new_word in words:
    dup = True
    times.append( times[ words.index( new_word ) ] / 2 )

    # add word to list
            words.append( new_word )

    # if no duplicate found, assign a new time value to the word
    if not( dup ):
    # add word to list
            words.append( new_word )

    # adding time for first letter
            times.append( 2 )

    # adding time for following letters
            for j in range( 1, len( words[ i ] ) ):
    times[ i ] += 2

    if ( words[ i ][ j ] in l_hand ) and ( words[ i ][ j - 1 ] in l_hand ):
    times[ i ] += 2

    elif ( words[ i ][ j ] in r_hand ) and ( words[ i ][ j - 1 ] in r_hand ):
    times[ i ] += 2

    print( int( sum( times ) ) )
}*/