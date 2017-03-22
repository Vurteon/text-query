#ifndef QUERY_RESULT
#define QUERY_RESULT

#include <string>
#include <set>
#include <map>
#include <vector>

class QueryResult{
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	using line_no = std::vector<std::string>::size_type;
	QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
			std::shared_ptr<std::vector<std::string>> f) : sought(s), lines(p), file(f) {}
	auto begin() {return lines->cbegin();}
	auto end() {return lines->cend();}
	auto get_file() {return file;}
private:
	std::string sought; // word this query represents
	std::shared_ptr<std::set<line_no>> lines; // lines it's on
	std::shared_ptr<std::vector<std::string>> file; // input file
};

#endif
