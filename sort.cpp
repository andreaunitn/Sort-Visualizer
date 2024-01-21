#include "utils.hh"

#include <iostream>
#include <vector>
#include <raylib.h>

int main()
{
    std::vector<int> vec;
    generate_random_numbers(vec);

    std::vector<Bar> final_vec;
    update_vector(final_vec, vec);

    // Raylib
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sort visualizer");
    SetTargetFPS(120);

    Screen current_screen = TITLE;
    std::vector<Button> alg_buttons;
    init_buttons(alg_buttons);

    Algorithm algorithm = BUBBLE_SORT;

    // Utility variables
    bool is_sorting = true;
    bool swapped = false;
    int index = 0;
    int min_index = -1;

    /*
    int current_size = 1;
    int left_start = 0;
    */

    bool is_alg_selected = false;

    while(!WindowShouldClose())
    {   
        // Update game mode
        switch(current_screen)
        {
            case TITLE:
            {
                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    update_button(alg_buttons, algorithm, is_alg_selected);
                }

                if(IsKeyPressed(KEY_S))
                {
                    current_screen = GAME;
                }

            } break;

            case GAME:
            {
                //execute_algorithm(vec, algorithm, is_sorting, index, swapped, min_index, current_size, left_start);
                execute_algorithm(vec, algorithm, is_sorting, index, swapped, min_index);

                final_vec.clear();
                update_vector(final_vec, vec);

            } break;

            default: break;
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch(current_screen)
        {
            case TITLE:
            {
                DrawText("Sort visualizer", SCREEN_WIDTH / 2 - 260, 100, 80, DARKGRAY);
                DrawText("Select algorithm and press s to start", SCREEN_WIDTH / 2 - 270, 300, 30, GRAY);
                DrawText("Made by Andrea Tomasoni", SCREEN_WIDTH - 220, SCREEN_HEIGHT - 20, 16, GRAY);
                draw_buttons(alg_buttons);
                draw_text(alg_buttons);

            } break;

            case GAME:
            {
                // Draw Rectangles
                for(int j = 0; j < NUM_ELEM; j++)
                {
                    Color color;
                    if(is_sorting)
                    {
                        color = (j == index || j == index + 1) ? RED : GRAY;
                    } else
                    {
                        color = LIME;
                    }

                    DrawRectangleRec(final_vec.at(j).rec, color);
                }

                DrawText(TextFormat(get_alg_name(algorithm)), SCREEN_WIDTH / 2 - 110, 10, 30, BLACK);
                DrawText(TextFormat("Status: "), SCREEN_WIDTH / 2 - 200, 60, 20, BLACK);
                
                if(index < final_vec.size())
                {
                    DrawText(TextFormat("Analyzed element: %d", final_vec.at(index).value), SCREEN_WIDTH / 2, 60, 20, BLACK);
                } else
                {
                    DrawText(TextFormat("Analyzed element: %d", final_vec.at(index - 1).value), SCREEN_WIDTH / 2, 60, 20, BLACK);
                }

                // Drawing element number if left mouse button is pressed
                if(!is_sorting)
                {
                    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                    {
                        Vector2 mouse_pos = GetMousePosition();

                        for(int i = 0; i < NUM_ELEM; i++)
                        {
                            if(CheckCollisionPointRec(mouse_pos, final_vec.at(i).rec))
                            {
                                DrawText(TextFormat("%d", final_vec.at(i).value), final_vec.at(i).rec.x, final_vec.at(i).rec.y - 70, 40, BLACK);
                                DrawRectangleRec(final_vec.at(i).rec, ORANGE);
                            }
                        }
                    }

                    DrawText(TextFormat("finished"), SCREEN_WIDTH / 2 - 120, 60, 20, DARKBLUE);
                    DrawText(TextFormat("Press r to return to menu"), SCREEN_WIDTH / 2 - 130, 100, 20, GRAY);

                    if(IsKeyPressed(KEY_R))
                    {
                        // Reset
                        //reset(vec, final_vec, is_sorting, swapped, index, current_screen, algorithm, alg_buttons, is_alg_selected, current_size, left_start);
                        reset(vec, final_vec, is_sorting, swapped, index, current_screen, algorithm, alg_buttons, is_alg_selected);
                    }

                } else
                {
                    DrawText(TextFormat("sorting"), SCREEN_WIDTH / 2 - 120, 60, 20, RED);
                }

                DrawText(TextFormat("fps: %d", GetFPS()), 10, 10, 20, BLACK);

            } break;

            default: break;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}