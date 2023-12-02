#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <sstream>
using namespace std;

class AOC {
	public:
		const char SPACE = ' ';
		const char COLON = ':';
		const char SEMI = ';';
		const char COMMA = ',';

		vector<string> split (string str, char delim) {
			vector<string> parts;
			string tmp;
			stringstream ss(str);
			while ( getline(ss, tmp, delim) ) {
				parts.push_back(tmp);
			}
			return parts;
		}

		std::string trim(const std::string& line) {
			const char* WhiteSpace = " \t\v\r\n";
			std::size_t start = line.find_first_not_of(WhiteSpace);
			std::size_t end = line.find_last_not_of(WhiteSpace);
			return start == end ? std::string() : line.substr(start, end - start + 1);
		}
};