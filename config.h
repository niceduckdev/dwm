#include <X11/XF86keysym.h>

/* windows */
static const unsigned int borderpx = 3;
static const unsigned int gappih = 10;
static const unsigned int gappiv = 10;
static const unsigned int gappoh = 10;
static const unsigned int gappov = 10;
static const unsigned int snap = 32;
static const float mfact = 0.50;
static const int nmaster = 1;
static const int resizehints = 0;
static const int lockfullscreen = 1;

/* bar */
static const int showbar = 1;
static const int topbar = 0;

/* fonts & colors */
static const char *fonts[] = { "Gohufont:size=18" };
static const char col_bg1[] = "#282828";
static const char col_bg2[] = "#3c3836";
static const char col_fg1[] = "#ebdbb2";
static const char *colors[][3] = {
	/* fg, bg, border */
	[SchemeNorm] = { col_fg1, col_bg1, col_bg2 },
	[SchemeSel] = { col_fg1, col_bg2, col_fg1 },
};

/* tags, rules & layouts */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };
static const Rule rules[] = {{}};
static const Layout layouts[] = {{ "tile", tile }};

/* shortcuts */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY, KEY, view, {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask, KEY, tag, {.ui = 1 << TAG} },

static const char *launchercmd[] = { "rofi", "-show", "drun", NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *increasevolumecmd[]  = { "pamixer", "--increase", "10", NULL };
static const char *decreasevolumecmd[]  = { "pamixer", "--decrease", "10", NULL };
static const char *mutevolumecmd[]  = { "pamixer", "--toggle-mute", NULL };
static const char *screenshotcmd[] = { "maim", "-s", "|", "xclip", "-selection", "clipboard", "-t" ,"image/png", "-i", NULL }; 

static const Button buttons[] = {{}};
static const Key keys[] = {
	{ MODKEY, XK_space, spawn, {.v = launchercmd } },
	{ MODKEY, XK_t, spawn, {.v = termcmd } },
	{ MODKEY, XK_j, focusstack, {.i = +1 } },
	{ MODKEY, XK_k, focusstack, {.i = -1 } },
	{ MODKEY, XK_h, setmfact, {.f = -0.05} },
	{ MODKEY, XK_l, setmfact, {.f = +0.05} },
	{ MODKEY, XK_q, killclient, {0} },
	{ 0, XF86XK_AudioLowerVolume, spawn, {.v = decreasevolumecmd } },
	{ 0, XF86XK_AudioRaiseVolume, spawn, {.v = increasevolumecmd } },
	{ 0, XF86XK_AudioMute, spawn, {.v = mutevolumecmd } },
	{ 0, XK_Print, spawn, {.v = screenshotcmd } },
	TAGKEYS(XK_ampersand, 0)
	TAGKEYS(XK_eacute, 1)
	TAGKEYS(XK_quotedbl, 2)
	TAGKEYS(XK_apostrophe, 3)
	TAGKEYS(XK_parenleft, 4)
	TAGKEYS(XK_section, 5)
	TAGKEYS(XK_egrave, 6)
	TAGKEYS(XK_exclam, 7)
	TAGKEYS(XK_ccedilla, 8)
	TAGKEYS(XK_agrave, 9)
};
