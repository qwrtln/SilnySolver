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
    cubeImproved.move(rotation::LEFT);
    // cubeImproved.printCubeState(); /* ~~This suppresses unnecessary output~~ */
    cubeImproved.resetCube();
    cubeImproved.setCube(1,2,3,4,5);
    cubeImproved.setCentre(0);
    cubeImproved.setInnerCorners(1);
    cubeImproved.setInnerEdges(2);
    cubeImproved.setOuterCorners(3);
    cubeImproved.setOuterEdges(4);
    cubeImproved.undoMove(rotation::LEFT);
}
#else

// This namespace provides functionality necessary for testing
// but not necessary for functioning of the cube itself.
namespace 
{
    CrazyCubeMoveMapper mapper;
    OuterCornersMapGenerator OCmapper;
    InnerCornersMapGenerator ICmapper;
    //OuterEdgesMapGenerator OEmapper;
    InnerEdgesMapGenerator IEmapper;
    CentreMapGenerator Cmapper;

    void setCubeImprovedFromCrazyCube(CrazyCubeImproved &cubeImproved, CrazyCube &cube)
    {
        cubeImproved.setCube( OCmapper.convertPiecesToInt(cube.getCubeState()),
                              ICmapper.convertPiecesToInt(cube.getCubeState()),
                              mapper.convertOuterEdgesToInt(cube.getCubeState()),
                              IEmapper.convertPiecesToInt(cube.getCubeState()),
                              Cmapper.convertPiecesToInt(cube.getCubeState())
                              );
    }

    unsigned long long getCubeImprovedState(CrazyCubeImproved &cubeImproved) 
    {
        return OCmapper.convertIntToPieces(cubeImproved.getOuterCorners()) | 
               mapper.convertIntToOuterEdges(cubeImproved.getOuterEdges()) | 
               ICmapper.convertIntToPieces(cubeImproved.getInnerCorners()) | 
               IEmapper.convertIntToPieces(cubeImproved.getInnerEdges()) | 
               Cmapper.convertIntToPieces(cubeImproved.getCentre());
    }
};

TEST_F(CrazyCubeImprovedTest, L)
{
    CrazyCube cube;
    cube.L();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::LEFT); // Zero translates as L

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}

TEST_F(CrazyCubeImprovedTest, F)
{
    CrazyCube cube;
    cube.F();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::FRONT); // One translates as F

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}

TEST_F(CrazyCubeImprovedTest, U)
{
    CrazyCube cube;
    cube.U();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::UP); // Two translates as U

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}

TEST_F(CrazyCubeImprovedTest, Ui)
{
    CrazyCube cube;
    cube.Ui();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::UP_INVERTED); // Three translates as Ui

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}

TEST_F(CrazyCubeImprovedTest, U2)
{
    CrazyCube cube;
    cube.U2();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::UP_2); // Four translates as U2

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}

TEST_F(CrazyCubeImprovedTest, Mv)
{
    CrazyCube cube;
    cube.Mv();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::MIDDLE_VERTICAL); // Five translates as Mv

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}

TEST_F(CrazyCubeImprovedTest, Mh)
{
    CrazyCube cube;
    cube.Mh();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::MIDDLE_HORIZONTAL); // Six translates as Mh

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}

TEST_F(CrazyCubeImprovedTest, MhRr)
{
    CrazyCube cube;
    cube.MhRr();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::MIDDLE_HORIZONTAL_RIGHT_ROTATION); // Six translates as MhRr

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}

TEST_F(CrazyCubeImprovedTest, MhLr)
{
    CrazyCube cube;
    cube.MhLr();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::MIDDLE_HORIZONTAL_LEFT_ROTATION); // Eight translates as MhLr

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}


TEST_F(CrazyCubeImprovedTest, MvFr) 
{
    CrazyCube cube;
    cube.MvFr();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::MIDDLE_VERTICAL_FRONT_ROTATION); // Nine translates as MvFr

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}

TEST_F(CrazyCubeImprovedTest, MvBr)
{
    CrazyCube cube;
    cube.MvBr();

    cubeImproved.resetCube();

    cubeToCompare.resetCube();
    cubeToCompare.move(rotation::MIDDLE_VERTICAL_BACK_ROTATION); // Ten translates as MvBr

    setCubeImprovedFromCrazyCube(cubeImproved,cube);

	ASSERT_EQ_HEX(getCubeImprovedState(cubeImproved), getCubeImprovedState(cubeToCompare))
}
#endif
