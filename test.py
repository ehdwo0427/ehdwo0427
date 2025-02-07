import sys

INF= sys.maxsize

def bellman(start):
  global n
  distance = [-INF]*(n+1)
  distance[start]=0
  route= [0]*(n+1)
  result=[]

  for i in range(n):
    for cur_node in range(1, n+1):
      if distance[cur_node]==-INF:
          continue

      for next_node, next_cost in graph[cur_node]:
        if distance[next_node]<distance[cur_node]+next_cost: 
          distance[next_node]=distance[cur_node]+next_cost 
          route[next_node]=cur_node 
          if i==n-1:
            distance[next_node]=INF  
  if distance[n]==INF: 
    print(-1)
    return
  else:
    result.append(n)
    while(n!=1):
      result.append(route[n])
      n= route[n]
    
    result.reverse()
    print(*result)
    return


n,m= map(int, input().split())

graph=[[] for _ in range(n+1)]

for _ in range(m):
  a,b,c= map(int, input().split())
  graph[a].append((b,c))


bellman(1)
