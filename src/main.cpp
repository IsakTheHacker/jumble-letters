#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <random>
#include <array>
#include <algorithm>

std::array<char, 32> specialChars = {
	'!',
	'"',
	'#',
	'$',
	'%',
	'&',
	'\'',
	'(',
	')',
	'*',
	'+',
	',',
	'-',
	'.',
	'/',
	':',
	';',
	'<',
	'=',
	'>',
	'?',
	'@',
	'[',
	'\\',
	']',
	'^',
	'_',
	'\'',
	'{',
	'|',
	'}',
	'~'
};

std::string jumbleLetters(const std::string& str) {
	std::vector<char> vec(str.begin(), str.end());
	size_t originalSize = vec.size();
	std::string outputStr;

	for (size_t i = 0; i < originalSize; i++) {
		int randomNumber = rand() % (vec.size());
		outputStr += vec[randomNumber];
		vec.erase(vec.begin() + randomNumber);
	}

	return outputStr;
}

std::vector<std::string> split(std::string str, const std::string &delimiter) {
	std::vector<std::string> tokens;
	size_t pos = 0;
	std::string token;
	while ((pos = str.find(delimiter)) != std::string::npos) {
		token = str.substr(0, pos);
		str.erase(0, pos + delimiter.length());
		if (token != "") {
			tokens.push_back(token);
		}
	}
	if (str != "") {
		tokens.push_back(str);
	}
	return tokens;
}

int main (int argc, char* argv[]) {
	std::vector<std::string> args(argv + 1, argv + argc);

	if (args.size() < 1) {							//No arguments specified, read from stdin instead
		std::string line;
		while (std::getline(std::cin, line)) {		//Read from stdin
			for (std::string word : split(line, " ")) {
				args.push_back(word);
			}
		}
	}

	for (size_t i = 0; i < args.size(); i++) {
		std::string oldWord = args[i];
		std::string punctuationBefore = "";
		std::string punctuationAfter = "";

		for (size_t forward = 0; forward < oldWord.length(); forward++) {
			bool specialCharExists = std::find(specialChars.begin(), specialChars.end(), oldWord[forward]) != specialChars.end();
			if (specialCharExists) {
				punctuationBefore = punctuationBefore + oldWord[forward];
			} else {
				break;
			}
		}
		for (size_t backward = oldWord.length() - 1; backward > 0; backward--) {
			bool specialCharExists = std::find(specialChars.begin(), specialChars.end(), oldWord[backward]) != specialChars.end();
			if (specialCharExists) {
				punctuationAfter = oldWord[backward] + punctuationAfter;
			} else {
				break;
			}
		}
		oldWord = oldWord.substr(punctuationBefore.length(), oldWord.length() - punctuationBefore.length());
		oldWord = oldWord.substr(0, oldWord.length() - punctuationAfter.length());

		std::string newWord;
		if (oldWord.length() < 4) {		//We can't jumble letters on short words, so do nothing
			newWord = oldWord;
		} else {
			newWord = oldWord.substr(0, 1) + jumbleLetters(oldWord.substr(1, oldWord.length() - 2)) + oldWord.substr(oldWord.length() - 1, 1);
		}
		
		std::cout << punctuationBefore << newWord << punctuationAfter;
		if (i < args.size() - 1) std::cout << " ";
	}

	std::cout << std::endl;
	return 0;
}
