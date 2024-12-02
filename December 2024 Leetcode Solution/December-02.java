class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        int n = sentence.length(), m = searchWord.length();
        int word_index = 1, i = 0;
        
        while (i < n) {
            if (sentence.startsWith(searchWord, i) && (i == 0 || sentence.charAt(i - 1) == ' ')) {
                return word_index;
            }
            while (i < n && sentence.charAt(i) != ' ') {
                i++;
            }
            word_index++;
            i++; 
        }
        
        return -1;
    }
}

2)
class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        String[] words = sentence.split(" "); 
        for (int i = 0; i < words.length; i++) {
            if (words[i].startsWith(searchWord)) { 
                return i + 1; 
            }
        }
        return -1; 
    }
}
