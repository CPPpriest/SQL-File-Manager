#include <mysql_driver.h>
#include <mysql_connection.h>

#include "SFM.h"
#include "Master.h"

int main() {

    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

    try {
        // Create a MySQL driver object
        driver = sql::mysql::get_mysql_driver_instance();

        // Establish a MySQL connection
        con = driver->connect("tcp://localhost:3306", "priest","2011");

        // Select a database
        con->setSchema("foldersDB");

//---------Execute SQL queries and process results here-----------------------//

        std::cout  <<  MACINTOSH << std::endl;

        std::string pathString = "/home/priest/Desktop/sampleFolder";
        Master m1(pathString);

        std::string tabs = "";
        m1.traverse(pathString,tabs);
        // Create Query object for the instance

        // Call evaluator process

        // Delete Query object



//----------------------------------------------------------------------------//


        // Close the connection
        delete con;

        std::cout << "Connected to MySQL and performed operations successfully." << std::endl;
    } catch (sql::SQLException &e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }

    return 0;
}
