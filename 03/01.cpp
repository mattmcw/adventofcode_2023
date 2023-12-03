#include "../aoc.h"

AOC aoc;
bool DEBUG = false;
vector<string> lines;

void debug (string line) {
   if (DEBUG) {
      cout << line << endl;
   }
}

bool is_symbol (char c) {
   if (!isdigit(c) && c != '.') {
      return true;
   }
   return false;
}

bool adjacent (int lineNum, int started, int ended) {
   //sides
   char c;
   int start;
   int end;
   string line = lines[lineNum];
   if (started > 0) {
      c = line[started - 1];
      if (is_symbol(c)) {
         return true;
      }
   }
   if (ended < line.length() - 1) {
      c = line[ended + 1];
      if (is_symbol(c)) {
         return true;
      }
   }
   //prev line
   if (lineNum > 0) {
      line = lines[lineNum - 1];
      if (started > 0) {
         start = started - 1;
      } else {
         start = started;
      }
      if (ended < line.length() - 1) {
         end = ended + 1;
      } else {
         end = ended;
      }
      for (int i = start; i < end + 1; i++) {
         if (is_symbol(line[i])) {
            return true;
         }
      }
   }
   //next line
   if (lineNum < lines.size() - 1) {
      line = lines[lineNum + 1];
      if (started > 0) {
         start = started - 1;
      } else {
         start = started;
      }
      if (ended < line.length() - 1) {
         end = ended + 1;
      } else {
         end = ended;
      }
      for (int i = start; i < end + 1; i++) {
         if (is_symbol(line[i])) {
            return true;
         }
      }
   }
   return false;
}

int32_t evaluate (string num, int started, int ended, int lineNum) {
   debug("EVAL   " + num);
   if (adjacent(lineNum, started, ended)) {
      debug("* PART #" + num);
      return stoi(num);
   } else {
      //cout << num << endl;
   }
   return 0;
}

int32_t parseLine (string s, int lineNum) {
   int32_t output = 0;
   string part = "";
   int started = -1;
   int ended = -1;
   for (int i = 0; i < s.length(); i++) {
      if (isdigit(s[i])) {
         part += s[i];
         if (started == -1) {
            started = i;
         }
      } else if (part.length() > 0) {
         ended = i - 1;
         output += evaluate(part, started, ended, lineNum);
         part = "";
         started = -1;
         ended = -1;
      }
   }
   if (started != -1) {
      ended = s.length() - 1;
      output += evaluate(part, started, ended, lineNum);
   }
   return output;
}

int main() {
   string s;
   string line;
   int64_t answer = 0;
   while( getline( cin, s ) ) {
      lines.push_back(s);
   }
   for (int i = 0; i < lines.size(); i++) {
      line = lines[i];
      //cout << line << endl;
      answer += parseLine(line, i);
   }
   cout << answer << endl;
}