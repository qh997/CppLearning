#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <iostream>
#include <set>
#include "Folder.h"

class Folder;

class Message
{
  public:
    Message(const std::string &);
    Message(const Message &);
    Message &operator=(const Message &);
    ~Message();

    void save(Folder &);
    void remove(Folder &);
    void show() const;

  private:
    void put_Msg_in_Folders(const std::set<Folder *> &);
    void remove_Msg_from_Folders();

    std::string contents;
    std::set<Folder *> folders;
};

#endif //__MESSAGE_H__
