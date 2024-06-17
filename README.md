# sys2_catan
Sources – 
•	SingleTon for map - https://www.geeksforgeeks.org/singleton-pattern-c-design-patterns/
•	Redeclaration of empty constructor – for Map Class - https://discuss.cocos2d-x.org/t/correct-way-to-implement-singleton/28226/23?page=2
•	Game Play -https://www.google.com/search?client=opera-gx&hs=y5H&sca_esv=d34e0a7206c3ba5b&sca_upv=1&sxsrf=ADLYWILDf2_RxaAxmYlLBqFt3S52PxOdpQ:1718476571284&q=catan+online&tbm=vid&source=lnms&fbs=AEQNm0COtQ6qE5snXClm_cWqGTLX_jMP5V4l2v9LemFtanifXXTKrMMqmKUWXEqMOTvUWjh32YiMrtRaydvvlf4xc59VozWZ1FcQ32Op83AMai-VD8_3g1l4-18Kl2RDkBGhvVyNTvJTBTukmWsgGfosjjmVxXD4WeoD5LDhEcSB9qPLLsi6UNro0E7qf2M0zZHmC70yVxKEkBKlZNesxzWmip2Tl3ErDA&sa=X&ved=2ahUKEwi5gtiMoN6GAxXAVfEDHUFFDyMQ0pQJegQIDBAB&biw=1495&bih=723&dpr=1.25#fpstate=ive&vld=cid:ea570e8d,vid:1raZRlTK3NI,st:0

How I built the map-
•	Ive decided to make a point grids that each point indicates a place that you can put the settlement/city and who possesses the point ,which tiles it belongs to and the roads is an object which is built with 2 points from the map and ownership (player) .
•	The map contains tiles which only contains how many building it has and how many road, and of course the number of token (for Dice).
Logic-
•	The players do their move and updates the map


![Map P1](https://github.com/SirAriela/sys2_catan/assets/25841033/989791fe-4d72-468a-a6fc-dba4196009a7)
