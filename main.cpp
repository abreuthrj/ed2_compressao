#include <iostream>
#include "_inc/compact.h"

int main( int argc, char** argv )
{
    std::ofstream debug("debug.txt");
    std::cerr.rdbuf( debug.rdbuf() );
    if( argc > 1 ){
        compact::lz78 encoder;
        if(std::string(argv[1]).compare("encode") == 0){
            if( argc > 2 ){
                std::ifstream input( argv[2] );
                std::cin.rdbuf( input.rdbuf() );
                encoder.rdin( compact::lz78::ENC );
                std::cout << encoder.buf;
            }else{
                std::string text;
                std::getline( std::cin, text );
                // std::cout << text;
                // std::cin >> text;
                encoder.rdpam(text,compact::lz78::ENC);
                std::cout << encoder.buf;
            }
        }else{
            if(std::string(argv[1]).compare("decode") == 0){
                if( argc > 2 ){
                    std::ifstream input( argv[2] );
                    std::cin.rdbuf( input.rdbuf() );
                    encoder.rdin(compact::lz78::DEC);
                    std::cout << encoder.buf;
                }else{
                    std::string text;
                    std::getline( std::cin, text );
                    // std::cin >> text;
                    encoder.rdpam(text,compact::lz78::DEC);
                    std::cout << encoder.buf;
                }
            }else if( std::string(argv[1]).compare("help") == 0 ){
                std::cout << "action = Pode ser encode/decode.\n"
                          << "?file = Caso passado um arquivo destino, a leitura sera a partir dele.\n"
                          << "A impressao sera feita na tela, para imprimir em um arquivo, use \"program <action> <?file> > destino.txt\"\n";
                return 0;
            }else{
                std::cout << "Invalid action\n";
                return 1;
            }
        }
    }
    else{
        std::cout << "Missing params: program <action> <?file>  or  program help\n";
    }

    return 0;
}