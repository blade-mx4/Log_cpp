#pragma once 



#include<iostream>
#include<filesystem>

namespace os = std ::filesystem ;

enum class LEVEL{ // i shall add log level no when the need arises , dont really see the use to add them 
    INFO ,
    DEBUG ,
    WARNING ,
    ERROR , 
    CRITICAL ,

}  ;

namespace Log_Function {
    void LOG_FILE(os ::path &File ,std ::string &message,std :: string &warning_level);   
    void LOG_CONSOLE(std::string &message,std ::string &level);
    std :: string console_level(LEVEL &level) ;

}

namespace Log {
    class Logger { 
        public :     
            std :: string filename ;
            bool to_console ;

        void log_file(std :: string message , LEVEL level) ;
        void log_console(std :: string message , LEVEL level);

    } ;
} 