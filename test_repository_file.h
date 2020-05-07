#if !defined(TEST_REPOSITORY_FILE_H)
#define TEST_REPOSITORY_FILE_H

#include "repository_file.h"
#include "library.h"

class Repository_test_file
{
private:
    Repository_file<Library> repo_file;
    char *file = NULL;

public:
    Repository_test_file();
    Repository_test_file(char *filename);
    ~Repository_test_file();
    void test_repo_file();
    void test_save_load();
};

#endif // TEST_REPOSITORY_FILE_H
