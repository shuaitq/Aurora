# Aurora - 极光

一个使用C++语言编写的CPU计算光栅化渲染器。寒假在家自学计算机图形学时利用所学知识写的一个渲染器。

# 特性

* 支持使用json格式定义场景、相机、灯光等参数。
* 支持obj格式模型，支持ppm格式图片贴图，采用二次线性差值进行采样。
* 渲染结果输出为ppm图片格式
* 支持方向光和点光源两种光源
* 采用Z-Buffer保证渲染正确的顺序，支持背面消影和三角形剔除(~~未实现三角形裁剪~~)

# 渲染结果

## 不同贴图

<a target="_blank" rel="noopener noreferrer" href="https://github.com/shuaitq/Aurora/blob/master/Image/chess_cube.png"><img src="https://github.com/shuaitq/Aurora/blob/master/Image/chess_cube.png" width="400pt" height="225pt"></a>
<a target="_blank" rel="noopener noreferrer" href="https://github.com/shuaitq/Aurora/blob/master/Image/chess_sphere.png"><img src="https://github.com/shuaitq/Aurora/blob/master/Image/chess_sphere.png" width="400pt" height="225pt"></a>
<a target="_blank" rel="noopener noreferrer" href="https://github.com/shuaitq/Aurora/blob/master/Image/wood_cube.png"><img src="https://github.com/shuaitq/Aurora/blob/master/Image/wood_cube.png" width="400pt" height="225pt"></a>
<a target="_blank" rel="noopener noreferrer" href="https://github.com/shuaitq/Aurora/blob/master/Image/wood_sphere.png"><img src="https://github.com/shuaitq/Aurora/blob/master/Image/wood_sphere.png" width="400pt" height="225pt"></a>
<a target="_blank" rel="noopener noreferrer" href="https://github.com/shuaitq/Aurora/blob/master/Image/marble_cube.png"><img src="https://github.com/shuaitq/Aurora/blob/master/Image/marble_cube.png" width="400pt" height="225pt"></a>
<a target="_blank" rel="noopener noreferrer" href="https://github.com/shuaitq/Aurora/blob/master/Image/marble_sphere.png"><img src="https://github.com/shuaitq/Aurora/blob/master/Image/marble_sphere.png" width="400pt" height="225pt"></a>

## 斯坦福兔子

<a target="_blank" rel="noopener noreferrer" href="https://github.com/shuaitq/Aurora/blob/master/Image/bunny.png"><img src="https://github.com/shuaitq/Aurora/blob/master/Image/bunny.png" width="400pt" height="225pt"></a>

## 不同光源

<a target="_blank" rel="noopener noreferrer" href="https://github.com/shuaitq/Aurora/blob/master/Image/direct_light_bunny.png"><img src="https://github.com/shuaitq/Aurora/blob/master/Image/direct_light_bunny.png" width="400pt" height="225pt"></a>
<a target="_blank" rel="noopener noreferrer" href="https://github.com/shuaitq/Aurora/blob/master/Image/point_light_bunny.png"><img src="https://github.com/shuaitq/Aurora/blob/master/Image/point_light_bunny" width="400pt" height="225pt"></a>

# 怎么构建

**请确认您已经安装了make和支持C++11的C++编译器（默认使用g++，可以在Makefile修改）**

1. 下载.zip或是git clone把代码下载下来。
2. 进入Src目录，使用make命令进行构建，构建成功后可以使用make clean把编译过程中的.o文件删除。

# 怎么使用

```shell
./Aurora [json场景文件]
Example:
    ./Aurora ../Example/bunny/bunny.json
```

# 感谢

[nlohmann/json](https://github.com/nlohmann/json)的json库提供json解析功能

# 参考

[3D游戏编程大师技巧](https://www.amazon.cn/dp/B008IBDL68)