
#ifndef _makro_h_
#define _makro_h_

#include "IVTEntry.h"

#define PREPAREENTRY(ivtno, routineflag)\
	void interrupt newRoutine##ivtno(...); \
	IVTEntry ivtentry##ivtno(ivtno, newRoutine##ivtno); \
	void interrupt newRoutine##ivtno(...)\
	{\
	ivtentry##ivtno.signalEvents(); \
if (routineflag)\
	ivtentry##ivtno.oldRoutine(); \
	}


#endif // !_makro_h_
