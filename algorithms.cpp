#include "algorithms.hh"

void bubble_sort(std::vector<int>& vec, bool& is_sorting, bool& swapped, int& index)
{
    if(is_sorting)
    {
        if(index < vec.size() - 1)
        {
            if(vec.at(index) > vec.at(index + 1))
            {
                std::swap(vec.at(index), vec.at(index + 1));
                swapped = true;
            }

            index++;
        } else
        {
            if(!swapped)
            {
                is_sorting = false;
            } else
            {
                swapped = false;
                index = 0;
            }
        }
    }
}

void insertion_sort(std::vector<int>& vec, bool& is_sorting, int& index)
{
    if (is_sorting && index < vec.size())
    {
        int key = vec.at(index);
        int j = index - 1;

        while (j >= 0 && vec.at(j) > key)
        {
            vec.at(j + 1) = vec.at(j);
            j--;
        }

        vec.at(j + 1) = key;
        index++;
        
        if (index == vec.size()) 
        {
            is_sorting = false;
        }
    }
}

void selection_sort(std::vector<int>& vec, bool& is_sorting, int& index, int& min_index)
{
    if(is_sorting)
    {
        if(index < vec.size() - 1)
        {
            if(min_index == -1)
            {
                min_index = index;
            }

            for(int j = index + 1; j < vec.size(); j++)
            {
                if(vec.at(j) < vec.at(min_index))
                {
                    min_index = j;
                }
            }

            if(min_index != index)
            {
                std::swap(vec.at(min_index), vec.at(index));
            }

            index++;
            min_index = -1;
        }
        else
        {
            is_sorting = false;
            index = 0;
        }
    }
}

/*
void merge(std::vector<int>& vec, const int left, const int mid, const int right)
{
    const auto sub_array_one = mid - left + 1;
    const auto sub_array_two = right - mid;

    std::vector<int> left_array(sub_array_one);
    std::vector<int> right_array(sub_array_two);

    for(auto i = 0; i < sub_array_one; i++)
    {
        left_array.at(i) = vec.at(left + i);
    }

    for(auto j = 0; j < sub_array_two; j++)
    {
        right_array.at(j) = vec.at(mid + 1 + j);
    }

    auto index_of_sub_array_one = 0;
    auto index_of_sub_array_two = 0;
    int index_of_merged_array = left;

    while(index_of_sub_array_one < sub_array_one && index_of_sub_array_two < sub_array_two)
    {
        if(left_array.at(index_of_sub_array_one) <= right_array.at(index_of_sub_array_two))
        {
            vec.at(index_of_merged_array) = left_array.at(index_of_sub_array_one);
            index_of_sub_array_one++;
        } else
        {
            vec.at(index_of_merged_array) = right_array.at(index_of_sub_array_two);
            index_of_sub_array_two++;
        }

        index_of_merged_array++;
    }

    while(index_of_sub_array_one < sub_array_one)
    {
        vec.at(index_of_merged_array) = left_array.at(index_of_sub_array_one);
        index_of_sub_array_one++;
        index_of_merged_array++;
    }

    while(index_of_sub_array_two < sub_array_two)
    {
        vec.at(index_of_merged_array) = right_array.at(index_of_sub_array_two);
        index_of_sub_array_two++;
        index_of_merged_array++;
    }
}

void merge_sort(std::vector<int>& vec, bool& is_sorting, int& current_size, int& left_start)
{
    if(is_sorting)
    {
        int n = vec.size();

        if(current_size > n - 1)
        {
            is_sorting = false;
            return;
        }

         int mid = left_start + current_size - 1;
         int right_end = std::min(left_start + 2 * current_size - 1, n - 1);

         if(mid < right_end)
         {
            merge(vec, left_start, mid, right_end);
         }

         left_start += 2 * current_size;

         if(left_start >= n)
         {
            left_start = 0;
            current_size *= 2;
         }
    }
}
*/
