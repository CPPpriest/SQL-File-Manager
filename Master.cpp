#include "Master.h"

// Constructor
Master::Master(std::string pathString):mp(pathString){}

// Traversal
void Master::traverse(fs::path p, std::string tabs){
	std::vector<fs::path> dirs;

	std::cout << tabs << "directory: " << p.filename() << std::endl ;
	tabs = tabs + "\t";
	for(auto& entry : fs::directory_iterator(p) )
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
Master::~Master(){}
