#include <string>
#include <set>

#include "folder.h"

using std::string;
using std::set;

class Message {
public:
    Message(const string &str = ""): contents(str) {}

    // copy controls
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();

    // add/remove
    void save(Folder&);
    void Remove(Folder&);

    void addFldr(Folder *);
    void remFldr(Folder *);

private:
    string contents;
    set<Folder*> folders;

    void put_msg_in_folders(const set<Folder *>&);
    void remove_msg_from_folders();
};

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
    put_msg_in_folders(folders);
}

Message& Message::operator=(const Message &rhs) {
    if (&rhs != this) {
        remove_msg_from_folders();
        contents = rhs.contents;
        folders = rhs.folders;
        put_msg_in_folders(rhs.folders);
    }
    return *this;
}

Message::~Message() {
    remove_msg_from_folders();
}

void Message::put_msg_in_folders(const set<Folder *> &rhs) {
    for (set<Folder *>::const_iterator beg = rhs.begin(); beg != rhs.end(); ++beg) {
        (*beg)->addMsg(this);
    }
}

void Message::remove_msg_from_folders() {
    for (set<Folder *>::const_iterator beg = folders.begin(); beg != folders.end(); ++beg) {
        (*beg)->remMsg(this);
    }
}

void Message::addFldr(Folder *fp) {
    folders.insert(fp);
}

void Message::remFldr(Folder *fp) {
    folders.erase(fp);
}
