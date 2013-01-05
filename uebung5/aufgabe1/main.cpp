/*
 * main.cpp
 *
 *  Created on: Jan 05, 2013
 *      Author: Torghele
 *      Author: Hewer
 *      Author: Vogl
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "cache.h"
#include "cachesim.h"

int main(int argc, const char* argv[]) {

	std::ifstream instructionFile(argv[1]);
	std::string currentLine;

	// instruction cache: size 4096 Bytes, cache line size 32 Bytes, direct-mapped.
	Cache instructionCache(4096, 32, direct_mapped);
	// data cache: size 256 Kilobytes, cache line size 32 Bytes, 4x associative.
	Cache dataCache(256*1024, 32, set_associative, 4);

	if (instructionFile.is_open()) {

		while (instructionFile.good()) {
			getline(instructionFile, currentLine);

			// Skip comments
			if(currentLine[0] == '#') continue;

			std::replace( currentLine.begin(), currentLine.end(), ',', ' ');

		    string token;
		    stringstream line(currentLine);
		    vector<string> tokens;

		    while (line >> token) {
		    	tokens.push_back(token);
		    }

		    unsigned addr, size;

		    size = atoi(tokens.back().c_str());
		    tokens.pop_back();
		    addr = atoi(tokens.back().c_str());

		    if (currentLine.find("I") != string::npos) instructionCache.read(addr, size);
		    if (currentLine.find("S") != string::npos) dataCache.store(addr, size);
		    if (currentLine.find("L") != string::npos) dataCache.load(addr, size);
		    if (currentLine.find("M") != string::npos) dataCache.modify(addr, size);

		}
		instructionFile.close();

	} else {
		std::cout << "Unable to open instruction file" << std::endl;
		std::cout << "Usage: cachesim <instruction file>" << std::endl;
	}

	return 0;
}



