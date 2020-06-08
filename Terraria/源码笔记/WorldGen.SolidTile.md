## 总结
`SolidTile1402(i,j,false) = SolidTile1353(i,j)`

`SolidTile1402(i,j,true) = SolidTile1353(i,j) && (tile[i,j] != ClosedDoor)`

## 1.4.0.2
``` c
    public static bool SolidTile(int i, int j, bool noDoors = false)
    {
      try
      {
        if (Main.tile[i, j] == null)
          return true;
        if (Main.tile[i, j].active())
        {
          if (Main.tileSolid[(int) Main.tile[i, j].type])
          {
            if (!Main.tileSolidTop[(int) Main.tile[i, j].type])
            {
              if (!Main.tile[i, j].halfBrick())
              {
                if (Main.tile[i, j].slope() == (byte) 0)
                {
                  if (!Main.tile[i, j].inActive())
                    return !noDoors || Main.tile[i, j].type != (ushort) 10;
                }
              }
            }
          }
        }
      }
      catch
      {
      }
      return false;
    }
```

## 1.3.5.3
``` c
    public static bool SolidTile(int i, int j)
    {
      try
      {
        if (Main.tile[i, j] == null)
          return true;
        if (Main.tile[i, j].active())
        {
          if (Main.tileSolid[(int) Main.tile[i, j].type])
          {
            if (!Main.tileSolidTop[(int) Main.tile[i, j].type])
            {
              if (!Main.tile[i, j].halfBrick())
              {
                if ((int) Main.tile[i, j].slope() == 0)
                {
                  if (!Main.tile[i, j].inActive())
                    return true;
                }
              }
            }
          }
        }
      }
      catch
      {
      }
      return false;
    }
```
