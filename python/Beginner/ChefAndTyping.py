cases = int( input( ) )
words = []
times = []
count = 0.0

while cases:
    for i in range( int( input( ) ) ):
        words.append( input( ) )
        times.append( 0.0 )
        
        times[i] += 0.2
        j = 1
        while j < len( words[i] ):
            times[i] += 0.2
            if ( words[i][j] == 'd' or words[i][j] == 'f' ) and ( words[i][j-1] == 'd' or words[i][j-1] == 'f' ):
                times[i] += 0.2
            elif ( words[i][j] == 'j' or words[i][j] == 'k' ) and ( words[i][j-1] == 'j' or words[i][j-1] == 'k' ):
                times[i] += 0.2
            j += 1

    # if multiples of the same word, dividing the typing time by two
    for i in range( len( words ) ):
        for j in range( len( words ) ):
            if words[i] == words[j]:
                times[i] += times[i] / 2.0
    
    for i in range( len( times ) ):
        count += times[i]

    print( count )

    cases -= 1