#include "GainContainer.h"
#include "Graph.h"
#include "Partitionment.h"
#include <algorithm>
#include <cassert>
GainContainer::GainContainer(Graph &graph, Partitionment &prt, bool is_mod) : is_mod(is_mod) {
    size_t prt_size = prt.get_prt().size();
    gain.resize(prt_size);
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
        get_needed_color(current_prt)[current_gain].push_back(i);
        // get_needed_color(current_prt)[current_gain].insert(i);
        gain[i] = current_gain;

    }
}

Colors &GainContainer::get_needed_color(int color) {
    return color ? second : first;
}

bool GainContainer::is_empty(int color)  {
    return get_needed_color(color).empty();
}

Move GainContainer::best_feasible_move(int color) {
    Colors &c = get_needed_color(color);
    auto&& [gainN, verticesN] = *c.rbegin();
    unsigned v = verticesN.front();
    int gainold = gainN;
    verticesN.pop_front();
    assert(gainN!=gainold);
    if ((verticesN).empty())
        c.erase(gainN);
    return std::make_pair(v, gainN);
}

void GainContainer::update(unsigned v, int color, int value) {
    if (deleted.count(v))
        return;
    erase(v, color);
    gain[v] += value;
    if (is_mod)
        get_needed_color(color)[gain[v]].push_back(v);
    else
        get_needed_color(color)[gain[v]].push_front(v);
        // get_needed_color(color)[gain[v]].insert(v);
}

void GainContainer::erase(unsigned v, int color) {
    get_needed_color(color)[gain[v]].remove(v);
    // get_needed_color(color)[gain[v]].erase(v);
    if (get_needed_color(color)[gain[v]].empty())
        get_needed_color(color).erase(gain[v]);
}

void GainContainer::update_deleted(unsigned v) { deleted.insert(v); }