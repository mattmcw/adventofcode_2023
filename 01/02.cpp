#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
using namespace std;

const vector<string> words = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

vector<size_t> findAll (string str, string sub) {
   vector<size_t> positions;
   size_t pos = str.find(sub, 0);
   while (pos != string::npos)
   {
      positions.push_back(pos);
      pos = str.find(sub, pos + 1);
   }
   return positions;
}


vector<string> getNumbers (string s) {
   vector<int> nums(s.length());
   vector<string> strs;
   for (int i = 0; i < s.length(); i++) {
      if (isdigit(s[i])) {
         string c(1, s[i]);
         nums[i] = stoi(c);
      }
   }
   for (int i = 0; i < words.size(); i++) {
      vector<size_t> positions = findAll(s, words[i]);
      if (!positions.empty()) {
         for (int j = 0; j < positions.size(); j++) {
            nums[positions[j]] = i;
         }
      }
   }

   for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
         strs.push_back(to_string(nums[i]));
      }
   }

   return strs;
}

int main() {
   string s;
   int sum = 0;
   while( getline( cin, s ) ) {
      vector<string> nums = getNumbers(s);
      string n = nums[0] + nums[nums.size() - 1];
      sum += stoi(n);
   }
   cout << sum << endl;
}