#ifndef QUEUE_H
#define QUEUE_H

#include <ostream>

using std::ostream;

// function template declaration must precede friend declaration in QueueItem
template <class T> class Queue;
template <class T> ostream& operator<<(ostream&, const Queue<T>&);

template <class T> class QueueItem
{
    // set friend class, so Queue can access all private fields
    friend class Queue<T>;
    friend ostream& operator<< <T> (ostream&, const Queue<T>&);

    QueueItem(const T &t): item(t), next(0) {}
    // value stored in this element
    T item;
    // pointer to next element in the Queue
    QueueItem *next;
};

template <class T> class Queue
{
    friend ostream& operator<< <T> (ostream&, const Queue<T>&);
public:
    template <class Iter> Queue(Iter beg, Iter end): head(0), tail(0) { copy_elems(beg, end); }
    template <class Iter> void assign(Iter, Iter);

    Queue(): head(0), tail(0) {}
    Queue(const Queue &q): head(0), tail(0) { copy_elems(q); }
    Queue& operator=(const Queue&);
    ~Queue() { destroy(); }

    T& front() { return head->item; }
    const T& front() const { return head->item; }
    void push(const T&);
    void pop();
    bool empty() const { return head == 0; }

private:
    // pointer to first/last element in the queue
    QueueItem<T> *head, *tail;
    // ddelete all the elements
    void destroy();
    // copy elements from parameter
    void copy_elems(const Queue&);
    template <class Iter> void copy_elems(Iter, Iter);
};

template <class T> void Queue<T>::destroy() {
    while (!empty()) pop();
}

template <class T> void Queue<T>::pop() {
    QueueItem<T> *p = head;
    head = head->next;
    delete p;
}

template <class T> void Queue<T>::push(const T &val) {
    QueueItem<T> *pt = new QueueItem<T>(val);

    if (empty())
    {
        head = tail = pt;
    } else {
        tail->next = pt;
        tail = pt;
    }
}

template <class T> void Queue<T>::copy_elems(const Queue &orig) {
    for (QueueItem<T> *pt = orig.head; pt; pt = pt->next) {
        push(pt->item);
    }
}

template <class T> Queue<T>& Queue<T>::operator=(const Queue &q) {
    destroy();
    copy_elems(q);
}

template <class T> ostream& operator<<(ostream &os, const Queue<T> &q) {
    os << "< ";
    QueueItem<T> *p;
    for (p = q.head; p; p=p->next) {
        os << p->item << " ";
    }
    os << ">";
    return os;
}

template <class T> template <class Iter>
void Queue<T>::assign(Iter beg, Iter end) {
    destroy();
    copy_elems(beg, end);
}

template <class T> template <class Iter>
void Queue<T>::copy_elems(Iter beg, Iter end) {
    while (beg != end) {
        push(*beg);
        ++beg;
    }
}

#endif