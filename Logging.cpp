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
using namespace std ;
namespace os  = std :: filesystem ;


// ==== Configs and Hyper Params ==== //


os :: path cwd = os :: current_path() ;


fstream f;

enum class LEVEL{ // i shall add log level no when the need arises , dont really see the use to add them 
    INFO ,
    DEBUG ,
    WARNING ,
    ERROR , 
    CRITICAL ,

}  ;


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

void append_file(os :: path &File , string &message , LEVEL &level ) { // openfile and append to it function 

    fstream file (File , ios ::app) ; 
    string warning_level ; 
    auto time = chrono ::system_clock::now() ;

    if(level == LEVEL :: INFO ) {
        warning_level = "INFO " ;
    }
    else if (level == LEVEL ::DEBUG) {
        warning_level = "DEBUG " ;
    }
    else if (level == LEVEL :: WARNING ) {
        warning_level =  "WARNING " ;

    }
    else if (level == LEVEL ::ERROR) {
        warning_level = "ERROR : " ;
    }
    else if (level == LEVEL ::CRITICAL) {
        warning_level = "CRITICAL : " ;
    }
    try {

    if (!file) {
        throw std :: runtime_error (" FILE NOT FOUND ") ;
    }
    else {
        string message_formated = std :: format ("TIME : {} | {} [  {}  ]",time ,warning_level ,message);
        file <<message_formated <<'\n';
        }
    }catch(std :: runtime_error &e){
        cerr << "ERROR " << e.what() << '\n'; 
    }
    
}
void LOG_CONSOLE (string &message , LEVEL &level) { // Function to log to console and not file  
    
}
namespace LOG {

    class logging {
        public : //basically i dont really see the ude of adding private for the filenames cause it just a logging library right ? 
            string filename ; 
            bool log_console ;

            void log_file(string &message , LEVEL level ){ // for file saving only first 
               
                os :: path log_dir = "LOG" ;
                os :: path  log_folder = cwd / log_dir ; //path -> cwd / LOG 

                if (! os :: exists(log_folder)) {
                    os :: create_directory(log_folder) ;
                }
                fstream File(log_dir/filename) ;
                //file_create(File) ; // create file
                os :: path file_append = log_folder /filename ; // path to log file 

            
                if (level == LEVEL ::INFO ){
                append_file(file_append ,message, level ) ;     
                if (log_console == true ) {
                    cerr <<" INFO : " <<message << '\n' ; 
                    }
                }

                if (level == LEVEL ::DEBUG ) { 
                    append_file(file_append ,message, level ) ;
                                       
                    if (log_console == true ){
                        cerr <<" DEBUG : " <<message << '\n' ; 
                    }
                }
                if (level == LEVEL ::ERROR){
                    append_file(file_append ,message, level ) ;
                    if (log_console == true){
                        cerr <<" ERROR : " <<message << '\n' ;                        
                    }
                }
                if (level == LEVEL ::WARNING ){
                    append_file(file_append ,message, level ) ;
                    if (log_console == true){
                        cerr <<" WARNING : " <<message << '\n' ;                        
                    }
                }
                if (level == LEVEL ::CRITICAL){
                    append_file(file_append ,message, level ) ;
                    if(log_console ==true ){
                        cerr <<" CRITICAL : " <<message << '\n' ; 
                    }
                }
                
            }
    }; 

}


// =================== Testing Area ======================= //
int main () { 

    LOG :: logging log("text.txt" ,true) ;
    string mesage = "Hellfdfdfo" ;
    string mes_age = "Hsasasa" ;

    log.log_file(mesage,LEVEL :: INFO) ;
    log.log_file(mes_age , LEVEL::DEBUG) ;

}