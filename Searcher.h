#ifndef AP_MS2_SEARCHER_H
#define AP_MS2_SEARCHER_H

#include "ISearcher.h"
#include "MyPriorityQueue.h"

/**
 * Defining Algorithms for Graph problems.
 * @tparam SolutionType Solution's implementation type.
 * @tparam StateType State type.
 * @tparam CostType double type.
 */
template<typename SolutionType, typename StateType, typename CostType>
class Searcher : public ISearcher<SolutionType, StateType, CostType> {
protected:
    unsigned long numberOfStatesEvaluated = 0;
public:
    virtual SolutionType search(ISearchable<StateType, CostType> *searchable) = 0;

    /**
     * For analytics purposes only, used to sum up how many nodes have been evaluated.
     * @return
     */
    virtual unsigned long getNumberOfStatesEvaluated() {
        return this->numberOfStatesEvaluated;
    }
};

#endif //AP_MS2_SEARCHER_H
