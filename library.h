#if !defined(LIBRARY_H)
#define LIBRARY_H

#include <iostream>
using namespace std;

class Library
{
private:
    int id;
    int year;
    char *author_name;
    char *title;
    bool borrowed;

public:
    Library();
    Library(int id, int year, char *author_name, char *title);
    Library(const Library &other_library);
    ~Library();
    int get_id();
    int get_year();
    char *get_name();
    char *get_title();
    bool get_borrowed();
    void set_id(int new_id);
    void set_year(int new_year);
    void set_name(char *new_name);
    void set_title(char *new_title);
    void set_borrowed(bool a);
    Library &operator=(const Library &lib);
    char *to_string();
    bool operator==(const Library &lib) const;
    bool operator<(const Library &lib) const;
    bool operator>(const Library &lib) const;
    friend ostream &operator<<(ostream &os, Library &lib);
    friend istream &operator>>(istream &is, Library &lib);
};

#endif // LIBRARY_H
