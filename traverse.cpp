#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;

void traverse(fs::path p, std::string tabs){
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


int main()
{
	std::filesystem::path p("/home/priest/Desktop/sampleFolder");
	std::filesystem::directory_entry dir (p);
	std::string tabs = "";
	traverse(p,tabs);
	return 0;
}
