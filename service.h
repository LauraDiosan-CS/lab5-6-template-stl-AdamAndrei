#if !defined(SERVICE_H)
#define SERVICE_H

#include "repository_file.h"
#include "repository.h"
#include "library.h"
#include <iostream>

using namespace std;

// class Service
// {
// private:
//     Repository_file<Library> repo;

// public:
//     Service()
//     {
//     }
//     Service(const Repository_file<Library> &repository)
//     {
//         this->repo = repository;
//     }
//     Service(const Service &other_service)
//     {
//         this->repo = other_service.repo;
//     }
//     ~Service()
//     {
//     }
//     void add_element(int id, int year, char *author_name, char *title)
//     {
//         Library lib(id, year, author_name, title);
//         this->repo.add_elem(lib);
//     }
//     void delete_element(int id)
//     {
//         Library lib = this->repo.get_by_id(id);
//         this->repo.delete_element(lib);
//     }
//     void update_element(int id, int new_year, char *new_author_name, char *new_title)
//     {
//         Library lib = this->repo.get_by_id(id);
//         Library new_lib(id, new_year, new_author_name, new_title);
//         this->repo.update_element(lib, new_lib);
//     }
//     priority_queue<Library> get_all_libraries()
//     {
//         return this->repo.get_all_from_file();
//     }

//     Library get_book_by_id(int id)
//     {
//         return this->repo.get_by_id(id);
//     }
//     void borrow_book(int id)
//     {
//         Library to_borrow = this->repo.get_by_id(id);
//         if (!to_borrow.get_borrowed())
//         {
//             int id = to_borrow.get_id();
//             int year = to_borrow.get_year();
//             char *name = new char[strlen(to_borrow.get_name())];
//             char *title = new char[strlen(to_borrow.get_title())];
//             strcpy(name, to_borrow.get_name());
//             strcpy(title, to_borrow.get_title());
//             Library new_lib(id, year, name, title);
//             bool a = 1;
//             new_lib.set_borrowed(a);
//             this->repo.update_element(to_borrow, new_lib);
//         }
//     }
//     void return_book(int id)
//     {
//         Library to_borrow = this->repo.get_by_id(id);
//         if (to_borrow.get_borrowed())
//         {
//             int id = to_borrow.get_id();
//             int year = to_borrow.get_year();
//             char *name = new char[strlen(to_borrow.get_name())];
//             char *title = new char[strlen(to_borrow.get_title())];
//             strcpy(name, to_borrow.get_name());
//             strcpy(title, to_borrow.get_title());
//             Library new_lib(id, year, name, title);
//             bool a = 0;
//             new_lib.set_borrowed(a);
//             this->repo.update_element(to_borrow, new_lib);
//         }
//     }

//     Service &operator=(const Service &n_service)
//     {
//         this->repo = n_service.repo;
//     }
//     priority_queue<Library> get_all_borrowed_books()
//     {
//         priority_queue<Library> borrowed_books;
//         priority_queue<Library> from_repo = this->repo.get_all_from_file();
//         while (!from_repo.empty())
//         {
//             Library lib = from_repo.top();
//             if (lib.get_borrowed())
//             {
//                 borrowed_books.push(lib);
//             }
//             from_repo.pop();
//         }
//         return borrowed_books;
//     }

//     priority_queue<Library> get_all_books_in_library()
//     {
//         priority_queue<Library> borrowed_books;
//         priority_queue<Library> from_repo = this->repo.get_all_from_file();
//         while (!from_repo.empty())
//         {
//             Library lib = from_repo.top();
//             if (!lib.get_borrowed())
//             {
//                 borrowed_books.push(lib);
//             }
//             from_repo.pop();
//         }
//         return borrowed_books;
//     }
// };
class Service
{
private:
    Repository_file<Library> repo;

public:
    Service()
    {
    }
    Service(const Repository_file<Library> &repository)
    {
        this->repo = repository;
    }
    Service(const Service &other_service)
    {
        this->repo = other_service.repo;
    }
    ~Service()
    {
    }
    void add_element(int id, int year, char *author_name, char *title)
    {
        Library lib(id, year, author_name, title);
        this->repo.add_elem(lib);
    }
    void delete_element(int id)
    {
        Library lib = this->repo.get_by_id(id);
        this->repo.delete_element(lib);
    }
    void update_element(int id, int new_year, char *new_author_name, char *new_title)
    {
        Library lib = this->repo.get_by_id(id);
        Library new_lib(id, new_year, new_author_name, new_title);
        this->repo.update_element(lib, new_lib);
    }
    priority_queue<Library> get_all_libraries()
    {
        return this->repo.get_all_from_file();
    }

    Library get_book_by_id(int id)
    {
        return this->repo.get_by_id(id);
    }
    void borrow_book(int id)
    {
        Library to_borrow = this->repo.get_by_id(id);
        if (!to_borrow.get_borrowed())
        {
            int id = to_borrow.get_id();
            int year = to_borrow.get_year();
            char *name = new char[strlen(to_borrow.get_name())];
            char *title = new char[strlen(to_borrow.get_title())];
            strcpy(name, to_borrow.get_name());
            strcpy(title, to_borrow.get_title());
            Library new_lib(id, year, name, title);
            bool a = 1;
            new_lib.set_borrowed(a);
            this->repo.update_element(to_borrow, new_lib);
        }
    }
    void return_book(int id)
    {
        Library to_borrow = this->repo.get_by_id(id);
        if (to_borrow.get_borrowed())
        {
            int id = to_borrow.get_id();
            int year = to_borrow.get_year();
            char *name = new char[strlen(to_borrow.get_name())];
            char *title = new char[strlen(to_borrow.get_title())];
            strcpy(name, to_borrow.get_name());
            strcpy(title, to_borrow.get_title());
            Library new_lib(id, year, name, title);
            bool a = 0;
            new_lib.set_borrowed(a);
            this->repo.update_element(to_borrow, new_lib);
        }
    }

    Service &operator=(const Service &n_service)
    {
        this->repo = n_service.repo;
    }
    priority_queue<Library> get_all_borrowed_books()
    {
        priority_queue<Library> borrowed_books;
        priority_queue<Library> from_repo = this->repo.get_all_from_file();
        while (!from_repo.empty())
        {
            Library lib = from_repo.top();
            if (lib.get_borrowed())
            {
                borrowed_books.push(lib);
            }
            from_repo.pop();
        }
        return borrowed_books;
    }

    priority_queue<Library> get_all_books_in_library()
    {
        priority_queue<Library> borrowed_books;
        priority_queue<Library> from_repo = this->repo.get_all_from_file();
        while (!from_repo.empty())
        {
            Library lib = from_repo.top();
            if (!lib.get_borrowed())
            {
                borrowed_books.push(lib);
            }
            from_repo.pop();
        }
        return borrowed_books;
    }
};
#endif // SERVICE_H
