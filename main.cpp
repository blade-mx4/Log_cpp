#include<iostream> 
#include "LOG.h" 

using namespace Log ;


Log::Logger Console("Log.txt",true) ;

int main () {

    Console.log_file("FUCK",LEVEL ::INFO) ;

}