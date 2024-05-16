#include <iostream>
#include "dailyleetcode.hpp"
using json = nlohmann::json;

int main() {
    Menu menu;
    string user_continue = "";
    int choice, section_index, hit_space_to_end_game, problem_num;
    Solution s;
    MISC m;
    vector<Section> sections = menu.load_sections("./problems.json");
    std::cout << "This program runs Leetcode 75 Study Plan" << std::endl;

    do
    {
        std::cout << std::endl
            << "0 for Menu" << std::endl;
        std::cout << "1-75 for Problems" << std::endl;
        std::cout << "76 to Quit" << std::endl;
        std::cin >> choice;
        while (choice < 0 || choice>76)
        {
            std::cout << "Error! Enter a number 0-76: ";
            std::cin >> choice;
        }
        switch (choice) {
        case 0:
            menu.display_main_menu(sections);
            std::cout << "Enter the # of the problem type to see the titles and difficulties of those problems: ";
            std::cin >> section_index;
            menu.display_problems(sections, section_index);
            std::cout << "Enter the problem # you would like to do!";
            std::cin >> problem_num;
            switch (problem_num)
            {
            case 1:
		    if(section_index == 1)
                    {
			    s.execute_merge_alternately();
	            }

               break;
            }
            break;
        case 1:
            s.execute_merge_alternately();
            break;
        case 2:
            s.execute_gcd_of_strings();
            break;
        case 76:
            user_continue = "quit";
            break;
        default:
            std::cerr << "Invalid Question" << std::endl;
            return 0;
        }

        std::cout << std::endl
            << "Do you want to continue using?(Y/n): ";
        std::cin >> user_continue;

    } while (user_continue == "Y" || user_continue == "y");

    std::cout << std::endl
        << "Thanks for using! :)" << std::endl;
    std::cin >> hit_space_to_end_game;
    return 0;
   
}

