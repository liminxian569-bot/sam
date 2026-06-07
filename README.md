# C++ 猜單字遊戲

## 團隊資訊
* **班級**：資工 1B
* **組長**：李旻憲
* **組員**：
  * 吳宸緯
  * 李庭偉

本專案使用 **C++** 實作，架構上採用物件導向設計（OOP），將程式拆解為資料讀取、遊戲邏輯、畫面顯示等不同模組，並透過多檔案分離編譯進行開發。

---

## 程式特點
1. **題庫與程式分離**：移除硬編碼題庫，改由外部文字檔（`.txt`）讀入，方便後續擴充單字。
2. **多檔案分離編編譯**：明確拆分標頭檔（`.h`）與實作檔（`.cpp`），降低模組間的耦合度。
3. **物件組合（Composition）**：`GameManager` 內部整合了 `Pet`（畫面反饋）與 `Scoreboard`（勝率/連勝統計）物件，強化程式內聚力。

---

## 檔案架構與分工

### 1. WordBank.h / WordBank.cpp（負責人：吳宸緯）
* **功能**：負責外部檔案讀寫與單字處理。
* **實作技術**：
  * 使用 `ifstream` 讀取原始題庫檔案。
  * 透過 `eng.length()` 判斷字串長度，自動分類並將單字分流寫入 `easy.txt`、`normal.txt`、`hard.txt`。
  * 設計隨機遮蔽演算法，依難度將選定的單字進行挖空（以底線 `_` 顯示）。

### 2. GameManager.h / GameManager.cpp & 子系統（負責人：李旻憲）
* **功能**：處理遊戲核心邏輯、輸入檢查與畫面渲染。
* **實作技術**：
  * **Pet 類別**：以 ASCII Art 實作畫面寵物，並根據血量與答題狀況切換表情狀態（HAPPY, SAD, ANGRY）。
  * **Scoreboard 類別**：負責在記憶體中維護玩家當前的連勝紀錄（Win Streak）。
  * **防呆機制**：即時檢查玩家輸入的字數與字元合法性，若輸入無效則跳出提示且不扣除血量。
  * 使用 `system("cls")` 清除舊畫面，確保終端機顯示排版整潔。

### 3. main.cpp（負責人：李庭偉）
* **功能**：程式入口點，控管主流程。
* **實作技術**：
  * 初始化各模組物件。
  * 利用 `do-while` 迴圈控制遊戲重開機制，並在每局開始時重置物件暫存狀態。

---

## 遊戲規則

1. **難度選擇**：啟動後輸入 `1` (簡單)、`2` (中等) 或 `3` (困難)。
2. **玩法**：畫面會顯示中文提示與挖空後的英文單字，玩家需輸入字母或直接猜測完整單字。
3. **扣血機制**：每局初始有 3 點血量。猜錯扣 1 點且寵物切換為負面表情；輸入重複或無效字元不扣血。
4. **勝負**：血量歸零前補全單字算獲勝，連勝數加 1；失敗則連勝歸零並顯示正確解答。每局結束可輸入 `Y` 繼續或 `N` 離開。

---

##  程式如何安裝與執行

### 1. 前置準備
* 請確保電腦作業系統已安裝支援 C++11 (含) 以上標準的編譯器環境（如 `GCC` / `MinGW-w64`）。

### 2. 多檔案分離編譯指令
* 打開終端機（PowerShell 或 CMD），切換至本專案所在的原始碼目錄夾，輸入以下編譯指令進行連結：
  
   ```bash
  g++ main.cpp WordBank.cpp GameManager.cpp Pet.cpp Scoreboard.cpp -o main.exe
* 請確保題庫文字檔（easy.txt、normal.txt、hard.txt 以及原始 words.txt）與生成的 main.exe 位在同一個資料夾目錄下，接著輸入指令即可運行：
 
  ```bash
  .\main.exe

---

##  遊戲執行畫面
<img width="384" height="288" alt="Image" src="https://github.com/user-attachments/assets/e4296c89-8765-40c7-a8c9-0e956606191e" />
<img width="384" height="288" alt="Image" src="https://github.com/user-attachments/assets/e9d25b2e-66ef-4c2c-b147-28d227557100" />
<img width="384" height="288" alt="Image" src="https://github.com/user-attachments/assets/2c22ceea-bee0-48f8-90bb-bebf5f6ed944" />
<img width="384" height="288" alt="Image" src="https://github.com/user-attachments/assets/effe8bf8-52f8-4e7b-9c0d-ac0773a7b142" />
<img width="384" height="288" alt="Image" src="https://github.com/user-attachments/assets/da939446-65d8-439b-a341-8edd169cf0e1" />
<img width="384" height="288" alt="Image" src="https://github.com/user-attachments/assets/f7920c10-c3cf-4988-b736-216794d5248b" />
<img width="384" height="288" alt="Image" src="https://github.com/user-attachments/assets/e5ec7dc7-e142-4e2d-8195-882da41eecc4" />
<img width="384" height="288" alt="Image" src="https://github.com/user-attachments/assets/3d93025e-e281-4eb9-bea2-fecfbc421715" />
<img width="384" height="288" alt="Image" src="https://github.com/user-attachments/assets/34c9fb0e-c12b-4aae-8fa7-c4f78258566f" />


