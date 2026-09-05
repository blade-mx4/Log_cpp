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
inline os :: path cwd = os :: current_path() ; // using inline to avoid breaking the one definintion rule 

enum class LEVEL{ // i shall add log level no when the need arises , dont really see the use to add them 
    INFO ,
    DEBUG ,
    WARNING ,
    ERROR , 
    CRITICAL ,

}  ;

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

    inline void LOG_FILE(os :: path &File , string &message , string &level ) { // openfile and append to it function 

        fstream file (File , ios ::app) ; 
        // string warning_level ;

        auto time = chrono ::system_clock::now() ;

        // if(level == LEVEL :: INFO ) {
        //     warning_level = "INFO " ;
        // }
        // else if (level == LEVEL ::DEBUG) {
        //     warning_level = "DEBUG " ;
        // }
        // else if (level == LEVEL :: WARNING ) {
        //     warning_level =  "WARNING " ;

        // }
        // else if (level == LEVEL ::ERROR) {
        //     warning_level = "ERROR : " ;
        // }
        // else if (level == LEVEL ::CRITICAL) {
        //     warning_level = "CRITICAL : " ;
        // }
        try {

        if (!file) {
            throw std :: runtime_error (" FILE NOT FOUND ") ;
        }
        else {
            string message_formated = std :: format ("TIME : {} | {} :[  {}  ] ",time ,level ,message);
            file <<message_formated <<'\n';
            }
        }catch(std :: runtime_error &e){
            cerr << "ERROR " << e.what() << '\n'; 
        }
        
    }
    inline string LOG_LEVEL (LEVEL &level ) { /*------ Converts log levels to string -----------*/
        try {
            switch(level) {/*-------------- elegance ------------------*/
                case LEVEL :: INFO     : return "INFO"    ;  break ;        
                case LEVEL :: DEBUG    : return "DEBUG"   ;  break ; 
                case LEVEL :: ERROR    : return "ERORR"   ;  break ; 
                case LEVEL :: WARNING  : return "WARNING" ;  break; 
                case LEVEL :: CRITICAL : return "CRITICAL";  break ;
                default : throw std :: runtime_error("UNKNOWN VALUE PASED "); break ;
            }
        }
        catch (std :: runtime_error &e ){
            cerr << "ERROR : " << e.what() ;  
            return "UNKNOWN";
        }
    }

    inline void LOG_CONSOLE (string &message , string &level) { // Function to log to console and not file  
        std :: string console_log = std :: format("{} : {} ",level,message);
        cerr << console_log << '\n' ;
    }
}
namespace Log { 
    class logging {
        public : //basically i dont really see the ude of adding private for the filenames cause it just a logging library right ? 
            string filename ; 
            bool log_console ;

           inline  void log_file(string message , LEVEL level ){ // Saving to file     
                os :: path log_dir = "LOG" ;
                os :: path  log_folder = cwd / log_dir ; //path -> cwd / LOG 

                if (! os :: exists(log_folder)) {
                    os :: create_directory(log_folder) ;
                }
                fstream File(log_dir/filename) ;
                //file_create(File) ; // create file
 
                os :: path file_append = log_folder /filename ; // path to log file 
                string  _level_ = Log_Function :: LOG_LEVEL(level) ;
                Log_Function::LOG_FILE(file_append ,message , _level_) ;           
                
                if (log_console == true ){ // log to console if true 
                   Log_Function ::LOG_CONSOLE(message , _level_) ;
                } 
            }
        }; 

    inline void log_console(string messages , LEVEL level) {// log to console level 
        string  _level_ = Log_Function :: LOG_LEVEL(level) ;
        Log_Function ::LOG_CONSOLE(messages , _level_) ;
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