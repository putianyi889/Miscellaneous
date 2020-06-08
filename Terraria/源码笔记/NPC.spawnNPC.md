## 代码细节调整

## 刷怪率与刷怪量

## 刷怪点
1.3.5.3中刷怪点会一直下落到maxTilesY，也就是说怪可能刷在生成区域下方。1.4.0.2中刷怪点落到生成区域底端就停了，不会刷在生成区域下方。
``` c
//1.3.5.3
for (int index7 = index6; index7 < Main.maxTilesY; ++index7)
//1.4.0.2
for (int index9 = index8; index9 < Main.maxTilesY && index9 < maxValue2; ++index9)
```
