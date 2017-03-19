#include "../include/QueryBase.h"
#include "../include/TextQuery.h"
#include "../include/QueryResult.h"
#include "Query.cpp"

class NotQuery : public QueryBase {

	friend Query operator~ (const Query&);

	NotQuery(const Query& q) : query(q) {}

	// Implement two abstract methods
	QueryResult eval (const TextQuery&) const override;
	std::string rep() const override {return "~(" + query.rep() + ")";}
	// A WordQuery Object
	Query query;
};

inline Query operator~ (const Query& operand) {
	return std::shared_ptr<QueryBase>(new NotQuery(operand));
}


//QueryResult NotQuery::eval(const TextQuery& t) const override {


//}
