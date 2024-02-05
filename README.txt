#server
sudo systemctl start mysql
sudo systemctl stop mysql


#compilation
g++ -o test test.cpp -lmysqlcppconn


#run
./test


#push to origin
git push origin master



