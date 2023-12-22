#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <vector>

using namespace std;


std::string getCurrentDateTime() {
    // Aktuelle Zeit im system_clock (meistens Unix Zeit)
    auto now = std::chrono::system_clock::now();

    // Konvertieren in time_t für die Umwandlung in lokale Zeit
    auto now_c = std::chrono::system_clock::to_time_t(now);

    // Erstellen eines stringstream Objekts
    std::stringstream ss;

    // Verwenden von put_time, um Datum und Uhrzeit im gewünschten Format zu formatieren
    ss << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");

    // String zurückgeben
    return ss.str();
}



class Logger
{
    protected:
        string name;
        int msg_counter;


    public:

        // Konstruktor der Klasse
        Logger(string n)
        {
            name = n;            
            msg_counter = 0;

            cout << "Logger constructor called." << endl;
        }

        // Eine weitere Methode
        virtual void logmsg(string txt) = 0;
       
        // Destruktor
        virtual ~Logger() {

        }

};


class LoggerFile : public Logger
{
    private:
    
        ofstream outfile;
        string   logfname;

    public:

        LoggerFile(string n, string logfilename) : Logger(n)
        {
            cout << "LoggerFile constructor called." << endl;
            outfile.open( logfilename );
            logfname = logfilename;
        }

        void logmsg(string txt)
        {
            string currentDateTime = getCurrentDateTime();
            outfile << name << " | " << currentDateTime << " - " << txt << endl;
            msg_counter++;
        }

        ~LoggerFile()
        {
            cout << "Schließe die Logdatei " << logfname << endl;
            outfile.close();
        }


};

class LoggerHTML : public Logger
{
    private:
    
        ofstream outfile;
        string   logfname;

    public:

        LoggerHTML(string n, string logfilename, string websitename) : Logger(n)
        {
            cout << "LoggerHTML constructor called." << endl;
            outfile.open( logfilename );
            logfname = logfilename;

            outfile << "<!DOCTYPE html>\n";
            outfile << "<html>\n";
            outfile << "   <head>\n";
            outfile << "     <title>\n";
            outfile << "         " << websitename << "\n";
            outfile << "     </title>\n";
            outfile << "   </head>\n";
            outfile << "   <body>\n";
            
        }

        
        void logmsg(string txt)
        {
            string currentDateTime = getCurrentDateTime();
            outfile << "\t\t\t<p>" << 
                       name << 
                       " | " <<
                       currentDateTime <<
                       " - " << 
                       txt <<
                       "</p>" << endl;
            msg_counter++;
        }

        ~LoggerHTML()
        {            
            cout << "Schließe die Logdatei / HTML-Datei " << logfname << endl;

            outfile << "   </body>\n";
            outfile << "</html>\n";
            outfile.close();
        }


};



int main()
{
  
   
    /*
    Logger* p = new Logger("L1");
    p->logmsg("Hallo! Ich bin die Ausgabe aus der Basisklasse.");
    */

    

    //LoggerFile* ptr_l1 = new LoggerFile("L1", "logfile.txt");
    Logger* ptr_l1 = new LoggerHTML("L1",
                                    "logfile.html",
                                    "Dies ist eine Beispiel Logdatei in HTML!!!");
    ptr_l1->logmsg("Programm wird gestartet!");

    for (int i=1; i<=5; i++)
    {
        ptr_l1->logmsg( to_string(i) + " --> " + to_string(i*i) );
    }

    delete ptr_l1;
    

    //l1->name = "Ätschibätch! Ich gebe dir einen anderen Name";

    /*
    for (int i=0; i<5; i++)
        l1->logmsg( to_string(i) );

    l1->logmsg("Programm wird beendet!");
    */
}