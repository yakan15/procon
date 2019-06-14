import heapq
if __name__ == "__main__":
    n,k = map(int,input().split())
    lst = [list(map(int,input().split())) for i in range(n)]
    selected = [False] * (n+1)
    pq = []
    lst.sort(key=lambda x:x[1], reverse=True)
    f = [0] * (n+1)
    cnt = 0
    res = 0
    for i in range(k):
        res += lst[i][1]
        if selected[lst[i][0]]:
            heapq.heappush(pq, lst[i][1])
        else:
            selected[lst[i][0]]=True
            cnt += 1
    f[cnt] = res
    now = k
    while len(pq)!=0 and now<n:
        diff=0
        while now < n and selected[lst[now][0]]:
            now +=1
        if now >= n:
            break
        diff -= heapq.heappop(pq)
        diff += lst[now][1]
        selected[lst[now][0]] = True
        cnt += 1
        f[cnt]=f[cnt-1]+diff
    res = 0 
    for i in range(n+1):
        if f[i]!=0 and f[i]+i**2>res:
            res=f[i]+i**2
    print("{}".format(res))
        

