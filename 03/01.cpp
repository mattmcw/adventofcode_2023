#include "../aoc.h"

AOC aoc;

int64_t evaluate (string full, string num, int started , int ended) {
   if (started > -1 && full[started - 1] != '.') {
      return 0;
   } else if (ended > -1 && full[ended + 1] != '.') {
      return 0;
   } else if (num == "") {
      return 0;
   }
   cout << num << endl;
   return stoi(num);
}

int64_t parseLine (string s) {
   int output = 0;
   string toparse = "";
   int started = -1;
   int ended = -1;
   for (int i = 0; i < s.length(); i++) {
      if (isdigit(s[i])) {
         toparse = toparse.append(to_string(s[i]));
         if (started == -1) {
            started = i;
         }
      } else {
         ended = i;
         output += evaluate(s, toparse, started, ended);
         toparse = "";
         ended = -1;
         started = -1;
      }
   }
   return output;
}

int main() {
   string s;
   int64_t answer = 0;
   while( getline( cin, s ) ) {
      cout << s << endl;
      answer += parseLine(s);
      //cout << parseLine(s) << endl;
   }
   cout << answer << endl;
}