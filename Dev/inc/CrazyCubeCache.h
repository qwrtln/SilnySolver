#ifndef CRAZYCUBECACHE_H_
#define CRAZYCUBECACHE_H_

#include "CrazyCubeAbstract.h"

class CrazyCubeCache: public CrazyCubeAbstract
{
	
private:
	
    int** outerCornersMap;
	int** innerCornersMap;
	int** outerEdgesMap;
	int** innerEdgesMap;
	int** centreMap;
	
public:

    CrazyCubeCache();
	~CrazyCubeCache();

	void setOuterCornersMap(int** outerCornersMap);
	void setInnerCornersMap(int** innerCornersMap);
	void setOuterEdgesMap(int** outerEdgesMap);
	void setInnerEdgesMap(int** innerEdgesMap);
	void setCentreMap(int** centreMap);
	
	int** getOuterCornersMap();
	int** getInnerCornersMap();
	int** getOuterEdgesMap();
	int** getInnerEdgesMap();
	int** getCentreMap();
};


#endif /* CRAZYCUBECACHE_H_ */
