#include "dailyleetcode.hpp"


vector<Section> Menu::load_sections(const string& filename)
{
  std::ifstream file(filename);
  vector<Section> sections;

  if(!file.is_open())
  {
    std::cerr << "Error opening the file" << std::endl;
    return sections;
  }

  json jsonData;

  file >> jsonData;
  for(const auto& section : jsonData)
  {
    Section new_section;
    new_section.name = section["name"];
    	for(const auto& problem : section["problems"])
	{
	  new_section.problems.push_back({problem["title"], problem["difficulty"]});
	}
    sections.push_back(new_section);
  } 
  return sections;
}

void Menu::display_main_menu(const vector<Section>& sections)
{
    int max_length = 0;
    for (const auto& section : sections)
    {
        int current_length = section.name.length();
        if (current_length > max_length)
        {
            max_length = current_length;
        }
    }

    int total_width = max_length + 8; // adjust padding as needed

   
    std::cout << "#" << std::setfill('-') << std::setw(total_width) << "-" << "#" << std::endl;
    std::cout << "|            Menu             |" << std::endl;
    std::cout << "#" << std::setfill('-') << std::setw(total_width) << "-" << "#" << std::endl;

    for (int i = 0; i < sections.size(); i++)
    {
        if (i + 1 < 10)
        {
            std::cout << "| " << i + 1 << ") " << sections[i].name <<std::setfill(' ') << std::setw(26 - sections[i].name.length())  << "|" << std::endl; // Subtracting the length of prefix
        }
        else
        {
            std::cout << "| " << i + 1 << ") " << sections[i].name << std::setfill(' ') << std::setw(25 - sections[i].name.length()) << "|" << std::endl; // Subtracting the length of prefix
        }
    }
    std::cout << "#" << std::setfill('-') << std::setw(total_width) << "-" << "#" << std::endl;
}

void Menu::display_problems(const vector<Section>& sections,int section_index)
{
     if(section_index < 1 || section_index > sections[section_index].problems.size())
     {
     	std::cerr << "Invalid section index" << std::endl;
     }
    
    const auto& section = sections[section_index - 1];

    int max_length_title = 0, max_length_difficulty;
    for(const auto& problem : sections[section_index - 1].problems)
    {
      max_length_title = std::max(max_length_title,static_cast<int>(problem.title.length()));
      max_length_difficulty = std::max(max_length_difficulty, static_cast<int>(problem.difficulty.length()));
    }
    int total_width = max_length_title + max_length_difficulty + 7; // adjust padding as needed
     std::cout << "#" << std::setfill('-') << std::setw(total_width) << "-" << "#" << std::endl;
     
     std::cout << "| "  << std::left << std::setfill(' ') << std::setw(total_width- 2) <<  section.name + " Problems" << " |" << std::endl;
     std::cout << "#" << std::setfill('-') << std::setw(total_width) << "-" << "#" << std::endl;

     
     for(size_t i = 0; i < section.problems.size(); i++)
     {
	     string display_line = std::to_string(i + 1) + ") " + section.problems[i].title + " - " + section.problems[i].difficulty;
	     std::cout << std::setfill(' ') <<"| " << std::left << std::setw(total_width - 2) << display_line << " |" << std::endl;
     }
     std::cout << std::setfill('-');
     std::cout << "#" <<  std::setw(total_width) << "-" << "#" << std::endl;
     std::cout << std::setfill(' ') << std::setw(1);
}

// Will merge to words alternately
string Solution::merge_alternately(const string* word1, const string* word2)
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

//Finds the greatest common divisors of strings
string Solution::gcd_of_strings(const string* str1, const string* str2)
{
    MISC m;
    if ((*str1) + (*str2) != (*str2) + (*str1)) return "";
    return str1->substr(0, m.get_gcd(str1->length(), str2->length()));
}

//Display the Greatest Common Divisor of two Strings code
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

//Display the merge alternately question
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

//Finds the gcd of integers recurrsively
int MISC::get_gcd(int num1, int num2)
{
    if (num1 == 0) return num2;
    else return (get_gcd(num2 % num1, num1));
}

//Displays each type of problem avaliable currently;
void MISC::display_type_of_problem()
{
    std::cout << "Menu" << std::endl;
    std::cout << "1-9 are Array/String" << std::endl;
    std::cout << "10-13 are Two Pointers" << std::endl;
    std::cout << "14-17 are Sliding Window" << std::endl;
    std::cout << "18-19 are Prefix Sum" << std::endl;
    std::cout << "20-23 are Hash Map/Set" << std::endl;
    std::cout << "24-26 are Stack" << std::endl;
    std::cout << "27-28 are Queue" << std::endl;
    std::cout << "29-32 are Linked List" << std::endl;
    std::cout << "33-38 are Binary Tree - DFS" << std::endl;
    std::cout << "39-40 are Binary Tree - BFS" << std::endl;
    std::cout << "41-42 are Binary Search Tree" << std::endl;
    std::cout << "43-46 are Graphs - DFS" << std::endl;
    std::cout << "47-48 are Graphs - BFS" << std::endl;
    std::cout << "49-52 are Heap/Priority Queue" << std::endl;
    std::cout << "53-56 are Binary Search" << std::endl;
    std::cout << "57-58 are Backtracking" << std::endl;
    std::cout << "59-62 are DP - 1D" << std::endl;
    std::cout << "63-66 are DP - Multidimensional" << std::endl;
    std::cout << "67-69 are Bit Manipulation" << std::endl;
    std::cout << "70-71 are Trie" << std::endl;
    std::cout << "72-73 are Intervals" << std::endl;
    std::cout << "74-75 are Monotonic Stack" << std::endl;
}


