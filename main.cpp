#include "Logging.hpp"

using namespace Log ;


/*--------- Basic Usage -----------*/
int main () {
    logging log("Log.txt",true) ; 

    log.log_file("HELLO" , LEVEL :: INFO) ;
    Log :: log_console("Operation Running Normally ",LEVEL::INFO) ;
}