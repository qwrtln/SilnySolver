#ifndef CRAZYCUBEPRUNER_H_
#define CRAZYCUBEPRUNER_H_

#include "CrazyCubeAbstract.h"
#include "OuterCornersPruneMapGenerator.h"
#include "InnerCornersPruneMapGenerator.h"
#include "OuterEdgesPruneMapGenerator.h"
#include "InnerEdgesPruneMapGenerator.h"
#include "CentrePruneMapGenerator.h"

#include <vector>
#include <memory>

class CrazyCubePruner: public CrazyCubeAbstract
{
 private:

   CrazyCubePruner();
   std::vector<int> outerCornersPruneMap;
   std::vector<int> innerCornersPruneMap;
   std::vector<int> outerEdgesPruneMap;
   std::vector<int> innerEdgesPruneMap;
   std::vector<int> centrePruneMap;
   static std::unique_ptr<CrazyCubePruner> instance;
  
public:
   static CrazyCubePruner* getInstance();
   static void cleanup();
   ~CrazyCubePruner();

   std::vector<int>& getOuterCornersPruneMap();
   std::vector<int>& getInnerCornersPruneMap();
   std::vector<int>& getOuterEdgesPruneMap();
   std::vector<int>& getInnerEdgesPruneMap();
   std::vector<int>& getCentrePruneMap();

};
#endif // CRAZYCUBEPRUNER_H_
