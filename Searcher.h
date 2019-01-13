//
// Created by Orsan Awwad on 13/01/2019.
//

#ifndef AP_MS2_SEARCHER_H
#define AP_MS2_SEARCHER_H

#include "ISearcher.h"
#include "MyPriorityQueue.h"

template<typename StateType, typename CostType>
class Searcher : public ISearcher<StateType, CostType> {
private:
    unsigned long numberOfStatesEvaluated = 0;
//    MyPriorityQueue<State<StateType,CostType>> priorityQueue;
public:
    virtual ISolution search(ISearchable<StateType, CostType> searchable) = 0;

    virtual unsigned long getNumberOfStatesEvaluated() {
        return this->numberOfStatesEvaluated;
    }
};

#endif //AP_MS2_SEARCHER_H
