#include "CrazyCubeImproved.h"
#include "CrazyCube.h"
#include "TestExecuter.h"

class CrazyCubeImprovedTest: public BaseTest
{
public:
	CrazyCubeImprovedTest(string testCase, string testName)
		:BaseTest(testCase, testName)
	{
		SetUp();
	}
protected:
	void SetUp()
	{

	}
	void TearDown()
	{

	}
protected:
	CrazyCubeImproved cubeImproved;
    CrazyCubeImproved cubeToCompare;
};

#ifdef MEMORY_CHECK
TEST_F(CrazyCubeImprovedTest, findingMemoryLeaks)
{
    cubeImproved.getCentre();
    cubeImproved.getInnerCorners();
    cubeImproved.getInnerEdges();
    cubeImproved.getOuterCorners();
    cubeImproved.getOuterEdges();
    cubeImproved.isSolved();
    cubeImproved.move(rotation::L);
    // cubeImproved.printCubeState(); /* ~~This suppresses unnecessary output~~ */
    cubeImproved.resetCube();
    cubeImproved.setCube(1,2,3,4,5);
    cubeImproved.setCentre(0);
    cubeImproved.setInnerCorners(1);
    cubeImproved.setInnerEdges(2);
    cubeImproved.setOuterCorners(3);
    cubeImproved.setOuterEdges(4);
    cubeImproved.undoMove(rotation::L);
}
#else

// This namespace provides functionality necessary for testing
// but not necessary for functioning of the cube itself.
namespace 
{
    CrazyCubeMapper mapper;

    void setCubeImprovedFromCrazyCube(CrazyCubeImproved &cubeImproved, CrazyCube &cube)
    {
        cubeImproved.setCube( mapper.convertOuterCornersToInt(cube.getCubeState()),
                              mapper.convertInnerCornersToInt(cube.getCubeState()),
                              mapper.convertOuterEdgesToInt(cube.getCubeState()),
                              mapper.convertInnerEdgesToInt(cube.getCubeState()),
                              mapper.convertCentreToInt(cube.getCubeState())
                              );
    }

    unsigned long long getCubeImprovedState(CrazyCubeImproved &cubeImproved) 
    {
        return mapper.convertIntToOuterCorners(cubeImproved.getOuterCorners()) | 
               mapper.convertIntToOuterEdges(cubeImproved.getOuterEdges()) | 
               mapper.convertIntToInnerCorners(cubeImproved.getInnerCorners()) | 
               mapper.convertIntToInnerEdges(cubeImproved.getInnerEdges()) | 
               mapper.convertIntToCentre(cubeImproved.getCentre());
    }
}

TEST_F(CrazyCubeImprovedTest, L)
{
    CrazyCube cube;
    cube.L();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::L); // Zero translates as L

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}

TEST_F(CrazyCubeImprovedTest, F)
{
    CrazyCube cube;
    cube.F();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::F); // One translates as F

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}

TEST_F(CrazyCubeImprovedTest, U)
{
    CrazyCube cube;
    cube.U();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::U); // Two translates as U

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}

TEST_F(CrazyCubeImprovedTest, Ui)
{
    CrazyCube cube;
    cube.Ui();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::UI); // Three translates as Ui

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}

TEST_F(CrazyCubeImprovedTest, U2)
{
    CrazyCube cube;
    cube.U2();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::U2); // Four translates as U2

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}

TEST_F(CrazyCubeImprovedTest, Mv)
{
    CrazyCube cube;
    cube.Mv();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::MV); // Five translates as Mv

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}

TEST_F(CrazyCubeImprovedTest, Mh)
{
    CrazyCube cube;
    cube.Mh();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::MH); // Six translates as Mh

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}

TEST_F(CrazyCubeImprovedTest, MhRr)
{
    CrazyCube cube;
    cube.MhRr();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::MHRR); // Six translates as MhRr

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}

TEST_F(CrazyCubeImprovedTest, MhLr)
{
    CrazyCube cube;
    cube.MhLr();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::MHLR); // Eight translates as MhLr

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}


TEST_F(CrazyCubeImprovedTest, MvFr) 
{
    CrazyCube cube;
    cube.MvFr();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::MVFR); // Nine translates as MvFr

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}

TEST_F(CrazyCubeImprovedTest, MvBr)
{
    CrazyCube cube;
    cube.MvBr();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::MVBR); // Ten translates as MvBr

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}
#endif
