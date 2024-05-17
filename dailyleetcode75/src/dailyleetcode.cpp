#include "dailyleetcode.hpp"

vector<Section> Menu::load_sections(const string &filename)
{
  std::ifstream file(filename);
  vector<Section> sections;

  if (!file.is_open())
  {
    std::cerr << "Error opening the file" << std::endl;
    return sections;
  }

  json jsonData;

  file >> jsonData;
  for (const auto &section : jsonData)
  {
    Section new_section;
    new_section.name = section["name"];
    for (const auto &problem : section["problems"])
    {
      new_section.problems.push_back({problem["title"], problem["difficulty"]});
    }
    sections.push_back(new_section);
  }
  return sections;
}

void Menu::display_main_menu(const vector<Section> &sections)
{
  std::cout << std::setfill(' ') << std::setw(0);
  int max_length = 0;
  for (const auto &section : sections)
  {
    int current_length = section.name.length();
    if (current_length > max_length)
    {
      max_length = current_length;
    }
  }

  int total_width = max_length + 8; // adjust padding as needed

  { // scope to reset setfill (" ")
    std::cout << "#" << std::setfill('-') << std::setw(total_width) << "-" << "#" << std::endl;
    int padding = (total_width - 4) / 2; // Calculate padding for centering "Menu"
    std::cout << "| " << std::setfill(' ') << std::setw(padding) << " " << "Menu" << std::setw(total_width - padding - 4) << " |" << std::endl;
    std::cout << "#" << std::setfill('-') << std::setw(total_width) << "-" << "#" << std::endl;
    std::cout << std::setfill(' ') << std::setw(0);
  }

  for (int i = 0; i < sections.size(); i++)
  {
    std::ostringstream oss;
    if (i + 1 < 10)
    {
      oss << "| " << i + 1 << ") " << sections[i].name << std::setfill(' ') << std::setw(total_width - 3 - sections[i].name.length()) << " |";
    }
    else
    {
      oss << "| " << i + 1 << ") " << sections[i].name << std::setfill(' ') << std::setw(total_width - 4 - sections[i].name.length()) << " |";
    }
    std::cout << oss.str() << std::endl;
  }

  { // scope
    std::cout << "#" << std::setfill('-') << std::setw(total_width) << "-" << "#" << std::endl;
  }
}

void Menu::display_problems(const vector<Section> &sections, int section_index)
{
  if (section_index < 1 || section_index > sections[section_index].problems.size())
  {
    std::cerr << "Invalid section index" << std::endl;
    return;
  }

  const auto &section = sections[section_index - 1];

  int max_length_title = 0, max_length_difficulty = 0;
  for (const auto &problem : sections[section_index - 1].problems)
  {
    max_length_title = std::max(max_length_title, static_cast<int>(problem.title.length()));
    max_length_difficulty = std::max(max_length_difficulty, static_cast<int>(problem.difficulty.length()));
  }
  int total_width = max_length_title + max_length_difficulty + 7; // adjust padding as need
                                                                  // Scope to reset setfill and setw
  {
    std::cout << "#" << std::setfill('-') << std::setw(total_width + 2) << "-" << "#" << std::endl;
    int padding = (total_width - section.name.length() - 7) / 2; // Calculate padding for centering section name
    std::cout << "| " << std::setfill(' ') << std::setw(padding) << " " << section.name << " Problems" << std::setw(total_width - padding - section.name.length() - 10) << " |" << std::endl;
    std::cout << "#" << std::setfill('-') << std::setw(total_width + 2) << "-" << "#" << std::endl;
  }

  for (size_t i = 0; i < section.problems.size(); i++)
  {
    string display_line = std::to_string(i + 1) + ") " + section.problems[i].title + " - " + section.problems[i].difficulty;
    std::cout << "| " << std::setfill(' ') << std::left << std::setw(total_width - 1) << display_line << " |" << std::endl;
  }
  {
    std::cout << "#" << std::setfill('-') << std::setw(total_width) << "-" << "#" << std::endl;
  }
}

// Will merge to words alternately
string Solution::merge_alternately(const string *word1, const string *word2)
{
  int i = 0;
  int j = 0;
  string merge = "";

  while (i < word1->size() && j < word2->size())
  {
    merge += (*word1)[i];
    merge += (*word2)[j];
    i++;
    j++;
  }

  merge += word1->substr(i);
  merge += word2->substr(j);

  return merge;
}

// Finds the greatest common divisors of strings
string Solution::gcd_of_strings(const string *str1, const string *str2)
{
  MISC m;
  if ((*str1) + (*str2) != (*str2) + (*str1))
    return "";
  return str1->substr(0, m.get_gcd(str1->length(), str2->length()));
}

// Display the Greatest Common Divisor of two Strings code
void Solution::execute_gcd_of_strings()
{
  Solution s;
  string str1, str2;
  std::cout << "Find the Greater common divisor of two words" << std::endl;
  std::cout << "Enter the first word: ";
  std::cin >> str1;
  std::cout << std::endl;
  std::cout << "Enter the second word: ";
  std::cin >> str2;
  std::cout << std::endl;

  if (s.gcd_of_strings(&str1, &str2) != "")
  {
    std::cout << "Result: " << s.gcd_of_strings(&str1, &str2) << std::endl;
  }
  else
  {
    std::cout << "Result: greatest common divisor not found, sorry" << std::endl;
  }
}

// Display the merge alternately question
void Solution::execute_merge_alternately()
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

  std::cout << "Result: " << s.merge_alternately(&word1, &word2) << std::endl;
}

vector<bool> Solution::kids_with_candies(vector<int> &candies, int extra_candies)
{

  vector<bool> result;
  int max_candies, has_additional_candies;

  for (int i = 0; i < candies.size(); i++)
  {
    has_additional_candies = candies[i] + extra_candies;
    max_candies = 0;
    for (int i = 0; i < candies.size(); i++)
    {
      max_candies = std::max(has_additional_candies, candies[i]);
      if (max_candies != has_additional_candies)
        break;
    }
    if (max_candies == has_additional_candies)
    {
      result.push_back(true);
    }
    else
    {
      result.push_back(false);
    }
  }
  return result;
}

void Solution::execute_kids_with_candies()
{
  Solution s;
  vector<int> candies;
  int extra_candies;
  string input;

  std::cout << "Kids With Candies\n";
  std::cout << "Enter a list of numbers seperated by spaces to represent how much candy each kid has: ";
  std::getline(std::cin, input);

  // trim(input);
  // while (input.empty())
  // {
  //   std::cout << "Enter a list of numbers separated by spaces to represent how much candy each kid has: ";
  //   std::getline(std::cin, input);
  //   trim(input);
  // }
  std::istringstream stream(input);
  int number;
  while (stream >> number)
  {
    candies.push_back(number);
  }

  std::cout << "Enter the amount of extra candies: ";
  std::cin >> extra_candies;
  std::cout << "When you have [ ";
  int i = 0;
  for (size_t i = 0; i < candies.size(); i++)
  {
    std::cout << candies[i];
    if (i != candies.size() - 1)
      std::cout << ", ";
  }

  std::cout << "]\n";

  std::cout << "With " << extra_candies << " extra candies" << std::endl;

  vector<bool> result = s.kids_with_candies(candies, extra_candies);

  std::cout << "Result: [";
  for (size_t i = 0; i < result.size(); i++)
  {
    if (result[i] == true)
    {
      std::cout << " true";
    }
    else
    {
      std::cout << "false";
    }
    if (i != result.size() - 1)
      std::cout << ", ";
  }
  std::cout << "]\n";
}

// Finds the gcd of integers recurrsively
int MISC::get_gcd(int num1, int num2)
{
  if (num1 == 0)
    return num2;
  else
    return (get_gcd(num2 % num1, num1));
}

void MISC::loading_bar()
{
#ifdef _WIN32
  system("COLOR OE");
  system("cls");
  printf("\e[?25]");

  SetConsoleCP(437);
  SetConsoleOutputCP(437);
  int bar1 = 177, bar2 = 219;
#else
  printf("\033[1;32m");       // Set text color
  printf("\033[2J\033[1;1H"); // Clear Screen
  int bar1 = '=', bar2 = '#';
#endif

  printf("\e[?25l");                                     // Hide cursor
  std::cout << "\n\t\t\tLoading...\n"; // Use spaces instead of tabs

  for (int i = 0; i < 50; i++)
  {
#ifdef _WIN32
    Sleep(10);
#else
#endif
    std::cout << char(bar1);
    std::cout.flush();
  }

  std::cout << "\r";
  std::cout.flush();

  for (int i = 0; i < 50; i++)
  {
#ifdef _WIN32
    Sleep(100);
#else
    usleep(10000);
#endif
    std::cout << char(bar2);
    std::cout.flush();
  }
  printf("\e[?25h");
  std::cout << "\n";
#ifdef _WIN32
  system("COLOR 07");
#else
  printf("\033[0m");
#endif
}

void MISC::color(int color)
{
#ifdef _WIN32
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#endif
}

void MISC::got_oxy(int x, int y)
{
#ifdef _WIN32
  COORD c;
  c.X = x;
  c.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
#endif
}

void MISC::select_menu_option(int &choice)
{
#ifdef _WIN32
  int Set[] = {7, 7, 7};
  int counter = 1;
  char key;
  MISC m;
  for (int i = 0;;)
  {
    m.got_oxy(10, 5);
    m.color(Set[0]);
    std::cout << "1. Menu";

    m.got_oxy(10, 6);
    m.color(Set[1]);
    std::cout << "2. About";

    m.got_oxy(10, 7);
    m.color(Set[2]);
    std::cout << "3. Quit";

    key = _getch();
    if (key == -32)
    {
      key = _getch();
      if (key == 72 && (counter >= 2 && counter <= 3))
      { // 72 = up arrow key
        counter--;
      }
      if (key == 80 && (counter >= 1 && counter <= 2))
      { // 80 = down arrow key
        counter++;
      }
      if (key == '\r')
      {
        choice = counter;
        break;
      }
    }

    Set[0] = 7;
    Set[1] = 7;
    Set[2] = 7;

    if (counter == 1)
    {
      Set[0] = 12;
    }
    if (counter == 2)
    {
      Set[1] = 12;
    }
    if (counter == 3)
    {
      Set[2] = 12;
    }
  }
  m.color(7); // Reset to default color
#else
  initscr();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);

  int highlight = 1;
  choice = 0;
  int c;

  while (1)
  {
    for (int i = 1; i <= 3; ++i)
    {
      if (highlight == i)
      {
        attron(A_REVERSE);
        mvprintw(i, 10, "%d. %s", i, (i == 1 ? "Menu" : (i == 2 ? "About" : "Quit")));
        attroff(A_REVERSE);
      }
      else
      {
        mvprintw(i, 10, "%d. %s", i, (i == 1 ? "Menu" : (i == 2 ? "About" : "Quit")));
      }
    }
    c = getch();
    switch (c)
    {
    case KEY_UP:
      if (highlight == 1)
        highlight = 3;
      else
        --highlight;
      break;
    case KEY_DOWN:
      if (highlight == 3)
        highlight = 1;
      else
        ++highlight;
      break;
    case 10: // Enter key
      choice = highlight;
      break;
    default:
      break;
    }
    if (choice != 0) // Exit loop if choice is made
      break;
  }
  endwin();
#endif
}
