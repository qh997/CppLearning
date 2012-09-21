#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__

#include <string>
#include <vector>
#include <fstream>
#include <set>
#include <map>

class TextQuery
{
  public:
    typedef std::vector<std::string>::size_type line_no;
    void read_file(std::ifstream &is);
    std::set<line_no> run_query(const std::string &) const;
    std::string text_line(line_no) const;
    line_no size() const {return lines_of_text.size();}

  private:
    void store_file(std::ifstream &);
    void build_map();

    std::vector<std::string> lines_of_text;
    std::map< std::string, std::set<line_no> > word_map;
};

#endif //__TEXTQUERY_H__
