#include <string>
#include "../include/QueryResult.h"
#include "../include/TextQuery.h"
#include "../include/QueryBase.h"

#include "WordQuery.cpp"


class Query
{
	friend Query operator~ (const Query&);
	friend Query operator| (const Query&, const Query&);
	friend Query operator& (const Query&, const Query&);

public:
	Query (const std::string&);
	QueryResult eval(const TextQuery &t) const{return q->eval(t);}
	std::string rep() const {return q->rep();}
	virtual ~Query ();

private:
	Query(std::shared_ptr<QueryBase> query) : q (query){}
	std::shared_ptr<QueryBase> q;
};

// out put the result
std::ostream& operator<< (std::ostream& os, const Query& query){
	return os << query.rep();
}

inline Query::Query(const std::string& s) : q(new WordQuery(s)){}

