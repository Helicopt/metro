# metro
### 启动

1. 运行时加入命令行参数-g或不加任何参数将启动图形界面。
2. 选择参数-a 并指定起点将遍历整个地图并在控制台输出。
3. 选择参数-b 并指定起点和终点将输出经过最少站点的路径。
4. 选择参数-c 并指定起点和终点将输出换乘最少并且经过站点尽可能少的路径。

### 图形界面下的操作

1. 右键地图可选择查询哪一个城市的地铁图。
2. 鼠标滚轮控制地图显示大小。
3. 鼠标左键拖动地图移动。
4. 直接在输入框中输入起点、终点或在地图站点上右键点击确定起点、终点，选择相应模式并点击查询将输出结果并在地图上标注。
5. 换乘站用绿色标注，非换乘站用蓝色标注，已走过的站点用灰色标注。

### 添加地图

可在.\Metro\data中加入地图信息，并在map.list中注册，格式参照其他地图。