#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
#include "cmsis_os.h"
#include "myfile.h"
extern "C"{
	extern osMessageQueueId_t LEDQueueHandle;
}
#endif
Model::Model() : modelListener(0)
{

}

void Model::tick()
{

}

void Model::LED_Control(bool state)
{
#ifndef SIMULATOR
	if(osMessageQueueGetSpace(LEDQueueHandle)>0)
	{
		osMessageQueuePut(LEDQueueHandle, &state, 0, 0);
	}
#endif
}

