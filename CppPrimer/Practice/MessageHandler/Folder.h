#ifndef __FOLDER_H__
#define __FOLDER_H__

#include <set>
#include "Message.h"

class Message;

class Folder
{
    friend class Message;

  public:
    Folder(const std::string &);
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    ~Folder();

    void addMsg(Message &);
    void remMsg(Message &);

  //private:
    std::string name;
    std::set<Message *> msgs;
};

#endif //__FOLDER_H__
