def journeyToMoon(n, astronaut):
    adj = [[] for i in range(n)]
    visited = [0 for i in range(n)]
    for i in range(len(astronaut)):
        adj[astronaut[i][0]].append(astronaut[i][1])
        adj[astronaut[i][1]].append(astronaut[i][0])
    different = 0
    sets = []
    for i in range(n):
        if(visited[i]==0):
            temp = []
            different+=1
            q = [i]
            visited[i] = 1
            temp.append(i)
            while(len(q)!=0):
                node = q.pop(0)
                for it in adj[node]:
                    if(visited[it]==0):
                        visited[it]= 1
                        q.append(it)
                        temp.append(it)
            sets.append(temp)
    # print(sets)
    # print(different)
    ans = 0
    for i in range(different):
        ans+=len(sets[i])*(sum([len(sets[j]) for j in range(i+1,different)]))
    return ans