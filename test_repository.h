#if !defined(TEST_REPOSITORY)
#define TEST_REPOSITORY

#include "repository.h"
#include "library.h"

class Repository_test
{
private:
    Repository<Library> repo_library;

public:
    Repository_test();
    ~Repository_test();
    void test_add();
};

#endif // TEST_REPOSITORY
