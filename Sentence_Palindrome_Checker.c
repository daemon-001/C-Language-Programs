#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

int main() {
    char sentence[200];
    char words[50][20]; // supports up to 50 words, each up to 20 chars
    int wordCount = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove newline at end if exists
    sentence[strcspn(sentence, "\n")] = '\0';
    toLowerCase(sentence);

    // Split into words
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        strcpy(words[wordCount++], token);
        token = strtok(NULL, " ");
    }

    // Check palindrome by words
    int isPalindrome = 1;
    for (int i = 0; i < wordCount / 2; i++) {
        if (strcmp(words[i], words[wordCount - i - 1]) != 0) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("The sentence is a word-level palindrome.\n");
    else
        printf("The sentence is NOT a word-level palindrome.\n");

    return 0;
}
