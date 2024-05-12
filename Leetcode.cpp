#include <iostream>
#include <string>
using std::string;

class Solution 
{
	public:
		string mergeAlternately(string, string);
                      
};   
 string Solution::mergeAlternately(string word1, string word2)
        {
     int i = 0;
     int j = 0;
     string merge = "";

    while(i < word1.size() && j < word2.size())
    {
            merge += word1[i];
            merge += word2[j];
            i++;
            j++;
    }
    while(i < word1.size())
    {
            merge += word1[i];
            i++;
    }
    while(j < word2.size())
    {
            merge += word2[j];
            j++;
    }
    return merge;

}

void execute_merge_alternately()
{
	
            	Solution s;
	string word1, word2;
			std::cout << "Merge Alternately" << std::endl;
			std::cout << "Enter the first word: ";
		 	std::cin >> word1;
			std::cout << std::endl;
			std::cout << "Enter the second word: ";
			std::cin >> word2;
			std::cout << std::endl;

			
			std::cout << "Result: " << s.mergeAlternately(word1, word2) << std::endl;		

}

int main() {
	string user_continue = "";
	int choice;
	Solution s;
	std::cout << "This program runs Leetcode 75" << std::endl;
	do 
	{
		std::cout << "Enter a number 1-75: ";
		std::cin >> choice;
		while(choice < 1|| choice >75)
		{
			std::cout << "Error! Enter a number 1-75: ";
			std::cin >> choice;
		}
	switch(choice){
		case 1: {
				execute_merge_alternately();
				break;
		}
		default:
			std::cerr << "Invalid Question" << std::endl;
			return 0;
	}
	std::cout << "Do you want to contiue using?(Y/n): ";
	std::cin >> user_continue;

	}while(user_continue == "Y" || user_continue == "y");

	std::cout << "Thanks for using! :)" << std::endl;
	return 0;
}

  
