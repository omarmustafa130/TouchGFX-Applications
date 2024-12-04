#ifndef PATTERNSCREENVIEW_HPP
#define PATTERNSCREENVIEW_HPP

#include <gui_generated/patternscreen_screen/patternscreenViewBase.hpp>
#include <gui/patternscreen_screen/patternscreenPresenter.hpp>

class patternscreenView : public patternscreenViewBase
{
public:
    patternscreenView();
    virtual ~patternscreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // PATTERNSCREENVIEW_HPP
