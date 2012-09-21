#include "Query.h"

using namespace std;

Query::Query(const std::string &s)
    : q(new WordQuery(s)), use(new size_t(1))
{}

set<TextQuery::line_no>
Query::eval(const TextQuery &t) const
    {return q->eval(t);}

ostream &Query::display(ostream &os) const
    {return q->display(os);}

void Query::decr_use()
{
    if (0 == --*use)
    {
        delete q;
        delete use;
    }
}

set<TextQuery::line_no>
WordQuery::eval(const TextQuery &file) const
{
    return file.run_query(query_word);
}

set<TextQuery::line_no>
NotQuery::eval(const TextQuery &file) const
{
    set<TextQuery::line_no> has_val = query.eval(file);
    set<line_no> ret_lines;

    for (TextQuery::line_no n = 0; n != file.size(); ++n)
        if (has_val.find(n) == has_val.end())
            ret_lines.insert(n);

    return ret_lines;
}

set<TextQuery::line_no>
OrQuery::eval(const TextQuery &file) const
{
    set<line_no> ret_lines = lhs.eval(file),
                 right = rhs.eval(file);
    ret_lines.insert(right.begin(), right.end());

    return ret_lines;
}

set<TextQuery::line_no>
AndQuery::eval(const TextQuery &file) const
{
    set<line_no> left = lhs.eval(file),
                 right = rhs.eval(file);
    set<line_no> ret_lines;
    set_intersection(left.begin(), left.end(),
                     right.begin(), right.end(),
                     inserter(ret_lines, ret_lines.begin()));

    return ret_lines;
}

ostream &WordQuery::display(ostream &os) const
    {return os << query_word;}

ostream &NotQuery::display(ostream &os) const
    {return os << "~(" << query << ")";}

ostream &BinaryQuery::display(ostream &os) const
    {return os << "(" << lhs << " " << oper << " " << rhs << ")";}
