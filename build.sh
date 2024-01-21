g++ -I./raylib/include -L./raylib/lib -pthread -o sort sort.cpp algorithms.cpp utils.cpp -lraylib -lm -ldl && ./sort
