#ifndef CRAZYCUBECACHE_H_
#define CRAZYCUBECACHE_H_

#include "CrazyCubeAbstract.h"
#include "CrazyCubeMapper.h"

class CrazyCubeCache: public CrazyCubeAbstract
{
	
private:
	
  CrazyCubeCache();
  int** outerCornersMap;
  int** innerCornersMap;
  int** outerEdgesMap;
  int** innerEdgesMap;
  int** centreMap;
  static CrazyCubeCache* instance;
	
public:
    static CrazyCubeCache* getInstance();
    static void cleanup();
    ~CrazyCubeCache();
	
	int** getOuterCornersMap();
	int** getInnerCornersMap();
	int** getOuterEdgesMap();
	int** getInnerEdgesMap();
	int** getCentreMap();
};

#endif /* CRAZYCUBECACHE_H_ */
