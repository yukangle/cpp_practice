#include "screen.h"
#include "scrptr.h"

class ScreenPtr 
{
public:
    ScreenPtr(Screen *p): ptr(new ScrPtr(p)) { }
    ScreenPtr(const ScreenPtr &orig): ptr(orig.ptr) { ++ptr->use; }
    ScreenPtr& operator=(const ScreenPtr&);
    ~ScreenPtr() { if (--ptr->use == 0) delete ptr; }

    Screen &operator*() { return *ptr->sp; }
    const Screen &operator*() const { return *ptr->sp; }
    Screen *operator->() { return ptr->sp; }
    const Screen *operator->() const { ptr->sp; }
private:
    ScrPtr *ptr;
};