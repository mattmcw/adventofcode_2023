#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <sstream>
#include <algorithm>
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

		string trim(string line) {
			const char* WhiteSpace = " \t\v\r\n";
			size_t start = line.find_first_not_of(WhiteSpace);
			size_t end = line.find_last_not_of(WhiteSpace);
			return start == end ? string() : line.substr(start, end - start + 1);
		}

		template <class T, class I>
		bool vectorContains(const vector<T>& v, I& t) {
			bool found = (std::find(v.begin(), v.end(), t) != v.end());
			return found;
		}

		int getVecPosString(vector<string> vec, string element) {
		    int i;
		    for (i = 0; i < vec.size(); i++){
		        if (vec[i] == element){
		            break;
		        }
		    }
		    if (i == vec.size()){
		        i = -1;
		    }
		        
		    return i;
		}

		int getVecPosInt(vector<int64_t> vec, int64_t element) {
		    int i;
		    for (i = 0; i < vec.size(); i++){
		        if (vec[i] == element){
		            break;
		        }
		    }
		    if (i == vec.size()){
		        i = -1;
		    }
		        
		    return i;
		}
};