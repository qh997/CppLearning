#include <iostream>
#include <stdexcept>
#include <sstream>
#include "TextQuery.h"

using namespace std;

void TextQuery::read_file(ifstream &is)
{
    store_file(is);
    build_map();
}

set<TextQuery::line_no>
TextQuery::run_query(const string &query_word) const
{
    map<string, set<line_no> >::const_iterator
        loc = word_map.find(query_word);

    if (loc == word_map.end())
        return set<line_no>();
    else
        return loc->second;
}

string TextQuery::text_line(line_no line) const
{
    if (line < lines_of_text.size())
        return lines_of_text[line];

    throw out_of_range("line number out of range");
}

void TextQuery::store_file(ifstream &is)
{
    string textline;
    while (getline(is, textline))
        lines_of_text.push_back(textline);
}

void TextQuery::build_map()
{
    for (line_no line_mun = 0;
         line_mun != lines_of_text.size(); 
         ++line_mun)
    {
        istringstream line(lines_of_text[line_mun]);
        string word;
        while (line >> word)
            word_map[word].insert(line_mun);
    }
}
