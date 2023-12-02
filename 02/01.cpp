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

bool evaluateColor (string s) {
   bool pass = true;
   int val;
   string tmp;
   stringstream ss(s);
   vector<string> parts;
   while ( getline(ss, tmp, space) ) {
      parts.push_back(tmp);
   }

   val = stoi(parts[0]);
   if ( (parts[1] == "red" && val > red) || 
       (parts[1] == "green" && val > green) ||
       (parts[1] == "blue" && val > blue) ) {
      pass = false;
   }

   return pass;
}

bool evaluatePart (string s) {
   bool pass = true;
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
      if (!evaluateColor(parts[i])) {
         return false;
      }
   }
   return pass;
}

bool evaluate (string s) {
   bool pass = true;
   string tmp;
   stringstream ss(s);
   vector<string> parts;
   while ( getline(ss, tmp, semi) ) {
      parts.push_back(tmp);
   }
   for (int i = 0; i < parts.size(); i++) {
      if (!evaluatePart(parts[i].substr(1))) {
         return false;
      }
   }
   return pass;
}

int main() {
   string s;
   string tmp;
   int answer = 0;

   while ( getline( cin, s ) ) {
      stringstream ss(s);
      vector<string> parts;
      vector<string> moves;
      while ( getline(ss, tmp, colon) ) {
         parts.push_back(tmp);
      }
      int id = getId(parts[0]);
      if (evaluate(parts[1])) {
         answer += id;
      }
      //cout << id << endl;
   }
   cout << answer << endl;
}