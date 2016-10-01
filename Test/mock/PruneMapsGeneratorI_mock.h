/*
 * PruneMapsGeneratorI_mock.h
 *
 *  Created on: Oct 1, 2016
 *      Author: qwrtln
 */
#include "PruneMapsGeneratorI.h"

// This class allows to neatly test methods implemented in
// abstract class PruneMapsGeneratorI.
class PruneMapsGeneratorI_mock: public PruneMapsGeneratorI
{
    public:
        std::vector<std::vector<int>> getPieceMap() override
        {
            std::vector<std::vector<int>> NoEffingVector(0, std::vector<int>(0));
            return NoEffingVector;
        }
};

