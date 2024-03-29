// 一、堆排序
// 1）做法：
//      1）先将整个数组排成大根堆 O(N * log2(N))
//      2）将堆顶的值放在数组尾巴上（交换两端）
//      3）size-- 让堆找不到最大值（不考虑末尾的最大值了）
//      4）维护大根堆
//      5）循环执行 2）3）4）O(N * log2(N))

// 二、增倍分析法：
// 1）log2(1) + log2(2) + log2(3) + ... + log2(N-1) + log2(N) 收敛于 O(N * log2(N))
//    log2(1) + log2(2) + log2(3) + ... + log2(N-1) + log2(N)
//    当问题规模为 N 的上限时间复杂度复杂度为 O(N * log2(N))
//    当问题规模为 2N 的下限时间复杂度复杂度为 O(N * log2(N))
//    按理说从 N -> 2N 时间复杂度不会改变，所以时间复杂度复杂度为 O(N * log2(N))
//
//
// 2）n*m 的矩阵的子矩阵个数的规模
//    第一个点有 (n+1)*(m+1) 种选法，第二个点有 ((n+1)*(m+1)-((m+1)+(n+1)-1)) 种选法，可能出现4种重复
//    共计规模 O(n^2 * m^2)
//    增倍分析法：
//    n*m 时以 O(n^2 * m^2)为上限
//    2n*2m 时以 O(n^2 * m^2)为下限
//    按理说从 n*m -> 2n*2m 规模不会改变，所以规模为 O(n^2 * m^2)

// 三、建大根堆
// 已有 arr[l...r] , 对应二叉树
// 1）自上而下建立大根堆
//      1）Time complexity：O(N * log2(N))
//              1）计算：log2(1) + log2(2) + log2(3) + ... + log2(N-1) + log2(N) 收敛于 O(N * log2(N))
//              2）解释：因为上层个数少排序任务少，下层个数多排序个数多，所以时间复杂度较高
//
//
// 2) 自上而下建立大根堆
//      2）Time complexity：O(N)
//              1）计算：(N/2 * 1) + (N/4 * 2) + (N/8 * 3) + ... + (1 * log2(N)) 收敛于 O(N)
//              2）解释：因为上层个数少排序任务多，下层个数多排序个数少，所以时间复杂度较低