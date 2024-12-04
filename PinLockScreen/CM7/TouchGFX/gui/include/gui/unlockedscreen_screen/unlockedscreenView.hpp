#ifndef UNLOCKEDSCREENVIEW_HPP
#define UNLOCKEDSCREENVIEW_HPP

#include <gui_generated/unlockedscreen_screen/unlockedscreenViewBase.hpp>
#include <gui/unlockedscreen_screen/unlockedscreenPresenter.hpp>

class unlockedscreenView : public unlockedscreenViewBase
{
public:
    unlockedscreenView();
    virtual ~unlockedscreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // UNLOCKEDSCREENVIEW_HPP
