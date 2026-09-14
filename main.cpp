#include<iostream> 
#include "LOG.h" 



Log::Logger Console("log.log" ,true) ;


int main () {

    Console.log_file("fuck" , Level ::INFO) ;

}