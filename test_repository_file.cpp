#include "test_repository_file.h"
#include <iostream>
#include <assert.h>

using namespace std;

Repository_test_file::Repository_test_file(char *filename)
{
    this->file = new char[strlen(filename) + 1];
    strcpy(this->file, filename);
}
Repository_test_file::Repository_test_file()
{
}
Repository_test_file::~Repository_test_file()
{
}

void Repository_test_file::test_repo_file()
{
    this->repo_file.set_filename(this->file);
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
    this->repo_file.add_elem(lib1);
    assert(this->repo_file.get_size() == 1);
    this->repo_file.add_elem(lib2);
    assert(this->repo_file.get_size() == 2);
    Library n = this->repo_file.get_by_id(id1);
    assert(lib1 == n);
    this->repo_file.delete_element(lib1);
    assert(this->repo_file.get_size() == 1);
    Library lib3(id2, year1, author1, title2);
    this->repo_file.add_elem(lib1);
    assert(this->repo_file.get_size() == 2);
    this->repo_file.update_element(lib2, lib3);
    Library e = this->repo_file.get_by_id(id2);
    assert(e == lib3);
    this->repo_file.delete_element(lib3);
    this->repo_file.delete_element(lib1);
    cout << "test_repo_file PASSED!!!" << endl;
    cout << endl;
}