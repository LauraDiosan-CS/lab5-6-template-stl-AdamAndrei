#include "console.h"

Console::Console()
{
}

Console::Console(Service &n_service)
{
    this->service = n_service;
}

Console::~Console()
{
}

Library Console::read_book()
{
    int id = 0;
    int year = 0;
    char title[40];
    char author_name[40];
    cout << "Id of the book :";
    cin >> id;
    cout << "Book title: ";
    cin >> title;
    cout << "Author name: ";
    cin >> author_name;
    cout << "Year of plublication: ";
    cin >> year;
    char *n_title = new char[strlen(title) + 1];
    char *n_name = new char[strlen(author_name) + 1];
    strcpy(n_name, author_name);
    strcpy(n_title, title);
    Library n(id, year, n_name, n_title);
    delete[] n_title;
    delete[] n_name;
    return n;
}

void Console::add_book()
{
    Library p = this->read_book();
    this->service.add_element(p.get_id(), p.get_year(), p.get_name(), p.get_title());
    cout << "Book added!!!" << endl;
}

void Console::update_book()
{
    cout << "Please give the new atributes of the book: " << endl;
    Library n = this->read_book();
    if (n.get_borrowed())
    {
        cout << "This book is borrowed for now, it can't be updated" << endl;
    }
    else
    {
        this->service.update_element(n.get_id(), n.get_year(), n.get_name(), n.get_title());
        cout << "Book updated!!!" << endl;
    }
}

void Console::borrow_book()
{
    int id = 0;
    cout << "The id of the book you want to borrow: ";
    cin >> id;
    Library p = this->service.get_book_by_id(id);
    this->service.borrow_book(id);
    if (p.get_borrowed())
    {
        cout << "This book is already borrowed, you cannot borrow it too!" << endl;
    }
    else
    {
        cout << "Book borrowed!" << endl;
    }
}

void Console::return_book()
{
    int id = 0;
    cout << "The id of the book you want to borrow: ";
    cin >> id;
    Library p = this->service.get_book_by_id(id);
    if (p.get_borrowed())
    {
        this->service.return_book(id);
        cout << "Book returned!!!" << endl;
    }
    else
    {
        cout << "You can't return a book which is not borrowed!" << endl;
    }
}

void Console::show_all()
{
    priority_queue<Library> libs;
    libs = this->service.get_all_libraries();
    while (!libs.empty())
    {
        Library p = libs.top();
        cout << p;
        libs.pop();
    }
}

void Console::show_borrowed_books()
{
    priority_queue<Library> libs;
    libs = this->service.get_all_borrowed_books();
    while (!libs.empty())
    {
        Library p = libs.top();
        cout << p;
        libs.pop();
    }
}

void Console::show_books_in_library()
{
    priority_queue<Library> libs;
    libs = this->service.get_all_books_in_library();
    while (!libs.empty())
    {
        Library p = libs.top();
        cout << p;
        libs.pop();
    }
}
void Console::menu()
{
    cout << endl;
    cout << "    ~~MENU~~" << endl;
    cout << endl;
    cout << "1. Add book" << endl;
    cout << "2. Show all" << endl;
    cout << "3. Borrow book" << endl;
    cout << "4. Return book" << endl;
    cout << "5. Show all borrowed books" << endl;
    cout << "6. Show all books in library" << endl;
    cout << "7. Exit" << endl;
}

void Console::print_menu()
{
    int op = 0;
    while (1 > 0)
    {
        this->menu();
        cout << "";
        cout << "Option: ";
        cin >> op;
        if (op == 1)
        {
            this->add_book();
        }
        else if (op == 2)
        {
            this->show_all();
        }
        else if (op == 3)
        {
            this->borrow_book();
        }
        else if (op == 4)
        {
            this->return_book();
        }
        else if (op == 5)
        {
            this->show_borrowed_books();
        }
        else if (op == 6)
        {
            this->show_books_in_library();
        }
        else if (op == 7)
        {
            break;
        }
    }
}