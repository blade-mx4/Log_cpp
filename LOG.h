#pragma once 
#include<iostream>
#include<filesystem>

namespace os = std::filesystem ;

enum class Level{ // i shall add log level no when the need arises , dont really see the use to add them 
    INFO ,
    DEBUG ,
    WARNING ,
    ERROR , 
    CRITICAL ,

}  ;



namespace Log {


    class Logger {
        public : 
            std :: string file_name ;
            bool to_console ;

        void log_file(std::string message , Level level) ;

    }









}
