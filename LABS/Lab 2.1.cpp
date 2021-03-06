#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

#define STUDENT_VARIANT 15

class isVowel {
public:
	bool operator()(char _simbol) const
	{
		const std::string vowels = "AEIOUY";
		return vowels.find_first_of(std::toupper(_simbol)) != std::string::npos;
	}
};

class isConsonant {
public:
	bool operator()(char _simbol) const
	{
		const std::string consonants = "BCDFGHJKLMNPQRSTVWXZ";
		return consonants.find_first_of(std::toupper(_simbol)) != std::string::npos;
	}
};

class TMyFirstClass {
public:
	TMyFirstClass()
	{
		std::cout << ".ctor" << std::endl;
	}

	TMyFirstClass(std::string& _sentence)
	{
		size_ = 0;
		for (auto c : _sentence)
		{
			if (c == ' ')
				size_++;
		}
		size_ += 1;
		words_ = _sentence;
	}

	int TMyFirstClass::countWords(int _len = 5)
	{
		int count = 0;
		std::stringstream text(words_);
		std::string word;
		while (text >> word)
		{
			if (word.length() > _len)
				count++;
		}
		return count;
	}

	int TMyFirstClass::countVowels(std::string &_string)
	{
		const std::string vowels = "AEIOUY";
		return std::count_if(_string.begin(), _string.end(), isVowel());
	}

	int TMyFirstClass::countConsonants(std::string &_string)
	{
		return std::count_if(_string.begin(), _string.end(), isConsonant());
	}

	int TMyFirstClass::countWordsInSentence()
	{
		return size_;
	}

	float TMyFirstClass::percentWords(int _len = 5)
	{
		return static_cast<float>(TMyFirstClass::countWords(_len)) / size_ * 100;
	}

	void TMyFirstClass::printWords()
	{
		std::cout << words_ << std::endl << std::endl;
	}

	void TMyFirstClass::information(int _len = 5)
	{
		std::cout << "\n" << "Count of words in sentence " << TMyFirstClass::countWordsInSentence()
			<< std::endl << std::endl;
		std::cout << "Count of words, which length " << _len << ", is " << TMyFirstClass::countWords(_len)
			<< std::endl << std::endl;
		std::cout << "Percent of words, which length " << _len << ", is " << TMyFirstClass::percentWords(_len) << "%"
			<< std::endl << std::endl;
		std::cout << "Count of vowels in sentence is " << TMyFirstClass::countVowels(words_)
			<< std::endl << std::endl;
		std::cout << "Count of consonants in sentence is " << TMyFirstClass::countConsonants(words_) << std::endl
			<< std::endl << std::endl;
	}

	~TMyFirstClass()
	{
		std::cout << ".dtor" << std::endl;
	}
private:
	std::string words_;
	int size_;
};
