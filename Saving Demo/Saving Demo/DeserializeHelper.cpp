#include "DeserializeHelper.h"

// Default Constructor
DeserializeHelper::DeserializeHelper(std::string serialString) :
	m_serialString(serialString)
{
	isActive = true;

	m_iterFront = 0;
	m_iterMiddle = 0;
	m_iterEnd = 0;
	m_iterCollectionFront = 0;
	m_iterCollectionEnd = 0;
	m_iterClassFront = 0;
	m_iterClassEnd = 0;
	m_isCollection = false;
	m_isCollectionFinalPiece = false;

	m_loopCounter = 0;
}


DeserializeHelper::~DeserializeHelper()
{
}

// allign string parser iterators to locate data and identify collections of data and classes
void DeserializeHelper::NextParse()
{
	// cannot make use of a 'do while' loop so this code will acieve the desired behaviour
	// once string iterators have been aligned and data prepared for output, prepare for the next data parsing
	if (m_iterMiddle != 0)
	{
		if (m_isCollectionFinalPiece)
		{
			m_isCollectionFinalPiece = false;
			m_isCollection = false;
		}
		if (!m_isCollection)
		{
			m_loopCounter++;
		}

		m_iterFront = m_iterMiddle = m_iterCollectionFront = m_iterCollectionEnd = m_iterClassFront = m_iterClassEnd = m_iterEnd + 1;
	}

	// true starting point of the method
	m_iterMiddle = m_serialString.find(":", m_iterMiddle);
	if (m_iterMiddle == std::string::npos)
	{
		// this replaces the original while loop that checks to see if the parser reached the end of the serialized string
		// : while ((<middleIterator> = serialString.find(":", <middleIterator>)) != string::npos)
		isActive = false;
	}
	else
	{
		// find the end point for the value to load from
		++m_iterMiddle;
		m_iterEnd = m_serialString.find(",", m_iterMiddle);
		if (m_iterEnd > m_serialString.size())
		{
			m_iterEnd = m_serialString.find("\n", m_iterMiddle);
		}

		// check to see if a collection of data is present (vector) and set a 'isCollection' flag to true if yes
		// NOTE - TODO - this version isn't built for array type collection of data, will have to come back to this if needed
		std::string subString = m_serialString.substr(m_iterFront, m_iterMiddle);
		if ((m_iterCollectionFront = subString.find("[", 0)) == std::string::npos)
		{
			m_iterCollectionFront = m_iterCollectionEnd;
		}
		else if (m_serialString[m_iterCollectionFront] == '[')
		{
			m_isCollection = true;
			size_t emptyCollection = m_serialString.find("[]", m_iterCollectionFront, m_iterCollectionFront + 2);//TODO - QUESTION - will +1 work instead? perhaps make 3rd paramater 'iterEnd'.  Create a text to check
			if (m_iterCollectionFront == emptyCollection)
			{
				m_isCollectionFinalPiece = true;
			}
		}
		// if there is a '[' for a collectin, there has to be a ']' to indicate the end of a collection
		if (m_isCollection /*&& !isCollectionFinalPiece*/)//TODO - QUESTION: is the second if paramater needed?
		{
			m_iterCollectionEnd = m_serialString.find("]", m_iterMiddle, m_iterEnd);
			if (m_serialString[m_iterCollectionEnd] == ']')
			{
				// flag to identify the last value to be passed into a collection of data (vector/list/etc.)
				m_isCollectionFinalPiece = true;
			}
		}

		// check to see if another set of class/object data is present within the current one
		if ((m_iterClassFront = subString.find("{", 0)) == std::string::npos)
		{
			m_iterClassFront = m_iterClassEnd;
		}
		else if (m_serialString[m_iterClassFront] == '{')
		{
			m_iterClassEnd = m_serialString.find("}", m_iterClassFront);

			// NOTE - create a tempClass that takes a substring from serialString between iterClassFront and iterClassEnd and call the class constructor accepting one string

			m_iterEnd = m_serialString.find(",", m_iterClassEnd);
		}

		m_parsedValue = m_serialString.substr(m_iterMiddle, m_iterEnd - m_iterMiddle);

		m_parsedClassSString = m_serialString.substr(m_iterClassFront, m_iterClassEnd - m_iterClassFront);
	}
}

// return the current loop count
int DeserializeHelper::ParseCount()
{
	return m_loopCounter;
}

// return the value found in the serialized string
std::string DeserializeHelper::ParsedValue()
{
	return m_parsedValue;
}

// return a serialized subString containing class data found in the serialized string
std::string DeserializeHelper::ParsedClassSString()
{
	return m_parsedClassSString;
}