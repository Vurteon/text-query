#include "BinaryQuery.h"

using namespace std;


class AndQuery : public BinaryQuery {
	
	friend Query operator& (const Query&, const Query&);

	AndQuery(const Query& left, const Query& right) : BinaryQuery (left, right, "&") {}

	QueryResult eval (const TextQuery&) const override;
};

Query operator& (const Query& lhs, const Query& rhs) {
	return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}


QueryResult AndQuery::eval(const TextQuery& text) const {
	auto left = lhs.eval(text), right = rhs.eval(text);

	auto ret_line = make_shared<set<line_no>>();
	// build intersection for two set
	set_intersection(left.begin(), left.end(), 
			right.begin(), right.end(), std::inserter(*ret_line, ret_line->begin()));
	// construct a new query result
	return QueryResult(rep(), ret_line, left.get_file());
}
