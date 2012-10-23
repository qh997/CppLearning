#ifndef __LIST_H__
#define __LIST_H__

template<class Elem>
class list
{
  public:
    class iterator;

    iterator begin();
    iterator end();

    iterator insert(iterator p, const Elem &e);
    iterator erase(iterator p);

    void push_back(const Elem &v);
    void push_front(const Elem &v);
    void pop_front();
    void pop_back();

    Elem &front();
    Elem &back();
};

template<class Elem>
class Link
{
  public:
    Link *prev;
    Link *succ;
    Elem val;
};

template<class Elem>
class list<Elem>::iterator
{
    Link<Elem> *curr;
  public:
    iterator(Link<Elem> *p): curr(p) {}

    iterator &operator++() {curr = curr->succ; return *this;}
    iterator &operator--() {curr = curr->prev; return *this;}
    Elem &operator*() {return curr->val;}

    bool operator==(const iterator &b) const {return curr == b.curr;}
    bool operator!=(const iterator &b) const {return curr != b.curr;}
};

#include "list.cpp"

#endif //__LIST_H__
