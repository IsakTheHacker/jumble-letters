#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <random>

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

int main (int argc, char* argv[]) {
	for (size_t i = 1; i < argc; i++) {
		std::string oldWord = std::string(argv[i], strlen(argv[i]));

		std::string newWord;
		if (oldWord.length() < 4) {		//We can't jumble letters on short words, so do nothing
			newWord = oldWord;
		} else {
			newWord = oldWord.substr(0, 1) + jumbleLetters(oldWord.substr(1, oldWord.length() - 2)) + oldWord.substr(oldWord.length() - 1, 1);
		}
		
		std::cout << newWord;
		if (i < argc - 1) std::cout << " ";
	}

	std::cout << std::endl;
	return 0;
}