# DNFInfoAnalyser

## 功能简介及使用方法

见COLG。

## todo
适配版本更新

计算奶装？

计算伤害？

## 技术栈
qt

opencv

## 目录结构

### ./
attrcalculator 装备属性计算相关函数

character 人物属性类

csvdataparser 处理csv数据的类

cvalgorithm opencv算法相关函数

DNFInfoAnalyser.pro qt creator 工程文件

equipment 装备抽象类

factory 工厂类

main 程序入口

mainwindow 主窗口（即托盘）

settingdata 设置数据

settingpanel 设置面板

userinfowindow 包含分析结果的窗口

### ./MyGlobalShortCut
第三方库，全局热键

### ./equipment
装备代码

### ./class
职业代码

### ./resources
资源文件，即贴图文件和csv文件

## 程序流程
从游戏画面截屏或者打开截图文件得到图片P，将一个角色面板上的特定图标I与P匹配，即可得到人物面板图片P1。

从P1的特定位置取数据，即可得到人物职业图片，人物装备图片，人物属性图片。

对于人物职业图片，做二值化后与资源文件匹配即可得到人物职业数据。

对于人物装备图片，与资源文件匹配即可得到人物装备数据。

对于人物属性图片，先做二值化，再做边框检测后即可把每个数字的图片提取出来，每个数字图片与资源文件匹配即可得到对应的数字，把这些数字连起来即可得到人物属性数据。

人物装备数据和人物职业数据经过工厂模式查表即可用具体的装备类和职业类对人物属性进行计算，得到“标准”打造的模板角色。
