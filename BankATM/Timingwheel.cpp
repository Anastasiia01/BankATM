#include "Timingwheel.h"
#include "Bank.h"

Timingwheel::Timingwheel()
{
	current_slot = 0;
	for (int i = 0; i < slot.length;i++) {
		slot[i] = nullptr;
	}
}
