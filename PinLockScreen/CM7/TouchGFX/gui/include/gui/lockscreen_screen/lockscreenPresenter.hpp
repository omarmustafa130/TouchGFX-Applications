#ifndef LOCKSCREENPRESENTER_HPP
#define LOCKSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class lockscreenView;

class lockscreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    lockscreenPresenter(lockscreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~lockscreenPresenter() {};

private:
    lockscreenPresenter();

    lockscreenView& view;
};

#endif // LOCKSCREENPRESENTER_HPP
