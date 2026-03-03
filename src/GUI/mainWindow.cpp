#include "mainWindow.h"

bool EncryptorApp::OnInit() {
    mainFrame *frame = new mainFrame();
    frame->show();
    return true;
}

mainFrame::mainFrame() : wxFrame(nullptr, wxID_ANY, "EncryptorApp") {
    CreateStatusBar();
    SetStatusText("Works!");
}

