; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDrawDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Draw.h"

ClassCount=3
Class1=CDrawApp
Class2=CDrawDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DRAW_DIALOG

[CLS:CDrawApp]
Type=0
HeaderFile=Draw.h
ImplementationFile=Draw.cpp
Filter=N

[CLS:CDrawDlg]
Type=0
HeaderFile=DrawDlg.h
ImplementationFile=DrawDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CDrawDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=DrawDlg.h
ImplementationFile=DrawDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DRAW_DIALOG]
Type=1
Class=CDrawDlg
ControlCount=2
Control1=IDC_BUTTON1,button,1342242817
Control2=IDC_STATIC,static,1342308352

