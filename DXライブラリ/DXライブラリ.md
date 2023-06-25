# C++�ŃQ�[�������

Visual Studio��DX���C�u������p���ăQ�[���𐧍삷��׋��������ۂ̔��Y�^�ł��B

# �����ݒ�

�ȉ��̃����N���Q�l�ɂ��āAVisual Studio 2019��DX���C�u�������_�E�����[�h���A�����ݒ���s���Ă��������B
>https://dxlib.xsrv.jp/use/dxuse_vscom2019.html


# �Q�[���쐬�̗��K
�ȍ~�͈ȉ��̃T�C�g���Q�l�Ɋw��ł����܂��B
>https://dixq.net/g/index.html

# 1. �E�B���h�E�̕\��

�܂��ŏ��̓Q�[���̉�ʂ�\�����Ă݂܂��傤�B�S��ʂŃL�����p�X��\�����A��������̑�����󂯂�ƏI������v���O���������܂��B

```c
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    DxLib_Init();   // DX���C�u��������������

    WaitKey();      // �L�[���͑҂�
    DxLib_End();    // DX���C�u�����I������
    return 0;
}
```

��������s����ƁA��ʂ��^���ÂɂȂ�(������ʂ��S��ʂŕ\������)�A��������̃{�^�����������Ɖ�ʂ����܂��B


## #include "DxLib.h"
�������ݒ肵���wDX���C�u�����x�Ƃ���C����ŃQ�[�����쐬����ۂɂƂĂ��֗��ȃ��C�u�����𓱓����܂��B

�����l�����ɂƂ肠���������Ƃ��đ��v�B

## int WINAPI WinMain(){}
�ŏ��͂�����ƂȂ�Ǝv���܂����A���̎�C����ł�"int main()"�Ɠ����Ӗ��ŁA��������v���O�������J�n���邱�Ƃ�\�����Ă��܂��B

���R�v���O����������ɓ��삵�����Ƃ�����"return 0"��Y�ꂸ�ɏ����܂��傤�B

## DxLib_Init();
DX���C�u�����̏����������ł��BDX���C�u�����̊֐����g���ۂɂ͕K�������K�v������A
�Ӗ��Ƃ��ẮA�E�B���h�E�̐����Ə��������s���Ă������̂ł��B

## DxLib_End();
DX���C�u�������I��������R�[�h�ł��B

## (WaitKey();)
�L�[���͂��󂯂�܂őҋ@������R�[�h�ł��B�ҋ@���Ȃ��Ƃ����I�������Ⴄ�̂œ���Ă邾���ł��B


# 2, �S��ʕ\������E�B���h�E�\����
�f�o�b�O�̂��ёS��ʂŃQ�[����ʂ��J�����̂͏������Ȃ̂ŁA�E�B���h�E�\�����Ă����悤�ɕύX���܂��B

```cpp
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE); //�S��ʕ\���ł͂Ȃ��E�B���h�E�\���ɂ���
    SetGraphMode(1280, 720, 32); //�E�B���h�E�T�C�Y��1280�~720�ɕύX
    DxLib_Init();

    while (1) {
        if (ProcessMessage() != 0) {
        break;
        }
    }
    DxLib_End();
    return 0;
}
```

## ChangeWindowMode(TRUE);

��ʂ̕\����ύX���Ă����֐��ł��BTRUE���E�B���h�E���[�h�ŁAFALSE���S��ʃ��[�h�ł��B


## SetGraphMode(1280, 720, 32);

�E�B���h�E�̃T�C�Y(�Q�[����ʂ̉𑜓x)��ύX����֐��ł��B�����̃Q�[���ł�1280�~720���̗p����Ă���̂ŁA��������ɏ]�����ƂƂ��܂��B

��ʓI�ȃR���s���[�^�ł������ł����A�Q�[���Ŏg�������̒P�ʂ�px(�s�N�Z��)�ł��B

���̏�Ԃ�"DxLib_Init();"�����s�����ƁA�E�B���h�E���[�h�̎w�肵���T�C�Y�ŕ\������܂��B

# if (ProcessMessage() != 0)
�E�B���h�E�́~�{�^�����������炵������ƃv���O�������I������悤�ɂ��Ă����܂��B

while(1)��Arduino�Ō���"void loop"�Ɠ������ʂ̂�����̂ŁA��ɉ�������̃R�[�h�𑖂点�Ă����������Ɏg���܂��B

����̓E�B���h�E�́~�{�^�����������Ƃ��ɋN����"ProcessMessage() = 0"�����ł����m�ł���悤�ɊĎ������Ă��܂��B


# 3. �摜�̕\��

�摜����ʂɕ\�����Ă����v���O�����������܂��B
�p����摜�́wDOTOWN�x�Ƃ����T�C�g���炨�؂肵�܂����B600�s�N�Z���~600�s�N�Z���̃f�[�^�ƂȂ��Ă���܂��B
>https://dotown.maeda-design-room.net/

�_�E�����[�h������A.cpp�t�@�C���Ɠ����f�B���N�g���ɁwImages�x�t�H���_�����A�����ɓ���Ă����܂��B

```cpp
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE);
    SetGraphMode(1280, 720, 32);
    DxLib_Init();

    int Handle; //�f�[�^�n���h���i�[�p�ϐ�
    Handle = LoadGraph("Images/���΂�.png"); //Imgaes�t�H���_�̒�png�t�@�C����ϐ��Ɋi�[
    DrawGraph(0, 0, Handle, TRUE); // �摜��`�悷��
    DrawExtendGraph(600, 50, 700, 150, Handle, TRUE); //�摜���g��k���`�悷��

    WaitKey();
    DxLib_End(); 
    return 0;
}
```

## int Handle;
�摜�̃f�[�^�̏��́w�n���h���x�Ƃ����Ƃ���Ɋi�[����܂��B

�܂��n���h���Ƃ������̂̊��o���͂߂ĂȂ��̂ŁA�����o�����炵������܂Ƃ߂܂��B

## Handle = LoadGraph("Images/���΂�.png");
�摜�̃f�[�^���n���h���Ɋi�[���܂��B

����͉��̂��߂ɍs���̂��Ƃ����ƁA�f�[�^���f�B�X�N���疈�񖈉񎝂��Ă���Ǝ��Ԃ��������Ă��܂��̂ŁA
��������Ɉ�U�����Ă��邱�Ƃŏ������y�����Ă��܂��B


## DrawGraph(0, 0, Handle, TRUE);
��������ɂ���摜��\������֐��ł��B
�����̂����A�ŏ���2��int�^�́A��ʂ̍���[��(0,0)���_�Ƃ���x���W��y���W�̈ʒu���w�肵�Ă܂��B(y���͉����������ł��邱�Ƃɒ��ӁI)
�����āA���̈ʒu���摜�̍���[�ƂȂ�悤�ɉ摜��\�����܂��B
�Ō�́wTRUE�x�͉摜�̓��ߏ������s�����ǂ������w�肷����̂ŁA�Ȃ��Ɠ��߉摜�ł����Ă����߂��Ȃ��ŕ\�����܂��B

## DrawExtendGraph(600, 50, 700, 150, Handle, TRUE);
�摜�����̂܂܂̑傫���ŕ\������Ƒ傫�������菬���������肷�邱�Ƃ�����܂��B���̍ۂ͂��̊֐��Ŋg��k�������ĕ\�����܂��傤�B

������1�ڂ�2�ڂ͏�Ɠ����ŁA�摜�̎n�_��\���A3�ڂ�4�ڂ͉摜�̏I�_(�E���[)��\���܂��B

����Đݒ肷��Əc���䂪���������Ȃ�̂ŁA�C��t���܂��傤�B

##   
�摜�\���Ɋւ��邻�̑��̊֐��͈ȉ��̃y�[�W���Q�l�ɂ��Ă��������B
>https://dxlib.xsrv.jp/function/dxfunc_graph1.html#R3N9

# 4. �L�[���͂��󂯂���
�L�[���͂��󂯂���֐��ɂ��Ċw�т܂��傤�B

```cpp
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE);
    SetGraphMode(1280, 720, 32);
    DxLib_Init();

    int Handle;
    Handle = LoadGraph("Images/���΂�.png");

    while (1) {
        if (CheckHitKey(KEY_INPUT_A) == 1) {
            DrawGraph(0, 0, Handle, TRUE); // �L�[�{�[�h�ŁwA�x�������ꂽ�Ƃ��ɉ摜��`�悷��
            break;
        }
        if (ProcessMessage() != 0) {
            break;
        }
    }

    DxLib_End();
    return 0;
}
```

## (CheckHitKey(KEY_INPUT_A) == 1)
�L�[�������ꂽ�ǂ����𔻒肷��ۂɂ�"CheckHitKey"�֐����g���܂��B�g�����͔��Ɉ����ŁA
"KEY_INPUT_���� == 1"(�����ɃL�[�̖��O)�Ə��������ł��B

�L�[�̎�ނ͈ȉ����Q�l�ɂ��Ă��������B
>https://dxlib.xsrv.jp/function/dxfunc_input.html#R5N2

# 5. �����L�[�ɂ���ĉ摜�𓮂���

```cpp
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE);
    SetGraphMode(1280, 720, 32);
    DxLib_Init();

    int x = 0; //�摜�̏���x���W��ݒ�
    int Handle;
    Handle = LoadGraph("Images/���΂�.png");

    while (1) {
        if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
            x += 2; //x��2���₷
        }
        DrawGraph(x, 0, Handle, TRUE); // �L�[�{�[�h�Łw���x�������ꂽ�Ƃ��ɉ摜������2�s�N�Z���Y�����ĕ\������
        Sleep(10); //���͂ɗP�\��^����
        if (ProcessMessage() != 0) {
            break;
        }
    }
    DxLib_End();
    return 0;
}
```

## int x = 0; x += 2;

�����L�[�ɉ����ĉ摜�𓮂����A����̓L�[�{�[�h�Łw���x�������Ɖ摜���E�ɓ����悤�ɂ��܂��B

�����Ȃ邱�Ƃ����҂��āA�摜�̕\���ʒu���E�ɂ��炵�Ă����R�[�h�������Ă݂܂����B

�������A��̃R�[�h�����s����ƁA�摜���E�ɂǂ�ǂ�d�Ȃ��ĕ\������Ă��܂��܂��B

����Ⴛ�����A�ȑO�̉摜���c�����܂ܐV�����摜��\�����Ă���̂ŁA
�ǂ�ǂ�ςݏd�Ȃ��Ă��܂��܂��B

## ����ʏ���

�����Ȃ��Ă��܂�Ȃ��悤�A����ʏ����Ƃ������̂��s���܂��B

����ʏ����Ƃ͂��̖��̒ʂ�A����ʂɉ摜��`�悵�A1�t���[�����̉悪�o������\��ʂɕ\������B
�Ƃ�����@�ł��B

```cpp
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE);
    SetGraphMode(1280, 720, 32);
    DxLib_Init();
    SetDrawScreen(DX_SCREEN_BACK); //�`���𗠉�ʂɐݒ�

    int x = 0;
    int Handle;
    Handle = LoadGraph("Images/���΂�.png");

    while (1) {
        if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
            x += 2; 
        }
        ClearDrawScreen(); // ��ʂ�����
        DrawGraph(x, 0, Handle, TRUE); 
        ScreenFlip(); //����ʂ�\��ʂɔ��f
        if (ProcessMessage() != 0) {
            break;
        }
    }
    DxLib_End();
    return 0;
}
```

# SetDrawScreen(DX_SCREEN_BACK);
����ʏ���������[�Ƃ����錾�ł��B����̓v���O�����S�̂ɉe�����܂��B

# ClearDrawScreen();�@ScreenFlip(); 
�����ŉ摜�̕`�������ł����邱�ƂŁA�w�\��ʏ����x���w����ʂɕ`�悷��x���w�\��ʂɔ��f����x�A
�Ƃ����v���Z�X���s���邽�߁A���P����܂��B

�܂��A���̍ۂ͐�قǂ�����sleep�֐��͕s�v�ł��B

�Ƃ����̂��A���̉摜�\���̏����͉�ʂ̃t���[�����[�g�Ɉˑ����Ă���A60fps�̃p�\�R�����g���ꍇ�A1/60�b�ҋ@���Ă���邩��ł��B

# 6.�����܂ł̂܂Ƃ�
���܂ŏo�Ă����R�[�h��Z���܂Ƃ߂�Ƃ��̂悤�ɂȂ�܂��B
```cpp
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE), SetGraphMode(1280, 720, 32), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

    int x = 0;
    int Handle;
    Handle = LoadGraph("Images/���΂�.png");

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

        if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
            x += 2;
        }
        DrawGraph(x, 0, Handle, TRUE);

    }

    DxLib_End(); // DX���C�u�����I������
    return 0;
}
```
�ŏ��̐錾�Ȃǂ��܂Ƃ߂čs���͖̂ܘ_�A1�t���[�����Ƃ̕`��̎w���������܂ŒZ�������܂��B

ScreenFlip��ClearDrawScreen��1�t���[�����Ƃ�1��Ԃ��悤�ɂȂ��Ă���A������while�̏������ɓ���邱�ƂŁAwhile�̒��g��
�w1�t���[�����̏����x�����������ɂ��Ă���Ă܂��B

����ProcessMessage()������̂ŁA�����ƃE�B���h�E��������v���O�����͏I���ł���悤�ɂȂ��Ă邵�ˁB

�ł͍Ō�ɃL�[�{�[�h���㉺�E���ɍ��킹�ĉ摜�������v���O�������쐬���܂��B
�E���������瓮���v���O�����������Ă����̂ŁA������l��������������ǂ������ł��ˁB

```cpp
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE), SetGraphMode(1280, 720, 32), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

    int x,y;
    x = y = 0;
    int Handle;
    Handle = LoadGraph("Images/���΂�.png");

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

    DxLib_End();
    return 0;
}
```

y�����������������ł��邱�ƂɋC��t����Α��v�ł��傤�B
�ȏ�ł��A�����l�ł����B

�v�������DX���C�u�������D�G��Unity�Ƃ��Ɠ������o�ŃQ�[������ꂻ���ł��ˁB

# ������Ƒ҂��āI
�����܂ł���ċC�Â������ǁAC++�ō�����Q�[�����ău���E�U�ɂ����Ď�y�ɗV��ł��炤��i�Ȃ��́H�H�H

Unity�݂����ɊȒP��Web��ɃA�b�v���[�h�o����悤�ȕ�������Ǝv���Ă�...

WebGL�HWebAssembly�Hemscripten�H�E�S�S�S�S.......

�����f�l��������Q�[���ŗ��Ƃ��K�v�̂����Ȃ�Ă���ۂǂ���Ȃ�����V��ł��炦�Ȃ����A���̂܂܈�l�Ǒł��ō�葱����̂��������������A���Ăǂ����邩�B

��͂�Unity�E�E�E�H
�ł�C++�̕׋��������������[�[��B
