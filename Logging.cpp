#include<iostream>
#include<filesystem>
#include<fstream>
#include<ctime>

using namespace std ;
namespace os  = std :: filesystem ;


// ==== Configs and Hyper Params ==== //

time_t current_time = time(&current_time) ;
os :: path cwd = os :: current_path() ;
char *time_now = ctime(&current_time) ;

fstream f;

enum class LEVEL{
    INFO ,
    DEBUG ,
    WARNING , 
    CRITICAL ,

}  ;


bool file_create(fstream &File ) {
    try {
    // create file empty file 
    if (true) { 
        
        File << " ================= LOG FILE ===================== " ;
        cout<< "INFO : -> [ FILE CREATED ] " ;
        return true ; 
    }    
    else {
        throw runtime_error(" [ Opening File ]")  ;
        return false ;        
        }
    }
    catch(runtime_error &e ) {
        cerr << "ERROR : " << e.what() << '\n';
        return false ;
    } 

}

void append_file(os :: path &File , string &message , LEVEL &level ) { // openfile and append to it function 

    fstream file (File , ios ::app) ; 
    string warning_level ; 

    if(level == LEVEL :: INFO ) {
        warning_level = "INFO " ;
    }
    else if (level == LEVEL ::DEBUG) {
        warning_level = "DEBUG " ;
    }
    else if (level == LEVEL :: WARNING ) {
        warning_level =  "WARNING " ;

    }
    else if (level == LEVEL ::CRITICAL) {
        warning_level = "CRITICAL : " ;
    }
    try {

    if (!file) {
        throw std :: runtime_error (" FILE NOT FOUND ") ;
    }
    else {
        file << "TIME : " << time_now <<warning_level<<message << " ] "<< "\n" ;
        }
    }catch(std :: runtime_error &e){
        cerr << "ERROR " << e.what() << '\n'; 
    }
    
}


namespace LOG {

    class logging {
        public :
            string filename ; 
            bool log_console ;
        
            void log_file(string &message , LEVEL level ){ // for file saving only first 
               
                os :: path log_dir = "LOG" ;
                os :: path  log_folder = cwd / log_dir ;

                if (! os :: exists(log_folder)) {
                    os :: create_directory(log_folder) ;
                }

                fstream File(log_dir/filename) ;
                file_create(File) ; // create file
                
                os :: path file_append = log_folder /filename ; // path to log file 

                if (level == LEVEL ::INFO ){
                    
                    append_file(file_append ,message, level ) ;
                    
                    if (log_console == true ) {
                        File<<"TIME : " << time_now <<" INFO : [ " <<message << " ] "<< "\n" ;                
                        cerr <<" INFO : " <<message << '\n' ; 
                    }
                    else {
                        File<<"TIME : " << time_now <<" INFO : [ " <<message << " ] "<< "\n" ;                
                    }
                }
                // if (level == LEVEL ::DEBUG ) { 
                //     File<<"TIME : " << time_now <<" INFO : [ " <<message << " ] "<< "\n" ;
                    
                // }


            }
    }; 

}

int main () { 

    LOG :: logging log("text.txt" ,false) ;
    string mesage = "Hellfdfdfo" ;

    log.log_file(mesage,LEVEL :: INFO) ;


}