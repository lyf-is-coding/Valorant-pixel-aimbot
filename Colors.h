#ifndef _COLORS_H_
#define _COLORS_H_

#pragma once

#include <d3d9.h>

#define WHITE(alpha)		 D3DCOLOR_ARGB(alpha, 255, 255, 255)
#define DARKWHITE(alpha)	 D3DCOLOR_ARGB(alpha, 235, 230, 227)
#define BLACK(alpha)		 D3DCOLOR_ARGB(alpha, 0, 0, 0)
#define DARKGRAY(alpha)      D3DCOLOR_ARGB(alpha, 73, 73, 73)
#define DARKERGRAY(alpha)    D3DCOLOR_ARGB(alpha, 31, 31, 31)
#define BLACK(alpha)         D3DCOLOR_ARGB(alpha, 0, 0, 0)

#define RED(alpha)           D3DCOLOR_ARGB(alpha, 255, 0, 0)

#define DARKRED(alpha)		 D3DCOLOR_ARGB(alpha, 139, 0, 0)
#define GREEN(alpha)         D3DCOLOR_ARGB(alpha, 0, 128, 0)
#define LIMEGREEN(alpha)	 D3DCOLOR_ARGB(alpha, 33, 100, 33)
#define LAWNGREEN(alpha)     D3DCOLOR_ARGB(alpha, 124, 252, 0)

#define AQUA(alpha)			 D3DCOLOR_ARGB(alpha, 85, 255, 255)
#define BLUE(alpha)          D3DCOLOR_ARGB(alpha, 0, 200, 255)
#define DEEPSKYBLUE(alpha)   D3DCOLOR_ARGB(alpha, 0, 191, 255)
#define SKYBLUE(alpha)       D3DCOLOR_ARGB(alpha, 0, 122, 204)
#define GRAY(alpha)          D3DCOLOR_ARGB(alpha, 128, 128, 128)

#define YELLOW(alpha)        D3DCOLOR_ARGB(alpha, 255, 255, 0)
#define ORANGE(alpha)        D3DCOLOR_ARGB(alpha, 255, 165, 0)
#define DARKORANGE(alpha)    D3DCOLOR_ARGB(alpha, 255, 140, 0)
#define PURPLE(alpha)        D3DCOLOR_ARGB(alpha, 125, 0, 255)
#define LIGHTCYAN(alpha)	 D3DCOLOR_ARGB(alpha, 33, 100, 100)
#define CYAN(alpha)          D3DCOLOR_ARGB(alpha, 0, 255, 255)
#define PINK(alpha)          D3DCOLOR_ARGB(alpha, 255, 20, 147)


#endif /* _COLORS_H_ */