#pragma once

#include <string>

class DeserializeHelper
{
public:
	DeserializeHelper(std::string serialString);
	~DeserializeHelper();

	bool isActive;

	void NextParse();
	int ParseCount();
	std::string ParsedValue();
	std::string ParsedClassSString();

private:
	std::string m_serialString;

	size_t m_iterFront;
	size_t m_iterMiddle;
	size_t m_iterEnd;
	size_t m_iterCollectionFront;
	size_t m_iterCollectionEnd;
	size_t m_iterClassFront;
	size_t m_iterClassEnd;
	bool m_isCollection;
	bool m_isCollectionFinalPiece;

	int m_loopCounter;

	std::string m_parsedValue;
	std::string m_parsedClassSString;

};

