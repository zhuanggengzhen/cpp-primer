#include "ex12_32.h"

TextQuery::TextQuery(std::ifstream &infile)
{
	std::string word;
    std::string line;
    int lineNum = 0;
    while(getline(infile, line))
    {   
    	file.push_back(line);
    	std::istringstream iss(line);
    	while(iss >> word)
		{
			auto &lines = wm[word];
			if(!lines)
				lines.reset(new std::set<line_no>);
			lines->insert(lineNum);
     	}
		lineNum++;
	}
}

QueryResult TextQuery::query(std::string s)
{
	auto iter = wm.find(s);
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	if(iter != wm.end())
		return QueryResult(s, file, iter->second);
	else
		return QueryResult(s, file, nodata);
}

void print(std::ostream &os, QueryResult qr)
{
    int i = 0;
    os << qr.word << " occurs " << qr.line_num->size() << " times\n";
    for(auto n : *qr.line_num)
	{
		auto bg = qr.lines.begin();
        os << "    (line " << n + 1 << ") ";
		while(n--)
			bg.incr();
		os << bg.deref() << "\n";
	}
}

