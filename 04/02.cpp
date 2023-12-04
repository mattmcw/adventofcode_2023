#include "../aoc.h"

AOC aoc;

vector<string> lines;

vector<string> toList (string input) {
   vector<string> list = aoc.split(input, aoc.SPACE);
   vector<string> l;
   for (string s : list) {
      if (aoc.trim(s) != "" || (s.length() == 1 && s != " ")) {
         l.push_back(s);
      }
   }
   return l;
}

int32_t scoreCard (string winning, string have) {
   int32_t score = 0;
   vector<string> winners = toList(winning);
   vector<string> h = toList(have);
   for (string c : h) {
      if (aoc.vectorContains(winners, c)) {
         score++;
      }
   }
   return score;
}

int main() {
   string s;
   int64_t answer = 0;
   int64_t score;
   vector<string> card;
   vector<string> parts;
   int x = 0;

   while( getline( cin, s ) ) {
      card = aoc.split(s, aoc.COLON);
      lines.push_back(card[1]);
   }

   vector<int64_t> copies(lines.size(), 1);

   for (string line : lines) {
      //cout << aoc.trim(line) << endl;
      parts = aoc.split(line, '|');
      
      score = scoreCard(aoc.trim(parts[0]), aoc.trim(parts[1]));
      //cout << x << " = " << score << endl;
      for (int c = 0; c < copies[x]; c++) {
         for (int i = 1; i < score + 1; i++) {
            //cout << to_string(x + i) << " ++" << endl;
            copies[x + i] += 1;
         }
      }
      //cout << copies[x] << endl;
      x++;
   }
   for (int score : copies) {
      answer += score;
   }
   cout << "ANSWER " << answer << endl;
}