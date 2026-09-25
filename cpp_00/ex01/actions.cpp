#include "phonebook.hpp"

PhoneBook::PhoneBook() : count_(0), next_index_(0) {}

PhoneBook::~PhoneBook() {}

bool PhoneBook::addContact() {
    Contact contact;

    if (!contact.NewContact()) {
        return false;
    }

    if (count_ < 8) {
        contacts_[count_++] = contact;
    } else {
        contacts_[next_index_] = contact;
        next_index_ = (next_index_ + 1) % 8;
    }
    return true;
}

void PhoneBook::showContactList() const {
    std::cout << "|" << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|\n";

    for (size_t i = 0; i < count_; ++i) {
        contacts_[i].printContact(i);
    }
}

bool PhoneBook::searchContact() {
    if (count_ == 0) {
        std::cout << "Phonebook is empty!\n";
        return true;
    }

    showContactList();

    while (true) {
        std::string idx_string;

        std::cout << "Choose an index [0-" << (count_ - 1) << "] (or type 'exit'): ";
        if (!std::getline(std::cin, idx_string)) {
            return false;
        }

        idx_string = trim(idx_string);
        if (idx_string == "exit") {
            return true;
        }

        if (!isNumber(idx_string) || idx_string.empty()) {
            std::cout << "Numbers only!\n";
            continue;
        }

        int idx = std::strtol(idx_string.c_str(), NULL, 10);
        if (idx < 0 || idx_string.size() > 1) {
            std::cout << "Invalid index range.\n";
            continue;
        }

        if (static_cast<size_t>(idx) >= count_) {
            std::cout << "Contact not found.\n";
            continue;
        }

        const Contact& chosen = contacts_[idx];
        chosen.printContactDetailed();
        break;
    }
    return true;
}