#ifndef COMPACT_H
#define COMPACT_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

namespace compact
{

    struct lz78
    {
        static const int DEC = 0;
        static const int ENC = 1;
        std::vector<std::string> dictionary;
        std::string buf;
        void rdpam( std::string, const int );
        void rdin( const int );
        int has( std::string );
        std::string en( std::string );
        std::string dec( std::string );
    };

}


#endif