/**
 * @file relayio.c
 * @author myasu
 * @brief API Drivers for Relay
 * @version 0.1
 * @date 2020-08-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <ert3/m3lib.h>
#include <errno.h>

#include "relayio.h"

/**
 * @brief 入力リレー読み出し共通処理
 * 
 * @param unit ユニット番号を指定（0～7）
 * @param slot スロット番号を指定（1～16）
 * @param pos 入力リレー番号を指定（1, 17, 33, 49 :2ブロック読み込み） / （1～64 :指定ビット読み込み）
 * @param num 読み出しブロック数を指定（2 :2ブロック読み込み）/ (0 :指定ビット読み込み)
 * @param data 読み出しデータ格納バッファ
 * @return int 
 */
int ReadInRelayCommon(int unit, int slot, int pos, int num, int *data)
{
    int result = -1;
    unsigned short dataarray[4];

    if (num == 2 && pos == 1)
    {
        //引数num=2とpos=1が指定されているときは、1～32まで2ブロック読み込み
        //（それ以外の組み合わせは、うまくいかないみたい）

        //API呼び出し
        result = readM3InRelay(unit, slot, pos, num, dataarray);

        //返り値に展開
        if (result == 0)
            //1-16は下位ビット、17-32は上位ビット
            *data = (dataarray[1] << 16) + dataarray[0];
    }
    else if (num == 0)
    {
        //引数numが指定されていないときは指定posだけをビット読み込み

        //API呼び出し
        result = readM3InRelayP(unit, slot, pos, dataarray);

        //返り値に展開
        if (result == 0)
            *data = dataarray[0];
    }
    else
    {
        //num=1のときは73242?　とかになって値がおかしい
        //num=3のときは err: [relayio.c/ReadInRelayCommon L59] errno -1 が出る
        //なので、0, 2以外は処理を飛ばしてエラーとする
    }

    //エラーメッセージ
    if (result != 0)
        result = errcommon((char *)__func__, __LINE__, result);

    //読み込み結果を返す
    return result;
}

/**
 * @brief 出力リレーブロック読み出し共通処理
 * 
 * @param unit ユニット番号を指定（0～7）
 * @param slot スロット番号を指定（1～16）
 * @param pos 出力リレー番号を指定（1, 17, 33, 49）
 * @param num 読み出しブロック数を指定（1～4）
 * @param data 読み出しデータ格納バッファ
 * @return int 
 */
unsigned int ReadOutRelayCommon(int unit, int slot, int pos, int num, unsigned int *data)
{
    int result = -1;
    unsigned short dataarray[4];

    if (num == 2 && pos == 1)
    {
        //API呼び出し
        result = readM3OutRelay(unit, slot, pos, num, dataarray);

        //debug
        //printf(" upper: %u  lower: %u \r\n", dataarray[1], dataarray[0]);

        //返り値に展開
        if (result == 0)
            //1-16は下位ビット、17-32は上位ビット
            *data = (dataarray[1] << 16) | dataarray[0];
    }
    else
    {
        //pos=1, num=2以外はエラーになる
        //なのでそれ以外は処理を飛ばしてエラーとする
    }

    //エラーメッセージ
    if (result != 0)
        result = errcommon((char *)__func__, __LINE__, result);

    //読み込み結果を返す
    return result;
}

/**
 * @brief 出力リレー書き込み
 * 
 * @param unit ユニット番号を指定（0～7）
 * @param slot スロット番号を指定（1～16）
 * @param pos 出力リレー番号を指定（1～64）
 * @param data 書き込みデータ
 * @return int 
 */
unsigned int WriteOutRelay1(int unit, int slot, int pos, unsigned short data)
{
    unsigned int result = -1;

    //API呼び出し
    result = writeM3OutRelayP(unit, slot, pos, data);

    if (result != 0)
        //エラーメッセージ
        result = errcommon((char *)__func__, __LINE__, result);
    else
        //返り値にスロット番号・ポジション・データを付加
        result = (slot * 1000 + pos * 10 + data);

    //書き込み結果を返す
    return result;
}

/**
 * @brief 出力リレーブロック書き込み
 * 
 * @param unit ユニット番号を指定（0～7）
 * @param slot スロット番号を指定（1～16）
 * @param pos 出力リレー番号を指定（1, 17, 33, 49）
 * @param data 書き込みデータ
 * @param mask 書き込みデータマスク
 * @return unsigned int 
 */
unsigned int WriteOutRelay(int unit, int slot, int pos, unsigned int data, unsigned int mask)
{
    unsigned int result = -1;
    unsigned short writedata[4];
    unsigned short writemask[4];

    //書き込みデータを配列に代入
    writedata[0] = 0xffff & data;
    writemask[0] = 0xffff & mask;
    writedata[1] = 0xffff & (data >> 16);
    writemask[1] = 0xffff & (mask >> 16);

    //debug
    //printf(" data: %u upper: %u  lower: %u \r\n", data, writedata[1], writedata[0]);

    //API呼び出し
    result = writeM3OutRelay(unit, slot, pos, 2, writedata, writemask);

    if (result != 0)
        //エラーメッセージ
        result = errcommon((char *)__func__, __LINE__, result);
    else
        //返り値に実際に書き込んだ値を付加
        result = (data & mask);

    //書き込み結果を返す
    return result;
}

/**
 * @brief エラーメッセージ共通処理
 * 
 * @param func 
 * @param line 
 * @return int 
 */
int errcommon(char *func, int line, int result)
{
    //メッセージ
    fprintf(stderr, " err: [%s/%s L%d] errno %d\r\n", __FILE__, func, line, result);
    //errnoを代入
    result = -1 * errno;

    return result;
}
