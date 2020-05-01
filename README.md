# PlaneWar
一个关于qt飞机大战游戏，根据[【b站 斧头帮-帮主】](https://space.bilibili.com/376641988?spm_id_from=333.788.b_765f7570696e666f.2)的[【C++之Qt版本飞机大战】](https://www.bilibili.com/video/BV1MJ411E7dP?p=1)视频而写。

## 一些说明
* 该代码是根据视频中老师的讲解和代码一行一行敲出来的； 
* 我几乎没有写注释，学习需要配合老师的视频来；

## 开发环境说明
* 我用的`win10` + `vs2019`，vs2017也可以；
* `vs2019`开发`qt`需要安装`msvc版的qt`和`qt vs tool插件`；
* 如果环境配置好了，编译错误，多半是`window sdk`不匹配，重新选择下`平台工具集`就好了

## `其他`
* 我已经生成好了`plane.rcc`文件【在项目的根目录下】，仅仅需要把它放到执行文件目录下即可，该项目需要把放到执行文件同级目录下的res目录里，需要新建个res目录。
* 关于中文乱码，可用c++11字符串字面量u8"xxx"解决;
* 有些地方的代码跟老师的代码不一样，我重构了下代码，比如：  
* * 需要显示的都提供`void draw(QPainter&)`接口
    ```cpp
    void MainScene::paintEvent(QPaintEvent* ev)
    {
        QPainter painter(this);

        map_.draw(painter);
        heroPlane_.draw(painter);
        enemy_.draw(painter);
        bombEffect_.draw(painter);
    }
    ```  
* * 将敌军飞机和爆炸分别再次封装
    ```cpp
    class Enemy 
    {
    public:
        using EnemyPlaneType = std::array<EnemyPlane, ENEMY_PLANE_NUM>;

        Enemy();
        void draw(QPainter& painter);

        void enemyToScene();
        void updatePosition();
        EnemyPlaneType& enemyPlanes();

    private:
        EnemyPlaneType enemyPlanes_;
        int recorder_{ 0 };
    };

    class BombEffect 
    {
    public:
        BombEffect() = default;

        void show(int x, int y);
        void update();
        void draw(QPainter& painter);

    private:
        std::array<Bomb, BOMB_MAX> bombs_;
    };
    ```  