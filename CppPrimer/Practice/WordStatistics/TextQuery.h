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

  private:
    void store_file(std::ifstream &);
    void build_map();

    std::vector<std::string> lines_of_text;
    std::map< std::string, std::set<line_no> > word_map;
};
