/*
 * CrazyCube_test.cpp
 *
 *  Created on: Aug 13, 2015
 *      Author: qwrtln
 */
#include "CrazyCube.h"
#include "TestExecuter.h"
#include "ConstDefs.h"
#include <cmath>
#include <pthread.h>

extern TestExecuter testExecuter;

unsigned long long globalnaZmienna = 0;

class CrazyCubeTest: public BaseTest
{
private:
	struct doMoveS
	{
		unsigned int depth;
		unsigned int move;
	};
public:
	CrazyCubeTest(string testCase, string testName)
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
	static void* doMoves(void* args)
	{
		doMoveS* s = (doMoveS*)args;
		int mov = s->move;
		unsigned int max = (unsigned int)pow((double)NUM_OF_MOVES, (double)s->depth);
		for(unsigned int i = 0; i < max; i++) 
		{			
				cube.move(mov);
				++globalnaZmienna;
		}		
		pthread_exit(NULL);
	}
	void TestMove(unsigned int depth)
	{
		globalnaZmienna = 0;

		cout << "Test of depth " << depth << "(" << (unsigned int)pow((double)NUM_OF_MOVES, (double)depth + 1) << " moves): ";
		cout.flush();
		time_t start = clock();
		unsigned int max = (unsigned int)pow((double)NUM_OF_MOVES, (double)depth);
		for(unsigned short int j = 0; j < NUM_OF_MOVES; j++)
		{
			for(unsigned int i = 0; i < max; i++) 
			{			
				cube.move(j);
				++globalnaZmienna;
			}		
		}
		cout << ((float)(clock() - start))/CLOCKS_PER_SEC << "s\n" << "Counter: " << globalnaZmienna << endl;
	}
	void TestMovePthreads(unsigned long int depth)
	{
		globalnaZmienna = 0;
		cout << "Test of depth " << depth << "(" << (unsigned int)pow((double)NUM_OF_MOVES, (double)depth + 1) << " moves): ";
		cout.flush();
		doMoveS* s = new doMoveS;
		s->depth = depth;
		// PTHREADS' STUFF
		pthread_t threads[NUM_OF_MOVES];
		pthread_attr_t attr;
		void* status;
		int rc;
		pthread_attr_init(&attr);
   	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
		// ----------------
	

		time_t start;
		time(&start);
		
		for(unsigned short int j = 0; j < NUM_OF_MOVES; j++)
		{
			s->move = j;
			pthread_create(&threads[j], &attr, CrazyCubeTest::doMoves, (void*) s);

		}
		for(unsigned short int j = 0; j < NUM_OF_MOVES; j++)
		{
			rc = pthread_join(threads[j], &status);
		}
		time_t end;
		time(&end);
		cout << difftime(end, start) << " s," << " Counter: " << globalnaZmienna << endl;
		delete s;
		pthread_attr_destroy(&attr);
}
protected:
	static CrazyCube cube;
};

CrazyCube CrazyCubeTest::cube;

TEST_F(CrazyCubeTest, setCentreTest)
{
	cube.setCentre(true);
	ASSERT_EQ_HEX( (cube.getCubeState() & (static_cast<unsigned long long>(true) << cube.centrePosition)),
			static_cast<unsigned long long>(true) << cube.centrePosition )
}

TEST_F(CrazyCubeTest, setCornersTest)
{
	cornerNames corners[NUM_OF_CORNERS] = {ygry, yrby, yboy, yogy, wrgw, wbrw, wobw};
	cube.setCorners(corners);
	ASSERT_EQ_HEX((solvedCube & cube.getCubeState()), cube.getCubeState() )
}

TEST_F(CrazyCubeTest, setEdgesTest)
{
	edgeNames edges[NUM_OF_EDGES] = {yry, yby, yoy, ygy, wrw, wbw, wow, wgw};
	cube.setEdges(edges);
	ASSERT_EQ_HEX((solvedCube & cube.getCubeState()), cube.getCubeState())
}

TEST_F(CrazyCubeTest, setCubeTest)
{
	ASSERT_EQ_HEX(cube.checkIfSolved(), 1);
	cout << dec;
}

TEST_F(CrazyCubeTest, setNEGATIVEcubeTest)
{
	edgeNames edges[NUM_OF_EDGES] = {wgw, yry, yby, yoy, ygy, wrw, wbw, wow}; // Wrong sequence
	cube.setEdges(edges);
	ASSERT_NE(cube.checkIfSolved(), 1)
}

TEST_F(CrazyCubeTest, setWholeCubeTest)
{
	cube.setCubeState(0xf);
	edgeNames edges[NUM_OF_EDGES] = {yry, yby, yoy, ygy, wrw, wbw, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {ygry, yrby, yboy, yogy, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	ASSERT_EQ_HEX(cube.checkIfSolved(), 1)
}

TEST_F(CrazyCubeTest, L)
{
	edgeNames edges[NUM_OF_EDGES] = {yry, wbw, yoy, ygy, wrw, yby, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {ygry, wobw, wbrw, yogy, wrgw, yboy, yrby};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.L();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, U)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {ygy, yry, yby, yoy, wrw, wbw, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {yogy, ygry, yrby, yboy, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	
	cubeToCompare.U();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, F)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {wrw, yby, yoy, ygy, yry, wbw, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {wbrw, wrgw, yboy, yogy, yrby, ygry, wobw};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.F();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, Ui) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {yby, yoy, ygy, yry, wrw, wbw, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {yrby, yboy, yogy, ygry, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.Ui();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, U2) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {yoy, ygy, yry, yby, wrw, wbw, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {yboy, yogy, ygry, yrby, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.U2();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, Mv) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {wow, yby, wrw, ygy, yoy, wbw, yry, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {ygry, yrby, yboy, yogy, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	cube.toggleCentre();
	CrazyCube cubeToCompare;
	cubeToCompare.Mv();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, Mh)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {yry, wgw, yoy, wbw, wrw, ygy, wow, yby};
	cornerNames corners[NUM_OF_CORNERS] = {ygry, yrby, yboy, yogy, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	cube.toggleCentre();
	CrazyCube cubeToCompare;
	cubeToCompare.Mh();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MhRr) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {yoy, yby, yry, wgw, wrw, wbw, wow, ygy};
	cornerNames corners[NUM_OF_CORNERS] = {yboy, yogy, ygry, yrby, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.MhRr();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MhLr)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {yoy, wbw, yry, ygy, wrw, yby, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {yboy, yogy, ygry, yrby, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.MhLr();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MvFr) 
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {wrw, ygy, yoy, yby, yry, wbw, wow, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {yboy, yogy, ygry, yrby, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.MvFr();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, MvBr)
{
	cube.resetCube();
	edgeNames edges[NUM_OF_EDGES] = {yry, ygy, wow, yby, wrw, wbw, yoy, wgw};
	cornerNames corners[NUM_OF_CORNERS] = {yboy, yogy, ygry, yrby, wrgw, wbrw, wobw};
	cube.setWholeCube(true,edges,corners);
	CrazyCube cubeToCompare;
	cubeToCompare.MvBr();
	ASSERT_EQ_HEX(cube.getCubeState(), cubeToCompare.getCubeState())
}

TEST_F(CrazyCubeTest, Move_undoMoveTest)
{
	cube.resetCube();
	// placeholder TODO
}

TEST_F(CrazyCubeTest, PerformanceTest)
{
	cube.resetCube(); 
	for(unsigned short int i = 0; i < 9; i++)
	{
		TestMove(i);
	}
}

TEST_F(CrazyCubeTest, PerformancePthreadsTest)
{
	cube.resetCube(); 
	for(unsigned short int i = 0; i < 9; i++)
	{
		TestMovePthreads(i);
	}
}
