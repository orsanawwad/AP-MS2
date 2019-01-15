//
// Created by Orsan Awwad on 13/01/2019.
//

#ifndef AP_MS2_SOLUTION_H
#define AP_MS2_SOLUTION_H

template<typename ReturnType, typename CostType>
class Solution {
public:
    virtual CostType getCost() = 0;
    virtual ReturnType getValues() = 0;
};

#endif //AP_MS2_SOLUTION_H
