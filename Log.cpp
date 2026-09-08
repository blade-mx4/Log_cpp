// #include "LOG.h" 
#include<iostream>
#include<format>
#include<filesystem>
#include<fstream>
#include<chrono>

namespace os = std :: filesystem ; 

/* --------- Configs and Hyper Param--------- */


enum class Level{ // i shall add log level no when the need arises , dont really see the use to add them 
    INFO ,
    DEBUG ,
    WARNING ,
    ERROR , 
    CRITICAL ,

}  ;

/*  ---------- Create File Function ------------
    Handles all function for file creation 
*/
os ::path create_log(std :: string file_name) {
    
    auto time = std :: chrono::system_clock::now() ;

    os::path cwd_dir = os::current_path() ;
    os::path log_folder = cwd_dir / "LOG" ;

    if (!os :: exists(log_folder)) {
        os :: create_directory(log_folder)  ;
    }

    std::ofstream LOG_FILE (log_folder/file_name) ; // creates file 

    try {
        if (!LOG_FILE) {
            throw std :: runtime_error("FILE OPERATION ERROR") ;
            
        }

        std::fstream LOG_FILE_WRITE(log_folder/file_name) ; // write to created file basically for beautification and small feature up scale 
        std::string LOG_WRITE = std :: format ("LOG STARTED  @ DATE / TIME : {}",time);
        LOG_FILE_WRITE << LOG_WRITE <<'\n';
    }
    catch(std :: runtime_error &Error) {
        std :: cerr << "ERROR -> "<<Error.what() ; 
    }
    return log_folder / file_name ; // returns path if everything goes as planed 

}


/* ------------------------- Functions to help the main functions ----------------------- */

namespace LOG_HELPER {
    void LOG_FILE(os::path &log_file_path ,std :: string &message , std::string warning_level) {
    /* LOG_FILE :
       - take the path to the file and append the message 
    */
        auto time = std :: chrono::system_clock::now() ;
        std :: ofstream File(log_file_path , std ::ios::app) ; // Openfile to be appended 

        try {
            if (!File) {
                throw std :: runtime_error("FILE DOESNT EXISTS ") ;
            }
            std::string LOG_INFO = std::format("TIME :{} | {} :[{}] ",time,warning_level,message) ;
            File << LOG_INFO << '\n';

        }
        catch(std ::exception &Error) {
            std::cerr <<"ERROR -> "<<Error.what(); 
           
        }
        File.close() ;
    }
    std ::string console_level (Level &level ) { 
    /*console_level
      - takes the enum defined level and mapps it to a string then return is     
    */
    try {
        switch(level) {/*-------------- elegance ------------------*/
            case Level :: INFO     : return "INFO"    ;          
            case Level :: DEBUG    : return "DEBUG"   ;   
            case Level :: ERROR    : return "ERORR"   ;   
            case Level :: WARNING  : return "WARNING" ;   
            case Level :: CRITICAL : return "CRITICAL";  
            default : throw std :: runtime_error("UNKNOWN VALUE PASED "); return " UNKNOWN ERROR TYPE " ;
        }
    }
    catch (std :: runtime_error &e ){std ::cerr << "ERROR : " << e.what() ;  return ""; }
    }

    void LOG_CONSOLE(std ::string &messages , std ::string &warning_level){ 
        /*LOG_CONSOLE 
            Simple Logging to console helper 
        */
        std :: string console_log = std :: format("{} : {} ",warning_level,messages);
        std::cerr << console_log << '\n' ;
    }

    void LOG_EXCEPTION (os::path log_file_path ,std :: exception & error ,Level level = Level::ERROR ) {
        /*LOG_EXCEPTION
            - function to help the method to log exception

        */
        
        auto time = std :: chrono::system_clock::now() ;
        std :: ofstream File(log_file_path , std ::ios::app) ; 

        try {
            if (!File) {
                throw std :: runtime_error("FILE DOESNT EXISTS ") ;
            }
            std :: string warning_level = LOG_HELPER ::console_level(level) ;
            std::string LOG_INFO = std::format("TIME :{} | {} :[{}] ",time,warning_level,error.what()) ;
            File << LOG_INFO << '\n';

        }
        catch(std ::exception &Error) {
            std::cerr <<"ERROR -> "<<Error.what(); 
           
        }
        
        File.close() ;
    }
    


}

namespace Log{
    std :: string file_name = "text.log" ;
    bool to_console  ;

    void log_file(std:: string message ,Level level) {
        /*log_file
            main methos to log to file  and console if to_console set to true 

        */
        os :: path log_file_path = create_log(file_name); //gets the file path from the create_file function
        
        std::string  warning_level = LOG_HELPER::console_level(level);  
        LOG_HELPER::LOG_FILE(log_file_path,message,warning_level) ;

        if (to_console == true ) {
            LOG_HELPER::LOG_CONSOLE(message , warning_level) ;
        }    
    }

    void log_console(std::string message , Level level ){
        /*log_console 
        - main method for writing to console only 
        */
        std::string  warning_level = LOG_HELPER::console_level(level);  
        LOG_HELPER :: LOG_CONSOLE(message ,warning_level) ;
    
    }

    void log_exception(std:: exception &e){
        /*
        
        */
        os::path log_file_path = create_log(file_name) ;
        LOG_HELPER ::LOG_EXCEPTION(log_file_path ,e) ;
    }

}






int main () {
    Log::to_console = false ;
    Log::log_file("HELLO" ,Level::INFO) ;

    int y = 1 ;

    try {
        if (y < 10 ){
            throw std :: runtime_error("LESS") ;
        }
    }
    catch(std :: exception &e) {
        
        Log::log_exception(e) ;

    }
    
}
