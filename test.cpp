#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>

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

        // Execute SQL queries and process results here

        // Close the connection
        delete con;

        std::cout << "Connected to MySQL and performed operations successfully." << std::endl;
    } catch (sql::SQLException &e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }

    return 0;
}

