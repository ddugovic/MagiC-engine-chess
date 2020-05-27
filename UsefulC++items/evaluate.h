/*
 * Teki, a free UCI-compliant chess engine
 * Copyright (C) 2017 Manik Charan
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef EVALUATE_H
#define EVALUATE_H

#include "score.h"

extern Score piece_value[5];
extern Score psqt[6][64];
extern Score psq_tmp[6][64];

namespace eval
{
    inline void init()
    {
        int k = 0;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0;  j < 4; ++j) {
                int sq1 = get_sq(i, j);
                int sq2 = get_sq(i, (7 - j));
                for (int pt = PAWN; pt <= KING; ++pt) {
                    psqt[pt][sq1]
                        = psqt[pt][sq2]
                        = psq_tmp[pt][k];
                }
                ++k;
            }
        }
    }
}

#endif
