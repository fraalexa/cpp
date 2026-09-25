#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <cstdlib>
#include <iostream>
#include <iomanip>

class Contact {
private:
    std::string first_name_;
    std::string last_name_;
    std::string nickname_;
    std::string phone_number_;
    std::string secret_;

public:
    Contact();
    ~Contact();

    bool NewContact();
    void printContactDetailed() const;
    void printContact(size_t idx) const;
};

std::string trim(const std::string& s);
bool        isNumber(const std::string& str);

#endif