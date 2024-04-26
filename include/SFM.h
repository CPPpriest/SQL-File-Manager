#ifndef SFM_HEADER_FILE
#define SFM_HEADER_FILE

#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

namespace FS = std::filesystem;

class SFM{
  private:
      FS::path pathStr;

  public:
      SFM(std::string pathString);
      void traverse(FS::path dirPath, std::string tabs);
      ~SFM();
};


#endif
