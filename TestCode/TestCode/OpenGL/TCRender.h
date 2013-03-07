#ifndef __TC_RENDER_H__
#define __TC_RENDER_H__

#include "TCCommon.h"
#include "tcgles.h"
#include "AutoReleaseObject.h"
#include "TCSingleton.h"

NS_TC_BEGIN
class TCRender:public TCSingleton<TCRender>{
	friend class TCSingleton<TCRender>;
private:
	TCRender();
	~TCRender();
public:
	void onResize(long width,long height);
	void onRender();

};

NS_TC_END
#endif