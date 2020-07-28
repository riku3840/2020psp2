# 課題4 レポート

aa83988848 薗田光太郎

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
6 構造体の定義

40~46　性別、身長のデータを構造体の中に格納する

50~53  IDを構造体の中に格納する

55 調べたいIDを入力させる

58~74 入力したIDと一致するIDを探し対応するデータを構造体の中からとりだす

76~80 一致するIDがなかったときにNO dateとだす

これでやってみたのですが、ファイルが読み込めなくてよくわかりませんでした。


## 入出力結果

例えば，ID 45313125のデータを調べたいとき，
 
```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴

[comment #20200720 sonoda]
- OKです．課題4の完了を確認しました．