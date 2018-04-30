#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include "resource.h"
#include "MainDlg.h"

/*
Template designed by RuPeng.com. Please visit http://www.rupeng.com for more information
��������http://www.rupeng.com����ѧ�������ѧϰ�������ṩ���������Ƶѧϰ�̳̣��ṩ���Ի�һ��һѧϰָ��
*/
BOOL WINAPI Main_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        HANDLE_MSG(hWnd, WM_INITDIALOG, Main_OnInitDialog);
        HANDLE_MSG(hWnd, WM_COMMAND, Main_OnCommand);
		HANDLE_MSG(hWnd,WM_CLOSE, Main_OnClose);
    }

    return FALSE;
}

BOOL Main_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
    return TRUE;
}

void Main_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case IDC_1:
		{
			TCHAR shortPath[MAX_PATH];
			GetShortPathName("C:\\Documents and Settings\\Jiangxincheng\\����\\�����ռ�\\1.wma",shortPath,sizeof(shortPath));
            TCHAR cmd[MAX_PATH+10];
			wsprintf(cmd,"play %s",shortPath);
			mciSendString(cmd,"",0,NULL);
		}
        break;
        default:
		break;
    }
}

void Main_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}