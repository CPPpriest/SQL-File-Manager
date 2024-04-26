#ifndef SFM_HEADER_FILE
#define SFM_HEADER_FILE

#include <string>
#include <iostream>
#include <vector>
#include <filesystem>

#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>

namespace FS = std::filesystem;

class SFM{
  private:
      FS::path pathStr;

  public:
      SFM(std::string pathString);
      void traverse(FS::path dirPath, sql::PreparedStatement* stmt);
      ~SFM();
};


#endif
