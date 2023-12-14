# C++中A*算法实现：技术文档

## 概述

本文档提供了一个在C++中实现的A*路径查找算法的概览。A*算法因其性能和准确性，是路径查找和图遍历的热门选择。此实现旨在找到网格状地图中的最短路径。

## Algorithm theory

* find start point and appending the start point into the open list.
* find the target node in open list wilch node was the most min distance to end point.
* append target node to close list, and remove the target node form open list.
* find all the accessible node of now node(target node)，appending to the open list.
* repaly those step until find the end point or open list was empty.


## 关键组件

### Node 类

- **目的**：表示地图中的单个节点（或单元格）。
- **属性**：
  - `x`, `y`：节点在地图中的坐标。
  - `xFarther`, `yFarther`：节点父节点的坐标。
  - `g_cost`：从起始节点到当前节点的成本。
  - `h_cost`：从当前节点到目标的启发式成本估算。
  - `f_cost`：总成本（`g_cost + h_cost`）。
- **方法**：
  - `showNode()`：打印节点的详细信息。

### AStart 类

- **目的**：实现A*算法。
- **属性**：
  - 地图数据、起始和目标位置、开放和关闭列表以跟踪节点。
- **构造函数**：
  - 重载构造函数，用于带有或不带有地图文件路径的初始化。
- **析构函数**：
  - 在对象销毁时清除地图。
- **方法**：
  - `loadMap()`：从文件加载地图。
  - `showMap()`, `showMapSize()`：显示地图数据的功能。
  - `setTargetNode()`, `setStartNode()`：设置目标和起始位置。
  - `setType()`：设置启发式类型（曼哈顿或欧几里得）。
  - `getNowNodeNextNodes()`：从当前节点生成下一个节点。
  - `addOpenList()`, `addCloseList()`：管理开放和关闭列表。
  - `isInOpenList()`, `isInCloseList()`, `IsInBlackList()`：检查节点是否在列表中。
  - `deleteOldNodeByXY()`：基于坐标从开放列表删除节点。
  - `getNextNode()`：从开放列表获取下一个要处理的节点。
  - `getDistance()`：计算启发式距离。
  - `isTarget()`：检查当前节点是否是目标节点。
  - `run()`：执行A*算法。
  - `Manhuattan()`, `EuclideanDistance()`：启发式函数。
  - `showPath()`：在控制台上可视化路径。

## 使用方法

1. **初始化**：

   - 创建 `AStart`类的实例，可选择指定地图文件。
   - 使用 `setType()`设置启发式类型。
   - 使用 `loadMap()`加载地图。
2. **设置起始和目标**：

   - 使用 `setStartNode()`和 `setTargetNode()`设置起始和目标节点。
3. **运行算法**：

   - 调用 `run()`开始算法。
   - 算法完成后，使用 `showPath()`可视化路径。

## 示例

```cpp
int main() {
    // 初始化A*算法
    std::shared_ptr<AStart> astar = std::make_shared<AStart>("map.txt");

    // 配置并运行算法
    astar->setType(0); // 0表示欧几里得，1表示曼哈顿
    astar->loadMap();
    astar->setTargetNode(34, 6, -1);
    astar->setStartNode(2, 20, -1);
    astar->run();
    astar->showPath();

    return 0;
}
```

## 限制和改进

- **地图灵活性**：当前实现要求特定格式的地图。可以进行改进以支持各种类型的地图。
- **错误处理**：需要更健壮的错误处理和验证，尤其是对于文件操作和地图数据。
- **性能优化**：对于大型地图或复杂场景，可以对算法进行优化。
- **可视化**：

路径可视化基本，可以改进以获得更好的清晰度。

## 结论

这个C++实现的A*算法为路径查找任务提供了一个有效的起点。它展示了算法的基本原则，包括启发式计算、开放和关闭列表的管理以及节点遍历。代码可以根据需要进行调整和扩展，适用于需要路径查找功能的各种应用。
