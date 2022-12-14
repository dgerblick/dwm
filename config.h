/* See LICENSE file for copyright and license details. */

/* alt-tab configuration */
static const unsigned int tabModKey 		= 0x40;	/* if this key is hold the alt-tab functionality stays acitve. This key must be the same as key that is used to active functin altTabStart `*/
static const unsigned int tabCycleKey 		= 0x17;	/* if this key is hit the alt-tab program moves one position forward in clients stack. This key must be the same as key that is used to active functin altTabStart */
static const unsigned int tabPosY 			= 1;	/* tab position on Y axis, 0 = bottom, 1 = center, 2 = top */
static const unsigned int tabPosX 			= 1;	/* tab position on X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxWTab 			= 600;	/* tab menu width */
static const unsigned int maxHTab 			= 200;	/* tab menu height */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int extbar             = 1;        /* 1 means use an external bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int focusonwheel       = 0;
static const int user_bh            = 35;       /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#282a36";
static const char col_gray2[]       = "#ffb86c";
static const char col_gray3[]       = "#ff79c6";
static const char col_gray4[]       = "#ffb86c";
static const char col_cyan[]        = "#282a36";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_cyan },
	[SchemeSel]  = { col_gray4, col_cyan,  col_gray2  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ NULL,       NULL,       NULL,       0,            False,       -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const int lpm[] = {
	/* Index of preferred layout], if LENGTH(lpm)<#monitors -> default layout */
	4, 2
};

static const Layout layouts[] = {
	/* symbol     arrange function          major axis */
	{ ">M>",      centeredfloatingmaster,   0 },
	{ "|M|",      centeredmaster,           0 },
	{ "TTT",      bstack,                   2 },
	{ "===",      bstackhoriz,              2 },
	{ "[]=",      tile,                     1 },
	{ "[\\]",     dwindle,                  1 },
	{ "HHH",      grid,                     0 },
	{ "---",      horizgrid,                0 },
	{ NULL,       NULL,                     0 },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask,              KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const Key keys[] = {
	/* modifier                     key        function        argument */
	/* Launch Applications */
	{ MODKEY,                       XK_space,           spawn,          SHCMD("rofi -modi 'drun,run' -show drun") },
	{ MODKEY,                       XK_Return,          spawn,          SHCMD("alacritty") },
	{ MODKEY|ShiftMask,             XK_w,               spawn,          SHCMD("firefox") },
	{ MODKEY|Mod1Mask,              XK_w,               spawn,          SHCMD("firefox --private-window") },
	/* Tags */
	TAGKEYS(                        XK_1,                               0)
	TAGKEYS(                        XK_2,                               1)
	TAGKEYS(                        XK_3,                               2)
	TAGKEYS(                        XK_4,                               3)
	TAGKEYS(                        XK_5,                               4)
	TAGKEYS(                        XK_6,                               5)
	TAGKEYS(                        XK_7,                               6)
	TAGKEYS(                        XK_8,                               7)
	TAGKEYS(                        XK_9,                               8)
	{ MODKEY,                       XK_minus,           focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_equal,           focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_minus,           tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_equal,           tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_0,               view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,               tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_Tab,             zoom,           {0} },
	/* Layouts */
	{ MODKEY|ControlMask,           XK_comma,           cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period,          cyclelayout,    {.i = +1 } },
	{ MODKEY,                       XK_grave,           setlayout,      {0} },
	{ MODKEY,                       XK_a,               setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_s,               setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_d,               setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_f,               togglefullscr,  {0} },
	{ MODKEY,                       XK_g,               setlayout,      {.v = &layouts[6]} },
	{ MODKEY,                       XK_bracketleft,     setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_bracketright,    setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_comma,           incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_period,          incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_space,           togglefloating, {0} },
	/* Program control */
	{ Mod1Mask,                     XK_Tab,             altTabStart,    {0} },
	{ MODKEY|ShiftMask,             XK_r,               quit,           {0} },
	{ MODKEY|ShiftMask,             XK_q,               spawn,          SHCMD("pkill dwm") },
	{ MODKEY,                       XK_c,               killclient,     {0} },

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask          button          function        argument */
	{ ClkLtSymbol,          0,                  Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                  Button3,        setlayout,      {.v = &layouts[5]} },
	{ ClkClientWin,         MODKEY,             Button1,        moveorplace,    {.i = 2} },
	{ ClkClientWin,         MODKEY,             Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,   Button2,        killclient,     {0} },
	{ ClkClientWin,         MODKEY,             Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                  Button1,        view,           {0} },
	{ ClkTagBar,            0,                  Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,             Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,             Button3,        toggletag,      {0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};

