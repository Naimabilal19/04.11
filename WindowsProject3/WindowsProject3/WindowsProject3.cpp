#include <Windows.h>
#include <tchar.h>
#include "resource.h"

HWND hB1, hB2, hB3, hB4, hB5, hB6, hB7, 
hB8, hB9, hPic1, hPic2, hPic3, hPic4, hPic5, hPic6, hPic7, hPic8, hPic9;  //переменна€ дл€ кнопок и 
//изобр. 
HBITMAP hBmp_X, hBmp_O;   //переменна€ дл€ крестиков и ноликов       
int change = 0, step = 0,
x1_X = 0, x2_X = 0, x3_X = 0, x1_O = 0, x2_O = 0, x3_O = 0,  //столбцы
y1_X = 0, y2_X = 0, y3_X = 0, y1_O = 0, y2_O = 0, y3_O = 0, //строки
d1_X = 0, d2_X = 0, d1_O = 0, d2_O = 0;    //диагональ 

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hWnd, NULL);
		return(TRUE);
	case WM_INITDIALOG:
		hB1 = GetDlgItem(hWnd, IDC_BUTTON1);
		hB2 = GetDlgItem(hWnd, IDC_BUTTON2);
		hB3 = GetDlgItem(hWnd, IDC_BUTTON3);
		hB4 = GetDlgItem(hWnd, IDC_BUTTON4);
		hB5 = GetDlgItem(hWnd, IDC_BUTTON5);
		hB6 = GetDlgItem(hWnd, IDC_BUTTON6);
		hB7 = GetDlgItem(hWnd, IDC_BUTTON7);
		hB8 = GetDlgItem(hWnd, IDC_BUTTON8);
		hB9 = GetDlgItem(hWnd, IDC_BUTTON9);
		hPic1 = GetDlgItem(hWnd, IDC_STATIC);
		hPic2 = GetDlgItem(hWnd, IDC_STATIC1);
		hPic3 = GetDlgItem(hWnd, IDC_STATIC2);
		hPic4 = GetDlgItem(hWnd, IDC_STATIC3);
		hPic5 = GetDlgItem(hWnd, IDC_STATIC4);
		hPic6 = GetDlgItem(hWnd, IDC_STATIC5);
		hPic7 = GetDlgItem(hWnd, IDC_STATIC6);
		hPic8 = GetDlgItem(hWnd, IDC_STATIC7);
		hPic9 = GetDlgItem(hWnd, IDC_STATIC8);
		hBmp_X = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP2));
		hBmp_O = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_BITMAP1));
		return(TRUE);


	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_BUTTON1)    //если нажата кнопка 1
		{
			if (change == NULL)     
			{
				SendMessage(hPic1, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp_X)); //передаем в окно картинку,
				//свз€ываем новое изобрж, передаем в правый параметр bitmap, в левый - само изображение
				EnableWindow(hB1, FALSE); //отключаем кнопку button
				++change; 
				++x1_X;
				++y1_X;
				++d1_X;
				++step;
			}
			else 
			{
				SendMessage(hPic1, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp_O));
				EnableWindow(hB1, FALSE);
				change = NULL;
				++x1_O;
				++y1_O;
				++d1_O;
				++step;
			}
		}
		else if (LOWORD(wParam) == IDC_BUTTON2)
		{
			if (change == NULL)
			{
				SendMessage(hPic2, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp_X));
				EnableWindow(hB2, FALSE);
				++change;
				++x2_X;
				++y1_X;
				++step;
			}
			else
			{
				SendMessage(hPic2, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp_O));
				EnableWindow(hB2, FALSE);
				change = NULL;
				++x2_O;
				++y1_O;
				++step;
			}
		}
		else if (LOWORD(wParam) == IDC_BUTTON3)
		{
			if (change == NULL)
			{
				SendMessage(hPic3, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp_X));
				EnableWindow(hB3, FALSE);
				++change;
				++x3_X;
				++y1_X;
				++d2_X;
				++step;
			}
			else
			{
				SendMessage(hPic3, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp_O));
				EnableWindow(hB3, FALSE);
				change = NULL;
				++x3_O;
				++y1_O;
				++d2_O;
				++step;
			}
		}
		else if (LOWORD(wParam) == IDC_BUTTON4)
		{
			if (change == NULL)
			{
				SendMessage(hPic4, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp_X));
				EnableWindow(hB4, FALSE);
				++change;
				++x1_X;
				++y2_X;
				++step;
			}
			else
			{
				SendMessage(hPic4, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp_O));
				EnableWindow(hB4, FALSE);
				change = NULL;
				++x1_O;
				++y2_O;
				++step;
			}
		}
		else if (LOWORD(wParam) == IDC_BUTTON5)
		{
			if (change == NULL)
			{
				SendMessage(hPic5, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp_X));
				EnableWindow(hB5, FALSE);
				++change;
				++x2_X;
				++y2_X;
				++d1_X;
				++d2_X;
				++step;
			}
			else
			{
				SendMessage(hPic5, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp_O));
				EnableWindow(hB5, FALSE);
				change = NULL;
				++x2_O;
				++y2_O;
				++d1_O;
				++d2_O;
				++step;
			}
		}
		else if (LOWORD(wParam) == IDC_BUTTON6)
		{
			if (change == NULL)
			{
				SendMessage(hPic6, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp_X));
				EnableWindow(hB6, FALSE);
				++change;
				++x3_X;
				++y2_X;
				++step;
			}
			else
			{
				SendMessage(hPic6, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp_O));
				EnableWindow(hB6, FALSE);
				change = NULL;
				++x3_O;
				++y2_O;
				++step;
			}
		}
		else if (LOWORD(wParam) == IDC_BUTTON7)
		{
			if (change == NULL)
			{
				SendMessage(hPic7, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp_X));
				EnableWindow(hB7, FALSE);
				++change;
				++x1_X;
				++y3_X;
				++d2_X;
				++step;
			}
			else
			{
				SendMessage(hPic7, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp_O));
				EnableWindow(hB7, FALSE);
				change = NULL;
				++x1_O;
				++y3_O;
				++d2_O;
				++step;
			}
		}
		else if (LOWORD(wParam) == IDC_BUTTON8)
		{
			if (change == NULL)
			{
				SendMessage(hPic8, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp_X));
				EnableWindow(hB8, FALSE);
				++change;
				++x2_X;
				++y3_X;
				++step;
			}
			else
			{
				SendMessage(hPic8, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp_O));
				EnableWindow(hB8, FALSE);
				change = NULL;
				++x2_O;
				++y3_O;
				++step;
			}
		}
		else if (LOWORD(wParam) == IDC_BUTTON9)
		{
			if (change == NULL)
			{
				SendMessage(hPic9, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp_X));
				EnableWindow(hB9, FALSE);
				++change;
				++x3_X;
				++y3_X;
				++d1_X;
				++step;
			}
			else
			{
				SendMessage(hPic9, STM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hBmp_O));
				EnableWindow(hB9, FALSE);
				change = NULL;
				++x3_O;
				++y3_O;
				++d1_O;
				++step;
			}
		}
		else
		{
			return(TRUE);
		}
		if (x1_X == 3 || x2_X == 3 || x3_X == 3 || y1_X == 3 || y2_X == 3 || y3_X == 3 || d1_X == 3 || d2_X == 3) //проверка на выигрыш игрока "крестик"
		{
			MessageBox(hWnd, TEXT("winner player: cross"), TEXT("Game over"), MB_OK);
			EndDialog(hWnd, NULL);
			return(TRUE);
		}
		else if (x1_O == 3 || x2_O == 3 || x3_O == 3 || y1_O == 3 || y2_O == 3 || y3_O == 3 || d1_O == 3 || d2_O == 3) //проверка на выигрыш игрока "нолик"
		{
			MessageBox(hWnd, TEXT("winner player: zero"), TEXT("Game over"), MB_OK);
			EndDialog(hWnd, NULL);
			return(TRUE);
		}
		else if (step == 9)       //если ничь€
		{
			MessageBox(hWnd, TEXT("Draw"), TEXT("Game over"), MB_OK);
			EndDialog(hWnd, NULL);
			return(TRUE);
		}
		else
		{
			return(TRUE);
		}
		return(TRUE);
	}
	return(FALSE);
}
