#include <regex>
#include <iostream>
#include <string>
#include <fstream>

int main() {
	std::regex re(":Spotify Premium - \\d/\\d\\d/\\d\\d");
	std::ifstream input( "combolist.txt" );
	std::ofstream outfile ("result.txt",std::ios::binary | std::ios::out);
	for( std::string line; getline( input, line ); )
	{
	    std::regex_replace (line, re, "");
	    std::cout<<line<<std::endl;
	    size_t len = line.size();
	    outfile<<line<<std::endl;
	    outfile.flush();
	}
	outfile.close();
	return 0;
}
