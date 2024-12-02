class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.length(), m = searchWord.length();
        int word_index = 1, i = 0;
        
        while (i < n) {
            if (sentence.substr(i, m) == searchWord && (i == 0 || sentence[i - 1] == ' ')) {
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
};

2)
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream iss(sentence); 
        string word;
        int wordIndex = 1;
        while (iss >> word) { 
            if (word.find(searchWord) == 0) { 
                return wordIndex;
            }
            wordIndex++;
        }
        return -1; 
    }
};
