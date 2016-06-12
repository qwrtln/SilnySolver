#include "CrazyCubePruner.h"

CrazyCubePruner* CrazyCubePruner::instance = nullptr;

CrazyCubePruner* CrazyCubePruner::getInstance() {
  if(!instance) {
    instance = new CrazyCubePruner();
  }
  return instance;
}

CrazyCubePruner::CrazyCubePruner() {
  CrazyCubeMoveMapper mapper;
  OuterCornersMapGenerator OCmapper;
  InnerCornersMapGenerator ICmapper;
  //OuterEdgesMapGenerator OEmapper;
  InnerEdgesMapGenerator IEmapper;

  outerCornersMap = OCmapper.generateMoveMap();
  innerCornersMap = ICmapper.generateMoveMap();
  outerEdgesMap = mapper.generateOuterEdgesMap();
  innerEdgesMap = IEmapper.generateMoveMap();
  centreMap = mapper.generateCentreMap();
}

CrazyCubePruner::~CrazyCubePruner() {

}
