#include "../aoc.h"

AOC aoc;
char* endptr;

vector<uint64_t> splitMap (string map, vector<uint64_t> &input, vector<uint64_t> &compare) {
   vector<string> parts = aoc.split(aoc.trim(map), aoc.SPACE);
   uint64_t startd = strtol(parts[0].c_str(), &endptr, 10);
   uint64_t starts = strtol(parts[1].c_str(), &endptr, 10);
   uint64_t range = strtol(parts[2].c_str(), &endptr, 10);
   uint64_t dest = startd;
   uint64_t src = starts;
   uint64_t diff;

   //cout << map << endl;
   //cout << startd << "-" << (startd + range) << " ";
   //cout << starts << "-" << (starts + range) << endl;

   for (uint64_t i = 0; i < input.size(); i++) {
      if (input[i] >= starts && input[i] <= starts + range && compare[i] < (uint64_t) 0) {
         diff = input[i] - starts;
         compare[i] = startd + diff;
         //cout << "* " << input[i] << "->" << compare[i] << endl;
      }
   }
   
   return compare;
}

vector<uint64_t> fix (vector<uint64_t> &input, vector<uint64_t> &output) {
   for (uint64_t i = 0; i < input.size(); i++) {
      if (output[i] == (uint64_t) -1) {
         output[i] = input[i];
      }
   }
   return output;
}

void display (vector<uint64_t> &line) {
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
   uint64_t answer = 0;
   int idx;
   int x;
   vector<string> parts;
   vector<string> map;

   string destination;
   string source;
   string tmp;
   vector<string> seedstr;
   uint64_t lowest = INT64_MAX;
   uint64_t start;
   uint64_t range;

   vector<vector<uint64_t>> data = {
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
      //cout << "BEFORE " << s << endl;
      if (data[0].empty() && s.find("seeds:") != string::npos) {
         parts = aoc.split(s, aoc.COLON);
         seedstr = aoc.split(aoc.trim(parts[1]), aoc.SPACE);
         for (uint64_t i = 0; i < (uint64_t) round(seedstr.size() / 2); i++) {
            start = strtol(seedstr[i * 2].c_str(), &endptr, 10);
            range = strtol(seedstr[(i * 2) + 1].c_str(), &endptr, 10);
            for (uint64_t x = 0; x < range; x++) {
               data[0].push_back(start + x);
            }
         }
         //display(data[0]);
         //cout << "SEEDS: " << data[0].size() << endl;
         for (int i = 1; i < data.size(); i++) {
            for (uint64_t x = 0; x < data[0].size(); x++) {
               data[i].push_back((uint64_t) -1);
            }
            //display(data[i]);
         }
      } else if (s.find("-") != string::npos) {
         parts = aoc.split(s, aoc.SPACE);
         map = aoc.split(parts[0], '-');
         destination = map[0];
         source = map[2];
         idx = aoc.getVecPosString(keys, source);
         if (idx > 1) {
            data[idx - 1] = fix(data[idx - 2], data[idx - 1]);
         }
         //cout << "----" << endl;
         //display(data[idx - 1]);
         cout << destination << " " << source << endl;
      } else if (!data[0].empty() && aoc.trim(s) != "") {
         //cout << s << endl;
         data[idx] = splitMap(aoc.trim(s), data[idx - 1], data[idx]);
         //display(data[idx]);
      }
   }
   data[7] = fix(data[6], data[7]);
   data[6] = {};
   //cout << "----" << endl;
   //display(data[7]);

   for (uint64_t val : data[7]) {
      if (val < lowest) {
         lowest = val;
      }
   }
   answer = lowest;

   cout << "ANSWER " << answer << endl;
}