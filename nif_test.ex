defmodule NifTest do
  @moduledoc """
  Documentation for `NifTest`.
  Elixirからのm3ライブラリへのアクセスサンプル
  """
  @on_load :init

  @doc """
  init
  初期化
  """
  def init do
    #nifのロード
    :erlang.load_nif("./nifm3", 0)
  end

  @doc """
  readinrelay
  入力リレー読み出し（2ブロック=32ビット単位）
  ## Parameter
    - 1:ユニット番号を指定（0～7）
    - 2:入力リレーを設置のスロット番号を指定（1～16）
    - 3:入力リレー番号を指定（1）
    - 4:読み出しブロック数を指定（2 :2ブロック読み込み）
  ## Examples
      iex> NifTest.readinrelay(0,3,1,2)   #入力リレーを32bit分読み出し
  """
  def readinrelay(_, _, _, _) do
    "readinrelay/4 : NIF library not loaded"
  end

  @doc """
  readinrelay
  入力リレー読み出し（1ビット単位）
  ## Parameter
    - 1:ユニット番号を指定（0～7）
    - 2:入力リレーを設置のスロット番号を指定（1～16）
    - 3:入力リレー番号を指定（1～32）
  ## Examples
      iex> NifTest.readinrelay(0,3,1)   #入力リレー1だけ読み出し
      iex> NifTest.readinrelay(0,3,32)  #入力リレー32だけ読み出し
  """
  def readinrelay(_, _, _) do
    "readinrelayp/3 : NIF library not loaded"
  end

  @doc """
  readoutrelay
  出力リレー読み出し（2ブロック=32ビット単位）
  ## Parameter
    - 1:ユニット番号を指定（0～7）
    - 2:出力リレーを設置のスロット番号を指定（1～16）
    - 3:出力リレー番号を指定（1）
    - 4:読み出しブロック数を指定（2 :2ブロック読み込み）
  ## Examples
      iex> NifTest.readoutrelay(0,2,1,2)   #出力リレーを32bit分読み出し
  """
  def readoutrelay(_, _, _, _) do
    "readoutrelay/4 : NIF library not loaded"
  end

  @doc """
  writeoutrelay
  出力リレー書き込み（2ブロック=32ビット単位）
  ## Parameter
    - 1:ユニット番号を指定（0～7）
    - 2:出力リレーを設置のスロット番号を指定（1～16）
    - 3:入力リレー番号を指定（1）
    - 4:書き込みデータ（1: 32bit）
    - 4:書き込みデータマスク（1: 32bit）
  ## Examples
      iex> NifTest.writeoutrelay(0,2,1,0x00000001,0xffffffff)   #出力リレー1だけON
      iex> NifTest.writeoutrelay(0,2,1,0xfffffffe,0xffffffff)   #出力リレー2～32をON、1をOFF
      iex> NifTest.writeoutrelay(0,2,1,0x00000000,0xffffffff)   #出力リレーを全てOFF
      iex> NifTest.writeoutrelay(0,2,1,0xffffffff,0x0000000f)   #出力リレー1～4だけON（マスクのとこだけ操作）
  """
  def writeoutrelay(_, _, _, _, _) do
    "writeoutrelay/5 : NIF library not loaded"
  end

  @doc """
  writeoutrelay
  出力リレー書き込み（1ビット単位）
  ## Parameter
    - 1:ユニット番号を指定（0～7）
    - 2:出力リレーを設置のスロット番号を指定（1～16）
    - 3:出力リレー番号を指定（1～32）
    - 4:書き込みデータ（0 / 1）
  ## Examples
      iex> NifTest.writeoutrelay(0,2,1,1)   #出力リレー1だけON
      iex> NifTest.writeoutrelay(0,2,10,0)  #出力リレー10だけOFF
  """
  def writeoutrelay(_, _, _, _) do
    "writeoutrelay/4 : NIF library not loaded"
  end

end
