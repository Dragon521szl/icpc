// int dxy[4][2]={//模拟上下左右四个方向
// 	-1,0,//向上（x减一，y不变）
// 	1, 0,//向下
// 	0,-1,//向左
// 	0, 1//向右
// 	}
// void dfs(int x0,int y0){
// 	if(x0,y0满足某种条件)//找到目标点
// 	{
// 		//执行操作如输出路径等
// 		return;
// 	}
// 	for(int i=0;i<4;i++)//遍历四个方向每一个分支，对每一个分支都进行深度搜索
// 	{
// 		int dx=dxy[i][0];//移动后的横坐标
// 		int dy=dxy[i][1];//移动后的纵坐标
// 		if(坐标越界||遇到障碍物||...)//不满足条件
// 			continue;
// 		//执行操作
// 		dfs(dx,dy)//深度遍历
// 		//遍历结束恢复操作
// 	}
// }