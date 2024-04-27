
# SQL File Manager

## Purpose of the Project
The SQL File Manager is a tool designed to traverse a specified directory recursively and insert all file paths into a MySQL database. This utility is intended to help in managing and indexing file systems.

## Getting Started

### Prerequisites
Before you start, ensure you have the following installed on your system:
- MySQL Connector/C++
- CMake (version 3.10 or higher recommended)
- GNU build essentials for compiling C++ code

### Database Setup
1. **MySQL Installation**: Make sure MySQL is installed and running on your system.
2. **Database Creation**: Create a MySQL database named `foldersDB`.
3. **Table Creation**:
   - Connect to your MySQL server: `sudo mysql -u root -p`
   - Run the following SQL commands:
     ```sql
     CREATE DATABASE IF NOT EXISTS foldersDB;
     USE foldersDB;
     CREATE TABLE paths (
         path VARCHAR(255) NOT NULL
     );
     ```

### Configuration
1. **Include Directory**: Update the `include_directories` in `CMakeLists.txt` to reflect the correct path to `cppconn`:
   ```cmake
   include_directories(include /path/to/cppconn)
   ```
2. **Database Connection**: Modify the database connection details in `main.cpp` to match your MySQL setup:
   ```cpp
   #define DB_HOST "tcp://localhost:3306"
   #define DB_USER "yourUsername"
   #define DB_PASS "yourPassword"
   ```

### Building the Project
1. Navigate to your project directory:
   ```bash
   cd SQL-File-Manager
   ```
2. Create and move into the build directory:
   ```bash
   mkdir build && cd build
   ```
3. Generate the Makefile using CMake and compile the project:
   ```bash
   cmake ..
   make
   ```

## Running the Program
1. **Start the MySQL Server**:
   ```bash
   sudo systemctl start mysql
   ```
2. **Execute the Program**:
   ```bash
   ./SQL-File-Manager
   ```
   When prompted, enter the path to the directory you wish to index.

3. **Stop the MySQL Server** (if no longer needed):
   ```bash
   sudo systemctl stop mysql
   ```

## Dependencies
This project relies on the following libraries and tools:
- `lmysqlcppconn` for MySQL connectivity
- CMake for managing the build process
- Build essentials for compiling the project

## Understanding the Database
To view and manage the database, use the following commands:
```bash
sudo mysql -u root -p
SHOW DATABASES;
USE foldersDB;
```

## Future Improvements
In future versions, the application will feature a graphical user interface (GUI) for managing database connections and queries, thereby simplifying the user experience and enhancing accessibility.
