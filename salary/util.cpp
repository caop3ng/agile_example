#include "util.h"
#include "salary.h"

std::string triming(const std::string& text)
{
	std::string whitespace = " \t";

	const auto strBegin = text.find_first_not_of(whitespace);
	if (strBegin == std::string::npos)
		return ""; // no content

	const auto strEnd = text.find_last_not_of(whitespace);
	const auto strRange = strEnd - strBegin + 1;

	return text.substr(strBegin, strRange);
}