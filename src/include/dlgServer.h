//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
// RCS-ID:      $Id$
// Copyright (C) 2002 - 2005, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
// dlgServer.h - Server property 
//
//////////////////////////////////////////////////////////////////////////


#ifndef __DLG_SERVERPROP
#define __DLG_SERVERPROP

#include "dlgProperty.h"

class pgServer;

class dlgServer : public dlgProperty
{
public:
    dlgServer(frmMain *frame, pgServer *s);
    ~dlgServer();
    int Go(bool modal);
    int GoNew();

    void CheckChange();
    wxString GetSql();
    pgObject *CreateObject(pgCollection *collection);
    pgObject *GetObject();
    wxString GetHelpPage() const;

    wxString GetPassword();
    bool GetTryConnect();

private:
    pgServer *server;

    void OnOK(wxCommandEvent &ev);
    void OnChangeTryConnect(wxCommandEvent &ev);
    void OnPageSelect(wxNotebookEvent &event);

    DECLARE_EVENT_TABLE();
};


class addServerFactory : public actionFactory
{
public:
    addServerFactory(wxMenu *mnu, wxToolBar *toolbar);
    wxWindow *StartDialog(pgFrame *form, pgObject *obj);
};


class controlServiceFactory : public contextActionFactory
{
public:
    bool CheckEnable(pgObject *obj);
protected:
    controlServiceFactory() {};
};


class startServiceFactory : public controlServiceFactory
{
public:
    startServiceFactory (wxMenu *mnu, wxToolBar *toolbar);
    wxWindow *StartDialog(pgFrame *form, pgObject *obj);
};

class stopServiceFactory : public controlServiceFactory
{
public:
    stopServiceFactory (wxMenu *mnu, wxToolBar *toolbar);
    wxWindow *StartDialog(pgFrame *form, pgObject *obj);
};


class connectServerFactory : public contextActionFactory
{
public:
    connectServerFactory(wxMenu *mnu, wxToolBar *toolbar);
    wxWindow *StartDialog(pgFrame *form, pgObject *obj);
    bool CheckEnable(pgObject *obj);
};


class disconnectServerFactory : public contextActionFactory
{
public:
    disconnectServerFactory(wxMenu *mnu, wxToolBar *toolbar);
    wxWindow *StartDialog(pgFrame *form, pgObject *obj);
    bool CheckEnable(pgObject *obj);
};

#endif
