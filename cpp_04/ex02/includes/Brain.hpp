#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain {
private:
    std::string	ideas_[100];

public:

    Brain();
    Brain( const Brain& other );
    Brain& operator=( const Brain& other );
    ~Brain();

    void				setIdea( int index, const std::string& idea );
    const std::string&	getIdea( int index ) const;
};

#endif