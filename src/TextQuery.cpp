#include "TextQuery.h"
#include <sstream>
#include <fstream>

using namespace std;

TextQuery::TextQuery(ifstream& is) : file(new vector<string>()) {
	string text;

	while (getline(is, text)) {
		file->push_back(text);
		size_t n = file->size() - 1;
		//
		istringstream line(text);

		string word;
		// Read a word of line into word var
		while (line >> word) {
			/*
			 * Return the element with key, if k is not in map,
			 * adds a new , value-initialized element with key
			 */
			auto& lines = wm[word];
			// true if *this stores a pointer, false otherwise.
			// operator bool
			if (!lines)
				lines.reset(new set<line_no>);
			// insert line number to this specific word.
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string& sought) const {
	static shared_ptr<set<line_no>> no_data(new set<line_no>);

	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, no_data, file);
	else
		return QueryResult(sought, loc->second, file);
}

string make_plural(size_t ctr, const string& word, const string& ending) {
	return (ctr > 1) ? word + ending : word;
}

ostream& print(ostream& os, const QueryResult& qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << endl;

	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ")"
		   << *(qr.file->begin() + num) << endl;

	return os;
}


