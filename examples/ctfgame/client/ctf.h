#ifndef CTF_H
#define CTF_H
// The MIT License
// 
// Copyright (c) 2011 Dylan Smith
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
#include "ctfmessage.h"

// Error numbers
#define	TXERROR -3
#define RXERROR -4
#define NACK -5
#define VPRANGE -6

# Viewport
#define VPXTILES	28
#define VPYTILES	23
#define VPXPIXELS	224
#define VPYPIXELS	184
#define MAXVPX	32767
#define MAXVPY	32767

#define TRUE	1
#define	FALSE 0

// Function prototypes
// General stuff
void *u_malloc(uint size);
void u_free(void *addr);

// Sprite display
extern void initSpriteLib();
extern void putSprite(SpriteMsg *msg);
extern void moveSprite(SpriteMsg *msg);
extern void manageSprite(SpriteMsg *msg);
extern void removeAllSprites();
extern void removeSprite(RemoveSpriteMsg *msg);
extern void drawMap(uchar *msgbuf);
extern void colourSpr(struct sp1_cs *c);

// Controls
extern void initInput();
extern void getInput();

// Communications
extern int initConnection(char *host, char *player);
extern int startGame(MapXY *xy);
extern int disconnect();
extern int sendSyncMsg(int txbytes);
extern int sendMsg(int txbytes);
extern int sendControlMsg(uchar dirs);
extern int messageloop();

#endif
