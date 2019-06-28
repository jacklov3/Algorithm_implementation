//
// Created by fish on 2019-06-28.
//

//计算列表中最大的位数
int maxbit(int data[],int n){
    int maxData = data[0];
    for(int i=1;i<n;i++) {
        if (data[i] > maxData)
            maxData = data[i];
    }
    int d=1;int base=10;
    while (maxData>=base){
        maxData /=10;
        ++d;
    }
    return d;
}

//基数排序
void radixsort(int data[],int n){
    int d=maxbit(data,n);
    int *tmp = new int[n];
    int *count = new int[10];//计数器
    int radix = 1;
    for(int i=1;i<=d;i++){
        for (int j=0;j<10;j++)
            count[j]=0;
        for(int j=0;j<n;j++){
            int k = (data[j]/radix)%10;//统计每个桶中的记录数
            count[k]++;
        }
        for (int j = 1; j < 10; ++j)
            count[j]=count[j-1]+count[j];

        for(int j=n-1;j>=0;j--){//将计数排序的东西赋予tmp数组
            int k=(data[j]/radix)%10;
            tmp[count[k]-1]=data[j];
            count[k]--;
        }
        for (int j = 0; j < n; ++j) //将临时数组的内容复制到data中
            data[j]=tmp[j];
        radix=radix*10;
    }
    delete []tmp;
    delete []count;
}
