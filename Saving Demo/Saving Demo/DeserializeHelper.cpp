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
	m_flagClass = false;

	m_loopCounter = 0;
}


DeserializeHelper::~DeserializeHelper()
{
}

/* INSTRUCTIONS -	1) In the class objects constructor taking in a "one-line" serialized string, create a instance of the
					DeserializedHelper, and a 'while' loop that runs while the helper instance's 'isActive()' returns true (bool).
					2) At the start of each loop iteration call the helpers 'NextParse()' method and it will store the approprate
					data value in its 'parsedValue()' (string) to assign to a data member variable or a subString
					'parsedClassSString()' (string) to run a different class type's constructor that accepts a serialized string.
					3) Finally, create a 'switch' if statement checking the helper instances 'ParseCount()' method (int) and assign
					data provided by the helper to the correct member variables.

					IMPORTANT: make sure the constructor assigns values to variables in the same order as the classes 'Serialized()'
					method builds and returns a serialString from its variables
					
					Example:	(serialString:		room:11,morning:Paolo,afternoon:no one,student[{name:Sebastian,gender:M,age:38,},{name:Bobbetta,gender:F,age:21,},{name:Charlie,gender:?,age:24,},],		)

					// Deserializer Constructor - accepts a 'one-line' serialized string filled with data
					ClassRoom::ClassRoom(std::string serialString)
					{
						DeserializeHelper deserHelper(serialString);

						while (deserHelper.isActive)
						{
							deserHelper.NextParse();

							switch (deserHelper.ParseCount())
							{
							case 0: m_RoomNumber = std::stoi(deserHelper.ParsedValue()); break;
							case 1: m_MorningInstructor = deserHelper.ParsedValue(); break;
							case 2: m_AfternoonInstructor = deserHelper.ParsedValue(); break;
							case 3: m_Students.push_back(Student(deserHelper.ParsedClassSString())); break;
							default: break;
							}
						}
					}

					*/

// A Method to allign string parser iterators to locate data and identify collections of data values and classes
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

		if (m_flagClass)
		{
			m_iterEnd = ++m_iterClassEnd;
			m_flagClass = false;
		}
		m_iterFront = m_iterMiddle = m_iterCollectionFront = m_iterCollectionEnd = m_iterClassFront = m_iterClassEnd = ++m_iterEnd;
	}

	// true starting point of the method
	m_iterMiddle = m_serialString.find(":", m_iterMiddle);
	if (m_iterMiddle == std::string::npos)
	{
		// this replaces the original while loop that checks to see if the parser reached the end of the serialized string
		// : while ((<middleIterator> = serialString.find(":", <middleIterator>)) != string::npos)
		isActive = false;
		m_parsedValue = "";
		m_parsedClassSString = "";
	}
	else
	{
		// find the end point for the value to load from
		++m_iterMiddle;
		m_iterEnd = m_serialString.find(",", m_iterFront);
		if (m_iterEnd > m_serialString.size())
		{
			//m_iterEnd = m_serialString.find("\n", m_iterMiddle);
			m_iterEnd = m_serialString.size() - 1;
		}

		if (m_iterMiddle > m_iterEnd)
		{
			m_iterMiddle = m_iterEnd;
		}

		//std::string subStringA = m_serialString.substr(m_iterFront, m_iterMiddle - m_iterFront);
		std::string subStringA = m_serialString.substr(m_iterFront, m_iterEnd - m_iterFront);

		// check to see if another set of class/object data is present within the current one
		if ((m_iterClassFront = subStringA.find("{", 0)+m_iterFront) == std::string::npos)
		{
			m_iterClassFront = m_iterClassEnd;
		}
		else if (m_serialString[m_iterClassFront] == '{')
		{
			m_flagClass = true;
			m_iterClassEnd = m_serialString.find("}", m_iterClassEnd);

			// temporary serialized subString
			std::string tempSerSubStr = m_serialString.substr(m_iterClassFront, m_iterClassEnd - m_iterClassFront + 2);

			// make sure the m_iterClassEnd is pointing to the correct class closing char tag by ensuring the count of '{' matches the count of '}' (this is where algorithm from the header file comes into play)
			size_t tempFCount = 0, tempECount = 0;
			while ((tempFCount = std::count(tempSerSubStr.begin(),tempSerSubStr.end(),'{')) != (tempECount = std::count(tempSerSubStr.begin(), tempSerSubStr.end(), '}')))
			{
				m_iterClassEnd = m_serialString.find("}", m_iterClassEnd + 1);
				tempSerSubStr = m_serialString.substr(m_iterClassFront, m_iterClassEnd - m_iterClassFront + 2);
			}

			// NOTE - create a tempClass that takes a substring from serialString between iterClassFront and iterClassEnd and call the class constructor accepting one string

			m_iterEnd = m_serialString.find(",", m_iterClassEnd);
		}

		// check to see if a collection of data is present (vector) and set a 'isCollection' flag to true if yes
		// NOTE - TODO - this version isn't built for array type collection of data, will have to come back to this if needed
		if ((m_iterCollectionFront = subStringA.find("[", 0) /*+ m_iterFront*/) == std::string::npos)
		{
			m_iterCollectionFront = m_iterCollectionEnd;
		}
		else
		{
			m_iterCollectionFront += m_iterFront;
		}

		if (m_serialString[m_iterCollectionFront] == '[')
		{
			m_isCollection = true;
			//size_t emptyCollection = m_serialString.find("[]", m_iterCollectionFront, m_iterCollectionFront + 2);//TODO - QUESTION - will +1 work instead? perhaps make 3rd paramater 'iterEnd'.  Create a text to check
			size_t emptyCollection = subStringA.find("[]", 0) + m_iterFront; // NOTE - QUESTION - is there need for this safety measure?  up for debate for another day.
			if (m_iterCollectionFront == emptyCollection)
			{
				m_isCollectionFinalPiece = true;
			}
		}
		// if there is a '[' for a collectin, there has to be a ']' to indicate the end of a collection
		if (m_isCollection /*&& !isCollectionFinalPiece*/)//TODO - QUESTION: is the second if paramater needed?
		{
			std::string subStringB = m_serialString.substr(m_iterMiddle, m_iterEnd - m_iterMiddle + 2);
			//m_iterCollectionEnd = m_serialString.find("]", m_iterMiddle, m_iterEnd - m_iterMiddle);
			//m_iterCollectionEnd = subStringA.find("]", 0) + m_iterCollectionFront;
			m_iterCollectionEnd = subStringB.find("]", 0) + m_iterMiddle;
			if (m_serialString[m_iterCollectionEnd] == ']')
			{
				// flag to identify the last value to be passed into a collection of data (vector/list/etc.)
				m_isCollectionFinalPiece = true;
			}
		}


		m_parsedValue = m_serialString.substr(m_iterMiddle, m_iterEnd - m_iterMiddle);

		m_parsedClassSString = m_serialString.substr(m_iterClassFront+1, m_iterClassEnd - m_iterClassFront-1);
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