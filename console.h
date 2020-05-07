#if !defined(CONSOLE_H)
#define CONSOLE_H

#include "service.h"

class Console
{
private:
    Service service;

public:
    Console(Service &n_service);
    Console();
    ~Console();
    Library read_book();
    void menu();
    void print_menu();
    void add_book();
    void update_book();
    void borrow_book();
    void return_book();
    void show_all();
    void show_borrowed_books();
    void show_books_in_library();
};

#endif // CONSOLE_H
