#ifndef LOCKSCREENVIEW_HPP
#define LOCKSCREENVIEW_HPP

#include <gui_generated/lockscreen_screen/lockscreenViewBase.hpp>
#include <gui/lockscreen_screen/lockscreenPresenter.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>

class lockscreenView : public lockscreenViewBase
{
public:
    lockscreenView();
    virtual ~lockscreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
private:
    bool showWrongPin; // Indicates if "Wrong PIN" is being displayed
    uint16_t wrongPinTimer; // Timer to track how long "Wrong PIN" is displayed
    char correctPin[5]="8426";
    char enteredPin[5]= "";
    uint8_t pinLength = 0;
    void OnButtonClicked_0();
    void OnButtonClicked_1();
    void OnButtonClicked_2();
    void OnButtonClicked_3();
    void OnButtonClicked_4();
    void OnButtonClicked_5();
    void OnButtonClicked_6();
    void OnButtonClicked_7();
    void OnButtonClicked_8();
    void OnButtonClicked_9();
    void OnButtonClicked_ent();
    void OnButtonClicked_clr();
    void validatePin();
    void appendDigitFromButton(const touchgfx::ButtonWithLabel& button);
    void updatePinDisplay();
    virtual void tickEvent();

};

#endif // LOCKSCREENVIEW_HPP
