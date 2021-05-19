#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>

int w, h;

void fillCanvas (int h, int w, int c[h][w], int v) {
    for(int j = 0; j < h; j++)
        for(int i = 0; i < w; i++)
            c[j][i] = v;
}

void clearCanvas (int w, int h, wchar_t c[w][h]) {
    fillCanvas(w, h, c, ' ');
}

void showCanvas (int h, int w, int c[h][w]) {
    for(int j = 0; j < h; j++)
        for(int i = 0; i < w; i++)
            wprintf(L"%lc", c[j][i]);
}

void fillBox (int x0, int y0, int x1, int y1, int bg, int c[h][w]) {
    for(int j = y0; j < y1; j++)
        for(int i = x0; i < x1; i++)
            c[j][i] = bg;
}

void drawBox (int x0, int y0, int x1, int y1, int c[h][w], int bh, int bv,
                int ca, int cb, int cc, int cd) {
    for(int i = x0; i < x1; i++) c[y0][i] = bh;
    for(int i = x0; i < x1; i++) c[y1][i] = bh;
    for(int j = y0; j < y1; j++) c[j][x0] = bv;
    for(int j = y0; j < y1; j++) c[j][x1] = bv;
    c[y0][x0] = ca;
    c[y0][x1] = cb;
    c[y1][x0] = cc;
    c[y1][x1] = cd;
}

void drawBoxDouble (int x0, int y0, int x1, int y1, int c[h][w] ) {
    drawBox(x0, y0, x1, y1, c, 0x2550, 0x2551, 0x2554, 0x2557, 0x255A, 0x255D);
}

void drawBoxSimple (int x0, int y0, int x1, int y1, int c[h][w] ) {
    drawBox(x0, y0, x1, y1, c, 0x2500, 0x2502, 0x250C, 0x2510, 0x2514, 0x2518);
}

void drawText(int x0, int y0, int x1, int y1, int c[h][w], char s[]) {
    int i = x0;
    while(*s != '\0') {
        if(*s == '\n') y0++, i = x0-1;
        else c[y0][i] = *s;
        s++;
        i++;
        if(i == w || i > x1) y0++, i = x0;
        if(y0 == h || y0 > y1) break;
    }
}

int main() {
    setlocale(LC_CTYPE, "");
    struct winsize win;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    w = win.ws_col;
    h = win.ws_row-1;
    int canvas[h][w];
    clearCanvas(w, h, canvas);
    fillCanvas(h, w, canvas, 0x2591);
    drawBoxDouble(0, 0, w-1, h-1, canvas);
    char btnClose[] = "[-][O][X]";
    drawText( w-12, 0, w, 0, canvas, btnClose);
    char title[] = "Sample of drawing a window";
    drawText(2, 2, w, 2, canvas, title);
    fillBox(2, 4, w - (w/2) -1, h-2, 0x2593, canvas);
    fillBox(w - (w/2) , 4, w-2, h-2, 0x2592, canvas);
    drawBoxSimple(4, 6, w - (w/2) -5, h-5, canvas);
    char msg[] = "Alice: \nQuanto tempo dura o eterno?\n\nCoelho: \nAs vezes apenas um segundo.";
    drawText(6, 8, w - (w/2) -6, h-6, canvas, msg);
    char text[] = "\"Meu Deus, meu Deus! Como tudo eh esquisito hoje! E ontem tudo era exatamente como de costume. Serah que fui eu que mudei ah noite? Deixe-me pensar: eu era a mesma quando me levantei hoje de manha? Estou quase achando que posso me lembrar de me sentir um pouco diferente. Mas se eu nao sou a mesma, a proxima pergunta eh: \'Quem eh que eu sou?\'. Ah, essa  eh a grande charada!\"";
    drawText(w - (w/2) + 2 , 6, w-5, h-2, canvas, text);
    showCanvas(h, w, canvas);
    return 0;
}