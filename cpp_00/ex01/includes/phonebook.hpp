

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.hpp"
#include <iostream>

class PhoneBook {
private:
    Contact contacts_[8];
    size_t  count_;
    size_t  next_index_;

public:
    PhoneBook();
    ~PhoneBook();

    bool addContact();
    bool searchContact();
    void showContactList() const;
};

#endif