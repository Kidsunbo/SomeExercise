import sys


def Dijskstra(graph):
    dis = [sys.maxsize] * len(graph)
    dis[0] = 0
    parent = [-1] * len(graph)

    def find_min(v, p):
        index = 0
        min_num = sys.maxsize
        for i, v in enumerate(v):
            if i != p and min_num > v != 0:
                index = i
                min_num = v
        return index

    current = 0
    while sys.maxsize in dis:
        for i, v in enumerate(graph[current]):
            if v and dis[i] > graph[current][i] + dis[current]:
                dis[i] = graph[current][i] + dis[current]
                parent[i] = current
        current = find_min(graph[current], parent[current])
    return parent, dis


if __name__ == '__main__':

    graph = [
        [0, 4, 0, 0, 0, 0, 0, 8, 0],
        [4, 0, 8, 0, 0, 0, 0, 11, 0],
        [0, 8, 0, 7, 0, 4, 0, 0, 2],
        [0, 0, 7, 0, 9, 14, 0, 0, 0],
        [0, 0, 0, 9, 0, 10, 0, 0, 0],
        [0, 0, 4, 14, 10, 0, 2, 0, 0],
        [0, 0, 0, 0, 0, 2, 0, 1, 6],
        [8, 11, 0, 0, 0, 0, 1, 0, 7],
        [0, 0, 2, 0, 0, 0, 6, 7, 0]
    ]

    a, b = Dijskstra(graph)

    index = 6
    i = index - 1
    temp = [index]
    while a[i] != -1:
        temp.append(a[i]+1)
        i = a[i]
    print("=>".join(map(str, temp[::-1])))
    print(b[index-1])
