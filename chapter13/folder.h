#include <set>

using std::set;

class Message {};

class Folder {
public:
    void addMsg(Message *);
    void remMsg(Message *);

private:
    set<Message *> messages;
};

// void Folder::addMsg(Message *mp) {
//     messages.insert(mp);
// }

// void Folder::remMsg(Message *mp) {
//     messages.erase(mp);
// }