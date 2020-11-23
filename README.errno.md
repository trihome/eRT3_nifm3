# APIエラーコード一覧

|マクロ名|エラーコード|説明|
|:--|:--|:--|
| S_m3io_MODULE_NOT_FOUND | 257 | モジュールが存在しないスロットが指定された |
| S_m3io_INVALID_UNIT | 258 | ユニット番号に範囲外の値が指定された |
| S_m3io_INVALID_SLOT | 259 | スロット番号に範囲外の値が指定された |
| S_m3io_INVALID_NUMBER | 260 | パラメータに範囲外の値が指定された |
| S_m3io_INVALID_FUNC | 261 | 想定外のIOCTL | コードが指定された |
| S_m3io_INVALID_MODULE | 262 | 未サポートのIOCTL | コードが指定された |
| S_m3io_DMA_ERROR | 263 | DMA | 通信が失敗した |
| S_m3io_BUS_ERROR_NR | 264 | I/O | バス異常 |
| S_m3io_BUS_ERROR_BR | 265 | I/O | バス異常 |
| S_m3io_BUS_ERROR_RDP | 266 | I/O | バス異常 |
| S_m3io_BUS_ERROR_MF | 267 | I/O | バス異常 |
| S_m3io_BUS_ERROR_DT | 268 | I/O | バス異常 |
| S_m3io_INTERNAL_ERROR | 357 | 内部エラー |
| S_m3cpu_MODULE_NOT_FOUND | 157 | モジュールが存在しないスロットが指定された |
| S_m3cpu_INVALID_UNIT | 158 | ユニット番号に範囲外の値が指定された |
| S_m3cpu_INVALID_SLOT | 159 | スロット番号に範囲外の値が指定された |
| S_m3cpu_INVALID_NUMBER | 160 | パラメータに範囲外の値が指定された |
| S_m3cpu_INVALID_FUNC | 161 | 想定外のIOCTL | コードが指定された |
| S_m3cpu_INVALID_MODULE | 162 | 未サポートのIOCTL | コードが指定された |
| S_m3cpu_TIMEOUT_ERROR | 163 | CPU | モジュールからの応答がない |
| S_m3cpu_INTERNAL_ERROR | 166 | 内部エラー |
| S_m3dev_INVALID_NUMBER | 392 | パラメータに範囲外の値が指定された |
| S_m3dev_DEVICE_NOT_FOUND | 393 | 指定されたデバイスが見つからない |
| S_m3dev_BOUNDARY_ERROR | 396 | デバイスのアライメントが無視されている |
| S_m3dev_INVALID_FUNC | 397 | パラメータに範囲外の値が指定された |
| S_m3dev_INTERNAL_ERROR | 398 | 内部エラー |
| S_m3ras_LRCHK_ERROR | 449 | サブユニット伝送路に異常を確認した |
| S_m3ras_CPUCHK_ERROR | 450 | 他の | CPU | に異常を確認した |
| S_m3ras_BUS_ERROR | 459 | I/O | バス異常 |
| S_m3ras_INTERNAL_ERROR | 460 | 内部エラー |
| S_m3flnet_INVALID_NUMBER | 414 | パラメータに範囲外の値が指定された |
| S_m3flnet_DEVICE_MISMATCH | 415 | 指定スロットはFL-net | インタフェースモジュールでない |
| S_m3flnet_DEVICE_NUMBER_OVER | 416 | モジュール数オーバー |
| S_m3flnet_DEVICE_ENTRY_ERROR | 417 | FL-net | インタフェースモジュールの管理情報が読めない |
| S_m3flnet_NODATA | 418 | データがない |
| S_m3flnet_IOBUS_ERROR | 420 | I/O | バス異常 |
| S_m3flnet_INTERNAL_ERROR | 422 | 内部エラー |
| S_m3flnet_NOLINK | 423 | FL-net | インタフェースモジュールがリンクしていない |
| S_m3flnet_INVALID_FUNC | 424 | 不正な呼び出し |
