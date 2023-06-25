#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE), SetGraphMode(1280, 720, 32), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

    int x,y;
    x = y = 0;
    int Handle;
    Handle = LoadGraph("Images/おばけ.png");

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

        if (CheckHitKey(KEY_INPUT_UP) == 1) {
            y -= 2;
        }
        if (CheckHitKey(KEY_INPUT_DOWN) == 1) {
            y += 2;
        }
        if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
            x += 2;
        }
        if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
            x -= 2;
        }
        DrawGraph(x, y, Handle, TRUE);
    }

    DxLib_End(); // DXライブラリ終了処理
    return 0;
}