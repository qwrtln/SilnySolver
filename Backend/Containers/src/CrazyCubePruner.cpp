#include "CrazyCubePruner.h"
#include "Tracer.h"

CrazyCubePruner* CrazyCubePruner::instance = nullptr;

CrazyCubePruner* CrazyCubePruner::getInstance() {
  if(!instance) {
    instance = new CrazyCubePruner();
  }
  return instance;
}

CrazyCubePruner::CrazyCubePruner() {

  TRACE( TRACE_ALL, 0, "Constructor CrazyCubePruner");

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

    TRACE( TRACE_ALL, 0, "Destructor CrazyCubePruner");
}
