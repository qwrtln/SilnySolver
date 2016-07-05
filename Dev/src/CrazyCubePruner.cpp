#include "CrazyCubePruner.h"

CrazyCubePruner* CrazyCubePruner::instance = nullptr;

CrazyCubePruner* CrazyCubePruner::getInstance() {
  if(!instance) {
    instance = new CrazyCubePruner();
  }
  return instance;
}

CrazyCubePruner::CrazyCubePruner() {
  OuterCornersMapGenerator OCmapper;
  InnerCornersMapGenerator ICmapper;
  OuterEdgesMapGenerator OEmapper;
  InnerEdgesMapGenerator IEmapper;
  CentreMapGenerator Cmapper;

  outerCornersMap = OCmapper.generateMoveMap();
  innerCornersMap = ICmapper.generateMoveMap();
  outerEdgesMap = OEmapper.generateMoveMap();
  innerEdgesMap = IEmapper.generateMoveMap();
  centreMap = Cmapper.generateMoveMap();
}

CrazyCubePruner::~CrazyCubePruner() {

}
