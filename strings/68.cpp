class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            // STEP 1: Fit as many words as possible on this line
            int lineLen = words[i].size();
            int j = i + 1;
            while (j < n && lineLen + 1 + words[j].size() <= maxWidth) {
                lineLen += 1 + words[j].size();
                j++;
            }

            int numWords = j - i;
            int numGaps = numWords - 1;

            // STEP 2: Count total letters
            int totalChars = 0;
            for (int k = i; k < j; k++)
                totalChars += words[k].size();

            // STEP 3: Build the line
            string line = words[i];

            // Last line OR single word → left justify
            if (j == n || numWords == 1) {
                for (int k = i + 1; k < j; k++)
                    line += " " + words[k];
                while ((int)line.size() < maxWidth)
                    line += " ";
            }
            // Middle lines → distribute spaces evenly
            else {
                int totalSpaces = maxWidth - totalChars;
                int spacePerGap = totalSpaces / numGaps;
                int extraSpaces = totalSpaces % numGaps;

                for (int k = i + 1; k < j; k++) {
                    int spacesHere = spacePerGap + (k - i <= extraSpaces ? 1 : 0);
                    line += string(spacesHere, ' ') + words[k];
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};