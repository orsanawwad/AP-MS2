//
// Created by Orsan Awwad on 08/01/2019.
//

#ifndef AP_MS2_ISOLVER_H
#define AP_MS2_ISOLVER_H

namespace server_side {
    template <typename Problem, typename Solution>
    class ISolver {
    public:
        virtual Solution solve(Problem problem) = 0;
    };
}

#endif //AP_MS2_ISOLVER_H
