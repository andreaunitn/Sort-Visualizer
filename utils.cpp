#include "utils.hh"

void generate_random_numbers(std::vector<int>& vec)
{
    std::random_device dev;
    std::mt19937 gen(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 100);

    for(unsigned int i = 0; i < NUM_ELEM; i++)
    {
        vec.push_back(dist(gen));
    }
}

void update_vector(std::vector<Bar>& final_vec, const std::vector<int>& vec)
{
    for(int i = 0; i < NUM_ELEM; i++)
    {
        Bar bar;
        Rectangle rec;
        rec.width = (float) SCREEN_WIDTH / NUM_ELEM;
        
        int value = vec.at(i);
        rec.height = (float) value / 100 * (SCREEN_HEIGHT / 1.25);

        if(i == 0)
        {
            rec.x = 0;
        }
        else 
        {
            rec.x = final_vec.at(i - 1).rec.x + rec.width;
        }

        rec.y = SCREEN_HEIGHT - rec.height;
        
        bar.rec = rec;
        bar.value = value;

        final_vec.push_back(bar);
    }
}

void init_buttons(std::vector<Button>& alg_buttons)
{
    const int NUM_ROWS = 1;
    const int NUM_COLS = 3;
    const int NUM_BUTTONS = NUM_ROWS * NUM_COLS;

    for(int i = 0; i < NUM_BUTTONS; i++)
    {
        Button button;
        Rectangle rec;

        int row = i / NUM_COLS;
        int col = i % NUM_COLS;

        rec.width = BUTTON_WIDTH;
        rec.height = BUTTON_HEIGHT;

        rec.x = BUTTON_POS_X + col * (BUTTON_WIDTH + SPACE_X);

        if(row == 0)
        {
            rec.y = BUTTON_POS_Y;
        } else
        {
            rec.y = BUTTON_HEIGHT + 2 * SPACE_Y;

        }

        button.rec = rec;
        button.color = GRAY;

        alg_buttons.push_back(button);
    }
}

void draw_buttons(std::vector<Button>& alg_buttons)
{
    for(Button button: alg_buttons)
    {
        DrawRectangleRec(button.rec, button.color);
    }
}

void draw_text(std::vector<Button>& alg_buttons)
{
    for(int i = 0; i < alg_buttons.size(); i++)
    {
        float x = alg_buttons.at(i).rec.x + BUTTON_WIDTH / 2 - 50;
        float y = alg_buttons.at(i).rec.y + BUTTON_HEIGHT / 2 - 10;

        switch(i)
        {
            case 0:
            {
                x -= 5;
                DrawText("Bubble sort", x, y, 20, LIGHTGRAY);

            } break;

            case 1:
            {
                x -= 20;
                DrawText("Insertion sort", x, y, 20, LIGHTGRAY);

            } break;

            case 2:
            {
                x -= 20;
                DrawText("Selection sort", x, y, 20, LIGHTGRAY);

            } break;

            default: break;
        }
    }
}

void update_button(std::vector<Button>& alg_buttons, Algorithm& algorithm, bool& is_alg_selected)
{
    for(Button& button: alg_buttons)
    {
        if(button.color.r == DARKGREEN.r && button.color.g == DARKGREEN.g && button.color.b == DARKGREEN.b && button.color.a == DARKGREEN.a)
        {
            is_alg_selected = true;
            break;
        }
    }

    Vector2 mouse_pos = GetMousePosition();

    for(int i = 0; i < alg_buttons.size(); i++)
    {
        if(!is_alg_selected)
        {

            if(CheckCollisionPointRec(mouse_pos, alg_buttons.at(i).rec))
            {   
                alg_buttons.at(i).color = DARKGREEN;

                switch(i)
                {
                    case 0:
                    {
                        algorithm = BUBBLE_SORT;
                    } break;

                    case 1:
                    {
                        algorithm = INSERTION_SORT;
                    } break;

                    case 2:
                    {
                        algorithm = SELECTION_SORT;
                    } break;
                    
                    /*
                    case 3:
                    {
                        algorithm = MERGE_SORT;
                    } break;
                    */

                    default: break;
                }

                break;
            }
        }
    }   
}

void execute_algorithm(std::vector<int>& vec, Algorithm& algorithm, bool& is_sorting, int& index, bool& swapped, int& min_index)
{
    switch(algorithm)
    {
        case BUBBLE_SORT:
        {
            bubble_sort(vec, is_sorting, swapped, index);
        } break;

        case INSERTION_SORT:
        {
            insertion_sort(vec, is_sorting, index);
        } break;

        case SELECTION_SORT:
        {
            selection_sort(vec, is_sorting, index, min_index);
        } break;
        
        /*
        case MERGE_SORT:
        {
            merge_sort(vec, is_sorting, current_size, left_start);
        } break;
        */

        default: break;
    }
}

const char* get_alg_name(Algorithm& algorithm)
{
    const char* name;
    switch(algorithm)
    {
        case BUBBLE_SORT: name = "Bubble sort"; break;
        case INSERTION_SORT: name = "Insertion sort"; break;
        case SELECTION_SORT: name = "Selection sort"; break;
        //case MERGE_SORT: name = "Merge sort"; break;
        default: break;
    }

    return name;
}

void reset(std::vector<int>& vec, std::vector<Bar>& final_vec, bool& is_sorting, bool& swapped, int& index, Screen& current_screen, Algorithm& algorithm, std::vector<Button>& alg_buttons, bool& is_alg_selected)
{
    is_sorting = true;
    swapped = false;
    index = 0;
    is_alg_selected = false;

    vec.clear();
    generate_random_numbers(vec);
    final_vec.clear();
    update_vector(final_vec, vec);

    current_screen = TITLE;
    algorithm = BUBBLE_SORT;

    for(Button& button: alg_buttons)
    {
        button.color = GRAY;
    }
}