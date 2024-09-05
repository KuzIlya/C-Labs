#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char* longestCommonWord = new char[1]; 
    strcpy(longestCommonWord, ""); 

    const char* sentence1 = "aaa bcd bb aaaa";
    char* words1 = new char[strlen(sentence1)];
    strcpy(words1, sentence1);

    const char* sentence2 = "bb ccc aaaaa";
    char* words2 = new char[strlen(sentence2)];
    strcpy(words2, sentence2);

    char* wordsArray[20]; 
    int wordCount = 0; 
    char* token1 = strtok(words1, " ");
    while (token1 != NULL) {
        wordsArray[wordCount++] = token1;
        token1 = strtok(NULL, " ");
    }

    char* token2 = strtok(words2, " "); 
    while (token2 != NULL) {
        if (strlen(token2) > strlen(longestCommonWord)) {
            for (int i = 0; i < wordCount; i++) {
                if (strcmp(token2, wordsArray[i]) == 0) {
                    longestCommonWord = new char[strlen(token2)]; 
                    strcpy(longestCommonWord, token2); 
                    break;
                }
            }
        }
        token2 = strtok(NULL, " ");
    }

    cout << "Longest word: " << longestCommonWord << endl;

    return 0;
}
