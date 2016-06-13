#ifndef CRAZYCUBEPRUNER_H_
#define CRAZYCUBEPRUNER_H_

#include "CrazyCubeAbstract.h"
#include "OuterCornersMapGenerator.h"
#include "InnerCornersMapGenerator.h"
#include "OuterEdgesMapGenerator.h"
#include "InnerEdgesMapGenerator.h"
#include "CentreMapGenerator.h"

class CrazyCubePruner: public CrazyCubeAbstract
{
 private:

   CrazyCubePruner();
   std::vector<std::vector<int>> outerCornersMap;
   std::vector<std::vector<int>> innerCornersMap;
   std::vector<std::vector<int>> outerEdgesMap;
   std::vector<std::vector<int>> innerEdgesMap;
   std::vector<std::vector<int>> centreMap;
   static CrazyCubePruner* instance;
  
  public:
   static CrazyCubePruner* getInstance();
   static void cleanup();
   ~CrazyCubePruner();

   std::vector<std::vector<int>>& getOuterCornersMap() { return outerCornersMap; }
   std::vector<std::vector<int>>& getInnerCornersMap() { return innerCornersMap; }
   std::vector<std::vector<int>>& getOuterEdgesMap() { return outerEdgesMap; }
   std::vector<std::vector<int>>& getInnerEdgesMap() { return innerEdgesMap; }
   std::vector<std::vector<int>>& getCentreMap() { return centreMap; }
};

#endif // CRAZYCUBEPRUNER_H_
