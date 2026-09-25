#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class Harl {
public:
    Harl();
    ~Harl();

    void complain(const std::string& level);

private:
    void info( void );
    void debug( void );
    void warning( void );
    void error( void );
};

#endif