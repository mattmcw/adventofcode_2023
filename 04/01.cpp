#include "../aoc.h"

AOC aoc;

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

bool inList (vector<string> v, string x) {
   if (find(v.begin(), v.end(), x) != v.end()) {
      return true;
   }
   return false;
}

int32_t scoreCard (string winning, string have) {
   int32_t score = 0;
   vector<string> winners = toList(winning);
   vector<string> h = toList(have);
   for (string c : h) {
      if (inList(winners, c)) {
         cout << "FOUND " << c << endl;
         if (score == 0) {
            score = 1;
         } else {
            score *= 2;
         }
      }
   }
   cout << "SCORE " << score << endl;
   return score;
}

int main() {
   string s;
   int32_t answer = 0;
   vector<string> card;
   vector<string> parts;
   while( getline( cin, s ) ) {
      card = aoc.split(s, aoc.COLON);
      cout << aoc.trim(card[1]) << endl;
      parts = aoc.split(card[1], '|');
      answer += scoreCard(aoc.trim(parts[0]), aoc.trim(parts[1]));
   }
   cout << "ANSWER " << answer << endl;
}