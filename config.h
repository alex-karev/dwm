/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx   = 3;        /* border pixel of windows */
static unsigned int defaultgappx     = 0;        /* gaps between windows */
static const unsigned int snap       = 32;       /* snap pixel */
static const int showbar             = 1;        /* 0 means no bar */
static const int topbar              = 1;        /* 0 means bottom bar */
static const int horizpadbar         = 10;        /* horizontal padding for statusbar */
static const int vertpadbar          = 15;        /* vertical padding for statusbar */
static const int title_width         = 15;
static const int tab_width           = 15;
static const int comp_integration    = 1;        /* enable compositor integration */
static unsigned int gamingmode       = 0;        /* enable/disable gaming mode (switch compositors)*/
static const char *restart_compositor_cmd[] = {"compositor-manager", "-c", "picom", "-r", "0", NULL};
static const char *restart_compositor_gaps_cmd[] = {"compositor-manager", "-c", "picom", "-r", "15", NULL};
static const char *restart_compositor_gaming_cmd[] = {"compositor-manager", "-f", NULL};

/*  Display modes of the tab bar: never shown, always shown, shown only in  */
/*  monocle mode in the presence of several windows.                        */
/*  Modes after showtab_nmodes are disabled.                                */
enum showtab_modes { showtab_never, showtab_auto, showtab_nmodes, showtab_always};
static const int showtab			= showtab_auto;        /* Default tab bar show mode */
static const int toptab				= 0;               /* False means bottom tab bar */

static const char *fonts[]          = {"Hack Nerd Font:size=14" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_bg[]          = "#282828";
static const char col_fg[]          = "#ebdbb2";
static const char col_fg1[]         = "#928374";
static const char col_fg2[]         = "#504945";
static const char col_border[]      = "#282828";
static const char col_border_sel[]  = "#ebdbb2";
static const char col_gray[]        = "#928374";
static const char col_red[]         = "#fb4934";
static const char col_green[]       = "#b8bb26";
static const char col_yellow[]      = "#fabd2f";
static const char col_cyan[]        = "#83a598";
static const char col_purple[]      = "#d3869b";
static const char col_aqua[]        = "#8ec07c";

enum { SchemeNorm, SchemeCol1, SchemeCol2, SchemeCol3, SchemeCol4,
       SchemeCol5, SchemeCol6, SchemeSel, SchemeTabNorm, SchemeTabSel, SchemeLayout, SchemeLauncher,
	   SchemeScreen1, SchemeScreen2, SchemeScreen3}; /* color schemes */

static const char *colors[][3]      = {
	/*                      fg          bg          border   */
	[SchemeNorm]     = { col_fg2,          col_bg,     col_border },
	[SchemeCol1]     = { col_red,          col_bg,     col_border },
	[SchemeCol2]     = { col_green,        col_bg,     col_border },
	[SchemeCol3]     = { col_yellow,       col_bg,     col_border },
	[SchemeCol4]     = { col_cyan,         col_bg,     col_border },
	[SchemeCol5]     = { col_purple,       col_bg,     col_border },
	[SchemeCol6]     = { col_aqua,         col_bg,     col_border },
	[SchemeSel]      = { col_fg,           col_bg,     col_border_sel },
	[SchemeTabNorm]  = { col_fg,           col_fg2,    col_border  },
	[SchemeTabSel]   = { col_bg,           col_fg,     col_border  },
	[SchemeLayout]   = { col_purple,       col_bg,     col_border  },
	[SchemeLauncher] = { col_cyan,         col_bg,     col_border  },
	[SchemeScreen1]  = { col_red,          col_bg,     col_border },
	[SchemeScreen2]  = { col_green,        col_bg,     col_border  },
	[SchemeScreen3]  = { col_yellow,       col_bg,     col_border  },
};/* color schemes */

static const unsigned int baralpha        = OPAQUE;
static const unsigned int bordernormalpha = OPAQUE;
static const unsigned int borderselalpha  = OPAQUE;
static const unsigned int alphas[][3]      = {
	/*                      fg               bg        border     */
	[SchemeNorm]      = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeCol1]      = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeCol2]      = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeCol3]      = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeCol4]      = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeCol5]      = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeCol6]      = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeSel]       = { OPAQUE,           baralpha,   borderselalpha },
	[SchemeTabNorm]   = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeTabSel]    = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeLayout]    = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeLauncher]  = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeScreen1]   = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeScreen2]   = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeScreen3]   = { OPAQUE,           baralpha,   bordernormalpha },
};/* alphas */

/* tagging */
static const char *tags[] = {"\uf121", "\uf0ac", "\uf040", "\uf11b", "\uf03e", "\uf086", "\uf02d", "\uf013", "\uf233"};

/* screen indicators */
static const char *screen_symbols[] = {"\uf109", "\U000f0379", "\uf26c"};

/* launch menu icon */
static const char *launcher_symbol = "\uf303";

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                    instance    title       tags mask     isfloating   monitor   ignoretransient */	
	{ "trayer",                  NULL,       NULL,       0,            1,           -1,       0},
	{ NULL,                      NULL,       "EmojiFloatWnd", 0,       1,           -1,       1},

	{ "Code",                    NULL,       NULL,       1 << 0,       0,           -1,       0 },
	{ "code-oss",                NULL,       NULL,       1 << 0,       0,           -1,       0 },
	  
	{ "firefox",                 NULL,       NULL,       1 << 1,       0,           -1,       0 },
	{ "Chromium",                NULL,       NULL,       1 << 1,       0,           -1,       0 },
	{ "Chromium-browser",        NULL,       NULL,       1 << 1,       0,           -1,       0 },
	  
	{ "Gimp-2.10",               NULL,       NULL,       1 << 2,       0,           -1,       0 },
	{ "Gimp",                    NULL,       NULL,       1 << 2,       0,           -1,       0 },
	{ "Darktable",               NULL,       NULL,       1 << 2,       0,           -1,       0 },
	{ "krita",                   NULL,       NULL,       1 << 2,       0,           -1,       0 },
	{ "Aseprite",                NULL,       NULL,       1 << 2,       0,           -1,       0 },
	{ "Inkscape",                NULL,       NULL,       1 << 2,       0,           -1,       0 },
	{ "kdenlive",                NULL,       NULL,       1 << 2,       0,           -1,       0 },
	{ "Cinelerra",               NULL,       NULL,       1 << 2,       0,           -1,       0 },
	{ "Blender",                 NULL,       NULL,       1 << 2,       0,           -1,       0 },
	{ "Audacity",                NULL,       NULL,       1 << 2,       0,           -1,       0 },
	  
	{ "Godot",                   NULL,       NULL,       1 << 3,       0,           -1,       0 },
	{ "UnityHub",                NULL,       NULL,       1 << 3,       0,           -1,       0 },
	{ "Lutris",                  NULL,       NULL,       1 << 3,       0,           -1,       0 },
	{ "com.github.tkashkin.gamehub", NULL,       NULL,       1 << 3,       0,       -1,       0 },
	{ "Steam",                   NULL,       NULL,       1 << 3,       0,           -1,       0 },
	{ "itch",                    NULL,       NULL,       1 << 3,       0,           -1,       0 },
	  
	{ "mpv",                     NULL,       NULL,       1 << 4,       0,           -1,       0 },
	{ "Stremio",                 NULL,       NULL,       1 << 4,       0,           -1,       0 },
	{ "FreeTube",                NULL,       NULL,       1 << 4,       0,           -1,       0 },
	{ "netease-cloud-music",     NULL,       NULL,       1 << 4,       0,           -1,       0 },
	{ "YouTube Music",           NULL,       NULL,       1 << 4,       0,           -1,       0 },
	{ "WebApp-YoutubeMusic0826", NULL,       NULL,       1 << 4,       0,           -1,       0 },
	{ "fluent-reader",           NULL,       NULL,       1 << 4,       0,           -1,       0 },
	  
	{ "discord",                 NULL,       NULL,       1 << 5,       0,           -1,       0 },
	{  NULL,                     NULL,   "wechat.exe",   1 << 5,       0,           -1,       0 },
	{ "TelegramDesktop",         NULL,       NULL,       1 << 5,       0,           -1,       0 },
	  
	{ "calibre",                 NULL,       NULL,       1 << 6,       0,           -1,       0 },
	{ "Wps",                     NULL,       NULL,       1 << 6,       0,           -1,       0 },
	{ "Et",                      NULL,       NULL,       1 << 6,       0,           -1,       0 },
	{ "Wpp",                     NULL,       NULL,       1 << 6,       0,           -1,       0 },
	{ "Evince",                  NULL,       NULL,       1 << 6,       0,           -1,       0 },
	{ "Komikku",                 NULL,       NULL,       1 << 6,       0,           -1,       0 },
	  
	{ "obs",                     NULL,       NULL,       1 << 7,       0,           -1,       0 },
	{ "Uget-gtk",                NULL,       NULL,       1 << 7,       0,           -1,       0 },
	  
	{ "Virt-manager",            NULL,       NULL,       1 << 8,       0,           -1,       0 },
	{ "Vmplayer",                NULL,       NULL,       1 << 8,       0,           -1,       0 },
	{ "scrcpy",                  NULL,       NULL,       1 << 8,       0,           -1,       0 },
	{ "org.remmina.Remmina",     NULL,       NULL,       1 << 8,       0,           -1,       0 },
	
    { "obsidian",                NULL,       NULL,       0,            0,           -1,       0 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "\ueb56",      tile },    /* first entry is default */
	{ "\ueb7f",      monocle },
	{ "\ueb57",      bstack },
	{ "\ueb6a",      bstackhoriz },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* commands */
#define SCREENSHOT_PATH "/home/alex/Pictures/Screenshots"
static const char *termcmd[]  			  = {"st", NULL };
static const char *runcmd[]   			  = {"rofi", "-show", "drun"};
static const char *browsercmd[]           = {"qutebrowser", NULL };
static const char *notescmd[]             = {"obsidian", NULL };
static const char *menucmd[]              = {"archmenu", NULL};
static const char *screenshooter[]        = {"flameshot", "full", "-p", SCREENSHOT_PATH, NULL};
static const char *advancedScreenshooter[]= {"flameshot", "gui", NULL};
static const char *filemanager[]          = {"rofi", "-show", "filebrowser"};
static const char *toggletray[]           = {"toggle-tray", "-c", "#282828"};
static const char *settingsmenu[]         = {"st", "settings-menu"};
static const char *tasklist[]             = {"rofi", "-show", "window"};
static const char *increaseBrightness[]   = {"dunst-brightness", "-inc", "10", NULL};
static const char *fullBrightness[]       = {"dunst-brightness", "-set", "100", NULL};
static const char *decreaseBrightness[]   = {"dunst-brightness", "-dec", "10", NULL};
static const char *offBrightness[]        = {"dunst-brightness", "-set", "0", NULL};
static const char *increaseVolume[]       = {"dunst-volume", "-i", "5"};
static const char *decreaseVolume[]       = {"dunst-volume", "-d", "5"};
static const char *muteVolume[]           = {"dunst-volume", "-t"};
static const char *closeDwm[]			  = {"killall", "dwm-start", NULL};

#include <X11/XF86keysym.h>
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY|ShiftMask,             XK_space,  tabmode,         {-1} },
	{ MODKEY,                       XK_f,      togglefullscreen,{0} },
	{ MODKEY,                       XK_Return, spawn,           {.v = termcmd } },
	{ MODKEY,                       XK_r,      spawn,           {.v = runcmd } },
	{ MODKEY,                       XK_b,      spawn,           {.v = browsercmd } },
	{ MODKEY,                       XK_n,      spawn,           {.v = notescmd } },
	{ MODKEY,                       XK_j,      focusstack,      {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,      {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      movestack,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,       {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,      {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,      {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,        {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,        {.f = +0.05} },
	{ MODKEY,                       XK_space,  zoom,            {0} },
	{ MODKEY,                       XK_c,      killclient,      {0} },
	{ MODKEY,                       XK_z,      layoutscroll,    {.i = -1 } },
	{ MODKEY,                       XK_x,      layoutscroll,    {.i = +1 } },
	{ MODKEY,                       XK_t,      togglefloating,  {0} },
	{ MODKEY,                       XK_0,      view,            {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,             {.ui = ~0 } },
	{ MODKEY,                       XK_Down,   focusmon,        {.i = -1 } },
	{ MODKEY,                       XK_Up,     focusmon,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,          {.i = -1 } },
	{ MODKEY,                       XK_Right,  shiftview,       {.i = +1 } },
	{ MODKEY,                       XK_Left,   shiftview,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Right,  shifttag,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Left,   shifttag,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,         {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,         {.i = 0  } },
	{ MODKEY,                       XK_g,      togglegamingmode,{0} },
	{ MODKEY,                       XK_s,      spawn,           {.v = screenshooter } },
	{ MODKEY|ShiftMask,             XK_s,      spawn,           {.v = advancedScreenshooter } },
	{ MODKEY,                       XK_v,      spawn,           {.v = filemanager } },
	{ MODKEY,                       XK_w,      spawn,           {.v = settingsmenu} },
	{ MODKEY,                       XK_y,      spawn,           {.v = toggletray} },
	{ MODKEY,                       XK_Tab,    spawn,           {.v = tasklist} },
	{ 0,                            XF86XK_MonBrightnessUp,  	spawn,   {.v = increaseBrightness } },
	{ 0,                            XF86XK_MonBrightnessDown,  	spawn,   {.v = decreaseBrightness} },
	{ MODKEY,                       XF86XK_MonBrightnessUp,  	spawn,   {.v = fullBrightness} },
	{ MODKEY,                       XF86XK_MonBrightnessDown,  	spawn,   {.v = offBrightness} },
	{ 0,                            XF86XK_AudioRaiseVolume,  	spawn,   {.v = increaseVolume} },
	{ 0,                            XF86XK_AudioLowerVolume,  	spawn,   {.v = decreaseVolume} },
	{ 0,                            XF86XK_AudioMute,           spawn,   {.v = muteVolume} },
	{ MODKEY,                       XK_F12,  	                spawn,   {.v = increaseBrightness } },
	{ MODKEY,                       XK_F11,  	                spawn,   {.v = decreaseBrightness} },
	{ MODKEY,                       XK_F3,  	                spawn,   {.v = increaseVolume} },
	{ MODKEY,                       XK_F2,  	                spawn,   {.v = decreaseVolume} },
	{ MODKEY,                       XK_F1,                      spawn,   {.v = muteVolume} },
	TAGKEYS(                        XK_1,                       0)
	TAGKEYS(                        XK_2,                       1)
	TAGKEYS(                        XK_3,                       2)
	TAGKEYS(                        XK_4,                       3)
	TAGKEYS(                        XK_5,                       4)
	TAGKEYS(                        XK_6,                       5)
	TAGKEYS(                        XK_7,                       6)
	TAGKEYS(                        XK_8,                       7)
	TAGKEYS(                        XK_9,                       8)
	TAGKEYS(                        XK_KP_End,                  0)
	TAGKEYS(                        XK_KP_Down,                 1)
	TAGKEYS(                        XK_KP_Next,                 2)
	TAGKEYS(                        XK_KP_Left,                 3)
	TAGKEYS(                        XK_KP_Begin,                4)
	TAGKEYS(                        XK_KP_Right,                5)
	TAGKEYS(                        XK_KP_Home,                 6)
	TAGKEYS(                        XK_KP_Up,                   7)
	TAGKEYS(                        XK_KP_Prior,                8)
	{ MODKEY|ShiftMask,             XK_r,      quit,            {0} },
	{ MODKEY|ShiftMask,             XK_q,      spawn,           {.v = closeDwm} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLauncher,          0,              Button1,        spawn,          {.v = menucmd} },
	{ ClkLtSymbol,          0,              Button1,        layoutscroll,   {.i = +1} },
	{ ClkScreenSymbol,      0,              Button1,        focusmon,       {.i = +1} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTabBar,            0,              Button1,        focuswin,       {0} },
};

