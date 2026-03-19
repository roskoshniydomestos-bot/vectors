#define _CRT_SECURE_NO_WARNINGS

#include "vectors.h"

#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

BOOL out = 0;

enum Window_0 {
	wx0 = 20,                                                                                      
	wy0 = 20,
	wdx = 800, 
	wdy = 800
};

enum KeyOrButStatus {                                                                                                    
	Down = 1,
	Up = 0	                                                                                   
};

struct Key { 
	int		code;																							
	BOOL	status;
};
struct Key Key;

static LRESULT CALLBACK WINAPI WndProc(																
	HWND	hwnd,
	UINT	mes,
	WPARAM	wParam,
	LPARAM	lParam
) {
	switch (mes) {
	case WM_KEYUP:																				
		Key.status = Up;
		Key.code = (int)wParam;
		return 0;
		break;
	case WM_KEYDOWN:
		Key.status = Down;
		Key.code = (int)wParam;
		return 0;
		break;
	case WM_DESTROY:																								
		PostQuitMessage(0);
		out = 1;
		return 0;
	default:
		return (DefWindowProcA(hwnd, mes, wParam, lParam));
	}

	return 0;
}

static void OrdinateInit(HDC dc, int ox, int oy) {
	MoveToEx(dc, ox, 0, NULL);
	LineTo(dc, ox, 800);

	MoveToEx(dc, 0, oy, NULL);
	LineTo(dc, 800, oy);
}

int main(
	HINSTANCE	hinst,
	HINSTANCE	hPrevInstance,
	LPSTR		lpCmdLine,
	int			nCmdShow
) {
	const char* szClassName = "ClassWin";																			
	const char* szTitleName = "vector-and-winApi"; 
	MSG			msg;
	WNDCLASSA	wc;
	memset(&wc, 0, sizeof(WNDCLASSA));

	wc.lpfnWndProc = WndProc;
	wc.hInstance = hinst;
	wc.hCursor = LoadCursorA(NULL, (LPCSTR)IDC_ARROW);
	wc.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255));
	wc.lpszClassName = szClassName;
	RegisterClassA(&wc);

	HWND hwnd = CreateWindowA(																			
		szClassName,
		szTitleName,
		WS_OVERLAPPEDWINDOW,
		wx0, wy0,
		wdx, wdy,
		HWND_DESKTOP,
		NULL,
		hinst,
		NULL
	);
	HDC dc = GetDC(hwnd);
	ShowWindow(hwnd, SW_SHOWNORMAL);																

	enum null {
		ox = 400,
		oy = 400
	};

	HPEN hWite	= CreatePen(PS_SOLID, 0, RGB(255, 255, 255));
	HPEN hBlue	= CreatePen(PS_SOLID, 0, RGB(0, 0, 255));
	HPEN hYelow = CreatePen(PS_SOLID, 0, RGB(255, 255, 0));
	HPEN hRed	= CreatePen(PS_SOLID, 0, RGB(255, 0, 0));
	HPEN hGrean = CreatePen(PS_SOLID, 0, RGB(0, 255, 0));

	/*создаём векторы для отрисовки фигуры*/
	struct Vector	v0;
	struct Vector	v11;
	struct Vector	v12;
	struct Vector	v13;
	struct Vector	v14;

	struct Vector	v21;
	struct Vector	v22;
	struct Vector	v23;
	struct Vector	v24;

	/*сщздаём базис, который будет преобразовывать векторное пространство*/
	struct Basis2D	b;

	struct ordinats {
		BASIS x;
		BASIS y;
		BASIS xi;
		BASIS yi;
		BASIS xj;
		BASIS yj;
	};
	struct ordinats Ord = {0};
	Ord.x	= 0;
	Ord.y	= 0;

	/*стандартный базис*/
	Ord.xi	= 1;
	Ord.yi	= 0;
	Ord.xj	= 0;
	Ord.yj	= 1;

	while (1) {
		if (out == 1) break;
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessageA(&msg);
		}
		SelectObject(dc, hWite);
		Rectangle(dc, 0, 0, 800, 800);

		SelectObject(dc, hBlue);
		OrdinateInit(dc, ox, oy);

		/*начальное положение векторов*/
		VInit(&v11, -40, 40);
		VInit(&v12, 20, 40);
		VInit(&v13, 20, -20);
		VInit(&v14, -40, -20);

		VInit(&v21, -20, 20);
		VInit(&v22, 40, 20);
		VInit(&v23, 40, -40);
		VInit(&v24, -20, -40);

		/*обработка клавиатуры*/
		if		(Key.code == VK_UP		&& Key.status == Down) Ord.y--;
		else if (Key.code == VK_DOWN	&& Key.status == Down) Ord.y++;
		else if (Key.code == VK_RIGHT	&& Key.status == Down) Ord.x++;
		else if (Key.code == VK_LEFT	&& Key.status == Down) Ord.x--;

		else if (Key.code == 0x51		&& Key.status == Down) Ord.xi += 0.01;
		else if (Key.code == 0x57		&& Key.status == Down) Ord.yi += 0.01;
		else if (Key.code == 0x45		&& Key.status == Down) Ord.xj += 0.01;
		else if (Key.code == 0x52		&& Key.status == Down) Ord.yj += 0.01;
		else if (Key.code == 0x41		&& Key.status == Down) Ord.xi -= 0.01;
		else if (Key.code == 0x53		&& Key.status == Down) Ord.yi -= 0.01;
		else if (Key.code == 0x44		&& Key.status == Down) Ord.xj -= 0.01;
		else if (Key.code == 0x46		&& Key.status == Down) Ord.yj -= 0.01;

		/*вектор для смещения фигуры по горизонтали и вертикали*/
		VInit(&v0, Ord.x, Ord.y);

		/*изминяя параметры базиса - преобразуем векторное пространство и сами векторы, соответственно и фигуру*/
		VNevBasis(&b, 2 * cos(Ord.xi), 2 * sin(Ord.yi), -2 * sin(Ord.xj), 2 * cos(Ord.yj));

		/*изменяем векторы по новому базису*/
		VTransformer(&v11, b);
		VTransformer(&v12, b);
		VTransformer(&v13, b);
		VTransformer(&v14, b);

		VTransformer(&v21, b);
		VTransformer(&v22, b);
		VTransformer(&v23, b);
		VTransformer(&v24, b);

		/*производим вектрорное сумирование двух векторов для осуществления смещения фигуры по горизонтали и вертикали*/
		VSumm(&v11, v11, v0);
		VSumm(&v12, v12, v0);
		VSumm(&v13, v13, v0);
		VSumm(&v14, v14, v0);

		VSumm(&v21, v21, v0);
		VSumm(&v22, v22, v0);
		VSumm(&v23, v23, v0);
		VSumm(&v24, v24, v0);

		/*отрисовка фигуры*/
		SelectObject(dc, hRed);
		POINT f1[5] = {
			{ox + (LONG)v11.i, oy + (LONG)v11.j},
			{ox + (LONG)v12.i, oy + (LONG)v12.j},
			{ox + (LONG)v13.i, oy + (LONG)v13.j},
			{ox + (LONG)v14.i, oy + (LONG)v14.j},
			{ox + (LONG)v11.i, oy + (LONG)v11.j}
		};
		POINT f2[5] = {
			{ox + (LONG)v21.i, oy + (LONG)v21.j},
			{ox + (LONG)v22.i, oy + (LONG)v22.j},
			{ox + (LONG)v23.i, oy + (LONG)v23.j},
			{ox + (LONG)v24.i, oy + (LONG)v24.j},
			{ox + (LONG)v21.i, oy + (LONG)v21.j}
		};
		SelectObject(dc, hRed);
		Polyline(dc, f1, 5);
		SelectObject(dc, hGrean);
		Polyline(dc, f2, 5);

		SelectObject(dc, hYelow);
		MoveToEx(dc, ox + (LONG)v11.i, oy + (LONG)v11.j, NULL);
		LineTo(dc, ox + (LONG)v21.i, oy + (LONG)v21.j);

		MoveToEx(dc, ox + (LONG)v12.i, oy + (LONG)v12.j, NULL);
		LineTo(dc, ox + (LONG)v22.i, oy + (LONG)v22.j);

		MoveToEx(dc, ox + (LONG)v13.i, oy + (LONG)v13.j, NULL);
		LineTo(dc, ox + (LONG)v23.i, oy + (LONG)v23.j);

		MoveToEx(dc, ox + (LONG)v14.i, oy + (LONG)v14.j, NULL);
		LineTo(dc, ox + (LONG)v24.i, oy + (LONG)v24.j);

		Sleep(5);
	}

	return 0;
}