/*
 * MoveMapsGeneratorI_mock.h
 *
 *  Created on: Jun 18, 2016
 *      Author: qwrtln
 */

// This class allows to neatly test methods implemented in
// abstract class MoveMapsGeneratorI.
class MoveMapsGeneratorI_mock: public MoveMapsGeneratorI
{
    int convertPiecesToInt(unsigned long long) override
    {
        return 0;
    }

    unsigned long long convertIntToPieces(int) override
    {
        return 0;
    }

    int getMapLength() override
    {
        return 0;
    }
};

