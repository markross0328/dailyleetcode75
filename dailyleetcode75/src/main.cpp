#include "dailyleetcode.hpp"
using json = nlohmann::json;

int main()
{
    Menu menu;
    string user_continue = "";
    int choice = 0, section_index, hit_space_to_end_game, problem_num;
    Solution s;
    MISC m;

    vector<Section> sections = menu.load_sections("./problems.json");

    std::cout << "\t\t\t\t This program runs Leetcode 75 Study Plan" << std::endl;

    do
    {
        m.select_menu_option(choice);

        while (choice < 1 || choice > 3)
        {
            std::cout << "Error! Enter a valid choice (1-3): ";
            std::cin >> choice;
        }

        switch (choice)
        {
        case 1:
            menu.display_main_menu(sections);
            std::cout << "\nEnter the # of the problem type to see the titles and difficulties of those problems: ";
            std::cin >> section_index;
#ifdef _WIN32
            system("cls");
#else
            sleep(2);
            std::cout << "\033[2J\033[1;1H";
#endif
            menu.display_problems(sections, section_index);
            std::cout << "\nEnter the problem # you would like to do: ";
            std::cin >> problem_num;
            m.loading_bar();

            if (section_index == 1)
                switch (problem_num)
                {
                case 1:
                    s.execute_merge_alternately();
                    break;
                case 2:
                    s.execute_gcd_of_strings();
                    break;
                case 3:
                    s.execute_kids_with_candies();
                    break;
                case 4:
                    break;
                default:
                    std::cerr << "404";
                }
            else if (section_index == 2)
            {
                std::cerr << "Invalid problem number for this section" << std::endl;
            }
            break;

        case 2: // About
            std::cout << "In this repository ill be coding a coding challenge from leetcode 75 study plan \n"
                      << "daily inside of WSL(Windows subsystem Linux) in Debian Unbuntu. Im doing this to \n"
                      << "learn linux system admin while using vim to code it all.";
            break;

        case 3: // Quit
            user_continue = "quit";
            break;

        default:
            std::cerr << "Invalid choice" << std::endl;
            break;
        }

        if (user_continue != "quit")
        {
            std::cout << std::endl
                      << "Do you want to continue using? (Y/n): ";
            std::cin >> user_continue;
        }

    } while (user_continue == "Y" || user_continue == "y");

    std::cout << std::endl
              << "Thanks for using! :)" << std::endl;
    std::cin >> hit_space_to_end_game;
    return 0;
}
