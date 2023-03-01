#include <iostream>
#include <string>

int main()
{
	std::string mystr="";
	getline (std::cin, mystr);
	std::string max="";
	std::string min="";
	std::string word="";
	std::string repeatable="";
	//find max and min words	
	for(int i = 0; i <= mystr.length(); i++) {
		if (mystr[i]==' ' || mystr[i]=='\0') {
			if (max.length() < word.length() ) max = word;
			if (min == ""||min.length() > word.length() ) min = word;
			word = "";
		} else {
			word += mystr[i];
		}
	}
	for(int i = 0; i < min.length(); i++) {
		for(int j = 0; j < max.length(); j++) {
			if((min[i]==max[j]) && (repeatable.find(min[i]) == std::string::npos)) {
				repeatable += min[i]; 
			}
		}
	}

            std::cout << "\nMin Word is: " << min << std::endl;
            std::cout << "Max Word is: " << max << std::endl;
            std::cout << "Repeat in min-max is: " << repeatable << std::endl;
	return 0;
}
