#include "BinaryQuery.cpp"

class AndQuery : public BinaryQuery {
	
	friend class Query operator& (const Query&, const Query&);

	AndQuery(const Query& left, const Query& right) : BinaryQuery (left, right, "&") {}

	QueryResult eval (const TextQuery&) const override;
};

inline Query operator& (const Query& lhs, const Query& rhs) {
	return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}
