#ifndef CRAZYCUBECACHE_H_
#define CRAZYCUBECACHE_H_

#include "CrazyCubeAbstract.h"
#include "CrazyCubeMapper.h"

#include <vector>

class CrazyCubeCache: public CrazyCubeAbstract
{
	
private:
	
  CrazyCubeCache();
  std::vector<std::vector<int>> outerCornersMap;
  std::vector<std::vector<int>> innerCornersMap;
  std::vector<std::vector<int>> outerEdgesMap;
  std::vector<std::vector<int>> innerEdgesMap;
  std::vector<std::vector<int>> centreMap;
  static CrazyCubeCache* instance;
	
public:
    static CrazyCubeCache* getInstance();
    static void cleanup();
    ~CrazyCubeCache();
	
    std::vector<std::vector<int>>& getOuterCornersMap();
    std::vector<std::vector<int>>& getInnerCornersMap();
    std::vector<std::vector<int>>& getOuterEdgesMap();
    std::vector<std::vector<int>>& getInnerEdgesMap();
    std::vector<std::vector<int>>& getCentreMap();
};

#endif /* CRAZYCUBECACHE_H_ */
