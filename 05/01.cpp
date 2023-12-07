#include "../aoc.h"

AOC aoc;

vector<int64_t> splitMap (string map, vector<int64_t> input) {
   vector<string> parts = aoc.split(aoc.trim(map), aoc.SPACE);
   int64_t startd = stoll(parts[0]);
   int64_t starts = stoll(parts[1]);
   int64_t range = stoll(parts[2]);
   int64_t dest = startd;
   int64_t src = starts;
   for (int64_t i = 0; i < range; i++) {
      
   }
   return input;
}

int main() {
   string s;
   int64_t answer = 0;
   int idx;
   int x;
   vector<string> parts;
   vector<string> map;

   string destination;
   string source;
   string tmp;
   vector<string> seedstr;

   vector<vector<int64_t>> data;

   vector<int64_t> tmpsrc;
   vector<int64_t> tmpdest;

   vector<string> keys = {
      "seeds",
      "soil",
      "fertilizer",
      "water",
      "light",
      "temperature",
      "humidity",
      "location"
   };

   while ( getline( cin, s ) ) {
      if (data[0].empty() && s.find("seeds:") != string::npos) {
         parts = aoc.split(s, aoc.COLON);
         seedstr = aoc.split(aoc.trim(parts[1]), aoc.SPACE);
         for (string x : seedstr) {
            data[0].push_back(stoll(x));
         }
         for (int i = 1; i < keys.size(); i++) {
            data[i].reserve(data[0].size());
         }
      } else if (s.find("-") != string::npos) {
         parts = aoc.split(s, aoc.SPACE);
         map = aoc.split(parts[0], '-');
         destination = map[0];
         source = map[2];
         cout << destination << " " << source << endl;
      } else if (!data[0].empty()) {
         tmpdest = splitMap(aoc.trim(s), 0);
         tmpsrc = splitMap(aoc.trim(s), 1);
         idx = aoc.getVecPosString(keys, source);
         for (int i = 0; i < data[idx - 1].size(); i++) {
            x = aoc.getVecPosInt(tmpsrc, data[idx - 1][i]);
            if (x > -1) {
               data[idx][i] = tmpdest[x];
            }
         }
         for (int i = 0; i <  data[idx].size(); i++) {
            cout << data[idx - 1][i] << " = " << data[idx][i] << endl;
         }
      }
   }
   cout << "ANSWER " << answer << endl;
}