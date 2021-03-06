//
// Created by leon on 21/03/2017.
//

#ifndef TEXT_QUERY_BINARYQUERY_H
#define TEXT_QUERY_BINARYQUERY_H

#include "QueryBase.h"
#include "Query.h"

class BinaryQuery : public QueryBase {

protected:
	BinaryQuery (const Query& l, const Query& r, std::string s) : lhs(l), rhs(r), opSym(s) {}

	std::string rep() const override { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";}

	Query lhs, rhs;
	std::string opSym;
};

#endif //TEXT_QUERY_BINARYQUERY_H
