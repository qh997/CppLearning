template <typename T>
int compare(const T &v1, const T &v2)
{
    if (v1 < v2)
        return -1;
    else if (v2 < v1)
        return 1;
    else
        return 0;
}

template <class T> template <class Iter>
void Queue<T>::assign(Iter beg, Iter end)
{
    destroy();
    copy_elems(beg, end);
}

template <class Type>
void Queue<Type>::destroy()
{
    while(!empty())
        pop();
}

template <class Type>
void Queue<Type>::pop()
{
    QueueItem<Type> *p = head;
    head = head->next;
    delete p;
}

template <class Type>
void Queue<Type>::push(const Type &val)
{
    QueueItem<Type> *pt = new QueueItem<Type>(val);
    if (empty())
        head = tail = pt;
    else
    {
        tail->next = pt;
        tail = pt;
    }
}

template <class Type>
void Queue<Type>::copy_elems(const Queue &orig)
{
    for (QueueItem<Type> *pt = orig.head; pt != orig.tail; pt = pt->next)
        push(pt->item);
}

template <class Type> template <class It>
void Queue<Type>::copy_elems(It beg, It end)
{
    while (beg != end)
    {
        push(*beg);
        ++beg;
    }
}

template <class Type>
std::ostream &operator<<(std::ostream &os, const Queue<Type> &q)
{
    os << "< ";
    QueueItem<Type> *p;
    for (p = q.head; p; p = p->next)
        os << p->item << " ";
    os << ">";

    return os;
}

void Queue<const char *>::push(const char *val)
{
    return real_queue.push(val);
}
