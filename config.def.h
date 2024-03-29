/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 10; 
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 2;        /* horizontal padding for statusbar */
static const int vertpadbar         = 0;        /* vertical padding for statusbar */
static const int title_width         = 10;
static const int tab_width           = 10;
static const int comp_integration    = 1;        /* enable compositor integration */
static unsigned int gamingmode       = 0;        /* enable/disable gaming mode (switch compositors)*/
static const char *restart_compositor_cmd[] = {"compositor-manager", "-c", "picom", "-r", "0", NULL};
static const char *restart_compositor_gaps_cmd[] = {"compositor-manager", "-c", "picom", "-r", "15", NULL};
static const char *restart_compositor_gaming_cmd[] = {"compositor-manager", "-c", "xcompmgr", NULL};

/*  Display modes of the tab bar: never shown, always shown, shown only in  */
/*  monocle mode in the presence of several windows.                        */
/*  Modes after showtab_nmodes are disabled.                                */
enum showtab_modes { showtab_never, showtab_auto, showtab_nmodes, showtab_always};
static const int showtab			= showtab_auto;        /* Default tab bar show mode */
static const int toptab				= 0;               /* False means bottom tab bar */

static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_bg[]          = "#282828";
static const char col_fg[]          = "#ebdbb2";
static const char col_fg1[]         = "#928374";
static const char col_fg2[]         = "#504945";
static const char col_border[]      = "#282828";
static const char col_border_sel[]  = "#928374";
static const char col_gray[]        = "#928374";
static const char col_red[]         = "#fb4934";
static const char col_green[]       = "#b8bb26";
static const char col_yellow[]      = "#fabd2f";
static const char col_cyan[]        = "#83a598";
static const char col_purple[]      = "#d3869b";
static const char col_aqua[]        = "#8ec07c";

static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";

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
	[SchemeSel]      = { col_fg,           col_bg,     col_border  },
	[SchemeTabNorm]  = { col_fg,           col_bg,     col_fg  },
	[SchemeTabSel]   = { col_bg,           col_fg,     col_border  },
	[SchemeLayout]   = { col_purple,       col_bg,     col_border  },
	[SchemeLauncher] = { col_cyan,         col_bg,     col_border  },
	[SchemeScreen1]  = { col_red,          col_bg,     col_border  },
	[SchemeScreen2]  = { col_green,        col_bg,     col_border  },
	[SchemeScreen3]  = { col_yellow,       col_bg,     col_border  },
};

static const unsigned int baralpha        = OPAQUE;
static const unsigned int bordernormalpha = 204U;
static const unsigned int borderselalpha  = OPAQUE;
static const unsigned int alphas[][3]      = {
	/*                      fg               bg        border     */
	[SchemeNorm]     = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeCol1]     = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeCol2]     = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeCol3]     = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeCol4]     = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeCol5]     = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeCol6]     = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeSel]      = { OPAQUE,           baralpha,   borderselalpha },
	[SchemeTabNorm]  = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeTabSel]   = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeLayout]   = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeLauncher] = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeScreen1]  = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeScreen2]  = { OPAQUE,           baralpha,   bordernormalpha },
	[SchemeScreen3]  = { OPAQUE,           baralpha,   bordernormalpha },
};/* alphas */

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

/* screen indicators */
static const char *screen_symbols[] = {"\uf109", "\uf878", "\uf26c"};

/* launch menu icon */
static const char *launcher_symbol = "A";

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor    ignoretransient*/
	{ "Gimp",     NULL,       NULL,       0,            1,           -1,        0},
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1,        0},
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "urxvt", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_w,      tabmode,         {-1} },
	{ MODKEY,                       XK_f,      togglefullscreen,{0} },
	{ MODKEY,                       XK_p,      spawn,           {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,           {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,       {0} },
	{ MODKEY,                       XK_j,      focusstack,      {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,      {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      movestack,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,       {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,      {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,      {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,        {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,        {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,            {0} },
	{ MODKEY,                       XK_Tab,    view,            {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,      {0} },
	{ MODKEY,                       XK_z,      layoutscroll,    {.i = -1 } },
	{ MODKEY,                       XK_x,      layoutscroll,    {.i = +1 } },
	{ MODKEY,                       XK_space,  setlayout,       {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating,  {0} },
	{ MODKEY,                       XK_0,      view,            {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,             {.ui = ~0 } },
	{ MODKEY,                       XK_Down,   focusmon,        {.i = -1 } },
	{ MODKEY,                       XK_Up,     focusmon,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,          {.i = -1 } },
	{ MODKEY,                       XK_Right,  shiftview,       {.i = +1 } },
	{ MODKEY,                       XK_Left,   shiftview,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Right,  shifttag,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Left,   shifttag,        {.i = -1 } },
	{ MODKEY,                       XK_minus,  setgaps,         {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,         {.i = 0  } },
	{ MODKEY,                       XK_g,      togglegamingmode,{0} },
	TAGKEYS(                        XK_1,                       0)
	TAGKEYS(                        XK_2,                       1)
	TAGKEYS(                        XK_3,                       2)
	TAGKEYS(                        XK_4,                       3)
	TAGKEYS(                        XK_5,                       4)
	TAGKEYS(                        XK_6,                       5)
	TAGKEYS(                        XK_7,                       6)
	TAGKEYS(                        XK_8,                       7)
	TAGKEYS(                        XK_9,                       8)
	{ MODKEY|ShiftMask,             XK_q,      quit,            {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLauncher,          0,              Button1,        setlayout,      {.v = &layouts[2]} },
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTabBar,            0,              Button1,        focuswin,       {0} },
};

