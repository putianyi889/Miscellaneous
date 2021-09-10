# 基础概念

## 规则
一个扫雷盘面由许多方格（Cell）组成，方格中随机分布着一定数量的雷（Mine），一个格子中至多只有1雷。胜利条件是打开所有安全格（非雷格，Safe cell），失败条件是打开了一个雷格（踩雷）。

打开一格有两种操作方式，一种是左键点开，一种是当数字周围标了

每打开一个安全格，格子上显示的数字表示这格周围的雷数（若此格在中腹，则周围有8格；若在边上，则有5格；若在角上，则有3格）。如果一个安全格周围全都不是雷（有时也称这格是0），游戏会自动帮你打开周围所有格，以这种方式打开的一片格子称为空（Opening）。
The board is divided into cells, with mines randomly distributed. To win, you need to open all the cells. The number on a cell shows the number of mines adjacent to it. Using this information, you can determine cells that are safe, and cells that contain mines. Cells suspected of being mines can be marked with a flag using the right mouse button.

To start a new game, you can click on the happy face at the top of the board or use the space bar. The remaining number of mines is displayed in the left corner, and the game timer is displayed in the right corner.
