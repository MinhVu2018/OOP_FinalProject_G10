#ifndef _Vehicle_h_
#define _Vehicle_h_

#include "Barrier.h"
#include "Traffic.h"

class Vehicle : public Barrier
{
public:
	void crash()
	{
		PlaySound(TEXT("D:\\crash.wav"), NULL, SND_SYNC);
	}
protected:
};

#endif