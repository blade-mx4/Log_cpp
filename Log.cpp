/*------------------- WRITTEN BY VICTOR AGU ------------------ */
/* 
MY FIRST C++ Library 
NO AI WAS USED IN THE PRODUCTION OF THIS CODE 

*/
#include<iostream>
#include<format>
#include<filesystem>
#include<fstream>
#include<chrono>
#include "LOG.h"


namespace os  = std :: filesystem ;

// ==== Configs and Hyper Params ==== //
os :: path cwd = os :: current_path() ;

// enum class LEVEL{ // i shall add log level no when the need arises , dont really see the use to add them 
//     INFO ,
//     DEBUG ,
//     WARNING ,
//     ERROR , 
//     CRITICAL ,

// }  ;

// =========================== HELPER FUNCTIONs ========================================== //
namespace Log_Function {
    // void file_create(fstream &File ) { // 
    //     try {
    //     // create file empty file 
    //     if (File){
    //         File << " ================= LOG FILE ===================== "<<'\n' ;
    //         cout<< "INFO : -> [ FILE CREATED ] " ; //return true ;
    //     }
        
    //     if(!File) {
    //         throw runtime_error(" [ Opening File ]")  ;
    //        // return false ;        
    //         }
    //     }
    //     catch(runtime_error &e ) {
    //         cerr << "ERROR : " << e.what() << '\n';
    //         //return false ;
    //     } 
    // }

    void LOG_FILE(os :: path &File , std :: string &message , std :: string &warning_level ) { // openfile and append to it function 

        std ::fstream file (File , std::ios ::app) ; 

        auto time = std :: chrono ::system_clock::now() ;
        try {

        if (!file) {
            throw std :: runtime_error (" FILE NOT FOUND ") ;
        }
        else {
            std::string message_formated = std :: format ("TIME : {} | {} :[  {}  ] ",time ,warning_level,message);
            file <<message_formated <<'\n';
            }
        }catch(std :: runtime_error &e){
            std::cerr << "ERROR " << e.what() << '\n'; 
        }
        
    }
    std ::string console_level (LEVEL &level ) { /*------ Converts log levels to string -----------*/
        try {
            switch(level) {/*-------------- elegance ------------------*/
                case LEVEL :: INFO     : return "INFO"    ;          
                case LEVEL :: DEBUG    : return "DEBUG"   ;   
                case LEVEL :: ERROR    : return "ERORR"   ;   
                case LEVEL :: WARNING  : return "WARNING" ;   
                case LEVEL :: CRITICAL : return "CRITICAL";  
                default : throw std :: runtime_error("UNKNOWN VALUE PASED "); return " UNKNOWN ERROR TYPE " ;
            }
        }
        catch (std :: runtime_error &e ){std ::cerr << "ERROR : " << e.what() ;  return ""; }
    }

    void LOG_CONSOLE (std::string &message , std::string &level) { // Function to log to console and not file  
        std :: string console_log = std :: format("{} : {} ",level,message);
        std::cerr << console_log << '\n' ;
    }
}

/*--------------------MAIN LOGGING FUNCTION------------------ */

namespace Log { 
    // class Logger{
    //     public : //basically i dont really see the ude of adding private for the filenames cause it just a logging library right ? 
    //         std ::string filename ; 
    //         bool to_console ;

    void Logger::log_file(std ::string message , LEVEL level ){ // Saving to file     
        /*

        Use implement method outside class 
        decleare the method under the class  in header file 
        and define the class in the function file {for my ass in case if forget }

        */
        os :: path log_dir = "LOG" ;
        os :: path  log_folder = cwd / log_dir ; //path -> cwd / LOG 

        if (! os :: exists(log_folder)) {
            os :: create_directory(log_folder) ;
        }
        std ::fstream File(log_dir/filename) ;

        os :: path file_append = log_folder /filename ; // path to log file 
        std::string  warning_level= Log_Function :: console_level(level) ;
        Log_Function::LOG_FILE(file_append ,message , warning_level) ; //    
        
        if (to_console == true ){ // log to console if true 
            Log_Function ::LOG_CONSOLE(message , warning_level) ;
        } 
    }
        // }; 

    void log_console(std::string messages , LEVEL level_status) {// log to console level 
        std::string  warining_level = Log_Function :: console_level(level_status) ;
        Log_Function ::LOG_CONSOLE(messages , warining_level) ;
    }    
}

// // =================== Testing Area ======================= //
// int main () { 

//     Log :: logging log("log.txt" ,false) ;
//     string mesage = "Hellfdfdfosdsd" ;
//     string mes_age = "Hsasasdsdsdsa" ;

//     log.log_file(mesage,LEVEL :: INFO) ;
//     log.log_file(mes_age , LEVEL::DEBUG) ;
//     Log ::log_console("FUCK",LEVEL::INFO) ;

// }