#ifndef DAILY_LEETCODE_H
#define DAILY_LEETCODE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <nlohmann/json.hpp>

#ifdef _WIN32
#define NOMINMAX
#include <Windows.h> // only include on Windows
#include <conio.h>   // only include on Windows for _getch()
#else
#include <ncurses.h>
#include <unistd.h> // for unsleep on non windows
#endif

#include <stdio.h> // printf();

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
    void display_main_menu(const vector<Section> &sections);
    void display_problems(const vector<Section> &sections, int section_index);
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

    void loading_bar();
    void color(int color);
    void got_oxy(int x, int y);
    void select_menu_option(int &choice);
};

// Trim from start (in place)
static inline void ltrim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
                                    { return !std::isspace(ch); }));
}

// Trim from end (in place)
static inline void rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                         { return !std::isspace(ch); })
                .base(),
            s.end());
}

// Trim from both ends (in place)
static inline void trim(std::string &s)
{
    ltrim(s);
    rtrim(s);
}

#endif // DAILY_LEETCODE_H
