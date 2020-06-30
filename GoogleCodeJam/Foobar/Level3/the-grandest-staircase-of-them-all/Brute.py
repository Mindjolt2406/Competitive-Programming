def solution(n):
  l = [ 0, 0, 0, 1, 1, 2, 3, 4, 5, 7, 9, 11, 14, 17, 21, 26, 31, 37, 45, 53, 63, 75, 88, 103, 121, 141, 164, 191, 221, 255, 295, 339, 389, 447, 511, 584, 667, 759, 863, 981, 1112, 1259, 1425, 1609, 1815, 2047, 2303, 2589, 2909, 3263, 3657, 4096, 4581, 5119, 5717, 6377, 7107, 7916, 8807, 9791, 10879, 12075, 13393, 14847, 16443, 18199, 20131, 22249, 24575, 27129, 29926, 32991, 36351, 40025, 44045, 48445, 53249, 58498, 64233, 70487, 77311, 84755, 92863, 101697, 111321, 121791, 133183, 145577, 159045, 173681, 189585, 206847, 225584, 245919, 267967, 291873, 317787, 345855, 376255, 409173, 444792, 483329, 525015, 570077, 618783, 671417, 728259, 789639, 855905, 927405, 1004543, 1087743, 1177437, 1274117, 1378303, 1490527, 1611387, 1741520, 1881577, 2032289, 2194431, 2368799, 2556283, 2757825, 2974399, 3207085, 3457026, 3725409, 4013543, 4322815, 4654669, 5010687, 5392549, 5802007, 6240973, 6711479, 7215643, 7755775, 8334325, 8953855, 9617149, 10327155, 11086967, 11899933, 12769601, 13699698, 14694243, 15757501, 16893951, 18108417, 19406015, 20792119, 22272511, 23853317, 25540981, 27342420, 29264959, 31316313, 33504745, 35839007, 38328319, 40982539, 43812109, 46828031, 50042055, 53466623, 57114843, 61000703, 65139007, 69545357, 74236383, 79229675, 84543781, 90198445, 96214549, 102614113, 109420548, 116658615, 124354421, 132535701, 141231779, 150473567, 160293887, 170727423, 181810743, 193582641, 206084095, 219358314, 233451097, 248410815, 264288461, 281138047, 299016607, 317984255, 338104629, 359444903, 382075867, 406072421, 431513601, 458482687, 487067745]
  return l[n]

  The Grandest Staircase Of Them All
==================================

With her LAMBCHOP doomsday device finished, Commander Lambda is preparing for her debut on the galactic stage - but in order to make a grand entrance, she needs a grand staircase! As her personal assistant, you've been tasked with figuring out how to build the best staircase EVER. 

Lambda has given you an overview of the types of bricks available, plus a budget. You can buy different amounts of the different types of bricks (for example, 3 little pink bricks, or 5 blue lace bricks). Commander Lambda wants to know how many different types of staircases can be built with each amount of bricks, so she can pick the one with the most options. 

Each type of staircase should consist of 2 or more steps.  No two steps are allowed to be at the same height - each step must be lower than the previous one. All steps must contain at least one brick. A step's height is classified as the total amount of bricks that make up that step.
For example, when N = 3, you have only 1 choice of how to build the staircase, with the first step having a height of 2 and the second step having a height of 1: (# indicates a brick)

#
##
21

When N = 4, you still only have 1 staircase choice:

#
#
##
31
 
But when N = 5, there are two ways you can build a staircase from the given bricks. The two staircases can have heights (4, 1) or (3, 2), as shown below:

#
#
#
##
41

#
##
##
32

Write a function called solution(n) that takes a positive integer n and returns the number of different staircases that can be built from exactly n bricks. n will always be at least 3 (so you can have a staircase at all), but no more than 200, because Commander Lambda's not made of money!
