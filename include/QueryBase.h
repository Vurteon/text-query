#ifndef QUERY_BASE
#define QUERY_BASE

#include <string>
#include "QueryResult.h"
#include "TextQuery.h"


class QueryBase {
	// Query class can access private member
	friend class Query;
protected:
	using line_no = TextQuery::line_no;
	virtual ~QueryBase() = default;

private:
	// Base text query generate query result
	virtual QueryResult eval(const TextQuery&) const = 0;
	// Show this query
	virtual std::string rep() const = 0;
};



#endif /* ifndef QUERY_BASE */
