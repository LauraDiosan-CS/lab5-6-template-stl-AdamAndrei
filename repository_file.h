#if !defined(REPOSITORY_FILE_H)
#define REPOSITORY_FILE_H

#include "repository.h"
#include <queue>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class Repository_file : public Repository<T>
{
private:
    char *filename;

public:
    Repository_file()
    {
        this->filename = NULL;
    }
    Repository_file(char *filename_a)
    {
        this->filename = new char[strlen(filename_a) + 1];
        strcpy(this->filename, filename_a);
        this->load_from_file();
        this->save_to_file();
    }
    Repository_file(const Repository_file &repo_file)
    {
        this->filename = new char[strlen(repo_file.filename) + 1];
        strcpy(this->filename, repo_file.filename);
        this->load_from_file();
        this->save_to_file();
    }
    ~Repository_file()
    {
        if (this->filename)
        {
            delete[] this->filename;
            this->filename = NULL;
        }
    }
    void load_from_file()
    {
        if (this->filename)
        {
            while (!this->elements.empty())
            {
                this->elements.pop();
            }
            ifstream f(this->filename);
            T elem;
            while (f >> elem)
            {
                Repository<T>::add_element(elem);
            }
            f.close();
        }
    }
    void save_to_file()
    {
        if (this->filename)
        {
            ofstream of(this->filename);
            priority_queue<T> copy;
            while (!this->elements.empty())
            {
                T topper = this->elements.top();
                of << topper;
                copy.push(topper);
                this->elements.pop();
            }
            this->elements = copy;
            of.close();
        }
    }
    Repository_file<T> &operator=(const Repository_file<T> &repo_file)
    {
        if (this->filename)
        {
            delete[] this->filename;
        }
        this->filename = new char[strlen(repo_file.filename) + 1];
        strcpy(this->filename, repo_file.filename);
        this->load_from_file();
        this->save_to_file();
        return *this;
    }
    void add_elem(T &elem)
    {
        Repository<T>::add_element(elem);
        this->save_to_file();
    }
    void delete_element(T &elem)
    {
        Repository<T>::delete_elem(elem);
        this->save_to_file();
    }
    void update_element(T &previous_elem, T &new_elem)
    {
        Repository<T>::update_elem(previous_elem, new_elem);
        this->save_to_file();
    }
    priority_queue<T> get_all_from_file()
    {
        return Repository<T>::get_all();
    }
    void set_filename(char *new_filename)
    {
        if (this->filename)
        {
            delete[] this->filename;
            this->filename = NULL;
        }
        this->filename = new char[strlen(new_filename) + 1];
        strcpy(this->filename, new_filename);
    }
};

#endif // REPOSITORY_FILE_H
