
#include <iostream>
#include <fstream>
#include "Query.h"

using namespace std;

int main() {
	Query query = Query("of") & Query("a") | Query("from") & ~Query("at");
	ifstream is;
	is.open("../LICENSE");
	TextQuery textQuery(is);
	print(std::cout, query.eval(textQuery));
	cout << query.rep() << endl;
}
