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

}
