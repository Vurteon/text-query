#include "BinaryQuery.cpp"
using namespace std;


class OrQuery : public BinaryQuery {
	friend Query operator| (const Query&, const Query&);
	OrQuery (const Query& left, const Query& right) : BinaryQuery (left, right, "|"){}
	
	QueryResult eval (const TextQuery&) const override;
};

inline Query operator| (const Query& lhs, const Query& rhs) {
	return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}


QueryResult OrQuery::eval(const TextQuery& text) const {

	auto right = rhs.eval(text), left = lhs.eval(text);
	auto ret_line = make_shared<set<line_no>>(left.begin(), left.end());
	// Union this querys
	ret_line->insert(right.begin(), right.end());
	// Return the new QueryResult representing the union of lhs and rhs
	return QueryResult(rep(), ret_line, left.get_file());
}
