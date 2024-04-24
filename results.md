
Random Input 

Operation | 100 | 1,000 | 10,000 | 100,000 | 1,000,000 | 10,000,000 | 100,000,000 |
----------|-----|-------|--------|---------|-----------|------------|-------------|
binary insert (java) | 0.000328 | 0.000105 | 0.001095 | 0.018122 | 0.420075 | 7.688661 | Out of mem. |
binary insert (c) | 0.000009 | 0.000082 | 0.001144 | 0.016982 | 0.622891 | 13.485158 | 221.095372 |
red black insert (java) | 0.000061 | 0.000436 | 0.001693 | 0.022173 | 0.571692 | 9.734067 | Out of mem. |
red black insert (c) | 0.000011 | 0.000113 | 0.001389 | 0.021093 | 0.609684 | 10.697785 | 182.316291 |
binary get (java) | 0.000021 | 0.000163 | 0.000980 | 0.017237 | 0.382841 | 7.574105 | Out of mem. |
binary get (c) | 0.000003 | 0.000031 | 0.000542 | 0.010602 | 0.536381 | 12.600009 | 231.436482 | 
red black get (java) | 0.000018 | 0.000167 | 0.001139 | 0.016662 | 0.445471 | 8.577500 | Out of mem. |
red black get (c) | 0.000003 | 0.000021 | 0.000352 | 0.007772 | 0.284726 | 5.353575 | 109.824046 | 
binary delete (java) | 0.000034 | 0.000334 | 0.001237 | 0.015158 | 0.488105 | 11.117415 | Out of mem. | 
binary delete (c) | 0.000005 | 0.000041 | 0.000548 | 0.012384 | 0.449614 | 9.839891 | 223.728083 | 
red black delete (java) | 0.000052 | 0.000527 | 0.001803 | 0.025106 | 0.695766 | 13.047160 | Out of mem. |
red black delete (c) | 0.000007 | 0.000053 | 0.000746 | 0.015047 | 0.588909 | 11.000803 | 232.912434 | 

Ordered Input

Operation | 100 | 1,000 | 10,000 | 100,000 | 1,000,000 |
----------|-----|-------|--------|---------|-----------|
binary insert (java) | 0.000120 | 0.001622 | 0.050535 | 5.413784 | 1353.688207 |
binary insert (c) | 0.000010 | 0.000859 | 0.115331 | 18.162251 | 5638.445621 |
red black insert (java) | 0.000065 | 0.000195 | 0.000602 | 0.007054 | 0.104467 |
red black insert (c) |  0.000005 | 0.000038 | 0.000585 | 0.008310 | 0.107680 |
binary get (java) | 0.000087 | 0.001241 | 0.049942 | 5.251935 | 1412.080052 |
binary get (c) | 0.000011 | 0.001117 | 0.139443 | 20.907294 | 6079.026653 | 
red black get (java) | 0.000016 | 0.000087 | 0.000388 | 0.445471 | 0.040362 | 
red black get (c) | 0.000002 | 0.000012 | 0.000331 | 0.002541 | 0.045427 | 
binary delete (java) | 0.000014 | 0.000037 | 0.000074 | 0.000536 | 0.007091 | 
binary delete (c) | 0.000003 | 0.000011 | 0.000078 | 0.001360 | 0.014759 | 
red black delete (java) | 0.000036 | 0.000527 | 0.000381 | 0.695766 | 0.035165 | 
red black delete (c) | 0.000005 | 0.000032 | 0.000312 | 0.004761 | 0.069045 | 


