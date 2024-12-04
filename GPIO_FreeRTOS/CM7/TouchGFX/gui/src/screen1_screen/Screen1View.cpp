#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}


void Screen1View::onClicked()
{
	presenter->LED_Control(true);
	Unicode::strncpy(textArea1Buffer, "LED ON", TEXTAREA1_SIZE);
	textArea1.invalidate();
}


void Screen1View::offClicked()
{
	presenter->LED_Control(false);
	Unicode::strncpy(textArea1Buffer, "LED OFF", TEXTAREA1_SIZE);
	textArea1.invalidate();
}
