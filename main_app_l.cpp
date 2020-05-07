#include "tools.h"
#include "library.h"
#include "repository.h"
#include "repository_file.h"
#include "test_repository.h"
#include "test_repository_file.h"
#include "service.h"
#include "console.h"
#include <iostream>
#include <string.h>
#include "tests_library.h"

using namespace std;

int main()
{
    char *filename = new char[15];
    strcpy(filename, "tests.txt");
    test_library();
    Repository_test repo;
    Repository_test_file repo_f(filename);
    repo.test_add();
    repo_f.test_repo_file();
    char *filename_exe = new char[15];
    strcpy(filename_exe, "libarries.txt");
    Repository_file<Library> repo_file(filename_exe);
    Service service(repo_file);
    Console console(service);
    console.print_menu();
    return 0;
}