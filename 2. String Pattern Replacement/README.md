# Algorithm

1. Loop until string ends
    1. if char in str match pattern(pat)
        - if char in pat is null
            1. set flag 1
            1. reset rep index k=0
            1. Loop until REP ends
                - insert char to final String(ANS) by incrementing indexes
            1. reset pat index (i)
            1. set str point after pat chars in str
    2. else 
        1. insert char to final String(ANS) by incrementing indexes
        2. reset pat index (i) = 0
        3. point str index after inserted chars to ans
    3. Set end of ANS to null
    4. return flag
