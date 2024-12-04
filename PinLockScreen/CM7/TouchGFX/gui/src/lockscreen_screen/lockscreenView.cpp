#include <gui/lockscreen_screen/lockscreenView.hpp>
#include <string.h>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <texts/TextKeysAndLanguages.hpp> // For text handling
#include <touchgfx/Color.hpp>
#include "cmsis_os.h"

lockscreenView::lockscreenView()
{

}

void lockscreenView::setupScreen()
{
    lockscreenViewBase::setupScreen();

    // Clear the wildcard buffer
    memset(pinDisplayTextBuffer, 0, sizeof(pinDisplayTextBuffer));

    // Add the initial text wrapped in '<' and '>'
    Unicode::strncpy(pinDisplayTextBuffer, "Enter PIN", sizeof(pinDisplayTextBuffer) / sizeof(pinDisplayTextBuffer[0]));

    // Link the wildcard buffer to the text widget
    pinDisplayText.setWildcard(pinDisplayTextBuffer);

    // Refresh the display
    pinDisplayText.invalidate();
}


void lockscreenView::tearDownScreen()
{
    lockscreenViewBase::tearDownScreen();
}



void lockscreenView::OnButtonClicked_0()
{
	appendDigitFromButton(button_0);
}



void lockscreenView::OnButtonClicked_1()
{
	appendDigitFromButton(button_1);
}

void lockscreenView::OnButtonClicked_2()
{
	appendDigitFromButton(button_2);
}

void lockscreenView::OnButtonClicked_3()
{
	appendDigitFromButton(button_3);
}

void lockscreenView::OnButtonClicked_4()
{
	appendDigitFromButton(button_4);
}

void lockscreenView::OnButtonClicked_5()
{
	appendDigitFromButton(button_5);
}

void lockscreenView::OnButtonClicked_6()
{
	appendDigitFromButton(button_6);
}

void lockscreenView::OnButtonClicked_7()
{
	appendDigitFromButton(button_7);
}
void lockscreenView::OnButtonClicked_8()
{
	appendDigitFromButton(button_8);
}
void lockscreenView::OnButtonClicked_9()
{
	appendDigitFromButton(button_9);
}

void lockscreenView::OnButtonClicked_clr()
{
    // Clear the entered PIN
    memset(enteredPin, 0, sizeof(enteredPin));
    pinLength = 0;

    // Reset the display text to "Enter PIN"
    Unicode::strncpy(pinDisplayTextBuffer, "Enter PIN", sizeof(pinDisplayTextBuffer) / sizeof(pinDisplayTextBuffer[0]));

    // Refresh the display
    pinDisplayText.invalidate();
}

void lockscreenView::OnButtonClicked_ent()
{
    validatePin(); // Validate the entered PIN
}

void lockscreenView::validatePin()
{
    const char correctPin[] = "8426"; // Define the correct PIN

    if (strcmp(enteredPin, correctPin) == 0) // Check if the entered PIN matches
    {
        // Transition to the next screen
        application().gotounlockedscreenScreenSlideTransitionNorth();
    }
    else
    {
        // Display "Wrong PIN" message in red
        Unicode::strncpy(pinDisplayTextBuffer, "Enter PIN", sizeof(pinDisplayTextBuffer) / sizeof(pinDisplayTextBuffer[0]));
        pinDisplayText.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0)); // Set text color to red
        pinDisplayText.invalidate(); // Refresh the display

        // Clear the entered PIN
        memset(enteredPin, 0, sizeof(enteredPin));
        pinLength = 0;

        // Set state to show "Wrong PIN"
        showWrongPin = true;
        wrongPinTimer = 0; // Reset timer
    }
}


void lockscreenView::appendDigitFromButton(const touchgfx::ButtonWithLabel& button)
{
    if (pinLength < 4) // Limit the PIN to 4 digits
    {
        touchgfx::TypedText labelText = button.getLabelText();

        // Retrieve the actual text associated with the TypedText
        const touchgfx::Unicode::UnicodeChar* buttonText = labelText.getText();
        if (buttonText != nullptr)
        {
            // Append the first character from the button text
            enteredPin[pinLength++] = static_cast<char>(buttonText[0]); // Convert UnicodeChar to char
            enteredPin[pinLength] = '\0'; // Null-terminate the string

            updatePinDisplay();
        }
    }
}

void lockscreenView::updatePinDisplay()
{
    pinDisplayText.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255)); // Set text color to red

    if (pinLength == 0) // No digits entered yet
    {
        // Display "Enter PIN" when no digits are entered
        Unicode::strncpy(pinDisplayTextBuffer, "Enter PIN", sizeof(pinDisplayTextBuffer) / sizeof(pinDisplayTextBuffer[0]));
    }
    else
    {
        // Display the entered numbers directly
        Unicode::UnicodeChar enteredText[5] = {0}; // Buffer for entered PIN + '\0'

        for (uint8_t i = 0; i < pinLength; ++i)
        {
            enteredText[i] = enteredPin[i]; // Copy the actual entered digits
        }

        enteredText[pinLength] = '\0'; // Null-terminate

        Unicode::strncpy(pinDisplayTextBuffer, enteredText, sizeof(pinDisplayTextBuffer) / sizeof(pinDisplayTextBuffer[0]));
    }

    pinDisplayText.invalidate(); // Refresh the display
}

void lockscreenView::tickEvent()
{
    if (showWrongPin)
    {
        if (++wrongPinTimer >= 120) // Assuming 60 ticks per second, 120 ticks = 2 seconds
        {
            // Reset to "Enter PIN" after 2 seconds
            showWrongPin = false;
            wrongPinTimer = 0;

            updatePinDisplay();
            pinDisplayText.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255)); // Reset color to white
            pinDisplayText.invalidate(); // Refresh the display
        }
    }
}
