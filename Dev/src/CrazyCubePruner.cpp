#include "CrazyCubePruner.h"

CrazyCubePruner* CrazyCubePruner::instance = nullptr;

CrazyCubePruner* CrazyCubePruner::getInstance() {
  if(!instance) {
    instance = new CrazyCubePruner();
  }
  return instance;
}

CrazyCubePruner::CrazyCubePruner() {
  CrazyCubeMapper mapper;

  outerCornersMap = mapper.generateOuterCornersMap();
  innerCornersMap = mapper.generateInnerCornersMap();
  outerEdgesMap = mapper.generateOuterEdgesMap();
  innerEdgesMap = mapper.generateInnerEdgesMap();
  centreMap = mapper.generateCentreMap();
}

CrazyCubePruner::~CrazyCubePruner() {
  // Clean the arrays created using CrazyCubeMapper
  for(int i = 0; i < factorials[NUM_OF_CORNERS]; ++i) {
    delete[] innerCornersMap[i];
    delete[] outerCornersMap[i];
  }
  delete[] innerCornersMap;
  delete[] outerCornersMap;

  for(int i = 0; i < factorials[NUM_OF_EDGES]; ++i) {
    delete[] innerEdgesMap[i];
    delete[] outerEdgesMap[i];
  }

  delete[] innerEdgesMap;
  delete[] outerEdgesMap;

  for(int i = 0; i < factorials[2]; ++i) {
    delete[] centreMap[i];
  }
  delete[] centreMap;
}

void CrazyCubePruner::cleanup() {
 delete instance;
 instance = nullptr;
}
