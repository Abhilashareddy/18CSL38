/*
    Design, Develop and Implement a Program in C for the following operations on Strings
        a. Read a main String (STR), a Pattern String (PAT) and a Replace String (REP)
        b. Perform Pattern Matching Operation: Find and Replace all occurrences of PAT in STR
            with REP if PAT exists in STR.
            Report suitable messages in case PAT does not exist in STR
    Support the program with functions for each of the above operations. Don't use Built-in functions.
*/

#include <stdio.h>

// Here we consider uppercase variable because it is considered as good practice
// To be able to differentiate GLOBAL and LOCAL variables inside function
char STR[100]; // Given main string
char PAT[50];  // Given pattern string
char REP[50];  // Given replacement string
char ANS[100]; // Final resultant string

// Match Function
// returns 1 on successful operation otherwise 0
int Match()
{
    // Consider index variables
    int i = 0; // For Pattern String -> PAT
    // m -> main index variable for Main string STR
    // c -> Used to set index in STR where pattern is matched
    int c = 0, m = 0;
    int k = 0;    // For Replace string -> REP
    int j = 0;    // For Final String -> ANS
    int flag = 0; // Denotes successful operation when 1 otherwise 0 on error

    // String always ends with NULL character '\0'
    // Loop until STR ends
    while (STR[c] != '\0')
    {
        // Check if Character in STR matches with PAT
        if (STR[m] == PAT[i])
        {
            // Increment index m and i
            m++;
            i++;
            // If Char in PAT mataches NULL(\0)
            if (PAT[i] == '\0')
            {
                flag = 1; // Set Result success
                k = 0;    // Reset index of REP
                // Insert replace string(REP) to Final String(ANS)
                // Loop Until REP ends with NULL
                while (REP[k] != '\0')
                {
                    // Insert characters to Final String
                    ANS[j++] = REP[k++];
                }
                i = 0; // Reset index of PAT
                c = m; // c will now point to end of PAT char found in STR
            }
        }
        else
        {
            // Insert Remaining Char in STR to ANS
            ANS[j++] = STR[c++];
            i = 0; // Reset index of PAT
            m = c; // m will now point to next character after insertion
        }
    }
    // Set end of ANS string to NULL
    ANS[j] = '\0';
    return flag;
}

// Driver program
void main()
{
    int success; // Variable for function return value

    printf("Enter\n");
    printf("Main string: ");
    // Using fgets() is safer than gets() for string input
    fgets(STR, 100, stdin);
    printf("Pattern String: ");
    fgets(PAT, 50, stdin);
    printf("Replacement String: ");
    fgets(REP, 50, stdin);

    success = Match();

    if (success)
        printf("Result: %s", ANS);
    else
        printf("Pattern string not found!\n");
}