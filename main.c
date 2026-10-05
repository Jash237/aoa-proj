#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT 1000
#define MAX_PATTERN 100

void toLowerCase(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = tolower((unsigned char)src[i]);
        i++;
    }
    dest[i] = '\0';
}

void stringMatch(char *text, char *pattern, int caseSensitive) {
    int n = strlen(text);
    int m = strlen(pattern);
    int matchIndices[MAX_TEXT];//stores starting position of each index at which pattern is found.
    int matchCount = 0;
    int totalComparisons = 0;
    int i,j;
    char processedText[MAX_TEXT];
    char processedPattern[MAX_PATTERN];

    if (m == 0) {
        printf("\nError: Pattern cannot be empty.\n");
        return;
    }
    if (m > n) {
        printf("\nResult: Pattern length (%d) is greater than text length (%d).\n", m, n);
        printf("Total character comparisons: 0\n");
        return;
    }

    

    //copy the same string and change it into lowercase if the option is chosen, so that the original text remains unchanged.
    if (caseSensitive) {
        strcpy(processedText, text);
        strcpy(processedPattern, pattern);
    } else {
        toLowerCase(processedText, text);
        toLowerCase(processedPattern, pattern);
    }

    for(i = 0; i <= n - m; i++) {//we use n-m because if the pattern is of two letters then any text after position n-2 will not follow the pattern, also risk of array index out of bounds
        for(j = 0; j < m; j++) {
            totalComparisons++;
            if (processedText[i + j] != processedPattern[j]) 
                break; 
        }
        if (j == m) {
            matchIndices[matchCount] = i;
            matchCount++;
        }
    }

    printf("\n");

    if (matchCount > 0) {
        printf("Status: MATCH FOUND\n");
        printf("Total Occurrences Found: %d\n", matchCount);
        printf("Starting Indices: ");
        for (i = 0; i < matchCount; i++) {
            printf("%d ", matchIndices[i]);
        }
        printf("\n\nHighlighted Text Position(s):\n");
        int matchIdx = 0;
        for (i = 0; i < n; ) {
            
            while (matchIdx < matchCount && matchIndices[matchIdx] < i) //skips overlapping matching words example - ttttt/tt
                matchIdx++;

            if (matchIdx < matchCount && i == matchIndices[matchIdx]) {
                printf("[");
                for (int k = 0; k < m; k++) {
                    printf("%c", text[i + k]);
                }
                printf("]");
                i += m; // Move index past the current match
                matchIdx++;
            } 

            else {
                printf("%c", text[i]);
                i++;
            }
        }
        printf("\n");
    } 
    else 
        printf("Status: MATCH NOT FOUND\n");

    printf("\nTotal Character Comparisons Performed: %d\n", totalComparisons);
    printf("\n");
}

int main() {
    char text[MAX_TEXT] = "";
    char pattern[MAX_PATTERN];
    int choice, caseChoice;

    while (1) {
        printf("\n");
        printf("1. Enter Main Text\n");
        printf("2. Display Main Text\n");
        printf("3. Search Keyword / Pattern\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter main text / paragraph:\n");
                scanf(" %[^\n]s", text);
                printf("\nText updated successfully!\n");
                break;

            case 2:
                if (strlen(text) == 0) {
                    printf("\nNo text available. Please enter text first.\n");
                } else {
                    printf("\n--- CURRENT TEXT ---\n");
                    printf("%s\n", text);
                }
                break;

            case 3:
                if (strlen(text) == 0) {
                    printf("\nNo text available. Please enter text first.\n");
                    break;
                }

                printf("\nEnter keyword / pattern to search: ");
                scanf(" %[^\n]s", pattern);

                printf("\nSearch Mode:\n");
                printf("1. Case-Sensitive\n");
                printf("2. Case-Insensitive\n");
                printf("Enter choice (1 or 2): ");
                scanf("%d", &caseChoice);

                stringMatch(text, pattern, (caseChoice == 1) ? 1 : 0);
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}
