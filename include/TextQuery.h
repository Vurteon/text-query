#ifndef TEXT_QUERY
#define TEXT_QUERY

#include <vector>
#include <map>
#include <set>

#include "QueryResult.h"


class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;

private:
	// Every string in this file is a line of ifstream.
	std::shared_ptr<std::vector<std::string>> file;
	// A map which key is a word, value is a set including all
	// line numbers this word occurs.
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

#endif