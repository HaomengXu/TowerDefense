# TowerDefense
一个以“抗击新冠疫情”为主题的抗疫塔防游戏(made by Qt)


（一）	系统设计说明
在新冠肺炎疫情爆发的大背景下，我认为我们青年人有义务也有责任为抗疫出一份力，尽一份心。特此，本人借程设大作业的机会，以当下时事为基调，选取了经典的抗疫素材，完成了此次任务。
这个程序的图形界面灵感来源于近10年前较火的“保卫萝卜”游戏，其中的图片及音效素材也大多取材于此。
本游戏中，我们的目标是保护肺部器官，防止各种病毒的侵犯。总共分为三种塔：
（1）疫苗：众所周知，这是人类最终战胜病毒的科学方法；在游戏中，它负责较远射程的点对点强攻击。
（2）口罩：这是每个人的好习惯，也是公德，是切断病毒传播的有效方式；在游戏中，它可以减慢病毒的移动速度，并造成一定程度上的伤害。
（3）医生：所谓医者仁心，医生是护佑生命的最后一道防线，他们是一线的英雄；在游戏中，他们能对病毒造成范围性的伤害。
（4）医疗垃圾桶：警示医疗垃圾的安全回收的重要性；在游戏中，它占据要塞部位，只有将他们填满之后它们才会消失，从而便于新塔的建立。
这些功能与现实中各种措施所产生的效果相对应。这种设计旨在表明，只要我们相信科学、相信自己、相信医生，再严重的疫情我们也可以克服，也可以战胜！


（二）游戏说明
该塔防游戏共有2张地图，3种防御塔，4 种怪物，1种障碍物。
    1.地图：每张地图设置3波怪物，怪物数量随波数和防御塔个数递增。
    2.防御塔：①疫苗：点对点强攻击；②口罩：对病毒有减速作用和弱攻击；③医生：范围性杀伤但攻击频率较低。
    3.怪物：①普通病毒：血少且对肺部伤害1；②快速入侵病毒：血少速度快且肺部伤害为2；③厚血病毒：血多且肺部伤害1；④大BOSS：血量极厚且肺部伤害为4，但死后玩家获得金币多。
    4.障碍：医疗垃圾桶，设置在要塞处，增加游戏难度。

开始界面：点击start开始游戏(按键盘enter键)；点击Instructions访问GitHub开发页面(按键盘任意键)，查看官网游戏简介；点击exit退出(按键盘esc键)。
游戏开始：有5s缓冲时间，每一波都有5s作为缓冲。
接着，一波怪物从怪物窝不断出现，先头部队较弱，逐渐增强，不同怪物出现的时间间隔也有不同；弱AI——还会根据玩家的火力情况适当增强敌军阵容。
玩家可在除金币显示区(第一行)和最后一行的任意非怪物路径上建塔。游戏已自动分配好格子用于建塔，玩家用鼠标点击后，点击点所属的格子会弹出选择框，让玩家选择所建的塔。金币不足时，塔的背景色为红色，表示不能建塔。
已建塔处点击会升级，扣除相应的金币，如金币不足，则无法升级，升级所需金币显示在游戏右上角。升级可以使塔的攻击增强，攻击间隔缩短，攻击范围加大；减速塔的减速效果增强。
已建塔处右击即可实现拆塔操作，会退还相应级别的金币。
塔会自动攻击射程内的敌人，根据威胁程度大小顺序攻击。

点击医疗垃圾桶，所有的能攻击到它的武器都会集中火力优先攻击它，此时它成为靶标；再次点击取消设置它为靶标。把其血量打光后，可以获得一定量的金币。但主要的作用是清理出要塞部分，便于建立新塔。

病毒到达肺部时仍有血量则判定为侵犯成功，有10条命的肺部减去相应命数。肺部命数为0时，游戏失败。反之，通过两张地图的6波敌人仍然幸存则游戏胜利。
游戏结束后，不论输赢，都可点击界面(按键盘任意键)，之后会自动返回主界面，并可以选择重新开始。


（三）总述
我的想法非常简单，就是希望能通过这个简单的小程序表达一种对战胜疫情的信心和渴望。通过这一次游戏的设计，我将之前所讲的许多知识点有机地串联起来，又对知识间千丝万缕的联系有了新的认识。通过上网查阅资料，我又了解了Qt的许多强大的功能，并将其中的一部分应用到我自己的程序中，这让我非常有成就感。
另一方面，游戏数据的设计之难也远远超出了我的想象。想要达到一种合适的难度是非常难调控的，为此我玩了若干次保卫萝卜来寻找参考数据，也把自己的游戏玩了不知道多少遍。我也长了教训，以后不再用游戏修改器了，这实在是对开发人员的不尊重。最后我的难度大概是满血通关有难度，但通关是较容易的。
这次大作业也暴露出我的许多问题。以前，我一直都是先编程，再照着程序写我的设计或UML图。这让我吃了不少苦头，导致程序经历许多次的“大换血”，有一些其实是可以避免的。我之前应该设计得再充分一点，就能避免许多低效的事情发生，毕竟补丁时常是越打越多的，最后的观感也不好，或者说，程序的可读性不高。
总而言之，这只是一个小游戏，不论输赢，不论分数，我都希望疫情能够早日结束，希望我们早日回归正常的生活。最后，向所有在疫情中奉献的医生们、科学家们，还有各行各业舍小家为大家的伟大的人民们致敬！

