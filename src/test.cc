#include <cassert>
#include <map>
#include <list>
#include <iostream>
using Colors = std::map<int, std::list<int>>;

int main() {
    Colors red;
    red[0].push_back(1);
    red[1].push_back(228);
    Colors &c = red;
    auto&& [gainN, verticesN] = *c.rbegin();
    std::cout << gainN << std::endl;;
    int gainold = gainN;
    verticesN.pop_front();
    if ((verticesN).empty())
        c.erase(gainN);
    std::cout << gainN << std::endl;
    assert(gainN==gainold);
}

