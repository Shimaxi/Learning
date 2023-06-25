# C++でゲームを作る

Visual StudioとDXライブラリを用いてゲームを制作する勉強をした際の備忘録です。

# 初期設定

以下のリンクを参考にして、Visual Studio 2019とDXライブラリをダウンロードし、初期設定を行ってください。
>https://dxlib.xsrv.jp/use/dxuse_vscom2019.html


# ゲーム作成の練習
以降は以下のサイトを参考に学んでいきます。
>https://dixq.net/g/index.html

# 1. ウィンドウの表示

まず最初はゲームの画面を表示してみましょう。全画面でキャンパスを表示し、何かしらの操作を受けると終了するプログラムを作ります。

```c
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    DxLib_Init();   // DXライブラリ初期化処理

    WaitKey();      // キー入力待ち
    DxLib_End();    // DXライブラリ終了処理
    return 0;
}
```

これを実行すると、画面が真っ暗になり(黒い画面が全画面で表示され)、何かしらのボタンが押されると画面が閉じます。


## #include "DxLib.h"
さっき設定した『DXライブラリ』というC言語でゲームを作成する際にとても便利なライブラリを導入します。

何も考えずにとりあえず書いといて大丈夫。

## int WINAPI WinMain(){}
最初はうわっとなると思いますが、その実C言語での"int main()"と同じ意味で、ここからプログラムを開始することを表現しています。

当然プログラムが正常に動作したことを示す"return 0"を忘れずに書きましょう。

## DxLib_Init();
DXライブラリの初期化処理です。DXライブラリの関数を使う際には必ず書く必要があり、
意味としては、ウィンドウの生成と初期化を行ってくれるものです。

## DxLib_End();
DXライブラリを終了させるコードです。

## (WaitKey();)
キー入力を受けるまで待機させるコードです。待機しないとすぐ終了しちゃうので入れてるだけです。


# 2, 全画面表示からウィンドウ表示へ
デバッグのたび全画面でゲーム画面が開かれるのは少し嫌なので、ウィンドウ表示してくれるように変更します。

```cpp
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE); //全画面表示ではなくウィンドウ表示にする
    SetGraphMode(1280, 720, 32); //ウィンドウサイズを1280×720に変更
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

画面の表示を変更してくれる関数です。TRUEがウィンドウモードで、FALSEが全画面モードです。


## SetGraphMode(1280, 720, 32);

ウィンドウのサイズ(ゲーム画面の解像度)を変更する関数です。多くのゲームでは1280×720が採用されているので、私もそれに従うこととします。

一般的なコンピュータでもそうですが、ゲームで使う長さの単位はpx(ピクセル)です。

この状態で"DxLib_Init();"が実行されると、ウィンドウモードの指定したサイズで表示されます。

# if (ProcessMessage() != 0)
ウィンドウの×ボタンを押したらしっかりとプログラムが終了するようにしてあげます。

while(1)はArduinoで見る"void loop"と同じ効果のあるもので、常に何かしらのコードを走らせておきたい時に使います。

今回はウィンドウの×ボタンを押したときに起こる"ProcessMessage() = 0"をいつでも検知できるように監視させています。


# 3. 画像の表示

画像を画面に表示してくれるプログラムを書きます。
用いる画像は『DOTOWN』というサイトからお借りしました。600ピクセル×600ピクセルのデータとなっております。
>https://dotown.maeda-design-room.net/

ダウンロードしたら、.cppファイルと同じディレクトリに『Images』フォルダを作り、そこに入れておきます。

```cpp
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE);
    SetGraphMode(1280, 720, 32);
    DxLib_Init();

    int Handle; //データハンドル格納用変数
    Handle = LoadGraph("Images/おばけ.png"); //Imgaesフォルダの中pngファイルを変数に格納
    DrawGraph(0, 0, Handle, TRUE); // 画像を描画する
    DrawExtendGraph(600, 50, 700, 150, Handle, TRUE); //画像を拡大縮小描画する

    WaitKey();
    DxLib_End(); 
    return 0;
}
```

## int Handle;
画像のデータの情報は『ハンドル』というところに格納されます。

まだハンドルというものの感覚が掴めてないので、理解出来たらしっかりまとめます。

## Handle = LoadGraph("Images/おばけ.png");
画像のデータをハンドルに格納します。

これは何のために行うのかというと、データをディスクから毎回毎回持ってくると時間がかかってしまうので、
メモリ上に一旦持ってくることで処理を軽くしています。


## DrawGraph(0, 0, Handle, TRUE);
メモリ上にある画像を表示する関数です。
引数のうち、最初の2つのint型は、画面の左上端を(0,0)原点としたx座標とy座標の位置を指定してます。(y軸は下が正方向であることに注意！)
そして、その位置が画像の左上端となるように画像を表示します。
最後の『TRUE』は画像の透過処理を行うかどうかを指定するもので、ないと透過画像であっても透過しないで表示します。

## DrawExtendGraph(600, 50, 700, 150, Handle, TRUE);
画像をそのままの大きさで表示すると大きすぎたり小さすぎたりすることがあります。その際はこの関数で拡大縮小をして表示しましょう。

引数の1つ目と2つ目は上と同じで、画像の始点を表し、3つ目と4つ目は画像の終点(右下端)を表します。

誤って設定すると縦横比がおかしくなるので、気を付けましょう。

##   
画像表示に関するその他の関数は以下のページを参考にしてください。
>https://dxlib.xsrv.jp/function/dxfunc_graph1.html#R3N9

# 4. キー入力を受けつける
キー入力を受けつける関数について学びましょう。

```cpp
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE);
    SetGraphMode(1280, 720, 32);
    DxLib_Init();

    int Handle;
    Handle = LoadGraph("Images/おばけ.png");

    while (1) {
        if (CheckHitKey(KEY_INPUT_A) == 1) {
            DrawGraph(0, 0, Handle, TRUE); // キーボードで『A』が押されたときに画像を描画する
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
キーが押されたどうかを判定する際には"CheckHitKey"関数を使います。使い方は非常に安直で、
"KEY_INPUT_○○ == 1"(○○にキーの名前)と書くだけです。

キーの種類は以下を参考にしてください。
>https://dxlib.xsrv.jp/function/dxfunc_input.html#R5N2

# 5. 方向キーによって画像を動かす

```cpp
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE);
    SetGraphMode(1280, 720, 32);
    DxLib_Init();

    int x = 0; //画像の初期x座標を設定
    int Handle;
    Handle = LoadGraph("Images/おばけ.png");

    while (1) {
        if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
            x += 2; //xを2増やす
        }
        DrawGraph(x, 0, Handle, TRUE); // キーボードで『→』が押されたときに画像を左に2ピクセルズラして表示する
        Sleep(10); //入力に猶予を与える
        if (ProcessMessage() != 0) {
            break;
        }
    }
    DxLib_End();
    return 0;
}
```

## int x = 0; x += 2;

方向キーに応じて画像を動かす、今回はキーボードで『→』を押すと画像が右に動くようにします。

そうなることを期待して、画像の表示位置を右にずらしていくコードを書いてみました。

しかし、上のコードを実行すると、画像が右にどんどん重なって表示されてしまいます。

そりゃそうか、以前の画像を残したまま新しい画像を表示しているので、
どんどん積み重なってしまいます。

## 裏画面処理

そうなってしまわないよう、裏画面処理というものを行います。

裏画面処理とはその名の通り、裏画面に画像を描画し、1フレーム分の画が出来たら表画面に表示する。
という手法です。

```cpp
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE);
    SetGraphMode(1280, 720, 32);
    DxLib_Init();
    SetDrawScreen(DX_SCREEN_BACK); //描画先を裏画面に設定

    int x = 0;
    int Handle;
    Handle = LoadGraph("Images/おばけ.png");

    while (1) {
        if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
            x += 2; 
        }
        ClearDrawScreen(); // 画面を消す
        DrawGraph(x, 0, Handle, TRUE); 
        ScreenFlip(); //裏画面を表画面に反映
        if (ProcessMessage() != 0) {
            break;
        }
    }
    DxLib_End();
    return 0;
}
```

# SetDrawScreen(DX_SCREEN_BACK);
裏画面処理をやるよーという宣言です。これはプログラム全体に影響します。

# ClearDrawScreen();　ScreenFlip(); 
これらで画像の描画を挟んであげることで、『表画面消す』→『裏画面に描画する』→『表画面に反映する』、
というプロセスが行われるため、改善されます。

また、この際は先ほどあったsleep関数は不要です。

というのも、この画像表示の処理は画面のフレームレートに依存しており、60fpsのパソコンを使う場合、1/60秒待機してくれるからです。

# 6.ここまでのまとめ
今まで出てきたコードを短くまとめるとこのようになります。
```cpp
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE), SetGraphMode(1280, 720, 32), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

    int x = 0;
    int Handle;
    Handle = LoadGraph("Images/おばけ.png");

    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

        if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
            x += 2;
        }
        DrawGraph(x, 0, Handle, TRUE);

    }

    DxLib_End(); // DXライブラリ終了処理
    return 0;
}
```
最初の宣言などをまとめて行うのは勿論、1フレームごとの描画の指示もここまで短くかけます。

ScreenFlipもClearDrawScreenも1フレームごとに1を返すようになっており、それらをwhileの条件式に入れることで、whileの中身を
『1フレーム中の処理』を書くだけにしてくれてます。

あとProcessMessage()もあるので、ちゃんとウィンドウ消したらプログラムは終了できるようになってるしね。

では最後にキーボードを上下右左に合わせて画像が動くプログラムを作成します。
右を押したら動くプログラムを書いていたので、それを四方向分書いたら良いだけですね。

```cpp
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

    DxLib_End();
    return 0;
}
```

y軸が下向き正方向であることに気を付ければ大丈夫でしょう。
以上です、お疲れ様でした。

思ったよりDXライブラリが優秀でUnityとかと同じ感覚でゲームが作れそうですね。

# ちょっと待って！
ここまでやって気づいたけど、C++で作ったゲームってブラウザにあげて手軽に遊んでもらう手段ないの？？？

Unityみたいに簡単にWeb上にアップロード出来るような物があると思ってた...

WebGL？WebAssembly？emscripten？ウゴゴゴゴ.......

今時素人が作ったゲームで落とす必要のあるやつなんてよっぽどじゃない限り遊んでもらえないし、このまま一人壁打ちで作り続けるのも厳しそうだが、さてどうするか。

やはりUnity・・・？
でもC++の勉強もしたいしうーーん。
