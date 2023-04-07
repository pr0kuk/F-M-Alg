#pragma once
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <vector>
using Colors = std::map<int, std::list<int>>;
// using Colors = std::map<int, std::set<int>>;
using Move = std::pair<unsigned, int>;
class Graph;
class Partitionment;
class GainContainer {
    public:
        GainContainer(Graph&, Partitionment&, bool is_mod);
        Move best_feasible_move(int color);
        const bool is_mod = false;
        bool is_empty(int color);
        void update(unsigned vertex, int color, int value);
        void erase(unsigned vertex, int color);
        void update_deleted(unsigned vertex);
    private:
        Colors first;
        Colors second;
        std::vector<int> gain;
        std::set<unsigned> deleted;
        Colors &get_needed_color(int color);
};