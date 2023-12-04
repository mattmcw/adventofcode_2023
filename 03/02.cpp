#include "../aoc.h"

AOC aoc;
bool DEBUG = true;
vector<string> lines;

void debug (string line) {
   if (DEBUG) {
      cout << line << endl;
   }
}

int32_t getNumberOnLine (string line, int i) {
   string numStr = "";
   int start = i;
   int32_t val = -1;
   bool started = false;

   if (i > 0 && isdigit(line[start])) {
      for (int x = 0; x < i; x++) {
         if (!isdigit(line[start])) {
            break;
         }
         start--;
      }
   }
   if (!isdigit(line[start]) && isdigit(line[start + 1])) {
      start = start + 1;
   }
   for (int i = start; i < line.length(); i++) {
      if (isdigit(line[i])) {
         started = true;
         numStr += line[i];
      } else if (started && !isdigit(line[i])) {
         break;
      }
      if (i == start + 1 && !isdigit(line[i])) {
         started = true;
      }
   }

   if (numStr.length() > 0) {
      cout << "NUMSTR " << numStr << endl;
      val = stoi(numStr);
   }
   return val;
}

vector<int32_t> adjacent (int lineNum, int i) {
   char c;
   string line;
   int startLine;
   int endLine;
   int startChar;
   int endChar;
   int32_t num = -1;
   vector<int32_t> nums;
   bool foundLine = false;
   if (lineNum > 0) {
      startLine = lineNum - 1;
   } else {
      startLine = lineNum;
   }
   if (lineNum < lines.size() - 1) {
      endLine = lineNum + 1;
   } else {
      endLine = lineNum;
   }
   if (i > 0) {
      startChar = i - 1;
   } else {
      startChar = i;
   }
   for (int l = startLine; l < endLine + 1; l++) {
      line = lines[l];
      debug("LINE " + line);
      num = getNumberOnLine(line, startChar);
      if (num > -1 && nums.size() < 2) {
         nums.push_back(num);
      }
      if (nums.size() == 1 && i + 1 < line.length() && isdigit(line[i + 1]) && i > 0 && !isdigit(line[i]) && isdigit(line[i - 1])) {
         num = getNumberOnLine(line, i + 1);
         if (num > -1) {
            nums.push_back(num);
         }
      }
   }
   return nums;
}

int32_t evaluate (int lineNum, int i) {
   int32_t output = 0;
   vector<int32_t> nums = adjacent(lineNum, i);
   if (nums.size() == 2) {
      debug(to_string(nums[0]));
      debug(to_string(nums[1]));
      
      output = nums[0] * nums[1];
   }
   debug("_____");
   return output;
}

int32_t parseLine (string s, int lineNum) {
   int32_t output = 0;
   for (int i = 0; i < s.length(); i++) {
      if (s[i] == '*') {
         debug("FOUND " + to_string(lineNum) + "," + to_string(i));
         output += evaluate(lineNum, i);
      }
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
      answer += parseLine(line, i);
   }
   cout << answer << endl;
}