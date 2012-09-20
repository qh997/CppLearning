#include "Message.h"

using namespace std;

Message::Message(const string &s = "")
    : contents(s)
{}

Message::Message(const Message &m)
    : contents(m.contents), folders(m.folders)
{
    put_Msg_in_Folders(folders);
}

Message &Message::operator=(const Message &rhs)
{
    if (&rhs != this)
    {
        remove_Msg_from_Folders();
        contents = rhs.contents;
        folders = rhs.folders;
        put_Msg_in_Folders(rhs.folders);
    }

    return *this;
}

Message::~Message()
{
    remove_Msg_from_Folders();
}

void Message::save(Folder &f)
{
    if (!folders.count(&f))
    {
        folders.insert(&f);
        f.addMsg(*this);
    }
}

void Message::remove(Folder &f)
{
    if (folders.count(&f))
    {
        folders.erase(&f);
        f.remMsg(*this);
    }
}

void Message::show() const
{
    cout << contents << ": ";
    for (set<Folder *>::const_iterator beg = folders.begin(); beg != folders.end(); ++beg)
        cout << (*beg)->name << " ";
    cout << endl;
}

void Message::put_Msg_in_Folders(const set<Folder *> &rhs)
{
    for (set<Folder *>::const_iterator beg = rhs.begin(); beg != rhs.end(); ++beg)
        (*beg)->addMsg(*this);
}

void Message::remove_Msg_from_Folders()
{
    for (set<Folder *>::const_iterator beg = folders.begin(); beg != folders.end(); ++beg)
        (*beg)->remMsg(*this);
}
