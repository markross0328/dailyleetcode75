#ifndef DAILY_LEETCODE_H
#define DAILY_LEETCODE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>       
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using std::string;
using std::vector;

struct Problem
{
    string title;
    string difficulty;
};

struct Section
{
    string name;
    vector<Problem> problems;
};

class Menu
{
public:
    vector<Section> load_sections(const string &filename);
    void display_main_menu(const vector<Section>& sections);
    void display_problems(const vector<Section>& sections, int section_index);
};

class Solution
{
public:
    string merge_alternately(const string *word1, const string *word2);
    string gcd_of_strings(const string *str1, const string *str2);
    vector<bool> kids_with_candies(vector<int> &candies, int extra_candies);
    void execute_merge_alternately();
    void execute_gcd_of_strings();
    void execute_kids_with_candies();
}; // Class of solutions to leet code 75 questions

class MISC
{
public:
    int get_gcd(int, int);
    void display_type_of_problem();
};

#endif // DAILY_LEETCODE_H
