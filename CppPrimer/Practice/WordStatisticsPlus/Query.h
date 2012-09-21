#ifndef QUERY_H_
#define QUERY_H_

#include <iostream>
#include <set>
#include <algorithm>

#include "TextQuery.h"

class Query_base
{
    friend class Query;

  protected:
    typedef TextQuery::line_no line_no;
    virtual ~Query_base() {}

  private:
    virtual std::set<line_no> eval(const TextQuery &) const = 0;
    virtual std::ostream &display(std::ostream & = std::cout) const = 0;
};

class Query
{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);

  public:
    Query(const std::string &);
    Query(const Query &c): q(c.q), use(c.use) {++*use;}
    ~Query() {decr_use();}
    Query &operator=(const Query &);

    std::set<TextQuery::line_no> eval(const TextQuery &) const;
    std::ostream &display(std::ostream &) const;

  private:
    Query(Query_base *query): q(query), use(new std::size_t(1)) {}

    void decr_use();

    Query_base *q;
    std::size_t *use;
};

class WordQuery : public Query_base
{
    friend class Query;

  private:
    WordQuery(const std::string &s): query_word(s) {};
    std::set<line_no> eval(const TextQuery &) const;
    std::ostream &display(std::ostream &) const;

    std::string query_word;
};

class NotQuery : public Query_base
{
    friend Query operator~(const Query &rhs);

  private:
    NotQuery(Query q): query(q) {}
    std::set<line_no> eval(const TextQuery &) const;
    std::ostream &display(std::ostream &) const;

    const Query query;
};

class BinaryQuery : public Query_base
{
  protected:
    BinaryQuery(Query l, Query r, std::string o)
        : lhs(l), rhs(r), oper(o) {}
    std::ostream &display(std::ostream &os) const;

    const Query lhs, rhs;
    const std::string oper;
};

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query &lhs, const Query &rhs);

  private:
    OrQuery(Query l, Query r): BinaryQuery(l, r, "|") {}
    std::set<line_no> eval(const TextQuery &) const;
};

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query &lhs, const Query &rhs);

  private:
    AndQuery(Query l, Query r): BinaryQuery(l, r, "&") {}
    std::set<line_no> eval(const TextQuery &) const;
};

inline Query operator~(const Query &oper)
    {return new NotQuery(oper);}

inline Query operator|(const Query &lhs, const Query &rhs)
    {return new OrQuery(lhs, rhs);}

inline Query operator&(const Query &lhs, const Query &rhs)
    {return new AndQuery(lhs, rhs);}

inline std::ostream &operator<<(std::ostream &os, const Query &q)
    {return q.display(os);}

#endif //QUERY_H_
