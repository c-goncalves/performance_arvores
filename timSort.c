
#define RUN 2


void timSort(int arr[], int tamanho){
    if (arr == 0 || tamanho <= 1) return;
    int i;
    for (i=0; i < tamanho; i+=RUN){
        tim_insertionSort(arr, i, min(i+RUN-1, tamanho-1));
    }
    int* temp = (int*)malloc(sizeof(int)*tamanho);
    int l, m, r, n;
    for (n=RUN; n < tamanho; n*=2){
        for (l=0; l < tamanho; l+=2*n){
            m = l+n-1;
            r = min(l+2*n-1, tamanho-1);
            if (m<r){
                tim_merge(arr, temp, l, m, r);
            }
        }
    }
    free(temp);
}
void tim_insertionSort(int arr[], int l, int r) {
    if (arr == 0 || l>=r) return;
    int key;
    int i, j;
    for (i=l+1; i<=r; i++) {
        key = arr[i];
        j = i-1;
            while (j>=l && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
void tim_merge(int arr[], int temp[], int l, int m, int r){
    if (arr == 0 || temp == 0) return;
    if (l > m || m+1 > r) return;
    int i = l;
    int j = m + 1;
    int start = l;
    while (i <= m && j <= r){
        if (arr[i] < arr[j]){
            temp[start++] = arr[i++];
        }else if (arr[i] == arr[j]){
            temp[start++] = arr[i++];
            temp[start++] = arr[j++];
        }else{temp[start++] = arr[j++];}
    }
    while (i <= m){temp[start++] = arr[i++];}
    while (j <= r){temp[start++] = arr[j++];}
    for (i = l; i <= r; i++){arr[i] = temp[i];}
}

int min(int arg1, int arg2){
    if (arg1 <= arg2){
        return arg1;
    } else {
        return arg2;
    }
}
