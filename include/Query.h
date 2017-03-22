//
// Created by leon on 21/03/2017.
//

#ifndef TEXT_QUERY_QUERY_H
#define TEXT_QUERY_QUERY_H

#include "QueryBase.h"

class Query
{
	friend Query operator~ (const Query&);
	friend Query operator| (const Query&, const Query&);
	friend Query operator& (const Query&, const Query&);

public:
	Query (const std::string&);
	QueryResult eval(const TextQuery &t) const{return q->eval(t);}
	std::string rep() const {return q->rep();}

private:
	Query(std::shared_ptr<QueryBase> query) : q (query){}
	std::shared_ptr<QueryBase> q;
};
#endif //TEXT_QUERY_QUERY_H
