#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

bool isNumber(const std::string &str) {
    if (str.empty()) {
        return false;
    }
    for (std::string::size_type i = 0; i < str.length(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(str[i]))) {
            return false;
        }
    }
    return true;
}

std::string trim(const std::string &s) {
    const std::string::size_type size = s.size();
    std::string::size_type start = 0;
    std::string::size_type end = size;

    while (start < size && std::isspace(static_cast<unsigned char>(s[start]))) {
        start++;
    }
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1]))) {
        end--;
    }
    return s.substr(start, end - start);
}

bool get_input(const std::string &label, std::string &result, bool require_number) {
    while (true) {
        std::cout << label;
        if (!std::getline(std::cin, result)) {
            return false;
        }
        result = trim(result);

        if (result.empty()) {
            std::cout << "Please fill the field to continue...\n";
            continue;
        }
        if (require_number && !isNumber(result)) {
            std::cout << "Only numbers allowed!\n";
            continue;
        }
        break;
    }
    return true;
}

bool Contact::NewContact() {
    if (!get_input("First name: ", first_name_, false)) return false;
    if (!get_input("Last name: ", last_name_, false)) return false;
    if (!get_input("Nickname: ", nickname_, false)) return false;
    if (!get_input("Phone number: ", phone_number_, true)) return false;
    if (!get_input("Tell me a darkest secret ('-'): ", secret_, false)) return false;
    return true;
}

static std::string formatColumn(const std::string &str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void Contact::printContact(size_t idx) const {
    std::cout << '|' << std::setw(10) << idx
              << '|' << std::setw(10) << formatColumn(first_name_)
              << '|' << std::setw(10) << formatColumn(last_name_)
              << '|' << std::setw(10) << formatColumn(nickname_)
              << "|\n";
}

void Contact::printContactDetailed() const {
    std::cout << "First name: "   << first_name_   << '\n'
              << "Last name: "    << last_name_    << '\n'
              << "Nickname: "     << nickname_     << '\n'
              << "Phone number: " << phone_number_ << '\n'
              << "Secret: "       << secret_       << '\n';
}