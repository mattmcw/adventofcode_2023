#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <sstream>
using namespace std;

int red = 12;
int green = 13;
int blue = 14;

char colon = ':';
char semi = ';';
char comma = ',';
char space = ' ';

int getId (string &s) {
   string tmp;
   stringstream ss(s);
   vector<string> parts;
   while ( getline(ss, tmp, space) ) {
      parts.push_back(tmp);
   }
   return stoi(parts[1]);
}

void evaluateColor (string s) {
   int val;
   string tmp;
   stringstream ss(s);
   vector<string> parts;
   while ( getline(ss, tmp, space) ) {
      parts.push_back(tmp);
   }

   val = stoi(parts[0]);
   if (parts[1] == "red" && val > red) {
      red = val;
   }
   if (parts[1] == "green" && val > green) {
      green = val;
   }
   if (parts[1] == "blue" && val > blue) {
      blue = val;
   }
}

void evaluatePart (string s) {
   string tmp;
   stringstream ss(s);
   vector<string> parts;
   while ( getline(ss, tmp, comma) ) {
      parts.push_back(tmp);
   }
   for (int i = 0; i < parts.size(); i++) {
      if (parts[i][0] == space) {
         parts[i] = parts[i].substr(1);
      }
      evaluateColor(parts[i]);
   }
}

void evaluate (string s) {
   string tmp;
   stringstream ss(s);
   vector<string> parts;
   while ( getline(ss, tmp, semi) ) {
      parts.push_back(tmp);
   }
   for (int i = 0; i < parts.size(); i++) {
      evaluatePart(parts[i].substr(1));
   }
}

int main() {
   string s;
   string tmp;
   int answer = 0;
   int factor;

   while ( getline( cin, s ) ) {
      red = 0;
      green = 0;
      blue = 0;
      stringstream ss(s);
      vector<string> parts;
      vector<string> moves;
      while ( getline(ss, tmp, colon) ) {
         parts.push_back(tmp);
      }
      int id = getId(parts[0]);
      evaluate(parts[1]);
      factor = red * green * blue;
      answer += factor;
   }
   cout << answer << endl;
}