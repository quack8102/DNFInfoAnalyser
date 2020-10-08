# DNFInfoAnalyser

> 一个从游戏截图或者实时游戏画面中自动计算属性的工具

[项目主页](https://quack8102.gitee.io)

## 项目背景

希洛克版本面板改版后，很多玩家对新面板不熟悉，加上新面板很多不合理的设计（例如算三攻时仍然计算武器精通，算属强时高亮显示不够人性化等等），使得玩家不方便查看角色面板，并且在理解角色面板数据的过程中抱有疑惑。经常有玩家问：XX职业XX面板（力智/三攻/属强）算高还是低？

为了解决该问题，作者开发了这个软件。

## 安装

### release

下载编译好的release版本，解压即可。

### source code

下载源码，用qt creator打开工程文件，然后编译。

> 请确保在qt creator中已经配置好了openssl库和opencv库的开发环境。

## 使用

详见[项目主页](https://quack8102.gitee.io)。

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
资源文件，主要是贴图文件和csv文件

## 程序主要流程

从游戏画面截屏或者打开截图文件得到图片P，将一个角色面板上的特定图标I与P匹配，即可得到人物面板图片P1。

从P1的特定位置取数据，即可得到人物职业图片，人物装备图片，人物属性图片。

对于人物职业图片，做二值化后与资源文件匹配即可得到人物职业数据。

对于人物装备图片，与资源文件匹配即可得到人物装备数据。

对于人物属性图片，先做二值化，再做边框检测后即可把每个数字的图片提取出来，每个数字图片与资源文件匹配即可得到对应的数字，把这些数字连起来即可得到人物属性数据。

人物装备数据和人物职业数据经过工厂模式查表即可用具体的装备类和职业类对人物属性进行计算，得到“标准”打造的模板角色。

## 项目维护者

我自己。

## 项目贡献者

详见[项目主页 - 致谢](https://quack8102.gitee.io/#/thanks)。

## 开源协议

GPLv3

禁止用于商业用途。
