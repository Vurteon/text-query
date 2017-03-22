//
// Created by leon on 21/03/2017.
//

#ifndef TEXT_QUERY_WORDQUERY_H
#define TEXT_QUERY_WORDQUERY_H

#include "QueryBase.h"

class WordQuery : public QueryBase {
	friend class Query;
	WordQuery(const std::string& s):query_word(s) {}
	QueryResult eval (const TextQuery& t) const override{ return t.query(query_word);}
	std::string rep() const override {return query_word;}
	std::string query_word;
};



#endif //TEXT_QUERY_WORDQUERY_H
