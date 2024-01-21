#ifndef UTIL_HH
#define UTIL_HH

#include "algorithms.hh"

#include <vector>
#include <random>
#include <algorithm>
#include <raylib.h>

const unsigned int SCREEN_WIDTH = 1280;
const unsigned int SCREEN_HEIGHT = 720;

const int NUM_ELEM = 60;

const unsigned int BUTTON_WIDTH = 200;
const unsigned int BUTTON_HEIGHT = 50;
const unsigned int BUTTON_POS_X = 175;
const unsigned int BUTTON_POS_Y = 450;
const unsigned int OFFSET = 550;
const unsigned int SPACE_X = (SCREEN_WIDTH - 3 * BUTTON_WIDTH) / 4;
const unsigned int SPACE_Y = ((SCREEN_HEIGHT / 2 + OFFSET) - 2 * BUTTON_HEIGHT) / 3;

typedef enum Screen {TITLE, GAME, RESET} Screen;
//typedef enum Algorithm {BUBBLE_SORT, INSERTION_SORT, SELECTION_SORT, MERGE_SORT} Algorithm;
typedef enum Algorithm {BUBBLE_SORT, INSERTION_SORT, SELECTION_SORT} Algorithm;

struct Bar
{
    Rectangle rec;
    int value;
};

struct Button
{
    Rectangle rec;
    Color color;
}; 

void generate_random_numbers(std::vector<int>& vec);
void update_vector(std::vector<Bar>& final_vec, const std::vector<int>& vec);
void init_buttons(std::vector<Button>& alg_buttons);
void draw_buttons(std::vector<Button>& alg_buttons);
void draw_text(std::vector<Button>& alg_buttons);
void update_button(std::vector<Button>& alg_buttons, Algorithm& algorithm, bool& is_alg_selected);
//void execute_algorithm(std::vector<int>& vec, Algorithm& algorithm, bool& is_sorting, int& index, bool& swapped, int& min_index, int& current_size, int& left_start);
void execute_algorithm(std::vector<int>& vec, Algorithm& algorithm, bool& is_sorting, int& index, bool& swapped, int& min_index);
const char* get_alg_name(Algorithm& algorithm);
//void reset(std::vector<int>& vec, std::vector<Bar>& final_vec, bool& is_sorting, bool& swapped, int& index, Screen& current_screen, Algorithm& algorithm, std::vector<Button>& alg_buttons, bool& is_alg_selected, int& current_size, int& left_start);
void reset(std::vector<int>& vec, std::vector<Bar>& final_vec, bool& is_sorting, bool& swapped, int& index, Screen& current_screen, Algorithm& algorithm, std::vector<Button>& alg_buttons, bool& is_alg_selected);

#endif