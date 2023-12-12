#include "../aoc.h"

AOC aoc;
char* endptr;

vector<int64_t> splitMap (string map, vector<int64_t> input, vector<int64_t> compare) {
   vector<string> parts = aoc.split(aoc.trim(map), aoc.SPACE);
   int64_t startd = strtol(parts[0].c_str(), &endptr, 10);
   int64_t starts = strtol(parts[1].c_str(), &endptr, 10);
   int64_t range = strtol(parts[2].c_str(), &endptr, 10);
   int64_t dest = startd;
   int64_t src = starts;
   int64_t diff;

   cout << map << endl;
   cout << startd << "-" << (startd + range) << " ";
   cout << starts << "-" << (starts + range) << endl;

   for (int i = 0; i < input.size(); i++) {
      if (input[i] >= starts && input[i] <= starts + range) {
         diff = input[i] - starts;
         compare[i] = startd + diff;
         cout << "* " << input[i] << "->" << compare[i] << endl;
      }
   }
   
   return compare;
}

void display (vector<int64_t> &line) {
   for (int i = 0; i < line.size(); i++) {
      cout << line[i];
      if (i < line.size() - 1) {
         cout << ",";
      }
   }
   cout << endl;
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
   int64_t lowest = INT64_MAX;

   vector<vector<int64_t>> data = {
      {},
      {},
      {},
      {},
      {},
      {},
      {},
      {}
   };

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
            data[0].push_back(strtol(x.c_str(), &endptr, 10));
         }
         display(data[0]);
         for (int i = 1; i < data.size(); i++) {
            for (int x = 0; x < data[0].size(); x++) {
               data[i].push_back((int64_t) -1);
            }
            display(data[i]);
         }
      } else if (s.find("-") != string::npos) {
         parts = aoc.split(s, aoc.SPACE);
         map = aoc.split(parts[0], '-');
         destination = map[0];
         source = map[2];
         cout << destination << " " << source << endl;
      } else if (!data[0].empty() && aoc.trim(s) != "") {
         idx = aoc.getVecPosString(keys, source);
         data[idx] = splitMap(aoc.trim(s), data[idx - 1], data[idx]);
         display(data[idx]);
         for (int i = 0; i < data[idx].size(); i++) {
            if (data[idx][i] == -1) {
               data[idx][i] = data[idx - 1][i];
            }
         }
      }
   }

   for (int64_t val : data[7]) {
      if (val < lowest) {
         lowest = val;
      }
   }
   answer = lowest;

   cout << "ANSWER " << answer << endl;
}