#include "compact.h"

void compact::lz78::rdpam( std::string buf, const int mode )
{
    if( mode == compact::lz78::ENC )
        compact::lz78::buf = compact::lz78::en(buf);
    else if( mode == compact::lz78::DEC )
        compact::lz78::buf = compact::lz78::dec(buf);
}

void compact::lz78::rdin( const int mode )
{
    std::string joined;
    std::string temp;
    while( std::getline( std::cin, temp, (char)EOF ) ) joined += temp;
    if( mode == compact::lz78::ENC )
        compact::lz78::buf = compact::lz78::en(joined);
    else if( mode == compact::lz78::DEC )
        compact::lz78::buf = compact::lz78::dec(joined);
}

int compact::lz78::has( std::string k )
{
    if( dictionary.size() == 0 || k.empty() ) return 0;
    // std::cout << "looking for " << k << std::endl;
    int i = 0;
    do{
        if( dictionary[i].compare(k) == 0 ) break;
        i++;
    }while( i < dictionary.size() );
    if( i == dictionary.size() ) i = -1;
    return i+1;
}

std::string compact::lz78::en( std::string buf )
{
    int i = 0;
    buf.append(1,'\n');
    std::string bufmem;
    std::string code;
    int ibuf;
    do{
        std::string tostr;
        tostr.push_back( buf[i] );//(buf[i] == '\n' ? 37:buf[i]) );
        if( ibuf = compact::lz78::has( bufmem+tostr ) == 0 ){
            dictionary.push_back(bufmem+tostr);
            // std::cout << "adicionando " << dictionary[dictionary.size()-1] << std::endl;
            code.append(std::to_string(compact::lz78::has(bufmem)));
            code += tostr;
            bufmem.clear();
        }else{
            bufmem += tostr;
        }
        i++;
    }while( i < buf.size() );
    
    // for( int i = 0; i < dictionary.size(); i++ )
        // std::cout << i+1 << "- " << dictionary[i] << std::endl;
    return code;
}

std::string compact::lz78::dec( std::string buf )
{
    std::string dec;
    std::istringstream convlong( buf );
    while( !convlong.eof() )
    {
        long int idict;
        convlong >> idict;
        std::string ctos;
        char c;
        convlong >> std::noskipws >> c;
        if( convlong.eof() ) break;
        ctos.append(1,c);//(c == 37 ? '\n':c));

        std::cerr << "pos: " << idict << std::endl;
        std::cerr << "char: " << ctos << std::endl;

        std::string tocode;
        if( idict != 0 ){
            tocode = compact::lz78::dictionary[idict-1];
            tocode += ctos;
            compact::lz78::dictionary.push_back(tocode);
        }else{
            tocode = ctos;
            compact::lz78::dictionary.push_back(tocode);
        }
        //a7a0i11c2r2i
        std::cerr << "adicionando " << tocode << std::endl;
        dec += tocode;
    }
    return dec;
}