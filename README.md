# nifm3

横河電機の「[リアルタイムOSコントローラ（e-RT3）](https://www.yokogawa.co.jp/solutions/products-platforms/control-system/real-time-os-controller/)」での、入出力モジュールの制御を、NIFs[^nifs] という仕組みを使ってElixirから制御する方法をまとめてみました。

[^nifs]: [NIFs - Erlang](http://erlang.org/doc/tutorial/nif.html)

##Qiita記事

[e-RT3の入出力をElixirから制御](https://qiita.com/myasu/items/0dbf308947b878423112)

## 参考資料

- NIF入門
  - [NIFsの初歩的な使い方](https://qiita.com/sym_num/items/7c86c5dd298fd29f4ec3)
  - [Elixir で NIF を利用するサンプル](https://gist.github.com/mattsan/1d0fc1a02965f19aa53db0eb5cc5376b)
- m3ライブラリの使い方
  - [e-RT3 plusの新機能について](https://www.softech.co.jp/mm_161005_firm.htm)
  - [e-RT3 2.0を使った開発方法について](https://www.softech.co.jp/mm_100526_plc.htm)
  - [APIエラーコード一覧](README.errno.md)
  