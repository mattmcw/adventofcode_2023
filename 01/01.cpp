#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
using namespace std;

vector<string> getNumbers (string s) {
   vector<string> nums;
   for (int i = 0; i < s.length(); i++) {
      if (isdigit(s[i])) {
         string c(1, s[i]);
         nums.push_back(c);
      }
   }
   return nums;
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