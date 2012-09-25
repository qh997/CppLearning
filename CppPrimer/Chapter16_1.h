#ifndef CHAPTER16_1_H_
#define CHAPTER16_1_H_

#include <iostream>

template <typename T>
int compare(const T &v1, const T &v2);

template <class Type> class Queue;
template <class Type> std::ostream &operator<<(std::ostream &, const Queue<Type> &);
template <class Type>
class QueueItem
{
    friend class Queue<Type>;
    friend std::ostream &operator<< <Type>(std::ostream &, const Queue<Type> &);

  private:
    QueueItem(const Type &t): item(t), next(NULL) {}

    Type item;
    QueueItem *next;
};

template <class Type>
class Queue
{
    friend std::ostream &operator<< <Type>(std::ostream &, const Queue<Type> &);

  public:
    Queue(): head(NULL), tail(NULL) {}
    Queue(const Queue &Q): head(NULL), tail(NULL) {copy_elems(Q);}
    template <class It> Queue(It beg, It end)
        :head(NULL), tail(NULL) {copy_elems(beg, end);}
    Queue &operator=(const Queue &);
    ~Queue() {destroy();}

    Type &front() {return head->item;}
    const Type &front() const {return head->item;}
    void push(const Type &);
    void pop();
    bool empty() const {return head == NULL;}
    template <class Iter> void assign(Iter, Iter);

  private:
    QueueItem<Type> *head;
    QueueItem<Type> *tail;
    void destroy();
    void copy_elems(const Queue &);
    template <class Iter> void copy_elems(Iter, Iter);
};

template <>
class Queue<const char *>
{
  public:
    void push(const char *);
    void pop() {real_queue.pop();}
    bool empty() const {return real_queue.empty();}
    std::string front() {return real_queue.front();}
    const std::string front() const {return real_queue.front();}

  private:
    Queue<std::string> real_queue;
};

#include "Chapter16_1.cpp"

#endif //CHAPTER16_1_H_
