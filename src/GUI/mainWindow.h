#include <wx/wx.h>

#pragma once

class EncryptorApp : public wxApp {
public:
    bool OnInit() override;
};

class mainFrame : public wxFrame {
public:
    mainFrame();
};
