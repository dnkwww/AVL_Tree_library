# AVL_Tree_library
 
111上資料結構HW4

[作業說明網頁](https://hackmd.io/@chtsai/2020DS-homework-4)

---

建構一個 AVL tree 的 library. (類似 BST 作業)

函式庫使用說明書.pdf的執行結果指令未分類檔案，在CMD打開根目錄打以下指令執行即可：

```
gcc -c -I./include ./src/AVLTree.c -o ./obj/AVLTree.o

ar -cr ./lib/libAVLTree.a ./obj/AVLTree.o

gcc -I./include ./src/main.c ./lib/libAVLTree.a -o ./bin/test.exe

cd bin
test.exe
```
