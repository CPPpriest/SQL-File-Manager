#include <mysql_driver.h>
#include <mysql_connection.h>

#include <cppconn/prepared_statement.h>
#include <cppconn/exception.h>

#include "SFM.h"

#define DB_HOST "tcp://localhost:3306"
#define DB_USER "priest"
#define DB_PASS "2011"
#define SCHEMA_STR "foldersDB"

int main() {

    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

    std::string pathSTR = "";
    std::cout << "Path to directory:";
    std::cin >> pathSTR;

    try {
        // Create a MySQL driver object
        driver = sql::mysql::get_mysql_driver_instance();

        // Establish a MySQL connection
        con = driver->connect(DB_HOST, DB_USER, DB_PASS);

        // Select a database
        con->setSchema( SCHEMA_STR );


//----------Modify DB---------------------------//
        std::string insertQuery = "INSERT INTO paths (path) VALUES (?)";
        sql::PreparedStatement* prep_stmt = con->prepareStatement(insertQuery);

        //---------Traversal----------------------//
                std::string pathString = pathSTR;
                SFM m1(pathString);
                m1.traverse(pathString, prep_stmt);
        //----------------------------------------------------------------------------//

        //prep_stmt->setString(1, "Hello World");  // Example data

        //prep_stmt->executeUpdate();

        // delete statement


//----------------------------------------------//




        // Close the connection
        delete con;

        std::cout << "Connected to MySQL and performed operations successfully." << std::endl;
    } catch (sql::SQLException &e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }

    return 0;
}
