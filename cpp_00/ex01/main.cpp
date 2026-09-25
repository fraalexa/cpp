#include "./includes/phonebook.hpp"

int main(void) {
    PhoneBook phoneBook;

    std::cout << "Welcome to Phonebook app.\n"
              << "Write an option (ADD, SEARCH, EXIT): ";

    std::string prompt;
    while (std::getline(std::cin, prompt)) {
        prompt = trim(prompt);

        if (prompt == "ADD") {
            phoneBook.addContact();
        } else if (prompt == "SEARCH") {
            phoneBook.searchContact();
        } else if (prompt == "EXIT") {
            break;
        } else if (!prompt.empty()) {
            std::cout << "Invalid option. Please enter ADD, SEARCH, or EXIT.\n";
        }

        std::cout << "Write an option (ADD, SEARCH, EXIT): ";
    }

    if (std::cin.eof()) {
        std::cout << '\n';
    }

    return 0;
}