class Solution {
    public String addSpaces(String s, int[] spaces) {
        int n = s.length();
        int m = spaces.length;
        StringBuilder result = new StringBuilder(n + m);

        int spaceIndex = 0, strIndex = 0;
        for (int i = 0; i < n; i++) {
            if (spaceIndex < m && i == spaces[spaceIndex]) {
                result.append(' ');
                spaceIndex++;
            }
            result.append(s.charAt(i));
        }

        return result.toString();
    }
}

2)
class Solution {
    public String addSpaces(String s, int[] spaces) {
        StringBuilder result = new StringBuilder(s.length() + spaces.length);
        int spaceIndex = 0;

        for (int i = 0; i < s.length(); i++) {
            if (spaceIndex < spaces.length && i == spaces[spaceIndex]) {
                result.append(' ');
                spaceIndex++;
            }
            result.append(s.charAt(i));
        }

        return result.toString();
    }
}
