#include "QueryBase.h"
#include "Query.h"

using namespace std;

class NotQuery : public QueryBase {

	friend Query operator~ (const Query&);

	NotQuery(const Query& q) : query(q) {}

	// Implement two abstract methods
	QueryResult eval (const TextQuery&) const override;
	std::string rep() const override {return "~(" + query.rep() + ")";}
	// A WordQuery Object
	Query query;
};

Query operator~ (const Query& operand) {
	return std::shared_ptr<QueryBase>(new NotQuery(operand));
}


QueryResult NotQuery::eval(const TextQuery& text) const{
	auto result = query.eval(text);

	auto ret_lines = make_shared<set<line_no>>();

	auto begin = result.begin(), end = result.end();

	auto sz = result.get_file()->size();
	// add others line's number to this ret_lines
	for (size_t n = 0; n != sz; ++n) {
		if (begin == end || *begin != n) {
			ret_lines->insert(n);
		} else if (begin != end) {
			++begin;
		}
	}
	
	return QueryResult(rep(), ret_lines, result.get_file());
}
