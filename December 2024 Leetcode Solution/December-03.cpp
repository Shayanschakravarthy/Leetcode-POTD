class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int spaceIndex = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (spaceIndex < spaces.size() && i == spaces[spaceIndex]) {
                result += ' ';
                spaceIndex++;
            }
            result += s[i];
        }

        return result;
    }
};

2)
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        result.reserve(s.length() + spaces.size());
        
        int spaceIndex = 0;
        for (int i = 0; i < s.size(); i++) {
            if (spaceIndex < spaces.size() && i == spaces[spaceIndex]) {
                result += ' ';
                spaceIndex++;
            }
            result += s[i];
        }
        
        return result;
    }
};

3)
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        int m = spaces.size();
        string result;
        result.reserve(n + m);  

        int spaceIndex = 0;
        for (int i = 0; i < n; ++i) {
            if (spaceIndex < m && i == spaces[spaceIndex]) {
                result.push_back(' ');  
                ++spaceIndex;
            }
            result.push_back(s[i]);  
        }

        return result;
    }
};
