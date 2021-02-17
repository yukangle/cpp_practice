#ifndef RESOURCE_H
#define RESOURCE_H

class Resource 
{
public:
    Resource(parms p): r(allocate(p)) { }
    ~Resource() { release(r); }

private:
    resource_type *r;
    resource_type *allocate(parms p);
    void release(resource_type);
};

#endif