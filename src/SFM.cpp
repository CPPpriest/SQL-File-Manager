#include "SFM.h"

// Constructor
SFM::SFM(std::string pathString):pathStr(pathString){}

// Traversal
void SFM::traverse(FS::path dirPath, sql::PreparedStatement* stmt){
	std::vector<FS::path> dirs;

	std::cout << "directory: " << dirPath.filename() << std::endl ;
	for(auto& entry : FS::directory_iterator(dirPath) )
	{
		if(! entry.is_directory() )
		{
			//std::cout << "file: " << entry.path().filename() << std::endl;
			std::string fileName = entry.path().filename().string();
      stmt->setString(1, fileName);
      stmt->executeUpdate();
      std::cout << "Inserted: " << fileName << std::endl;
		}
		else
			dirs.push_back(entry.path());
	}

	for(auto& directoryPath : dirs)
	{
		traverse( directoryPath, stmt);
	}

}

// Destructor
SFM::~SFM(){}
