def DEBUG(debug,*args):
    if not debug:
        return
    for i in args:
        print(i)

def dfs(ps, strs, num):
    if ps[num]!=0:
        return (ps[num], strs[num])
    np,ns = dfs(ps, strs, num-1)
    ps[num] =np*2+1
    strs[num]=ns*2+3
    return (ps[num], strs[num])

def dfs2(ps, strs, num, x):
    if num==0:
        return 1
    if x==1:
        return 0
    elif x > 1 and x < 1+strs[num-1]:
        return dfs2(ps, strs, num-1, x-1)
    elif x==1+strs[num-1] or x==2+strs[num-1]:
        return ps[num-1]+1
    elif x> 2+strs[num-1] and x < strs[num]:
        return ps[num-1] + 1 + dfs2(ps, strs, num-1, x-2-strs[num-1])
    elif x==strs[num]:
        return ps[num]
    assert("why?")


if __name__ == "__main__":
    debug=False

    N,X = map(int, input().split())
    ps= [0]*(N+1)
    strs=[0]*(N+1)
    ps[0]=1
    strs[0]=1
    dfs(ps, strs, N) 
    st = dfs2(ps, strs, N, X)
    # DEBUG(debug,st)
    print(st)
