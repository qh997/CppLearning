#include "Folder.h"

using namespace std;

Folder::Folder(const string &s)
    : name(s)
{}

Folder::Folder(const Folder &f)
    : name(f.name), msgs(f.msgs)
{
    for (set<Message *>::const_iterator beg = msgs.begin(); beg != msgs.end(); ++beg)
        (*beg)->save(*this);
}

Folder &Folder::operator=(const Folder &f)
{
    return *this;
}

Folder::~Folder()
{
    for (set<Message *>::const_iterator beg = msgs.begin(); beg != msgs.end(); ++beg)
        (*beg)->remove(*this);
}

void Folder::addMsg(Message &m)
{
    if (!msgs.count(&m))
    {
        msgs.insert(&m);
        m.save(*this);
    }
}

void Folder::remMsg(Message &m)
{
    if (msgs.count(&m))
    {
        msgs.erase(&m);
        m.remove(*this);
    }
}
