#include "SFM.h"

// Constructor
SFM::SFM(std::string pathString):pathStr(pathString){}

// Traversal
void SFM::traverse(FS::path dirPath, std::string tabs){
	std::vector<FS::path> dirs;

	std::cout << tabs << "directory: " << dirPath.filename() << std::endl ;
	tabs = tabs + "\t";
	for(auto& entry : FS::directory_iterator(dirPath) )
	{
		if(! entry.is_directory() )
		{
			std::cout << tabs << "file: " << entry.path().filename() << std::endl;
		}
		else
			dirs.push_back(entry.path());
	}

	for(auto& directoryPath : dirs)
	{
		traverse( directoryPath , tabs );
	}

}

// Destructor
SFM::~SFM(){}
