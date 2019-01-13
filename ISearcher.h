#ifndef AP_MS2_ISEARCHER_H
#define AP_MS2_ISEARCHER_H

#include "ISearchable.h"

template<typename StateType, typename CostType>
class ISearcher {
public:
    virtual ISolution search(ISearchable<StateType, CostType> searchable) = 0;
    virtual unsigned long getNumberOfStatesEvaluated() = 0;
};

#endif //AP_MS2_ISEARCHER_H