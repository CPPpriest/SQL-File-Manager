#ifndef SFM_MASTER_FILE
#define SFM_MASTER_FILE

#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

class Master{
  private:
      fs::path mp;

  public:
      Master(std::string pathString);
      void traverse(fs::path p, std::string tabs);
      ~Master();
};

#endif
