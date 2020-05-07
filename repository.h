#if !defined(REPOSITORY_H)
#define REPOSITORY_H

#include <queue>
#include <iostream>
using namespace std;

template <class T>
class Repository
{
protected:
    priority_queue<T> elements;

public:
    Repository()
    {
    }
    Repository(priority_queue<T> q)
    {
        this->elements = q;
    }
    ~Repository()
    {
        while (!this->elements.empty())
        {
            this->elements.pop();
        }
    }
    void add_element(T &elem)
    {
        this->elements.push(elem);
    }
    void delete_elem(T &elem)
    {
        int len = this->elements.size();
        priority_queue<T> new_elem;
        while (!this->elements.empty())
        {
            if (!(this->elements.top() == elem))
            {
                new_elem.push(this->elements.top());
            }
            this->elements.pop();
        }
        this->elements = new_elem;
    }

    void update_elem(T &prevous_elem, T &new_elem)
    {
        priority_queue<T> copy;
        while (!this->elements.empty())
        {
            T topper = this->elements.top();
            if (topper == prevous_elem)
            {
                copy.push(new_elem);
            }
            else
            {
                copy.push(topper);
            }
            this->elements.pop();
        }
        this->elements = copy;
    }
    priority_queue<T> get_all()
    {
        priority_queue<T> to_return = this->elements;
        return to_return;
    }

    int get_size()
    {
        return this->elements.size();
    }

    T get_by_id(int id)
    {
        priority_queue<T> copy = this->elements;
        while (!copy.empty())
        {
            T comp = copy.top();
            if (comp.get_id() == id)
            {
                return comp;
            }
            copy.pop();
        }
    }
};

#endif // REPOSITORY_H
