/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef PATTERNSCREENVIEWBASE_HPP
#define PATTERNSCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/patternscreen_screen/patternscreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/Button.hpp>

class patternscreenViewBase : public touchgfx::View<patternscreenPresenter>
{
public:
    patternscreenViewBase();
    virtual ~patternscreenViewBase() {}
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Image image1;
    touchgfx::Button button1;
    touchgfx::Button button1_1;
    touchgfx::Button button1_2;
    touchgfx::Button button1_3;
    touchgfx::Button button1_4;
    touchgfx::Button button1_5;
    touchgfx::Button button1_6;
    touchgfx::Button button1_7;
    touchgfx::Button button1_8;

private:

};

#endif // PATTERNSCREENVIEWBASE_HPP
