#include "tests_library.h"
#include "library.h"
#include <string.h>
#include "assert.h"
#include <iostream>

using namespace std;

void test_library()
{
    int id1 = 1;
    int id2 = 2;
    int year1 = 2000;
    int year2 = 2013;
    char *title1 = new char[20];
    char *title2 = new char[20];
    char *author1 = new char[20];
    char *author2 = new char[20];
    strcpy(title1, "Inferno");
    strcpy(title2, "Origini");
    strcpy(author1, "Dante");
    strcpy(author2, "Dan");
    Library lib1(id1, year1, author1, title1);
    Library lib2(id2, year2, author2, title2);
    assert(lib1.get_id() == id1);
    assert(lib2.get_year() == year2);
    assert(!strcmp(lib1.get_title(), title1));
    assert(!strcmp(lib2.get_name(), author2));
    assert(!lib1.get_borrowed());
    assert(!lib2.get_borrowed());
    int new_id1 = 5;
    int new_year2 = 2001;
    bool f1 = 1;
    char *new_title1 = new char[20];
    char *new_author2 = new char[20];
    strcpy(new_title1, "Purgatoriu");
    strcpy(new_author2, "Brown");
    lib1.set_id(new_id1);
    lib2.set_year(new_year2);
    lib1.set_title(new_title1);
    lib2.set_name(new_author2);
    lib2.set_borrowed(f1);
    assert(lib1.get_id() == new_id1);
    assert(lib2.get_year() == new_year2);
    assert(lib2.get_borrowed());
    assert(!strcmp(lib1.get_title(), new_title1));
    assert(!strcmp(lib2.get_name(), new_author2));
    Library lib3 = lib1;
    assert(lib1 == lib3);
    assert(lib1 < lib2);
    assert(lib3 < lib2);
    assert(lib2 > lib1);
    cout << "test_library PASSED!!!" << endl;
}