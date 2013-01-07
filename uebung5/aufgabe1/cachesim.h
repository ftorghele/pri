/*
 * cachesim.h
 *
 *  Created on: Jan 5, 2013
 *      Author: Torghele
 *      Author: Hewer
 *      Author: Vogl
 */

#ifndef CACHESIM_H_
#define CACHESIM_H_

#include "cache.h"

#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

class Cachesim {
public:
	Cachesim(Cache& _instructionCache, Cache& _dataCache, const char* _inputPath) :
			instructionCache(&_instructionCache), dataCache(&_dataCache), inputPath(_inputPath) {};

	int parse() {
		std::ifstream instructionFile(inputPath);
		std::string currentLine;

		if (instructionFile.is_open()) {
			std::vector<std::string> tokens;
			while (!instructionFile.eof()) {
				std::getline(instructionFile, currentLine);

				// Skip comments
				if(currentLine[0] == '#' || currentLine[0] == 'x' || currentLine == "") continue;

				std::replace( currentLine.begin(), currentLine.end(), ',', ' ');

				std::string token;
				std::stringstream line(currentLine);

				while (line >> token) {
					tokens.push_back(token);
				}

				unsigned addr, size;

				size = atoi(tokens.back().c_str());
				tokens.pop_back();
				addr = atoi(tokens.back().c_str());

				if (currentLine.find("I") != std::string::npos) instructionCache->read(addr, size);
				if (currentLine.find("S") != std::string::npos) dataCache->store(addr, size);
				if (currentLine.find("L") != std::string::npos) dataCache->load(addr, size);
				if (currentLine.find("M") != std::string::npos) dataCache->modify(addr, size);

				tokens.clear();
			}
			instructionFile.close();

			return 0;

		} else {
			std::cout << "Unable to open instruction file" << std::endl;
			std::cout << "Usage: cachesim <instruction file>" << std::endl;

			return 1;
		}

	}

private:
	const char* inputPath;
	Cache* instructionCache;
	Cache* dataCache;
};

#endif /* CACHESIM_H_ */
