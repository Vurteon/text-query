#ifndef QUERY
#define QUERY
#include <string>
#include "Query.h"
#include "WordQuery.h"

// out put the result
std::ostream& operator<< (std::ostream& os, const Query& query){
	return os << query.rep();
}

Query::Query(const std::string& s) : q(new WordQuery(s)){}

#endif
