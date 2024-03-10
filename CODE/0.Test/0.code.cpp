#include <bits/stdc++.h>
using namespace std;

struct Line
{
    int start;
    int end;
};

const int N = 1e4 + 10;
Line line[N] = {};
int n, MinHeap[N], size; 

// 自定义小根堆
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void MinHeapInsert(int i)
{
    // 子结点 < 父结点
    while (MinHeap[i] < MinHeap[(i - 1) / 2])
    {
        swap(MinHeap[i], MinHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    return;
}

void MinHeapify(int x)
{
    int left = (x << 1) + 1;
    while (left <= size - 1)
    {
        int right = left + 1;
        // 找到 左右孩子中最小的一个
        int minn_index = (right <= size - 1) && (MinHeap[right] < MinHeap[left]) ? right : left;
        minn_index = MinHeap[minn_index] < MinHeap[x] ? minn_index : x;
        if (minn_index == x)
        {
            break;
        }
        else
        {
            swap(MinHeap[minn_index], MinHeap[x]);
            x = minn_index;
            left = (x << 1) + 1;
        }
    }
    return;
}

void add(int x) // MinHeap[0 , size-1]
{
    int i = size; // 新加入数据的位置
    MinHeap[i] = x;
    size++;
    MinHeapInsert(i);
}

void pop()
{
    // 交换 MinHeap[0] 和 MinHeap[size-1] , size--
    swap(MinHeap[0], MinHeap[size - 1]);
    size--;
    MinHeapify(0);
}

int Compute()
{
    // 清空堆
    size = 0; // heap-->size 用来让堆保持规则的

    // 一共 n 条线段，line[0].start , line[0].end ...
    // 所有线段，根据开始位置排序，结束位置不考虑

    auto f = [](const Line &a, const Line &b) {
        return a.start > b.start;
    };

    sort(line, line + n, f);

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        // i：line[i].start , line[i].end
        // 新线段的左端点大于等于当前小根堆堆顶元素
        while (size > 0 && MinHeap[0] <= line[i].start)
        {
            pop();
        }
        add(line[i].end);
        ans = max(ans, size);
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &line[i].start, &line[i].end);
    }

    printf("%d", Compute());

    return 0;
}
