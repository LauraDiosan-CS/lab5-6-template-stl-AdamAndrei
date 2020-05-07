#include "library.h"
#include "tools.h"
#include <iostream>
#include <string.h>

using namespace std;

Library::Library()
{
    this->author_name = NULL;
    this->title = NULL;
    this->year = 0;
    this->id = 0;
    this->borrowed = 0;
}

Library::Library(int a_id, int a_year, char *a_author_name, char *a_title)
{
    this->id = a_id;
    this->year = a_year;
    this->author_name = new char[strlen(a_author_name) + 1];
    strcpy(this->author_name, a_author_name);
    this->title = new char[strlen(a_title) + 1];
    strcpy(this->title, a_title);
    this->borrowed = 0;
}

Library::Library(const Library &other_library)
{
    this->author_name = new char[strlen(other_library.author_name) + 1];
    this->title = new char[strlen(other_library.title) + 1];
    strcpy(this->author_name, other_library.author_name);
    strcpy(this->title, other_library.title);
    this->id = other_library.id;
    this->year = other_library.year;
    this->borrowed = other_library.borrowed;
}

Library::~Library()
{
    if (this->author_name)
    {
        delete[] this->author_name;
        this->author_name = NULL;
    }
    if (this->title)
    {
        delete[] this->title;
        this->title = NULL;
    }
}

bool Library::get_borrowed()
{
    return this->borrowed;
}

int Library::get_id()
{
    return this->id;
}

int Library::get_year()
{
    return this->year;
}

char *Library::get_name()
{
    return this->author_name;
}

char *Library::get_title()
{
    return this->title;
}

void Library::set_id(int new_id)
{
    this->id = new_id;
}

void Library::set_year(int new_year)
{
    this->year = new_year;
}

void Library::set_name(char *new_name)
{
    if (this->author_name)
    {
        delete[] this->author_name;
    }
    this->author_name = new char[strlen(new_name) + 1];
    strcpy(this->author_name, new_name);
}

void Library::set_title(char *new_title)
{
    if (this->title)
    {
        delete[] this->title;
    }
    this->title = new char[strlen(new_title) + 1];
    strcpy(this->title, new_title);
}

void Library::set_borrowed(bool a)
{
    if (a)
    {
        this->borrowed = 1;
    }
    else
    {
        this->borrowed = 0;
    }
}

char *Library::to_string()
{
    int name_length = strlen(this->author_name) + 1;
    int title_length = strlen(this->title) + 1;
    int l = strlen("Book: ");
    int m = strlen(" ,write by: ");
    char *for_name = new char[m + 1];
    strcpy(for_name, " ,write by: ");
    int n = strlen(" ,published in year: ");
    char *for_year = new char[n + 1];
    strcpy(for_year, " ,published in year: ");
    int p = strlen(" ,with id: ");
    char *for_id = new char[p + 1];
    strcpy(for_id, " ,with id: ");
    char *q = new char[20];
    char *r = new char[20];
    itoa(this->year, q, 10);
    itoa(this->id, r, 10);
    int w = strlen(" ,borrowed status: ");
    char *for_borrow = new char[w + 1];
    strcpy(for_borrow, " ,borrowed status: ");
    char *g = new char[20];
    if (this->borrowed)
    {
        strcpy(g, "borrowed");
    }
    else
    {
        strcpy(g, "not borrowed");
    }
    int len = l + title_length + m + name_length + n + strlen(q) + p + strlen(r) + w + strlen(g) + 1;
    char *str = new char[len];
    strcpy(str, "Book: ");
    strcat(str, this->title);
    strcat(str, for_name);
    strcat(str, this->author_name);
    strcat(str, for_year);
    strcat(str, q);
    strcat(str, for_id);
    strcat(str, r);
    strcat(str, for_borrow);
    strcat(str, g);
    delete[] q;
    delete[] r;
    delete[] g;
    delete[] for_borrow;
    delete[] for_name;
    delete[] for_id;
    delete[] for_year;
    return str;
}

Library &Library::operator=(const Library &lib)
{
    if (this != &lib)
    {
        if (this->author_name)
        {
            delete[] this->author_name;
        }
        this->author_name = new char[strlen(lib.author_name) + 1];
        strcpy(this->author_name, lib.author_name);
        if (this->title)
        {
            delete[] this->title;
        }
        this->title = new char[strlen(lib.title) + 1];
        strcpy(this->title, lib.title);
        this->id = lib.id;
        this->year = lib.year;
        this->borrowed = lib.borrowed;
    }
    return *this;
}

bool Library::operator==(const Library &lib) const
{
    return ((strcmp(this->author_name, lib.author_name) == 0) &&
            (strcmp(this->title, lib.title) == 0) && (this->id == lib.id) &&
            (this->year == lib.year));
}

bool Library::operator<(const Library &lib) const
{
    if (this->year < lib.year)
    {
        return true;
    }
    return false;
}

bool Library::operator>(const Library &lib) const
{
    if (this->year > lib.year)
    {
        return true;
    }
    return false;
}

ostream &operator<<(ostream &os, Library &lib)
{
    if (lib.borrowed)
    {
        os << "Book: " << lib.title << " ,write by: " << lib.author_name << " ,published in year: " << lib.year << " ,with id: " << lib.id << " ,borrowed status: borrowed" << endl;
    }
    else
    {
        os << "Book: " << lib.title << " ,write by: " << lib.author_name << " ,published in year: " << lib.year << " ,with id: " << lib.id << " ,borrowed status: not borrowed" << endl;
    }

    return os;
}

istream &operator>>(istream &is, Library &lib)
{
    char *new_title = new char[100];
    char *new_author = new char[100];
    cout << "Book title is: " << endl;
    is >> new_title;
    lib.set_title(new_title);
    cout << "Author name is: " << endl;
    is >> new_author;
    lib.set_name(new_author);
    delete[] new_author;
    delete[] new_title;
    int year;
    cout << "Year of publication: " << endl;
    is >> year;
    lib.set_year(year);
    int id;
    cout << "Id book: " << endl;
    is >> id;
    lib.set_id(id);
    bool a = 0;
    lib.set_borrowed(a);
    return is;
}
