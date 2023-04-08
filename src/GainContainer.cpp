#include "GainContainer.h"
#include "Graph.h"
#include "Partitionment.h"
#include <algorithm>
#include <cassert>
GainContainer::GainContainer(Graph &graph, Partitionment &prt, bool is_mod) : is_mod(is_mod) {
    // st = 0;
    size_t prt_size = prt.get_prt().size();
    deleted = std::vector<bool>(prt_size, false);
    gain = std::vector<int>(prt_size);
    its = std::vector<std::list<int>::iterator>(prt_size);
    for (unsigned i = 0; i != prt_size; ++i) {
        int current_gain = 0, current_prt = prt.get_prt()[i];
        for (unsigned e : graph.get_vertices()[i]) {
            bool from_block = true, to_block = true;
        for (unsigned v : graph.get_edges()[e]) {
            if (current_prt != prt.get_prt()[v])
                to_block = false;
            else if (v != i)
                from_block = false;
        }
        if (from_block)
            current_gain++;
        if (to_block)
            current_gain--;
        }
        get_color(current_prt)[current_gain].push_back(i);
        its[i] = std::prev(std::end(get_color(current_prt)[current_gain]));
        gain[i] = current_gain;

    }
}

Colors &GainContainer::get_color(int color) {
    return color ? second : first;
}

bool GainContainer::is_empty(int color)  {
    return get_color(color).empty();
}

Move GainContainer::best_feasible_move(int color) {
    Colors &c = get_color(color);
    auto&& [gainN, verticesN] = *c.rbegin();
    unsigned v = verticesN.front();
    auto ret = std::make_pair(v, gainN);
    verticesN.pop_front();
    deleted[v] = true;
    if ((verticesN).empty())
        c.erase(std::prev(c.end()));
    return ret;
}

void GainContainer::update(unsigned v, int color, int value) {
    if (deleted[v])
        return;
    erase(v, color);
    gain[v] += value;
    if (is_mod){
        get_color(color)[gain[v]].push_back(v);
        its[v] = std::prev(std::end(get_color(color)[gain[v]]));
    }
    else {
        get_color(color)[gain[v]].push_front(v);
        its[v] = std::begin(get_color(color)[gain[v]]);
    }
        // get_color(color)[gain[v]].insert(v);
}

void GainContainer::erase(unsigned v, int color) {
    if(deleted[v])
        return;
    // auto start = std::chrono::steady_clock::now();
    get_color(color)[gain[v]].erase(its[v]);
    // auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - start).count();
    // st+=time;
    // get_color(color)[gain[v]].erase(v);
    if (get_color(color)[gain[v]].empty())
        get_color(color).erase(gain[v]);
}

void GainContainer::update_deleted(unsigned v) { deleted[v] = true; }