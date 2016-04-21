#ifndef CRAZYCUBEPRUNER_H_
#define CRAZYCUBEPRUNER_H_

//#include "CrazyCube.h"
#include "CrazyCubeAbstract.h"

class CrazyCubePruner: public CrazyCubeAbstract
{
 private:
   CrazyCubePruner();
   int** outerCornersMap;
   int** innerCornersMap;
   int** outerEdgesMap;
   int** innerEdgesMap;
   int** centreMap;
   static CrazyCubePruner* instance;
  
  public:
   static CrazyCubePruner* getInstance();
   static void cleanup();
   ~CrazyCubePruner();

   int** getOuterCornersMap() { return outerCornersMap; }
   int** getInnerCornersMap() { return innerCornersMap; }
   int** getOuterEdgesMap() { return outerEdgesMap; }
   int** getInnerEdgesMap() { return innerEdgesMap; }
   int** getCentreMap() { return centreMap; }
};

#endif // CRAZYCUBEPRUNER_H_
