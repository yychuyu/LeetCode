class Solution:
        
    def numIslands(self, grid):
        
        if not grid:
            return 0

        # 确定gird的长和宽
        height = len(grid)
        width  = len(grid[0])

        # 初始化lst,指针和计数器
        lst = []
        pointer = 0
        counter = 1

        # 将当前元素变成counter并保存其位置到lst中
        def fun1(r1, c1):
            grid[r1][c1] = counter
            coordinate = (r1, c1)
            lst.append(coordinate)

        # 检查当前元素相邻元素
        def fun2(r2, c2):
            # 右侧元素
            if c2 + 1 < width and grid[r2][c2 + 1] == "1":
                fun1(r2, c2 + 1)
            # 下侧元素
            if r2 + 1 < height and grid[r2 + 1][c2] == "1":
                fun1(r2 + 1, c2)
            # 左侧元素
            if c2 - 1 >= 0 and grid[r2][c2 - 1] == "1":
                fun1(r2, c2 - 1)
            # 上侧元素
            if r2 - 1 >= 0 and grid[r2 - 1][c2] == "1":
                fun1(r2 - 1, c2)

        # 主循环
        while True:
            flag_main = True
            for row in range(height):
                for col in range(width):
                    if grid[row][col] == "1":
                        flag_main = False
                        fun1(row, col)
                        fun2(row, col)
                        while True:
                            a = lst[pointer]
                            if a != lst[-1]:  # p2 = None
                                pointer += 1
                                r3, c3 = lst[pointer]
                                fun2(r3, c3)
                            else:
                                break
                        print(pointer)
                        break
                else:
                    continue
                break

            if flag_main:
                print(counter - 1)
                print(lst)
                return counter - 1
            counter += 1