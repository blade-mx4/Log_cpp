#include<iostream> 
#include "LOG.h" 

using namespace Log ;


Log::Logger Console("Lcxcog.txt",true) ;

int main () {

    Console.log_file("FUCxcxK",LEVEL ::INFO) ;
    Console.log_console("asas",LEVEL ::WARNING) ;
}