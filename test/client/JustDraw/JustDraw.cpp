// JustDraw.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "JustDraw.h"
#include "CheckWin.h"
#include "ai.h"
#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

void SetClientSize(HWND hWnd,int width, int height);
int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: 在此放置代码。
	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_JUSTDRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_JUSTDRAW));

	// 主消息循环:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_JUSTDRAW));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_JUSTDRAW);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 将实例句柄存储在全局变量中

   hWnd = CreateWindow(szWindowClass, szTitle, /*WS_OVERLAPPEDWINDOW|*/WS_DLGFRAME|WS_SYSMENU,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: 处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	static ChessBoardShow chessBoard;
	static int height;
	static int width;
	static AI *ai = NULL;
	HPEN hPen,hOldP;
	HBRUSH hBrush,hOldB;
	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择:
		switch (wmId)
		{
		case IDM_FILE_OPEN:
			{
				//FILE *fpOpen;
			 //   fopen_s(&fpOpen,"file.dat","rb");
				//
				//fread(&chessBoard.intChessBoard,sizeof(int),MAX_NUM*MAX_NUM,fpOpen);
				//fread(&chessBoard.intWhoPlay,sizeof(int),1,fpOpen);
				//fread(&chessBoard.chessColor,sizeof(COLORREF),1,fpOpen);
				//fread(&chessBoard.chessLineColor,sizeof(COLORREF),1,fpOpen);
				//fread(&chessBoard.AColor,sizeof(COLORREF),1,fpOpen);
				//fread(&chessBoard.BColor,sizeof(COLORREF),1,fpOpen);
				//
				////list<POINT> tmpList = chessBoard.replayList;
				//POINT pt;
				//while(chessBoard.replayList.size() > 0)
				//{
				//	chessBoard.replayList.pop_front();
				//}
				//int sizeTmpList;
				//fread(&sizeTmpList,sizeof(int),1,fpOpen);
				//
				//while(sizeTmpList > 0)
				//{
				//	fread(&pt,sizeof(POINT),1,fpOpen);
				//	chessBoard.replayList.push_back(pt);
				//	sizeTmpList--;
				//}	
				//fclose(fpOpen);
				//InvalidateRect(hWnd,NULL,TRUE);
			}
			break;
		case IDM_FILE_SAVE:
			{
			/*	FILE *fpSave;
			    fopen_s(&fpSave,"file.dat","wb+");
				
				fwrite(&chessBoard.intChessBoard,sizeof(int),MAX_NUM*MAX_NUM,fpSave);
				fwrite(&chessBoard.intWhoPlay,sizeof(int),1,fpSave);
				fwrite(&chessBoard.chessColor,sizeof(COLORREF),1,fpSave);
				fwrite(&chessBoard.chessLineColor,sizeof(COLORREF),1,fpSave);
				fwrite(&chessBoard.AColor,sizeof(COLORREF),1,fpSave);
				fwrite(&chessBoard.BColor,sizeof(COLORREF),1,fpSave);
				list<POINT> tmpList = chessBoard.replayList;
				POINT pt;
				int sizeTmpList = tmpList.size();
				fwrite(&sizeTmpList,sizeof(int),1,fpSave);
				while(tmpList.size() > 0)
				{
					pt = tmpList.front();
					tmpList.pop_front();
					fwrite(&pt,sizeof(POINT),1,fpSave);
				}
				fclose(fpSave);*/
			}
			break;
		case IDM_OP_BACK:
			//只能甲方撤销
			if(chessBoard.intWhoPlay == 0)
			{
				POINT pt;
				if(chessBoard.replayList.size() > 0)
				{
					pt = chessBoard.replayList.front();
					chessBoard.replayList.pop_front();
					chessBoard.BLast.x = pt.x;
					chessBoard.BLast.y = pt.y;
					chessBoard.intChessBoard[chessBoard.BLast.x][chessBoard.BLast.y] = -1;

					pt = chessBoard.replayList.front();
					chessBoard.replayList.pop_front();
					chessBoard.ALast.x = pt.x;
					chessBoard.ALast.y = pt.y;
					chessBoard.intChessBoard[chessBoard.ALast.x][chessBoard.ALast.y] = -1;
					InvalidateRect(hWnd,NULL,TRUE);
					if(ai->back())
					{
						true;
						//MessageBox(hWnd,"AI撤销成功","...",MB_OK);
					}
				}
			}
			else if(chessBoard.intWhoPlay == 1)
			{
				POINT pt;
				if(chessBoard.replayList.size() > 0)
				{
					pt = chessBoard.replayList.front();
					chessBoard.replayList.pop_front();
					chessBoard.ALast.x = pt.x;
					chessBoard.ALast.y = pt.y;
					chessBoard.intChessBoard[chessBoard.ALast.x][chessBoard.ALast.y] = -1;

					pt = chessBoard.replayList.front();
					chessBoard.replayList.pop_front();
					chessBoard.BLast.x = pt.x;
					chessBoard.BLast.y = pt.y;
					chessBoard.intChessBoard[chessBoard.BLast.x][chessBoard.BLast.y] = -1;

					pt = chessBoard.replayList.front();
					chessBoard.replayList.pop_front();
					chessBoard.ALast.x = pt.x;
					chessBoard.ALast.y = pt.y;
					chessBoard.intChessBoard[chessBoard.ALast.x][chessBoard.ALast.y] = -1;
					chessBoard.intWhoPlay = 0;

					InvalidateRect(hWnd,NULL,TRUE);
					
				}
			}
			break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_CREATE:
		{
			SetClientSize(hWnd,480, 480);
			int i = -1;
			IniChessBoard(chessBoard);
			if (ai != NULL)
			{
				delete ai;
			}
			ai = new AI();
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: 在此添加任意绘图代码...
		RECT rt;
		GetClientRect(hWnd,&rt);
		
		height = (rt.bottom - rt.top)/MAX_NUM;  //每一个格子的高度
		width = (rt.right - rt.left)/MAX_NUM;   //每一个格子的宽度

		RepaintChessBoard(hdc,chessBoard,rt,height,width);

		EndPaint(hWnd, &ps);
		break;
	case WM_LBUTTONDOWN:	
		//甲落子
		if(chessBoard.intWhoPlay == 0)
		{
			hdc = GetDC(hWnd);
			
			int xLBD = LOWORD(lParam);
			int yLBD = HIWORD(lParam);
			
			for(int x = width;x < MAX_NUM * width; x = x + width)
				for(int y = height;y < MAX_NUM * height; y = y + height)
				{
					if(xLBD < (x + width * 0.5) && xLBD > (x - width * 0.5) &&
						yLBD < (y + height *0.5) && yLBD > (y - height *0.5))
					{
						if(chessBoard.intChessBoard[x/width][y/height] != 0 &&  //这个点还有被画过
							chessBoard.intChessBoard[x/width][y/height] != 1)
						{
							hBrush = CreateSolidBrush(chessBoard.AColor);
							SelectObject(hdc,hBrush);
							Ellipse(hdc,x - width * 0.5,y - height *0.5,x + width * 0.5,y + height *0.5);
							DeleteObject(hBrush);

							chessBoard.intChessBoard[x/width][y/height] = 0;
							chessBoard.ALast.x = x/width;
							chessBoard.ALast.y = y/height;
							chessBoard.replayList.push_front(chessBoard.ALast);

							//消除黑棋的十字
							hPen = CreatePen(PS_SOLID,2,RGB(0,0,0));
							hOldP = (HPEN)SelectObject(hdc,hPen);
							MoveToEx(hdc,(chessBoard.BLast.x - 0.3) * width ,chessBoard.BLast.y * height,NULL);
							LineTo(hdc,(chessBoard.BLast.x + 0.3) * width ,chessBoard.BLast.y * height);
							MoveToEx(hdc,chessBoard.BLast.x * width ,(chessBoard.BLast.y - 0.3) * height ,NULL);
							LineTo(hdc,chessBoard.BLast.x * width,(chessBoard.BLast.y + 0.3) * height );
							SelectObject(hdc,hOldP);
							DeleteObject(hPen);

							if(CheckWin(chessBoard.intChessBoard,chessBoard.intWhoPlay,x/width,y/height))
							{
								MessageBox(hWnd,"白方胜利","厉害",MB_OK);
								int wmId = IDM_FILE_SAVE;
								chessBoard.intWhoPlay = 1;
								SendMessage(hWnd,WM_COMMAND,(WPARAM)wmId,0); //保存一下
								if (ai != NULL)
								{
									delete ai;
								}
								ai = new AI();
								//IniChessBoard(chessBoard);
								//InvalidateRect(hWnd,NULL,TRUE);
							}
							else 
							{
								chessBoard.intWhoPlay = 1;
								SendMessage(hWnd,WM_AUTOPLAY,NULL,NULL);
							}
						}
					}
				}
			
			
		}
		break;
	case WM_RBUTTONDOWN:
		{
			/*POINT pt;
			int x,y;
			pt = MachinePlay(chessBoard.intChessBoard,JIA,chessBoard.ALast);
			x= pt.x;
			y= pt.y;*/
		}
		break;
	case WM_AUTOPLAY:
		//乙落子
		if(chessBoard.intWhoPlay == 1)
		{
			POINT pt;pt.x = chessBoard.ALast.x - 1; pt.y = chessBoard.ALast.y - 1;
			Pos pos; pos.x = pt.x; pos.y = pt.y;
			pos = ai->set(pos);
			pt.x = pos.x + 1; pt.y = pos.y + 1;

			hdc = GetDC(hWnd);
			int xLBD = pt.x * width;        //LOWORD(lParam);
			int yLBD = pt.y * height;         //HIWORD(lParam);
			hBrush = CreateSolidBrush(chessBoard.BColor);
			SelectObject(hdc,hBrush);
			Ellipse(hdc,xLBD - width * 0.5,yLBD - height *0.5,xLBD + width * 0.5,yLBD + height *0.5);
			DeleteObject(hBrush);
			
			chessBoard.intChessBoard[pt.x][pt.y] = 1;
			chessBoard.BLast.x = pt.x;
			chessBoard.BLast.y = pt.y;
			chessBoard.replayList.push_front(chessBoard.BLast);


			hPen = CreatePen(PS_SOLID,2,RGB(255,0,0));
			hOldP = (HPEN)SelectObject(hdc,hPen);
			MoveToEx(hdc,(pt.x - 0.3) * width ,pt.y * height,NULL);
	        LineTo(hdc,(pt.x + 0.3) * width ,pt.y * height);
			MoveToEx(hdc,pt.x * width ,(pt.y - 0.3 )* height ,NULL);
	        LineTo(hdc,pt.x * width,(pt.y + 0.3) * height );
			SelectObject(hdc,hOldP);
			DeleteObject(hPen);

			
			if(CheckWin(chessBoard.intChessBoard,chessBoard.intWhoPlay,pt.x,pt.y))
			{	
				if(IDOK == MessageBox(hWnd,"黑方胜利","辣鸡",MB_OKCANCEL))
				{
					IniChessBoard(chessBoard);
					InvalidateRect(hWnd,NULL,TRUE);
					if (ai != NULL)
					{
						delete ai;
					}
					ai = new AI();
				}
			}
			chessBoard.intWhoPlay = 0;
			
			
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
void SetClientSize(HWND hWnd,int width, int height)
{
  if(!hWnd)
  {
     MessageBox(NULL, "设置窗口失败", NULL, 1);
     exit(1);
  }
  RECT  rectProgram,rectClient;
  GetWindowRect(hWnd, &rectProgram);   //获得程序窗口位于屏幕坐标
  GetClientRect(hWnd, &rectClient);      //获得客户区坐标
  //非客户区宽,高
  int nWidth = rectProgram.right - rectProgram.left -(rectClient.right - rectClient.left); 
  int nHeiht = rectProgram.bottom - rectProgram.top -(rectClient.bottom - rectClient.top); 
  nWidth += width;
  nHeiht += height;
  rectProgram.right =  nWidth;
  rectProgram.bottom =  nHeiht;
  int showToScreenx = GetSystemMetrics(SM_CXSCREEN)/2-nWidth/2;    //居中处理
  int showToScreeny = GetSystemMetrics(SM_CYSCREEN)/2-nHeiht/2;
  MoveWindow(hWnd, showToScreenx, showToScreeny, rectProgram.right, rectProgram.bottom, false);
}