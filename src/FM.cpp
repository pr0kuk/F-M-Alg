#include "GainContainer.h"
#include "Partitionment.h"

static int FMpass(GainContainer &gain_container, Partitionment &prt, Graph &graph);
static void gain_update(GainContainer &gain_container, Partitionment &prt, Graph &graph, unsigned Movev);

unsigned FM(Graph &graph, Partitionment &prt, bool is_mod) {
    for (unsigned iter = 1;; iter++) {
        GainContainer gain_container{graph, prt, is_mod};
        int Best = FMpass(gain_container, prt, graph);
        if (Best == prt.get_cost())
            return iter;
        prt.set_cost(Best);
    }
}

int FMpass(GainContainer &gain_container, Partitionment &prt, Graph &graph) {
    std::set<unsigned> changing;
    int cost = prt.get_cost(), best_cost = prt.get_cost();
    for (int color = prt.get_color(); !gain_container.is_empty(prt.get_color()); color = prt.get_color()){
        Move gain = gain_container.best_feasible_move(color);
        changing.insert(gain.first);
        cost -= gain.second;
        if (cost < best_cost) {
        best_cost = cost;
        changing.clear();
        }
        gain_update(gain_container, prt, graph, gain.first);
    }
    for (auto v : changing)
        prt.apply(v);
    return best_cost;
}

void gain_update(GainContainer &gain_container, Partitionment &prt, Graph &graph, unsigned move) {
    for (auto e : graph.get_vertices()[move]) {
        int no_v_in_dest = 1, is_1v_in_source = 1, v_dest_num = 0, v_source_num = 0;
        unsigned v_dest = 0, v_source = 0;
        for (auto v : graph.get_edges()[e]) {
            if (prt.get_color() ^ prt.get_prt()[v])
                no_v_in_dest = 0, v_dest_num++, v_dest = v;
            else if (v != move)
                v_source = v, v_source_num++;
            if (prt.get_prt()[move] == prt.get_prt()[v] && v != move)
                is_1v_in_source = 0;
        }
        int UpdateVal = no_v_in_dest ? 1 : is_1v_in_source ? -1 : 0;
        if (UpdateVal)
            for (auto v : graph.get_edges()[e])
                gain_container.update(v, prt.get_prt()[v], UpdateVal);
        if (v_source_num == 1)
            gain_container.update(v_source, prt.get_prt()[v_source], 1);
        if (v_dest_num == 1)
            gain_container.update(v_dest, prt.get_prt()[v_dest], -1);
    }
    gain_container.erase(move, prt.get_prt()[move]);
    gain_container.update_deleted(move);
    prt.apply(move);
}