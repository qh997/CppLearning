#include <iostream>
#include <cstdlib>
#include "TextQuery.h"
#include "Query.h"

using namespace std;

ifstream &open_file(ifstream &in, const string &file);
void print_results(const set<TextQuery::line_no> locs,
                   const TextQuery &file,
                   const Query &query);
string make_plural(size_t str, const string &word, const string &ending);

int main(int argc, char **argv)
{
    std::ifstream infile;

    if (2 > argc || !open_file(infile, argv[1]))
    {
        cerr << "No input file!" << endl;
        return EXIT_FAILURE;
    }

    TextQuery tq;
    tq.read_file(infile);

    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        cin >> s;

        if (!cin || s == "q")
            break;

        Query wq(s);
        set<TextQuery::line_no> locs = wq.eval(tq);
        print_results(locs, tq, wq);
    }

    return EXIT_SUCCESS;
}

ifstream &open_file(ifstream &in, const string &file)
{
    in.close();
    in.clear();

    in.open(file.c_str());
    return in;
}

void print_results(const set<TextQuery::line_no> locs,
                   const TextQuery &file,
                   const Query &query)
{
    typedef set<TextQuery::line_no> line_nums;
    line_nums::size_type size = locs.size();
    cout << "\n" << query << " occurs " << size << " "
         << make_plural(size, "time", "s") << endl;

    
    for (line_nums::iterator it = locs.begin(); it != locs.end(); ++it)
        cout << "\t(line " << (*it) + 1 << ") "
             << file.text_line(*it) << endl;
}

string make_plural(size_t str, const string &word, const string &ending)
{
    return (str <= 1) ? word : word + ending;
}
