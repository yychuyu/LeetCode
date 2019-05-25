int findJudge(int N, int** trust, int trustRowSize, int trustColSize) {
    int out,in;
    int i;
    /* 两种不同的申请二维数组的方法1，此种方法借助malloc来实现*/
    int **graph;
    graph = (int **)malloc(N*sizeof(int *));
    for(i=0;i<N;i++){
    graph[i] = (int *)malloc(2*sizeof(int));
    graph[i][0]=0;
    graph[i][1]=0;
    }
    /* 两种不同的申请二维数组的方法2，此种方法借助C99的变长数组(VLA)来实现*/
    // int graph[N][2];
    // for(i=0;i<N;i++){
    // graph[i][0]=0;
    // graph[i][1]=0;
    // }
    for(i=0;i<trustRowSize;i++){
            out = trust[i][0];
            in  = trust[i][1];
            graph[out-1][0]++;
            graph[in-1][1]++;
    }
    for(i=0;i<N;i++){
        if(graph[i][0]==0&&graph[i][1]==N-1)
            return i+1;
    }
    for(i=0;i<N;i++)//释放动态内存空间
    free(*(graph+i));
    return -1;
}
