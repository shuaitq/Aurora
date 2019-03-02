# Aurora - 极光

一个使用C++语言编写的CPU计算光栅化渲染器。寒假在家自学计算机图形学时利用所学知识写的一个渲染器。

# 特性

* 支持使用json格式定义场景、相机、灯光等参数。
* 支持obj格式模型，支持ppm格式图片贴图，采用双线性过滤，使用平铺纹理坐标寻址。
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

## 不同光源 （平行光和点光源

<a target="_blank" rel="noopener noreferrer" href="https://github.com/shuaitq/Aurora/blob/master/Image/direct_light_bunny.png"><img src="https://github.com/shuaitq/Aurora/blob/master/Image/direct_light_bunny.png" width="400pt" height="225pt"></a>
<a target="_blank" rel="noopener noreferrer" href="https://github.com/shuaitq/Aurora/blob/master/Image/point_light_bunny.png"><img src="https://github.com/shuaitq/Aurora/blob/master/Image/point_light_bunny.png" width="400pt" height="225pt"></a>

## 彩色光源叠加 （左边黄色平行光，右边蓝色点光源

<a target="_blank" rel="noopener noreferrer" href="https://github.com/shuaitq/Aurora/blob/master/Image/colorful_bunny.png"><img src="https://github.com/shuaitq/Aurora/blob/master/Image/colorful_bunny.png" width="400pt" height="225pt"></a>

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

# 配置文件格式

```json
{
    "width" : 1920,                                         宽
    "height" : 1080,                                        高
    "camera" :{                                             相机参数
        "position" : [0.800000, 0.800000, 0.800000],        位置
        "u" : [0.707106, -0.707106, 0],                     右向量
        "v" : [-0.408248, -0.408248, 0.816496],             上向量
        "n" : [-0.577349, -0.577349, -0.577349],            前向量
        "fov" : 80,                                         视角
        "near" : 0.1,                                       近裁剪面
        "far" : 1000                                        远裁剪面
    },
    "object" :[                                             模型参数
        {
            "path" : "cube.obj",                            obj文件目录
            "position" : [0.000000, 0.000000, 0.000000],    位置
            "u" : [1, 0, 0],                                同相机
            "v" : [0, 1, 0],
            "n" : [0, 0, 1]
        }
    ],
    "light" :[                                              光源参数
        {
            "type" : "DirectLight",                         方向光
            "direction" : [-0.267261, -0.534522, -0.801784],方向
            "color" : [1, 1, 1]                             颜色
        },
        {
            "type" : "PointLight",                          点光源
            "position" : [1, 1, 1],                         位置
            "color" : [0.5, 0.5, 0.5]                       颜色
        }
    ]
}
```

# 感谢

[nlohmann/json](https://github.com/nlohmann/json)的json库提供json解析功能

# 参考

[《3D游戏编程大师技巧》](https://www.amazon.cn/dp/B008IBDL68)
