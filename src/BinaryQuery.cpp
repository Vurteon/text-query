#include "../include/QueryBase.h"
#include "Query.cpp"




class BinaryQuery : public QueryBase {

protected:
	BinaryQuery (const Query& l, const Query& r, std::string s) : lhs(l), rhs(r), opSym(s) {}

	std::string rep() const override { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";}

	Query lhs, rhs;
	std::string opSym;
};
