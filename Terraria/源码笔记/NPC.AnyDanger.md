# 总结：1.4.0.2中的`AnyDanger(false)`相当于1.3.5.3中的`AnyDanger()`。

# 1.4.0.2
``` c
\\NPC
    public static bool AnyDanger(bool quickBossNPCCheck = false)
    {
      bool flag = false;
      if (NPC.MoonLordCountdown > 0)
        flag = true;
      if (Main.invasionType > 0)
        flag = true;
      if (Main.snowMoon || Main.pumpkinMoon || DD2Event.Ongoing)
        flag = true;
      if (!flag)
      {
        if (quickBossNPCCheck)
        {
          flag |= Main.CurrentFrameFlags.AnyActiveBossNPC;
        }
        else
        {
          for (int index = 0; index < 200; ++index)
          {
            if (Main.npc[index].active && (Main.npc[index].boss || NPCID.Sets.DangerThatPreventsOtherDangers[Main.npc[index].type]))
              flag = true;
          }
        }
      }
      return flag;
    }
//NPCID.Sets
    public static bool[] DangerThatPreventsOtherDangers = NPCID.Sets.Factory.CreateBoolSet(517, 422, 507, 493, 399);
```

# 1.3.5.3

``` c
//NPC
    public static bool AnyDanger()
    {
      bool flag = false;
      if (NPC.MoonLordCountdown > 0)
        flag = true;
      if (Main.invasionType > 0)
        flag = true;
      if (!flag)
      {
        for (int index = 0; index < 200; ++index)
        {
          if (Main.npc[index].active && (Main.npc[index].boss || NPCID.Sets.TechnicallyABoss[Main.npc[index].type]))
            flag = true;
        }
      }
      return flag;
    }
//NPCID.Sets
    public static bool[] TechnicallyABoss = NPCID.Sets.Factory.CreateBoolSet(517, 422, 507, 493, 399);
```
