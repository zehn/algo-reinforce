/*! @file abstractFactory.cc
 *  @brief Abstract Factory Pattern example
 *
 *  The abstract factory pattern provides a way to encapsulate a group of 
 *  individual factories that have a common theme without specifying their 
 *  concrete classes.
 */
#include <iostream>

using namespace std;

/**************** abstract classes ****************/
class Button {
public:
    virtual void Paint() = 0;
};

class Frame {
public:
    virtual void Paint() = 0;
};

// abstract factory
class GUIFactory {
public:
    virtual Button* CreateButton() = 0;
    virtual Frame* CreateFrame() = 0;
};

/**************** classes ****************/
class WinButton : public Button {
public:
    void Paint() {
        cout << "Render a window button" << endl;
    } 
};

class OSXButton : public Button {
public:
    void Paint() {
        cout << "Render an OSX button" << endl;
    }
};

class WinFrame : public Frame {
public:
    void Paint() {
        cout << "Render a window frame" << endl;
    }
};

class OSXFrame : public Frame {
public:
    void Paint() {
        cout << "Render an OSX frame" << endl;
    }
};

/**************** factories ****************/
class WinFactory : public GUIFactory {
public:
    virtual Button* CreateButton() {
        return new WinButton();
    }
    virtual Frame* CreateFrame() {
        return new WinFrame();
    }
};

class OSXFactory : public GUIFactory {
public:
    virtual Button* CreateButton() {
        return new OSXButton();
    }
    virtual Frame* CreateFrame() {
        return new OSXFrame();
    }
};

int main(void) {
    WinFactory *factory_win = new WinFactory();
    Frame *windows_frame = factory_win->CreateFrame();
    windows_frame->Paint();
    Button *windows_button = factory_win->CreateButton();
    windows_button->Paint();

    OSXFactory* factory_osx = new OSXFactory();
    Frame *osx_frame = factory_osx->CreateFrame();
    osx_frame->Paint();
    Button *osx_button = factory_osx->CreateButton();
    osx_button->Paint();

    return 0;
}

