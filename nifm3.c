/**
 * @file nifm3.c
 * @author myasu
 * @brief nif for e-RT3 API
 * @version 0.1
 * @date 2020-08-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <erl_nif.h>

#include "relayio.h"

/**
 * @brief 入力リレーブロック読み出し
 * I/O モジュールの入力リレーを16 点単位で読み出します。
 * 引数 unitおよびslotで指定されたI/Oモジュールの入力リレーを
 * posで指定されたデバイス番号からnum個のデータブロックを読み出します。
 * pos は1, 17, 33, 49 の値を指定しなければいけません。
 * 範囲内のこれ以外の値は指定値よりも小さい値に丸められます
 * （例えば24 ならば17 になる）。
 * 読み出したデータはdata[]の先頭からnumブロック分格納され，
 * 16 点分の接点状態がLSB から入力リレー番号順に格納されます。
 * @param env nif指定の引数
 * @param argc nif指定の引数
 * @param argv nif指定の引数
 * @return ERL_NIF_TERM 
 */
static ERL_NIF_TERM _readM3InRelay(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    int unit, slot, pos, num, data;
    unsigned int ret = -1;

    //引数を取り出し
    enif_get_int(env, argv[0], &unit);
    enif_get_int(env, argv[1], &slot);
    enif_get_int(env, argv[2], &pos);
    enif_get_int(env, argv[3], &num);

    //処理
    ret = ReadInRelayCommon(unit, slot, pos, num, &data);
    //実行結果に合わせて処理
    if (ret == 0)
        //正常なら、得た値を代入
        ret = data;

    //読み込み結果を返す
    //エラー時は負の値
    return enif_make_uint(env, ret);
}

/**
 * @brief 入力リレー読み出し
 * I/O モジュールの入力リレーを1点単位で読み出します。
 * 引数 unit およびslot で指定されたI/O モジュールの
 * pos で指定した入力リレー番号を1 点だけ読み出します。
 * 入力リレーがON の場合は1，OFF の場合は0 がdata に格納されます。
 * @param env nif指定の引数
 * @param argc nif指定の引数
 * @param argv nif指定の引数
 * @return ERL_NIF_TERM 
 */
static ERL_NIF_TERM _readM3InRelayP(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    int unit, slot, pos, data;
    unsigned int ret = -1;

    //引数を取り出し
    enif_get_int(env, argv[0], &unit);
    enif_get_int(env, argv[1], &slot);
    enif_get_int(env, argv[2], &pos);

    //処理
    ret = ReadInRelayCommon(unit, slot, pos, 0, &data);
    if (ret == 0)
        //正常なら、得た値を代入
        ret = data;

    //読み込み結果を返す
    //エラー時は負の値
    return enif_make_uint(env, ret);
}

/**
 * @brief 出力リレーブロック読み出し
 * I/O モジュールの出力リレーを16 点単位で読み出します。
 * 引数 unit およびslot で指定されたI/O モジュールの出力リレーを
 * pos で指定されたデバイス番号からnum 個のデータブロックを読み出します。
 * pos は1, 17, 33, 49 の値を指定しなければいけません。
 * 範囲内のこれ以外の値は指定値よりも小さい値に丸められます（例えば24 ならば17 になる）。
 * 読み出したデータはdata[]の先頭からnumブロック分格納され，
 * 16 点分の接点状態がLSB から入力リレー番号順に格納されます。
 * @param env nif指定の引数
 * @param argc nif指定の引数
 * @param argv nif指定の引数
 * @return ERL_NIF_TERM 
 */
static ERL_NIF_TERM _readM3OutRelay(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    int unit, slot, pos, num;
    unsigned int data, ret = -1;

    //引数を取り出し
    enif_get_int(env, argv[0], &unit);
    enif_get_int(env, argv[1], &slot);
    enif_get_int(env, argv[2], &pos);
    enif_get_int(env, argv[3], &num);

    //処理
    ret = ReadOutRelayCommon(unit, slot, pos, num, &data);
    //実行結果に合わせて処理
    if (ret == 0)
        //正常なら、得た値を代入
        ret = data;

    //読み込み結果を返す
    //エラー時は負の値
    return enif_make_uint(env, ret);
}

/**
 * @brief 出力リレーブロック書き込み
 * @param env nif指定の引数
 * @param argc nif指定の引数
 * @param argv nif指定の引数
 * @return ERL_NIF_TERM 
 */
static ERL_NIF_TERM _writeM3OutRelay(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    int unit, slot, pos;
    unsigned int data, mask;
    unsigned int ret = -1;

    //引数を取り出し
    enif_get_int(env, argv[0], &unit);
    enif_get_int(env, argv[1], &slot);
    enif_get_int(env, argv[2], &pos);
    enif_get_uint(env, argv[3], &data);
    enif_get_uint(env, argv[4], &mask);

    //処理
    ret = WriteOutRelay(unit, slot, pos, data, mask);
    //実行結果に合わせて処理
    if (ret == 0)
        //正常なら、書き込んだ値を代入
        ret = (data & mask);

    //読み込み結果を返す
    //エラー時は負の値
    return enif_make_uint(env, ret);
}

/**
 * @brief 出力リレー書き込み
 * @param env nif指定の引数
 * @param argc nif指定の引数
 * @param argv nif指定の引数
 * @return ERL_NIF_TERM 
 */
static ERL_NIF_TERM _writeM3OutRelayP(ErlNifEnv *env, int argc, const ERL_NIF_TERM argv[])
{
    int unit, slot, pos, data;
    int ret = -1;

    //引数を取り出し
    enif_get_int(env, argv[0], &unit);
    enif_get_int(env, argv[1], &slot);
    enif_get_int(env, argv[2], &pos);
    enif_get_int(env, argv[3], &data);

    //処理
    ret = WriteOutRelay1(unit, slot, pos, data);
    if (ret == 0)
        //正常なら、得た値を代入
        ret = data;

    //読み込み結果を返す
    //エラー時は負の値
    return enif_make_uint(env, ret);
}

/**
 * @brief define the array of ErlNifFunc beforehand
 * 
 */
static ErlNifFunc nif_funcs[] =
    {
        // {erl_function_name, erl_function_arity, c_function}
        {"readinrelay", 4, _readM3InRelay},
        {"readinrelay", 3, _readM3InRelayP},
        {"readoutrelay", 4, _readM3OutRelay},
        {"writeoutrelay", 5, _writeM3OutRelay},
        {"writeoutrelay", 4, _writeM3OutRelayP},
};

ERL_NIF_INIT(Elixir.NifTest, nif_funcs, NULL, NULL, NULL, NULL)
