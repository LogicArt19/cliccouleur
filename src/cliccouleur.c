/* ClicCouleur.exe - clic automatique sur une couleur, sans AutoHotkey.
   F8 : choisir la couleur sous le curseur
   F9 : activer / desactiver
   F10 : quitter (ou fermer la fenetre)
   Ne clique jamais quand un jeu en ligne est au premier plan. */

typedef unsigned int UINT; typedef unsigned long DWORD; typedef int BOOL; typedef long LONG;
typedef unsigned short WCHAR; typedef unsigned char BYTE;
typedef unsigned long long ULONG_PTR, WPARAM, UINT_PTR; typedef long long LPARAM, LRESULT;
typedef void *HANDLE, *HWND, *HDC, *HINSTANCE, *HICON, *HCURSOR, *HBRUSH, *HMENU, *HGDIOBJ;
typedef const WCHAR *LPCWSTR;
typedef LRESULT (*WNDPROC)(HWND, UINT, WPARAM, LPARAM);
#define IMP __declspec(dllimport)

typedef struct { LONG x, y; } POINT;
typedef struct { LONG left, top, right, bottom; } RECT;
typedef struct { UINT style; WNDPROC lpfnWndProc; int cbClsExtra, cbWndExtra; HINSTANCE hInstance;
  HICON hIcon; HCURSOR hCursor; HBRUSH hbrBackground; LPCWSTR lpszMenuName, lpszClassName; } WNDCLASSW;
typedef struct { HWND hwnd; UINT message; WPARAM wParam; LPARAM lParam; DWORD time; POINT pt; DWORD lPrivate; } MSG;
typedef struct { HDC hdc; BOOL fErase; RECT rcPaint; BOOL fRestore, fIncUpdate; BYTE rgbReserved[32]; } PAINTSTRUCT;
typedef struct { LONG dx, dy; DWORD mouseData, dwFlags, time; ULONG_PTR dwExtraInfo; } MOUSEINPUT;
typedef struct { DWORD type; MOUSEINPUT mi; } INPUT;

/* kernel32 */
IMP HINSTANCE GetModuleHandleW(LPCWSTR); IMP void ExitProcess(UINT); IMP DWORD GetTickCount(void);
IMP HANDLE OpenProcess(DWORD, BOOL, DWORD); IMP BOOL CloseHandle(HANDLE);
IMP BOOL QueryFullProcessImageNameW(HANDLE, DWORD, WCHAR *, DWORD *); IMP DWORD GetCurrentProcessId(void);
/* user32 */
IMP BOOL SetProcessDPIAware(void); IMP unsigned short RegisterClassW(const WNDCLASSW *);
IMP HWND CreateWindowExW(DWORD, LPCWSTR, LPCWSTR, DWORD, int, int, int, int, HWND, HMENU, HINSTANCE, void *);
IMP BOOL ShowWindow(HWND, int); IMP BOOL GetMessageW(MSG *, HWND, UINT, UINT);
IMP BOOL TranslateMessage(const MSG *); IMP LRESULT DispatchMessageW(const MSG *);
IMP LRESULT DefWindowProcW(HWND, UINT, WPARAM, LPARAM); IMP void PostQuitMessage(int);
IMP BOOL RegisterHotKey(HWND, int, UINT, UINT); IMP UINT_PTR SetTimer(HWND, UINT_PTR, UINT, void *);
IMP BOOL KillTimer(HWND, UINT_PTR); IMP BOOL GetCursorPos(POINT *); IMP HDC GetDC(HWND);
IMP UINT SendInput(UINT, INPUT *, int); IMP HWND GetForegroundWindow(void);
IMP DWORD GetWindowThreadProcessId(HWND, DWORD *); IMP BOOL InvalidateRect(HWND, const RECT *, BOOL);
IMP HDC BeginPaint(HWND, PAINTSTRUCT *); IMP BOOL EndPaint(HWND, const PAINTSTRUCT *);
IMP int DrawTextW(HDC, LPCWSTR, int, RECT *, UINT); IMP HCURSOR LoadCursorW(HINSTANCE, LPCWSTR);
IMP int FillRect(HDC, const RECT *, HBRUSH); IMP BOOL DestroyWindow(HWND);
/* gdi32 */
IMP DWORD GetPixel(HDC, int, int); IMP HBRUSH CreateSolidBrush(DWORD); IMP BOOL DeleteObject(HGDIOBJ);
IMP int SetBkMode(HDC, int);
/* selection de zone */
typedef struct { DWORD biSize; LONG biWidth, biHeight; unsigned short biPlanes, biBitCount;
  DWORD biCompression, biSizeImage; LONG biXPelsPerMeter, biYPelsPerMeter; DWORD biClrUsed, biClrImportant; DWORD pal; } BMI;
IMP int GetSystemMetrics(int); IMP HDC CreateCompatibleDC(HDC); IMP HGDIOBJ CreateCompatibleBitmap(HDC, int, int);
IMP HGDIOBJ CreateDIBSection(HDC, const BMI *, UINT, void **, HANDLE, DWORD); IMP HGDIOBJ SelectObject(HDC, HGDIOBJ);
IMP BOOL BitBlt(HDC, int, int, int, int, HDC, int, int, DWORD); IMP BOOL DeleteDC(HDC);
IMP DWORD SetTextColor(HDC, DWORD); IMP DWORD SetBkColor(HDC, DWORD);
IMP int FrameRect(HDC, const RECT *, HBRUSH); IMP HWND SetCapture(HWND); IMP BOOL ReleaseCapture(void);
IMP BOOL SetForegroundWindow(HWND); IMP int ReleaseDC(HWND, HDC); IMP BOOL GetWindowRect(HWND, RECT *); IMP HWND FindWindowW(LPCWSTR, LPCWSTR);
IMP LRESULT SendMessageW(HWND, UINT, WPARAM, LPARAM); IMP void Sleep(DWORD);
/* mises a jour */
IMP DWORD GetTempPathW(DWORD, WCHAR *); IMP HANDLE CreateFileW(LPCWSTR, DWORD, DWORD, void *, DWORD, DWORD, HANDLE);
IMP BOOL ReadFile(HANDLE, void *, DWORD, DWORD *, void *); IMP BOOL MoveFileExW(LPCWSTR, LPCWSTR, DWORD);
IMP BOOL DeleteFileW(LPCWSTR); IMP HANDLE CreateThread(void *, unsigned long long, DWORD (*)(void *), void *, DWORD, DWORD *);
IMP long URLDownloadToFileW(void *, LPCWSTR, LPCWSTR, DWORD, void *);
IMP HINSTANCE ShellExecuteW(HWND, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, int);
IMP int MessageBoxW(HWND, LPCWSTR, LPCWSTR, UINT); IMP BOOL PostMessageW(HWND, UINT, WPARAM, LPARAM);
IMP BOOL SetWindowTextW(HWND, LPCWSTR); IMP BOOL SetLayeredWindowAttributes(HWND, DWORD, BYTE, DWORD);
IMP BOOL IsIconic(HWND); IMP HWND WindowFromPoint(POINT);
/* demarrage */
IMP DWORD GetModuleFileNameW(HINSTANCE, WCHAR *, DWORD); IMP WCHAR *GetCommandLineW(void);
IMP BOOL OpenProcessToken(HANDLE, DWORD, HANDLE *); IMP BOOL GetTokenInformation(HANDLE, int, void *, DWORD, DWORD *);
IMP LONG RegSetKeyValueW(HANDLE, LPCWSTR, LPCWSTR, DWORD, const void *, DWORD);

void *memset(void *d, int c, unsigned long long n) { BYTE *p = d; while (n--) *p++ = (BYTE)c; return d; }

#ifndef VERSION
#define VERSION 0
#endif
#define URL_DEPOT L"https://github.com/LogicArt19/cliccouleur/releases/latest/download/"

/* ---- Reglages ---- */
#define TOLERANCE   20    /* 0 = couleur exacte */
#define INTERVALLE  50    /* ms entre deux verifications */
#define DELAI_CLIC  300   /* ms minimum entre deux clics */

static HDC ecran; static DWORD couleur = 0xFFFFFFFF; static int actif = 0, dejaSur = 0, bloque = 0;
static DWORD dernierClic = 0; static HWND fenetre, voile, mini, avantSelection; static int touchesOk = 1; static int versionDispo = 0; static int nbClics = 0; static int cibleAdmin = 0, moiAdmin = 0; static int enSelection = 0;

static void rafraichir(void) { InvalidateRect(fenetre, 0, 1); if (mini) InvalidateRect(mini, 0, 1); }

/* ---- Selection d'une zone a l'ecran, facon capture d'ecran ---- */
static int vx, vy, vw, vh, glisse = 0; static POINT p0, p1;
static HDC dcCapture, dcTampon; static HGDIOBJ bmCapture, bmTampon, ancienCapture, ancienTampon;
static DWORD *pixels;
static DWORD compte[4096]; static unsigned long long sr[4096], sg[4096], sb[4096];

/* Couleur dominante de la zone (la plus presente), en COLORREF */
static DWORD couleurDominante(int x0, int y0, int x1, int y1) {
  int t; if (x0 > x1) { t = x0; x0 = x1; x1 = t; } if (y0 > y1) { t = y0; y0 = y1; y1 = t; }
  if (x0 < 0) x0 = 0; if (y0 < 0) y0 = 0; if (x1 >= vw) x1 = vw - 1; if (y1 >= vh) y1 = vh - 1;
  memset(compte, 0, sizeof compte); memset(sr, 0, sizeof sr); memset(sg, 0, sizeof sg); memset(sb, 0, sizeof sb);
  int best = 0;
  for (int y = y0; y <= y1; y++) for (int x = x0; x <= x1; x++) {
    DWORD p = pixels[(long long)y * vw + x]; DWORD r = (p >> 16) & 255, g = (p >> 8) & 255, b = p & 255;
    int k = (int)(((r >> 4) << 8) | ((g >> 4) << 4) | (b >> 4));
    compte[k]++; sr[k] += r; sg[k] += g; sb[k] += b; if (compte[k] > compte[best]) best = k; }
  if (!compte[best]) return 0xFFFFFFFF;
  DWORD n = compte[best];
  return (DWORD)(sr[best] / n) | ((DWORD)(sg[best] / n) << 8) | ((DWORD)(sb[best] / n) << 16);
}

static void fermerSelection(void) {
  if (glisse) ReleaseCapture(); glisse = 0;
  if (voile) { HWND v = voile; voile = 0; DestroyWindow(v); }
  if (dcCapture) { SelectObject(dcCapture, ancienCapture); DeleteObject(bmCapture); DeleteDC(dcCapture); dcCapture = 0; }
  if (dcTampon) { SelectObject(dcTampon, ancienTampon); DeleteObject(bmTampon); DeleteDC(dcTampon); dcTampon = 0; }
  enSelection = 0; dejaSur = 1; /* pas de clic immediat */
  rafraichir();
  if (avantSelection) { SetForegroundWindow(avantSelection); avantSelection = 0; }  /* rend la main a ton logiciel */
}

static void ouvrirSelection(void) {
  if (enSelection) return;
  vx = GetSystemMetrics(76); vy = GetSystemMetrics(77); vw = GetSystemMetrics(78); vh = GetSystemMetrics(79);
  BMI bi; memset(&bi, 0, sizeof bi); bi.biSize = 40; bi.biWidth = vw; bi.biHeight = -vh; bi.biPlanes = 1; bi.biBitCount = 32;
  dcCapture = CreateCompatibleDC(ecran); bmCapture = CreateDIBSection(ecran, &bi, 0, (void **)&pixels, 0, 0);
  if (!dcCapture || !bmCapture) { fermerSelection(); return; }
  ancienCapture = SelectObject(dcCapture, bmCapture);
  BitBlt(dcCapture, 0, 0, vw, vh, ecran, vx, vy, 0x00CC0020);
  dcTampon = CreateCompatibleDC(ecran); bmTampon = CreateCompatibleBitmap(ecran, vw, vh);
  ancienTampon = SelectObject(dcTampon, bmTampon);
  enSelection = 1; glisse = 0; avantSelection = GetForegroundWindow();
  voile = CreateWindowExW(0x88, L"ClicCouleurZone", L"", 0x80000000, vx, vy, vw, vh, 0, 0, GetModuleHandleW(0), 0);
  ShowWindow(voile, 5); SetForegroundWindow(voile);
}

static LRESULT procZone(HWND h, UINT m, WPARAM w, LPARAM l) {
  int x = (short)(l & 0xFFFF), y = (short)((l >> 16) & 0xFFFF);
  switch (m) {
  case 0x14: return 1; /* pas d'effacement : evite le clignotement */
  case 0xF: { PAINTSTRUCT ps; HDC dc = BeginPaint(h, &ps);
    BitBlt(dcTampon, 0, 0, vw, vh, dcCapture, 0, 0, 0x00CC0020);
    if (glisse) { RECT r = { p0.x < p1.x ? p0.x : p1.x, p0.y < p1.y ? p0.y : p1.y,
                             (p0.x > p1.x ? p0.x : p1.x) + 1, (p0.y > p1.y ? p0.y : p1.y) + 1 };
      HBRUSH rouge = CreateSolidBrush(0x0000FF); FrameRect(dcTampon, &r, rouge);
      r.left--; r.top--; r.right++; r.bottom++; FrameRect(dcTampon, &r, rouge); DeleteObject(rouge); }
    SetBkMode(dcTampon, 2); SetBkColor(dcTampon, 0); SetTextColor(dcTampon, 0xFFFFFF);
    RECT t = { -vx + 20, -vy + 20, -vx + 900, -vy + 60 };
    DrawTextW(dcTampon, L"  Fais glisser pour entourer la zone (ou clique sur un point)  -  Échap ou clic droit : annuler  ", -1, &t, 0x20);
    BitBlt(dc, 0, 0, vw, vh, dcTampon, 0, 0, 0x00CC0020); EndPaint(h, &ps); return 0; }
  case 0x201: glisse = 1; p0.x = p1.x = x; p0.y = p1.y = y; SetCapture(h); InvalidateRect(h, 0, 0); return 0;
  case 0x200: if (glisse) { p1.x = x; p1.y = y; InvalidateRect(h, 0, 0); } return 0;
  case 0x202: if (glisse) { DWORD c; p1.x = x; p1.y = y;
      c = couleurDominante(p0.x, p0.y, p1.x, p1.y); if (c != 0xFFFFFFFF) couleur = c; fermerSelection(); } return 0;
  case 0x204: fermerSelection(); return 0;
  case 0x100: if (w == 0x1B) fermerSelection(); return 0;
  }
  return DefWindowProcW(h, m, w, l);
}

/* Jeux en ligne : aucun clic quand l'un d'eux est au premier plan */
/* Noms exacts des executables (un nom finissant par '_' = prefixe) */
static const char *jeux[] = { "valorant-win64-shipping.exe", "valorant.exe", "cs2.exe", "csgo.exe",
  "fivem.exe", "fivem_", "gta5.exe", "gta5_enhanced.exe", "r5apex.exe", "r5apex_dx12.exe",
  "fortniteclient-win64-shipping.exe", "overwatch.exe", "tslgame.exe", "cod.exe", "rainbowsix.exe",
  "rainbowsix_vulkan.exe", "rustclient.exe", "deadlock.exe", "marvel-win64-shipping.exe",
  "escapefromtarkov.exe", "bf6.exe", "bf2042.exe", "discovery.exe", "league of legends.exe", 0 };

static WCHAR nomPremierPlan[64];
static void ajouteNom(const WCHAR *s) { int i = 0; while (s[i] && i < 63) { nomPremierPlan[i] = s[i]; i++; } nomPremierPlan[i] = 0; }
static WCHAR basse(WCHAR c) { return (c >= 'A' && c <= 'Z') ? c + 32 : c; }
static int correspond(const WCHAR *s, const char *p) {
  while (*p) { if (p[0] == '_' && !p[1]) return basse(*s) == '_';   /* prefixe */
    if (basse(*s) != (WCHAR)*p) return 0; s++; p++; }
  return *s == 0; }

/* 1 si le processus tourne en administrateur, 2 si on ne peut pas savoir (souvent = administrateur) */
static int estAdmin(HANDLE proc) {
  HANDLE t; DWORD e = 0, n = 0;
  if (!OpenProcessToken(proc, 8 /* TOKEN_QUERY */, &t)) return 2;
  BOOL ok = GetTokenInformation(t, 20 /* TokenElevation */, &e, sizeof e, &n); CloseHandle(t);
  return ok ? (e != 0) : 2;
}
static DWORD pixelActuel = 0; static int surActuel = 0;
static int jeuAuPremierPlan(void) {
  DWORD pid = 0; WCHAR chemin[520]; DWORD n = 520; const WCHAR *nom; int i;
  HWND w = GetForegroundWindow(); if (!w) return 0;
  GetWindowThreadProcessId(w, &pid);
  nomPremierPlan[0] = 0;
  if (pid == GetCurrentProcessId()) { ajouteNom(L"ClicCouleur"); return 0; }          /* ne clique pas sur sa propre fenetre */
  cibleAdmin = 0;
  HANDLE h = OpenProcess(0x1000, 0, pid); if (!h) { cibleAdmin = !moiAdmin; return 0; }
  cibleAdmin = !moiAdmin && estAdmin(h) != 0;
  BOOL ok = QueryFullProcessImageNameW(h, 0, chemin, &n); CloseHandle(h); if (!ok) return 0;
  nom = chemin; for (i = 0; chemin[i]; i++) if (chemin[i] == '\\') nom = chemin + i + 1;
  ajouteNom(nom);
  for (i = 0; jeux[i]; i++) if (correspond(nom, jeux[i])) return 1;
  return 0;
}

static int proche(DWORD a, DWORD b) {
  for (int s = 0; s < 24; s += 8) { int d = (int)((a >> s) & 0xFF) - (int)((b >> s) & 0xFF);
    if (d < -TOLERANCE || d > TOLERANCE) return 0; } return 1; }

static void clic(void) {
  INPUT in[2]; memset(in, 0, sizeof in);
  in[0].mi.dwFlags = 0x2; in[1].mi.dwFlags = 0x4;   /* gauche bas / haut */
  SendInput(1, &in[0], sizeof(INPUT)); Sleep(40);      /* certains logiciels ignorent un clic trop rapide */
  SendInput(1, &in[1], sizeof(INPUT));
}

static WCHAR *ajoute(WCHAR *d, const WCHAR *s) { while (*s) *d++ = *s++; *d = 0; return d; }

static WCHAR *hexa(WCHAR *p, DWORD c) { static const WCHAR h[] = L"0123456789ABCDEF";
  DWORD v[3] = { c & 255, (c >> 8) & 255, (c >> 16) & 255 }; *p++ = '#';
  for (int i = 0; i < 3; i++) { *p++ = h[v[i] >> 4]; *p++ = h[v[i] & 15]; } *p = 0; return p; }
static WCHAR *chiffres(WCHAR *p, int n);
static void dessine(HWND hwnd) {
  PAINTSTRUCT ps; HDC dc = BeginPaint(hwnd, &ps); WCHAR t[512], *p = t;
  static const WCHAR hex[] = L"0123456789ABCDEF";
  SetBkMode(dc, 1);
  p = ajoute(p, L"F8 : entourer une zone à l'écran pour prendre sa couleur\nF9 : activer / désactiver\nF10 : quitter\n\nCouleur : ");
  if (couleur == 0xFFFFFFFF) p = ajoute(p, L"aucune");
  else { DWORD rgb[3] = { couleur & 0xFF, (couleur >> 8) & 0xFF, (couleur >> 16) & 0xFF };
    *p++ = '#'; for (int i = 0; i < 3; i++) { *p++ = hex[rgb[i] >> 4]; *p++ = hex[rgb[i] & 15]; } *p = 0; }
  p = ajoute(p, actif ? L"\nÉtat : ACTIVÉ" : L"\nÉtat : désactivé");
  if (versionDispo) p = ajoute(p, L"\nMise à jour disponible : clique sur « Mettre à jour »");
  if (!touchesOk) p = ajoute(p, L"\n(touches F8/F9/F10 prises par un autre logiciel : utilise les boutons)");
  if (actif) {
    p = ajoute(p, L"\nSous le curseur : "); p = hexa(p, pixelActuel);
    p = ajoute(p, surActuel ? L"  (correspond)" : L"  (ne correspond pas)");
    p = ajoute(p, L"\nClics faits : "); p = chiffres(p, nbClics);
    if (cibleAdmin) p = ajoute(p, L"\n!! Ton logiciel est en administrateur : Windows bloque les clics.\n   Ferme ClicCouleur et relance-le en administrateur (clic droit).");
    p = ajoute(p, L"\nAppli au premier plan : "); p = ajoute(p, nomPremierPlan[0] ? nomPremierPlan : L"?");
    if (bloque) p = ajoute(p, L"\nEN PAUSE : jeu en ligne au premier plan");
  }
  RECT r = { 12, 10, 470, 270 }; DrawTextW(dc, t, -1, &r, 0x10);
  if (couleur != 0xFFFFFFFF) { RECT c = { 300, 72, 340, 92 }; HBRUSH b = CreateSolidBrush(couleur);
    FillRect(dc, &c, b); DeleteObject(b); }
  EndPaint(hwnd, &ps);
}

static void mettreAJour(HWND hwnd);
static LRESULT proc(HWND hwnd, UINT m, WPARAM w, LPARAM l) {
  switch (m) {
  case 0x312: /* WM_HOTKEY */
    if (w == 1) ouvrirSelection();
    else if (w == 2 && couleur != 0xFFFFFFFF && !enSelection) {
      actif = !actif; dejaSur = 0;
      if (actif) SetTimer(hwnd, 1, INTERVALLE, 0); else KillTimer(hwnd, 1); }
    else if (w == 3) { fermerSelection(); DestroyWindow(hwnd); }
    rafraichir(); return 0;
  case 0x113: { /* WM_TIMER */
    if (enSelection) return 0;
    int b = jeuAuPremierPlan(); if (b != bloque) { bloque = b; rafraichir(); }
    POINT pt; GetCursorPos(&pt); int sur = proche(GetPixel(ecran, pt.x, pt.y), couleur);
    /* ne pas cliquer seulement si la fenetre VISIBLE sous le curseur est a ClicCouleur */
    DWORD pidSous = 0; HWND sous = WindowFromPoint(pt); if (sous) GetWindowThreadProcessId(sous, &pidSous);
    int surFenetre = sous && pidSous == GetCurrentProcessId();
    if (!b && !surFenetre && sur && !dejaSur && GetTickCount() - dernierClic > DELAI_CLIC) { clic(); dernierClic = GetTickCount(); nbClics++; rafraichir(); }
    { static int n = 0; DWORD px = GetPixel(ecran, pt.x, pt.y);
      if (++n >= 5 || sur != surActuel) { n = 0; pixelActuel = px; surActuel = sur; rafraichir(); } }
    dejaSur = sur; return 0; }
  case 0x111: /* boutons */
    if ((w & 0xFFFF) >= 101 && (w & 0xFFFF) <= 102) return proc(hwnd, 0x312, (w & 0xFFFF) - 100, 0);
    if ((w & 0xFFFF) == 103) { mettreAJour(hwnd); return 0; }
    break;
  case 0x8000: rafraichir(); return 0;
  case 0xF: dessine(hwnd); return 0;
  case 0x2: PostQuitMessage(0); return 0;
  }
  return DefWindowProcW(hwnd, m, w, l);
}

/* ---- Mises a jour depuis GitHub ---- */
static WCHAR *chiffres(WCHAR *p, int n) { WCHAR t[12]; int i = 0; if (n <= 0) { *p++ = '0'; *p = 0; return p; }
  while (n) { t[i++] = (WCHAR)('0' + n % 10); n /= 10; } while (i) *p++ = t[--i]; *p = 0; return p; }

static int versionDistante(void) {
  WCHAR tmp[600], url[300]; char buf[32]; DWORD lu = 0; int v = 0, i;
  if (!GetTempPathW(500, tmp)) return -1; { WCHAR *p = tmp; while (*p) p++; ajoute(p, L"cliccouleur_version.txt"); }
  { WCHAR *p = ajoute(url, URL_DEPOT); p = ajoute(p, L"version.txt?t="); chiffres(p, (int)(GetTickCount() & 0x7FFFFFFF)); }
  DeleteFileW(tmp);
  if (URLDownloadToFileW(0, url, tmp, 0, 0) != 0) return -1;
  HANDLE f = CreateFileW(tmp, 0x80000000, 1, 0, 3, 0x80, 0); if (f == (HANDLE)-1) return -1;
  ReadFile(f, buf, 31, &lu, 0); CloseHandle(f); DeleteFileW(tmp);
  for (i = 0; i < (int)lu; i++) if (buf[i] >= '0' && buf[i] <= '9') v = v * 10 + (buf[i] - '0'); else if (v) break;
  return v ? v : -1;
}

static DWORD verifAuDemarrage(void *x) {
  WCHAR exe[600], *p; Sleep(3000);
  DWORD n = GetModuleFileNameW(0, exe, 520); if (n && n < 520) { p = exe + n; ajoute(p, L".old"); DeleteFileW(exe); }
  int v = versionDistante(); if (v > VERSION) { versionDispo = v; PostMessageW(fenetre, 0x8000, 0, 0); }
  return 0;
}

/* Ajoute un chemin entre apostrophes pour PowerShell (les ' sont doubles) */
static WCHAR *cheminPS(WCHAR *p, const WCHAR *c) { *p++ = '\''; while (*c) { if (*c == '\'') *p++ = '\''; *p++ = *c++; } *p++ = '\''; *p = 0; return p; }

static void mettreAJour(HWND hwnd) {
  static WCHAR exe[600], neuf[620], url[300], cmd[2600]; DWORD n; WCHAR *p;
  int v = versionDistante();
  if (v < 0) { MessageBoxW(hwnd, L"Impossible de vérifier les mises à jour (pas d'internet, ou aucune version publiée sur GitHub).", L"ClicCouleur", 0x30); return; }
  if (v <= VERSION) { MessageBoxW(hwnd, L"Tu as déjà la dernière version.", L"ClicCouleur", 0x40); return; }
  n = GetModuleFileNameW(0, exe, 520); if (!n || n >= 520) return;
  if (!GetTempPathW(500, neuf)) return; p = neuf; while (*p) p++; ajoute(p, L"ClicCouleur_nouveau.exe");
  ajoute(ajoute(url, URL_DEPOT), L"ClicCouleur.exe");
  DeleteFileW(neuf);
  if (URLDownloadToFileW(0, url, neuf, 0, 0) != 0) { MessageBoxW(hwnd, L"Le téléchargement a échoué.", L"ClicCouleur", 0x10); return; }
  /* PowerShell attend que ce programme soit ferme, remplace le fichier, puis relance la nouvelle version */
  p = ajoute(cmd, L"-NoProfile -ExecutionPolicy Bypass -WindowStyle Hidden -Command \"Wait-Process -Id ");
  p = chiffres(p, (int)GetCurrentProcessId());
  p = ajoute(p, L" -ErrorAction SilentlyContinue; for($i=0;$i -lt 30;$i++){try{Copy-Item -LiteralPath ");
  p = cheminPS(p, neuf); p = ajoute(p, L" -Destination "); p = cheminPS(p, exe);
  p = ajoute(p, L" -Force -ErrorAction Stop; break}catch{Start-Sleep -Milliseconds 500}}; Start-Process -FilePath ");
  p = cheminPS(p, exe); p = ajoute(p, L"\"");
  if ((long long)ShellExecuteW(0, L"open", L"powershell.exe", cmd, 0, 0) <= 32) {
    MessageBoxW(hwnd, L"Impossible de lancer la mise à jour.", L"ClicCouleur", 0x10); return; }
  DestroyWindow(hwnd);   /* se ferme pour liberer le fichier */
}

/* Ajoute (ou met a jour) le lancement automatique avec Windows, demarre en reduit */
static void ajouterDemarrage(void) {
  WCHAR v[600], *p = v; DWORD n;
  *p++ = '"'; n = GetModuleFileNameW(0, p, 520); if (!n || n >= 520) return; p += n;
  p = ajoute(p, L"\" /min");
  RegSetKeyValueW((HANDLE)(long long)(LONG)0x80000001, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run",
    L"ClicCouleur", 1 /* REG_SZ */, v, (DWORD)((p - v + 1) * 2));
}

static int lanceEnReduit(void) {
  const WCHAR *c = GetCommandLineW();
  for (; *c; c++) if (c[0] == '/' && c[1] == 'm' && c[2] == 'i' && c[3] == 'n') return 1;
  return 0;
}

/* ---- Mini barre toujours visible, qui ne prend pas le focus de ton logiciel ---- */
#define MINI_L 300
#define MINI_H 40
static void bouton(HDC dc, int x0, int x1, LPCWSTR t) {
  RECT r = { x0, 6, x1, MINI_H - 6 }; HBRUSH b = CreateSolidBrush(0x505050); FillRect(dc, &r, b); DeleteObject(b);
  DrawTextW(dc, t, -1, &r, 0x1 | 0x4 | 0x20); }
static LRESULT procMini(HWND h, UINT m, WPARAM w, LPARAM l) {
  int x = (short)(l & 0xFFFF);
  switch (m) {
  case 0xF: { PAINTSTRUCT ps; HDC dc = BeginPaint(h, &ps); RECT r = { 0, 0, MINI_L, MINI_H };
    HBRUSH fond = CreateSolidBrush(0x202020); FillRect(dc, &r, fond); DeleteObject(fond);
    SetBkMode(dc, 1); SetTextColor(dc, 0xFFFFFF);
    RECT c = { 8, 10, 28, 30 };
    if (couleur != 0xFFFFFFFF) { HBRUSH b = CreateSolidBrush(couleur); FillRect(dc, &c, b); DeleteObject(b); }
    else { HBRUSH b = CreateSolidBrush(0x808080); FrameRect(dc, &c, b); DeleteObject(b); }
    RECT t = { 34, 0, 112, MINI_H };
    if (actif && bloque) { SetTextColor(dc, 0x00A5FF); DrawTextW(dc, L"PAUSE", -1, &t, 0x4 | 0x20); }
    else if (actif) { SetTextColor(dc, 0x50D050); DrawTextW(dc, L"ACTIVÉ", -1, &t, 0x4 | 0x20); }
    else { SetTextColor(dc, 0xB0B0B0); DrawTextW(dc, L"désactivé", -1, &t, 0x4 | 0x20); }
    SetTextColor(dc, 0xFFFFFF);
    bouton(dc, 116, 196, L"Couleur"); bouton(dc, 202, 292, actif ? L"Désactiver" : L"Activer");
    EndPaint(h, &ps); return 0; }
  case 0x21: return 3;  /* WM_MOUSEACTIVATE -> MA_NOACTIVATE : ton logiciel garde le focus */
  case 0x201:
    if (x >= 116 && x < 196) { proc(fenetre, 0x312, 1, 0); return 0; }
    if (x >= 202 && x < 292) { proc(fenetre, 0x312, 2, 0); return 0; }
    ReleaseCapture(); SendMessageW(h, 0xA1, 2, 0); return 0;   /* deplacer la barre en la faisant glisser */
  case 0x204: ShowWindow(fenetre, 9); SetForegroundWindow(fenetre); return 0;  /* clic droit : fenetre complete */
  }
  return DefWindowProcW(h, m, w, l);
}

void demarrer(void) {
  SetProcessDPIAware(); ajouterDemarrage(); moiAdmin = estAdmin((HANDLE)-1) == 1;
  for (int i = 0; i < 5; i++) { HWND ancien = FindWindowW(L"ClicCouleur", 0); if (!ancien) break;
    SendMessageW(ancien, 0x10, 0, 0); Sleep(200); }   /* ferme une ancienne copie qui garderait les touches */ ecran = GetDC(0);
  HINSTANCE hi = GetModuleHandleW(0); WNDCLASSW wc; memset(&wc, 0, sizeof wc);
  wc.lpfnWndProc = proc; wc.hInstance = hi; wc.hCursor = LoadCursorW(0, (LPCWSTR)32512);
  wc.hbrBackground = (HBRUSH)(5 + 1); wc.lpszClassName = L"ClicCouleur"; RegisterClassW(&wc);
  wc.lpfnWndProc = procZone; wc.lpszClassName = L"ClicCouleurZone"; wc.hCursor = LoadCursorW(0, (LPCWSTR)32515);
  wc.hbrBackground = 0; RegisterClassW(&wc);
  wc.lpfnWndProc = procMini; wc.lpszClassName = L"ClicCouleurMini"; wc.hCursor = LoadCursorW(0, (LPCWSTR)32512); RegisterClassW(&wc);
  HWND hwnd = fenetre = CreateWindowExW(0x8, L"ClicCouleur", L"ClicCouleur", 0x00CA0000,
    (int)0x80000000, (int)0x80000000, 480, 370, 0, 0, hi, 0);
  touchesOk = RegisterHotKey(hwnd, 1, 0x4000, 0x77) & RegisterHotKey(hwnd, 2, 0x4000, 0x78) & RegisterHotKey(hwnd, 3, 0x4000, 0x79);
  CreateWindowExW(0, L"BUTTON", L"Choisir la couleur (F8)", 0x50000000, 12, 280, 150, 32, hwnd, (HMENU)101, hi, 0);
  CreateWindowExW(0, L"BUTTON", L"Activer / Désactiver (F9)", 0x50000000, 168, 280, 160, 32, hwnd, (HMENU)102, hi, 0);
  CreateWindowExW(0, L"BUTTON", L"Mettre à jour", 0x50000000, 334, 280, 118, 32, hwnd, (HMENU)103, hi, 0);
  { WCHAR titre[40], *p = ajoute(titre, L"ClicCouleur v"); chiffres(p, VERSION); SetWindowTextW(hwnd, titre); }
  CreateThread(0, 0, verifAuDemarrage, 0, 0, 0);
  /* mini barre : toujours au-dessus, sans prendre le focus, en haut a droite */
  mini = CreateWindowExW(0x08000000 | 0x80000 | 0x80 | 0x8, L"ClicCouleurMini", L"", 0x80000000,
    GetSystemMetrics(0) - MINI_L - 20, 20, MINI_L, MINI_H, 0, 0, hi, 0);
  SetLayeredWindowAttributes(mini, 0, 230, 2); ShowWindow(mini, 4);
  ShowWindow(hwnd, lanceEnReduit() ? 7 : 5);  /* 7 = reduit sans voler le focus */
  MSG msg; while (GetMessageW(&msg, 0, 0, 0) > 0) { TranslateMessage(&msg); DispatchMessageW(&msg); }
  ExitProcess(0);
}
