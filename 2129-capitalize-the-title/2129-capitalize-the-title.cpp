class Solution {
public:
     string capitalizeTitle(string title) {
          int n = title.size();
          int start = 0,end = 0;
          while (start < n) {
               while (title[end] != ' ' && end < n) {
                    end++;
               }
               for (int k = start; k < end; k++) {
                    title[k] = tolower(title[k]);
               }
               if (end - start > 2) {
                    title[start] = toupper(title[start]);
               }
               end++;
               start = end;
          }
          return title;
     }
};