int findJudge(int N, int** trust, int trustRowSize, int trustColSize) {
    int out,in;
    int i;
    /* ���ֲ�ͬ�������ά����ķ���1�����ַ�������malloc��ʵ��*/
    int **graph;
    graph = (int **)malloc(N*sizeof(int *));
    for(i=0;i<N;i++){
    graph[i] = (int *)malloc(2*sizeof(int));
    graph[i][0]=0;
    graph[i][1]=0;
    }
    /* ���ֲ�ͬ�������ά����ķ���2�����ַ�������C99�ı䳤����(VLA)��ʵ��*/
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
    for(i=0;i<N;i++)//�ͷŶ�̬�ڴ�ռ�
    free(*(graph+i));
    return -1;
}
