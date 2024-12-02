int isPrefixOfWord(char* sentence, char* searchWord) {
    int n = strlen(sentence), m = strlen(searchWord);
    int word_index = 1, i = 0;
    
    while (i < n) {
        if (strncmp(&sentence[i], searchWord, m) == 0 && (i == 0 || sentence[i - 1] == ' ')) {
            return word_index;
        }
        
        while (i < n && sentence[i] != ' ') {
            i++;
        }
        word_index++;
        i++; 
    }
    
    return -1;
}

2)
int isPrefixOfWord(char* sentence, char* searchWord) {
    int wordIndex = 1; 
    char* word = strtok(sentence, " "); 

    while (word != NULL) {
        if (strncmp(word, searchWord, strlen(searchWord)) == 0) {
            return wordIndex;
        }
        wordIndex++;
        word = strtok(NULL, " ");
    }

    return -1; 
}
