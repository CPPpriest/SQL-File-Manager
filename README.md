# Dependencies:
	- lmysqlcppconn -mySQL connector
	- build_essentials
	- cmake

# Setup
1. Modify CMakeLists.txt  
Add mysqlcppconn path to "# Include directories" part

2. build:  
*SQL-File-Manager$* **cd build**    
*SQL-File-Manager/build$* **cmake ..**  
*SQL-File-Manager/build$* **make**

3. start mySQL server  
*$* **sudo systemctl start mysql**  
*$* **sudo systemctl status mysql**

4. run  
*SQL-File-Manager/build$* **./SQL-File-Manager**  
*Path to directory:* **/home/priest/Desktop/dummyFolder**

5. stop mySQL server  
*$* **sudo systemctl stop mysql**

# Properties of Final Version
- mySQL server and all modifications on code are removed and accessed via GUI. (Blackboxed)
- From the point the program is run, all files in the provided directory are available on mySQL server.

# How it suppose to work on the first version:
- User sets up the program and runs
- On the terminal, enters the user and password information
- On the terminal, specifies the path to directory
- All the files in the directory are available on mySQL Database

# Database  
*$* **sudo mysql -u root -p**  
*mysql>* **SHOW DATABASES;**  
*mysql>* **USE foldersDB;**
